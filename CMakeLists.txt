cmake_minimum_required(VERSION 3.10)

project(LearnCPP)

# 设置可执行文件的生成目录
set(EXECUTABLE_OUTPUT_PATH ${LearnCPP_SOURCE_DIR}/output)

option(USE_SALES_DATA "Use Sales_data" OFF)

if(DEFINED USE_SALES_DATA)
    message(STATUS "Sales_data: " ${USE_SALES_DATA})

    add_definitions(-DUSE_SALES_DATA)

    # 告诉cmake去include下找CMakeLists.txt文件，其Makefile文件放在bin下
    add_subdirectory(${CMAKE_SOURCE_DIR}/include bin)

    # 告诉cmake去include文件下找头文件
    include_directories(${CMAKE_SOURCE_DIR}/include)

    # 添加需要链接的库文件
    link_libraries(Sales_data)

    list(APPEND EXTRA_LIBS Sales_data)
    list(APPEND EXTRA_INCLUDES "${CMAKE_SOURCE_DIR}/include")
endif(USE_SALES_DATA)

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" -g -O2 -Wall)

set(CMAKE_BUILD_TYPE Debug)

set(IOStream src/IOStream)
set(DynamicMemory src/DynamicMemory)

set(Bookstore ${IOStream}/Bookstore/Bookstore.cpp)
set(PhoneNum ${IOStream}/PhoneNum/PhoneNum.cpp)
set(WordTransformation ${IOStream}/WordTransformation/WordTransformation.cpp)

message(STATUS "This is binary dir " ${LearnCPP_BINARY_DIR})
message(STATUS "This is source dir " ${LearnCPP_SOURCE_DIR})

add_executable(main ${Bookstore})
# add_executable(main ${PhoneNum})
# add_executable(main ${WordTransformation})

target_include_directories(main PUBLIC ${EXTRA_INCLUDES})

# link_directories(${CMAKE_SOURCE_DIR}/lib)

# 链接库到.exe上
target_link_libraries(main PUBLIC ${EXTRA_LIBS})
# target_link_libraries(main PUBLIC Sales_data)

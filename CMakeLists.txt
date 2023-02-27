cmake_minimum_required(VERSION 3.10)

project(LearnCpp VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_definitions(-DNOMINMAX)

option(USE_SALES_DATA "Sales_data" OFF)
option(USE_BITREE "BiTree" ON)

configure_file(LearnCppConfig.h.in LearnCppConfig.h)

if(USE_SALES_DATA)
    message(STATUS "Sales_data: " ${USE_SALES_DATA})

    # add_definitions(-DUSE_SALES_DATA)

    # 告诉cmake去include下找CMakeLists.txt文件，其Makefile文件放在bin下
    add_subdirectory(include)

    list(APPEND EXTRA_LIBS Sales_data)
endif()

if(USE_BITREE)
    message(STATUS "BiTree: " ${USE_BITREE})

    # add_definitions(-DUSE_SALES_DATA)

    add_subdirectory(include)

    list(APPEND EXTRA_LIBS BiTree)
endif()

# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" -g -O2 -Wall)

# set(CMAKE_BUILD_TYPE Debug)

set(IOStream src/IOStream)
set(DynamicMemory src/DynamicMemory)
set(BinaryTree src/BinaryTree)

set(Bookstore ${IOStream}/Bookstore/Bookstore.cpp)
set(PhoneNum ${IOStream}/PhoneNum/PhoneNum.cpp)
set(WordTransformation ${IOStream}/WordTransformation/WordTransformation.cpp)

message(STATUS "This is binary dir " ${PROJECT_BINARY_DIR})
message(STATUS "This is source dir " ${PROJECT_SOURCE_DIR})

# add_executable(main ${Bookstore} ${PROJECT_BINARY_DIR}/LearnCppConfig.h)
# add_executable(main ${PhoneNum} ${PROJECT_BINARY_DIR}/LearnCppConfig.h)
# add_executable(main ${WordTransformation} ${PROJECT_BINARY_DIR}/LearnCppConfig.h)
add_executable(main ${BinaryTree}/main.cpp ${PROJECT_BINARY_DIR}/LearnCppConfig.h)

# 链接库到.exe上
target_link_libraries(main PUBLIC ${EXTRA_LIBS})

# target_include_directories(main PUBLIC ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/include)
# target_include_directories(main PUBLIC "${PROJECT_BINARY_DIR}" ${EXTRA_INCLUDES})
target_include_directories(main PUBLIC ${PROJECT_BINARY_DIR})

# install(TARGETS main DESTINATION bin)
# install(FILES "${PROJECT_BINARY_DIR}/LearnCppConfig.h" DESTINATION include)
# install(FILES "${IOStream}/Bookstore/input.txt" DESTINATION src/IOStream/Bookstore)

# include(InstallRequiredSystemLibraries)
# set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
# set(CPACK_PACKAGE_VERSION_MAJOR "${LearnCpp_VERSION_MAJOR}")
# set(CPACK_PACKAGE_VERSION_MINOR "${LearnCpp_VERSION_MINOR}")
# set(CPACK_SOURCE_GENERATOR "TGZ")
# include(CPack)

# cmake -G "MinGW Makefiles" ..
# cmake --build .
# 安装命令路径无权限
# cmake --install . --prefix "C:\Users\IssacF\Documents\Visual Studio Code\LearnCpp\"
# objdump -s -d xxx.o

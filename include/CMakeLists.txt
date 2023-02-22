add_library(Sales_data Sales_data.cpp)

# 给当前需要编译的目标文件指定目录，CMAKE_CURRENT_SOURCE_DIR是此CMakeLists的所在目录
target_include_directories(Sales_data INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS Sales_data DESTINATION lib)
install(FILES Sales_data.h DESTINATION include)

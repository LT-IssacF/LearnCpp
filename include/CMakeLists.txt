# 告诉cmake去include文件下找头文件
include_directories(${CMAKE_SOURCE_DIR}/include)

# 设置静态库文件.a的生成目录
set(LIBRARY_OUTPUT_PATH ${LearnCPP_SOURCE_DIR}/lib)

# 生成静态库文件
add_library(Sales_data STATIC Sales_data.cpp)

set_target_properties(Sales_data PROPERTIES OUTPUT_NAME "Sales_data")

set_target_properties(Sales_data PROPERTIES CLEAN_DIRECT_OUTPUT 1)

add_library(Sales_datadll SHARED Sales_data.cpp)

set_target_properties(Sales_datadll PROPERTIES OUTPUT_NAME "Sales_data")

set_target_properties(Sales_datadll PROPERTIES CLEAN_DIRECT_OUTPUT 1)

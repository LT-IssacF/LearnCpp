# 告诉cmake去include文件下找头文件
include_directories(${CMAKE_SOURCE_DIR}/include)

# 设置库文件.a的生成目录
set(LIBRARY_OUTPUT_PATH ${LearnCPP_SOURCE_DIR}/lib)

# 生成库文件
add_library(Sales_data STATIC Sales_data.cpp)

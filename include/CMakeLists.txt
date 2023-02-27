if(USE_SALES_DATA)
    add_library(Sales_data STATIC Sales_data.cpp)
    # 给当前需要编译的目标文件指定目录，CMAKE_CURRENT_SOURCE_DIR是此CMakeLists的所在目录
    target_include_directories(Sales_data INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
    install(TARGETS Sales_data DESTINATION lib)
    install(FILES Sales_data.h DESTINATION include)
endif()

if(USE_BITREE)
    add_library(BiTree STATIC BiTree.cpp)
    target_include_directories(BiTree INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
    install(TARGETS BiTree DESTINATION lib)
    install(FILES BiTree.h DESTINATION include)
endif()

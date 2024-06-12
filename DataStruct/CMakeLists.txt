# 添加库 "DataStruct"
add_library(DataStruct STATIC
    HttpResponse.cpp
    HttpResponse.h
)

target_link_libraries(DataStruct PRIVATE Logger)

# 公开头文件目录
target_include_directories(DataStruct PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
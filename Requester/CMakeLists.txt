# 添加库 "Requester"
add_library(Requester STATIC
    Requester.cpp 
    Requester.h
)

target_link_libraries(Requester PRIVATE Logger DataStruct)

# 公开头文件目录
target_include_directories(Requester PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
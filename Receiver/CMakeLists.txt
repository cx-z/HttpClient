# 添加库 "Receiver"
add_library(Receiver STATIC
    Receiver.cpp 
    Receiver.h
)

target_link_libraries(Receiver PRIVATE Logger DataStruct)

# 公开头文件目录
target_include_directories(Receiver PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
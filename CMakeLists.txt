cmake_minimum_required(VERSION 3.10)

# 设置项目名称和版本
project(HttpClient VERSION 1.0)

# 指定 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# 可调试
set(CMAKE_BUILD_TYPE Debug)

# 添加可执行文件
add_executable(HttpClient main.cpp)

# 包含子目录
add_subdirectory(Logger)
add_subdirectory(DataStruct)
add_subdirectory(Receiver)
add_subdirectory(Requester)
add_subdirectory(Utils)

# 链接 Logger 库到主可执行文件
target_link_libraries(HttpClient PRIVATE Logger DataStruct Receiver Requester)
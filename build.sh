#!/bin/bash

# 检查是否存在build目录，如果不存在则创建
if [ ! -d "build" ]; then
    echo "Creating build directory..."
    mkdir build
fi

# 进入build目录
cd build

# 清理build目录中的所有文件
echo "Cleaning build directory..."
rm -rf *

# 执行cmake生成makefile
echo "Running CMake..."
cmake ..

# 构建项目
echo "Building project..."
make

# 如果需要，可以在这里添加更多命令，例如运行测试等

echo "Build completed."
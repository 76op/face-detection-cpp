# MCP Demo

这是一个使用 CMake 构建的 C++ 项目，集成了 OpenCV 库。

## 依赖项

- CMake (>= 3.10)
- OpenCV
- C++17 兼容的编译器

## 构建说明

1. 创建构建目录：
   ```bash
   mkdir build
   cd build
   ```

2. 配置项目：
   ```bash
   cmake ..
   ```

3. 构建项目：
   ```bash
   cmake --build .
   ```

## 项目结构

- `src/`: 源代码文件
- `include/`: 头文件（如果需要）
- `CMakeLists.txt`: CMake 构建配置
- `.gitignore`: Git 忽略文件配置

## 许可证

[MIT License](LICENSE)

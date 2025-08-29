# MCP Demo

这是一个使用 CMake 构建的 C++ 项目，集成了 OpenCV 库，实现了基本的人脸检测功能。

## 功能特性

- 使用 OpenCV 的 Haar 级联分类器进行人脸检测
- 支持图像文件输入
- 包含单元测试
- 规范的代码组织结构

## 依赖项

- CMake (>= 3.10)
- OpenCV
- C++17 兼容的编译器
- Google Test (自动下载)

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

4. 运行测试：
   ```bash
   ctest
   ```

## 使用方法

运行程序需要两个参数：
1. 级联分类器文件路径
2. 要处理的图像文件路径

例如：
```bash
./mcp_demo data/haarcascade_frontalface_alt.xml path/to/image.jpg
```

## 项目结构

- `include/`: 头文件
  - `face_detector.hpp`: 人脸检测器类的声明
- `src/`: 源代码文件
  - `face_detector.cpp`: 人脸检测器类的实现
  - `main.cpp`: 主程序入口
- `tests/`: 测试文件
  - `face_detector_test.cpp`: 人脸检测器的单元测试
- `CMakeLists.txt`: CMake 构建配置
- `README.md`: 项目文档

## 代码规范

- 使用 namespace 封装
- 清晰的类层次结构
- 完整的错误处理
- 详细的注释文档
- 统一的代码风格

## 许可证

[MIT License](LICENSE)

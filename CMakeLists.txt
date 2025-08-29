cmake_minimum_required(VERSION 3.10)

project(mcp_demo)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找 OpenCV 包
find_package(OpenCV REQUIRED)

# 启用测试
enable_testing()

# 查找 Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
FetchContent_MakeAvailable(googletest)

# 添加头文件目录
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)

# 添加库目标
add_library(face_detector
    src/face_detector.cpp
)
target_link_libraries(face_detector ${OpenCV_LIBS})

# 添加可执行文件
add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME}
    face_detector
    ${OpenCV_LIBS}
)

# 添加测试
add_executable(face_detector_test
    tests/face_detector_test.cpp
)
target_link_libraries(face_detector_test
    face_detector
    GTest::gtest_main
    ${OpenCV_LIBS}
)

# 注册测试
include(GoogleTest)
gtest_discover_tests(face_detector_test)

# 下载级联分类器文件
set(CASCADE_URL "https://raw.githubusercontent.com/opencv/opencv/master/data/haarcascades/haarcascade_frontalface_alt.xml")
set(CASCADE_PATH "${CMAKE_BINARY_DIR}/data/haarcascade_frontalface_alt.xml")

file(DOWNLOAD ${CASCADE_URL} ${CASCADE_PATH} SHOW_PROGRESS)

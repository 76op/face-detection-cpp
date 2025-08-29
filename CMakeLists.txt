cmake_minimum_required(VERSION 3.10)

project(mcp_demo)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找 OpenCV 包
find_package(OpenCV REQUIRED)

# 查找 Python
find_package(Python3 REQUIRED)

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

# 创建数据目录
add_custom_target(create_data_dirs
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/data/test_images
)

# 下载 Haar 级联分类器
add_custom_target(download_cascade
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        https://raw.githubusercontent.com/opencv/opencv/master/data/haarcascades/haarcascade_frontalface_alt.xml
        ${CMAKE_SOURCE_DIR}/data/haarcascade_frontalface_alt.xml
    DEPENDS create_data_dirs
)

# 生成测试图片
add_custom_target(generate_test_images
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/scripts/generate_test_images.py
    DEPENDS create_data_dirs
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

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

# 添加单元测试
add_executable(unit_tests
    tests/face_detector_test.cpp
)
target_link_libraries(unit_tests
    face_detector
    GTest::gtest_main
    ${OpenCV_LIBS}
)

# 添加集成测试
add_executable(integration_tests
    tests/integration_test.cpp
)
target_link_libraries(integration_tests
    face_detector
    GTest::gtest_main
    ${OpenCV_LIBS}
)

# 注册测试
include(GoogleTest)
gtest_discover_tests(unit_tests)
gtest_discover_tests(integration_tests)

# 添加测试数据依赖
add_dependencies(unit_tests download_cascade generate_test_images)
add_dependencies(integration_tests download_cascade generate_test_images)

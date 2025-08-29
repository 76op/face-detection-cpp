#include <gtest/gtest.h>
#include "face_detector.hpp"
#include <opencv2/opencv.hpp>

class FaceDetectorTest : public ::testing::Test {
protected:
    void SetUp() override {
        // 设置测试用的级联分类器路径
        cascade_path_ = cv::samples::findFile(
            "haarcascade_frontalface_alt.xml",
            false,
            "../data"
        );
        
        // 创建测试图像
        test_image_ = cv::Mat(400, 400, CV_8UC3, cv::Scalar(255, 255, 255));
        // 在图像中央绘制一个类似人脸的圆形
        cv::circle(test_image_, cv::Point(200, 200), 100, cv::Scalar(200, 200, 200), -1);
    }

    std::string cascade_path_;
    cv::Mat test_image_;
};

TEST_F(FaceDetectorTest, ConstructorTest) {
    ASSERT_NO_THROW({
        mcp::FaceDetector detector(cascade_path_);
    });
}

TEST_F(FaceDetectorTest, InvalidCascadePathTest) {
    ASSERT_THROW({
        mcp::FaceDetector detector("invalid_path.xml");
    }, std::runtime_error);
}

TEST_F(FaceDetectorTest, EmptyImageTest) {
    mcp::FaceDetector detector(cascade_path_);
    cv::Mat empty_image;
    
    ASSERT_THROW({
        detector.detect(empty_image);
    }, std::invalid_argument);
}

TEST_F(FaceDetectorTest, DetectTest) {
    mcp::FaceDetector detector(cascade_path_);
    std::vector<cv::Rect> faces = detector.detect(test_image_);
    
    // 验证是否返回了检测结果（可能检测到也可能没检测到）
    ASSERT_NO_THROW({
        mcp::FaceDetector::drawFaces(test_image_, faces);
    });
}

#include "face_detector.hpp"

namespace mcp {

FaceDetector::FaceDetector(const std::string& cascade_path) {
    if (!face_cascade_.load(cascade_path)) {
        throw std::runtime_error("Error loading cascade classifier");
    }
}

std::vector<cv::Rect> FaceDetector::detect(const cv::Mat& image) {
    if (image.empty()) {
        throw std::invalid_argument("Input image is empty");
    }

    std::vector<cv::Rect> faces;
    cv::Mat gray;

    // 转换为灰度图像
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    cv::equalizeHist(gray, gray);

    // 检测人脸
    face_cascade_.detectMultiScale(
        gray,
        faces,
        1.1,     // scale factor
        3,       // minimum neighbors
        0,       // flags
        cv::Size(30, 30) // minimum size
    );

    return faces;
}

void FaceDetector::drawFaces(cv::Mat& image, const std::vector<cv::Rect>& faces) {
    for (const auto& face : faces) {
        // 绘制矩形框
        cv::rectangle(image, face, cv::Scalar(0, 255, 0), 2);
    }
}

} // namespace mcp

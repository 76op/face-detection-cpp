#ifndef FACE_DETECTOR_HPP
#define FACE_DETECTOR_HPP

#include <opencv2/opencv.hpp>
#include <string>
#include <vector>
#include <stdexcept>

namespace mcp {

class FaceDetector {
public:
    /**
     * @brief 构造函数
     * @param cascade_path 级联分类器文件路径
     * @throw std::runtime_error 如果分类器加载失败
     */
    explicit FaceDetector(const std::string& cascade_path);

    /**
     * @brief 检测图像中的人脸
     * @param image 输入图像
     * @return 检测到的人脸矩形区域向量
     */
    std::vector<cv::Rect> detect(const cv::Mat& image);

    /**
     * @brief 在图像上绘制检测到的人脸
     * @param image 要绘制的图像
     * @param faces 人脸矩形区域向量
     */
    static void drawFaces(cv::Mat& image, const std::vector<cv::Rect>& faces);

private:
    cv::CascadeClassifier face_cascade_;
};

} // namespace mcp

#endif // FACE_DETECTOR_HPP

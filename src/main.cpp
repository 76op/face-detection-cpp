#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    std::cout << "MCP Demo with OpenCV " << CV_VERSION << std::endl;
    
    // 创建一个测试图像
    cv::Mat image(400, 600, CV_8UC3, cv::Scalar(255, 255, 255));
    
    // 在图像上绘制文本
    cv::putText(image, "MCP Demo", 
                cv::Point(200, 200),
                cv::FONT_HERSHEY_SIMPLEX,
                1.0,
                cv::Scalar(0, 0, 255),
                2);
    
    // 显示图像
    cv::imshow("MCP Demo", image);
    cv::waitKey(0);
    
    return 0;
}

#include <iostream>
#include <string>
#include "face_detector.hpp"

int main(int argc, char* argv[]) {
    try {
        // 检查命令行参数
        if (argc != 3) {
            std::cerr << "Usage: " << argv[0] 
                      << " <cascade_file_path> <image_path>" << std::endl;
            return 1;
        }

        // 创建人脸检测器
        mcp::FaceDetector detector(argv[1]);

        // 读取图像
        cv::Mat image = cv::imread(argv[2]);
        if (image.empty()) {
            std::cerr << "Error: Could not read image file: " << argv[2] << std::endl;
            return 1;
        }

        // 检测人脸
        std::vector<cv::Rect> faces = detector.detect(image);

        // 绘制结果
        detector.drawFaces(image, faces);

        // 显示结果
        std::cout << "Found " << faces.size() << " faces" << std::endl;
        cv::imshow("Face Detection Result", image);
        cv::waitKey(0);

        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}

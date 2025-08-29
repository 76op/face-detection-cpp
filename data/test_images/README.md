# 测试图像说明

## 图像来源

本目录中的测试图像应从以下来源获取：

1. OpenCV 官方示例图片：
   - https://github.com/opencv/opencv/tree/master/samples/data

2. 公开的人脸数据集：
   - Yale Face Database
   - AT&T Face Database
   - CelebA Dataset 公开样本

3. 创造内容：
   - 手绘人脸
   - Emoji 表情
   - 简笔画人脸

## 使用说明

1. 在这个目录中应包含以下类型的图片：
   - single_face.jpg: 单人脸测试图片
   - multiple_faces.jpg: 多人脸测试图片
   - no_face.jpg: 无人脸测试图片
   - test_face_1.jpg, test_face_2.jpg 等：其他测试图片

2. 使用前请确保：
   - 图片大小适中（建议 300x300 至 1024x1024 像素）
   - 格式为 JPG 或 PNG
   - 清晰度足够进行人脸检测

## 获取测试图片

你可以通过以下方式获取测试图片：

1. 下载 OpenCV 官方示例：
   ```bash
   wget https://raw.githubusercontent.com/opencv/opencv/master/samples/data/face.jpg -O single_face.jpg
   wget https://raw.githubusercontent.com/opencv/opencv/master/samples/data/faces.jpg -O multiple_faces.jpg
   ```

2. 使用公开数据集：
   - Yale Face Database: http://vision.ucsd.edu/content/yale-face-database
   - AT&T Face Database: https://git-disl.github.io/GTDLBench/datasets/att_face_dataset/

3. 创建简单的测试图片：
   - 使用简单的绘图工具创建人脸轮廓
   - 使用几何图形绘制人脸轮廓

注意：使用任何图片前请确保符合相关的使用条款和版权要求。
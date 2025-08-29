import cv2
import numpy as np

def create_simple_face(width=300, height=300):
    # 创建白色背景
    image = np.ones((height, width, 3), dtype=np.uint8) * 255
    
    # 绘制脸型（圆形）
    center = (width//2, height//2)
    face_radius = min(width, height)//3
    cv2.circle(image, center, face_radius, (220, 220, 220), -1)
    
    # 绘制眼睛
    eye_radius = face_radius//6
    left_eye_center = (center[0] - face_radius//3, center[1] - face_radius//4)
    right_eye_center = (center[0] + face_radius//3, center[1] - face_radius//4)
    cv2.circle(image, left_eye_center, eye_radius, (100, 100, 100), -1)
    cv2.circle(image, right_eye_center, eye_radius, (100, 100, 100), -1)
    
    # 绘制嘴巴
    smile_center = center[1] + face_radius//3
    cv2.ellipse(image, 
                (center[0], smile_center),
                (face_radius//2, face_radius//4),
                0, 0, 180, (150, 150, 150), 2)
    
    return image

def create_multiple_faces(width=600, height=400, face_count=3):
    image = np.ones((height, width, 3), dtype=np.uint8) * 255
    face_size = min(width//(face_count+1), height//2)
    
    for i in range(face_count):
        x = (i + 1) * width//(face_count + 1)
        y = height//2
        face = create_simple_face(face_size, face_size)
        
        # 把小人脸放到大图中
        y_start = y - face_size//2
        y_end = y_start + face_size
        x_start = x - face_size//2
        x_end = x_start + face_size
        
        image[y_start:y_end, x_start:x_end] = face
    
    return image

def create_no_face():
    # 创建一个简单的几何图案
    image = np.ones((400, 600, 3), dtype=np.uint8) * 255
    
    # 绘制一些几何图形
    cv2.rectangle(image, (100, 100), (200, 200), (200, 200, 200), -1)
    cv2.circle(image, (400, 200), 50, (180, 180, 180), -1)
    cv2.line(image, (250, 300), (350, 300), (150, 150, 150), 5)
    
    return image

def main():
    # 生成并保存测试图片
    cv2.imwrite('data/test_images/test_face_1.jpg', create_simple_face())
    cv2.imwrite('data/test_images/test_faces_group.jpg', create_multiple_faces())
    cv2.imwrite('data/test_images/test_no_face.jpg', create_no_face())

if __name__ == '__main__':
    main()

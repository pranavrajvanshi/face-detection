#include<iostream>
#include<stdlib.h>
#include<opencv2\objdetect\objdetect.hpp>
#include<opencv2\highgui\highgui.hpp>

using namespace std;
using namespace cv;
int main() {
	CascadeClassifier fd;
	if (!fd.load("E:\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml")) {
		cout << "\n load the file properly";
		exit(0);
	}
	char path[100];
	cout << "\n enter image path";
	cin.getline(path, 100);

	Mat image = imread(path, IMREAD_UNCHANGED);
	
	if (image.empty()) {
		cout << "\n image not loaded properly";
	}
	else {
		cout << "\n Processing...";
		
		vector<Rect> faces;
		fd.detectMultiScale(image, faces);
		for (int i = 0; i < faces.size(); i++) {
			Point p1(faces[i].x, faces[i].y);
			Point p2((faces[i].x + faces[i].height), (faces[i].y + faces[i].width));
			rectangle(image, p1, p2, Scalar(255, 0, 0), 3, 8, 0);
		}
		
		imwrite("E:\\opencv\\jpg images\\fd.jpg",image);
		cout << "\n face detected";
	}
	
	
	
	
	return 0;
}
#include <iostream>
#include <conio.h>
#include <opencv2/opencv.hpp>
#include <fstream>
using namespace std;
using namespace cv;

void whereIsDice(Mat img, int &x, int &y)
{
	int maxX = 0;
	int maxY = 0;
	double maxSum = 0;
	for (int i = 0; i < img.cols - 200; i += 20)
	{
		for (int j = 0; j < img.rows - 200; j += 20)
		{
			int sum = 0;
			for (int k = 0; k < 200; k++)
			{

				for (int l = 0; l < 200; l++)
				{
					sum += img.at<uchar>(i + k, j + l);
				}
			}
			if (sum > maxSum)
			{
				maxY = i;
				maxX = j;
				maxSum = sum;
			}

		}
	}
	x = maxX;
	y = maxY;
}

Mat makeBW(Mat &image)
{
	for (int x = 0; x < image.cols; x++)
	{
		for (int y = 0; y < image.rows; y++)
		{
			if (image.at<uchar>(x, y) <= 50) image.at<uchar>(x, y) = 0;
			else image.at<uchar>(x, y) = 255;
		}
	}
	return image;
}

// pierwszy znak w tekscie 4-d4 6-d6 8-d8 9-d10 3-d12 2-d20
void myFunction(string whichDice, string trainOrValid, int count, string firstNumberInTxt)
{
	string endJPG = ").jpg";
	string endBMP = ").bmp";
	string endTXT = ").txt";

	for (int i = 1; i <= count; i++)
	{
		stringstream ss;
		ss << i;
		string str = ss.str();
		string path = "input/dice/"+ trainOrValid+"/"+whichDice+"/dice (" + str + endJPG;
		string pathOUT = "output/diceBWcrop/" + trainOrValid + "/" + whichDice + "/dice (" + str + endBMP;
		string pathOUT2 = "output/diceBWcropResized/" + trainOrValid + "/" + whichDice + "/dice (" + str + endBMP;
		string pathOUT3 = "output/diceTXT/" + trainOrValid + "/" + whichDice + "/dice (" + str + endTXT;


		Mat img = imread(path);
		Mat greyImg;
		cvtColor(img, greyImg, COLOR_BGR2GRAY);
		GaussianBlur(greyImg, greyImg, Size(11, 11), 1.5, 1.5);
		Mat cannyIMG;
		Canny(greyImg, cannyIMG, 100, 150);
		int x;
		int y;
		whereIsDice(cannyIMG, x, y);
		int offset_x = x;
		int offset_y = y;
		cv::Rect roi;
		roi.x = offset_x;
		roi.y = offset_y;
		roi.width = 200;
		roi.height = 200;
		Mat crop = cannyIMG(roi);
		imwrite(pathOUT, crop);
		Mat resizedIMG;
		cv::resize(crop, resizedIMG, cv::Size(), 0.33, 0.33);

		resizedIMG = makeBW(resizedIMG);
		imwrite(pathOUT2, resizedIMG);

		string newS = firstNumberInTxt;
		for (int i = 0; i < resizedIMG.rows; i++)
		{
			for (int j = 0; j < resizedIMG.cols; j++)
			{
				stringstream ss2;
				if (resizedIMG.at<uchar>(i, j) > 100)
					ss2 << 1;
				else
					ss2 << 0;
				string str2 = ss2.str();
				newS += str2;
			}
		}


		ofstream file;
		file.open(pathOUT3);
		file << newS;
		file.close();


		if(i%100==0)cout << i << endl;
	}
}

int main()
{
	// pierwszy znak w tekscie 4-d4 6-d6 8-d8 9-d10 3-d12 2-d20
	//myFunction(string whichDice, string trainOrValid, int count, string firstNumberInTxt)
	myFunction("d4","train",1947,"4");
	cout << "d4 done" << endl;
	myFunction("d6", "train", 4046, "6");
	cout << "d6 done" << endl;
	myFunction("d8", "train", 1532, "8");
	cout << "d8 done" << endl;
	myFunction("d10", "train", 1722, "9");
	cout << "d10 done" << endl;
	myFunction("d12", "train", 1691, "3");
	cout << "d12 done" << endl;
	myFunction("d20", "train", 3346, "2");
	cout << "d20 done" << endl;
	cout << "train done" << endl;

	myFunction("d4", "valid", 278, "4");
	cout << "d4 done" << endl;
	myFunction("d6", "valid", 578, "6");
	cout << "d6 done" << endl;
	myFunction("d8", "valid", 218, "8");
	cout << "d8 done" << endl;
	myFunction("d10", "valid", 246, "9");
	cout << "d10 done" << endl;
	myFunction("d12", "valid", 241, "3");
	cout << "d12 done" << endl;
	myFunction("d20", "valid", 478, "2");
	cout << "d20 done" << endl;
	cout << "valid done" << endl;




	_getch();
	return 0;
}


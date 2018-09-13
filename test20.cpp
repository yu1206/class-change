
#include <fstream>
#include <iostream>
#include <string>
#include <sstream> 
#include "opencv\cv.h"
#include "opencv\highgui.h"
using namespace cv;
using namespace std;
int test20(int argc, char *argv[])
{
	
	string  labelpath = "G:/F/MTCNN/mtcnn-master2/mtcnn-master/train-twoplate-3class-分类/gen-data/train-label.txt";
	string  labelpathone = "G:/F/MTCNN/mtcnn-master2/mtcnn-master/train-twoplate-3class-分类/gen-data/train-label-1.txt";

	fstream finRead;
	finRead.open(labelpath);
	if (!finRead.is_open())
	{
		cout << "finRead 文件数据打开错误！" << endl;
		system("pause");
		return false;
	}

	fstream finWrite;
	finWrite.open(labelpathone, ios::out);
	if (!finWrite.is_open())
	{
		cout << "finRead 文件数据打开错误！" << endl;
		system("pause");
		return false;
	}

	string line;
	while (getline(finRead, line))
	{
		if (line.empty())
		{
			break;
		}
		
		cout << line.c_str() << endl;

		string ntxt; int label; float x1, y1, x2, y2;
		stringstream str_s(line);
		str_s >> ntxt >> label >> x1 >> y1 >> x2 >> y2;
		
		finWrite << ntxt << " " << label-1<<" "<<x1 << " " << y1 << " " << x2 << " " << y2<<endl;
	}
	finRead.close();
	
	return 0;
}

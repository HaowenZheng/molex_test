//#include<string>
//#include<fstream>
//#include <iostream>
//
//using namespace std;
//
//void main()
//{
//
//	fstream file;
//	string filepath = "\\\\zh-mfs-srv\\Passive\\EDFATemp\\haowenz";
//	filepath.append("\\a.txt");
//	//filepath = "C:\\Users\\hzheng17\\OneDrive - kochind.com\\haowenz\\C++11\\test";
//	//filepath.append("\\a.txt");
//	//filepath = "\\a.txt";
//
//	file.open(filepath,std::ios::in | std::ios::out | std::ios::app);
//
//	if (file.is_open())
//	{
//		file << "test text" << endl;
//
//		file.close();
//	}
//	else
//		cout << "打开文件异常" << endl;
//
//	system("pause");
//
//
//}
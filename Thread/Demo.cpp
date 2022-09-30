//#include<iostream>
//using namespace std;
//#include<ctime>
//#include <thread>
//
//class Camera
//{
//public:
//	double perpixum;
//	int col;
//	int row;
//};
//
//class Comport
//{
//public:
//	int port;
//	int baud;
//};
//
//typedef struct AA
//{
//	AA()
//	{
//		cam = nullptr;
//		port = nullptr;
//	}
//	Camera* cam;
//	Comport* port;
//
//};
//
//void test(void* t)
//{
//	AA* a1 = (AA*)t;
//	cout <<"col: " << a1->cam->col << endl;
//	cout << "baud: " << a1->port->baud << endl;
//}
//
//void main()
//{
//	/*time_t now = time(0);
//	cout << now << endl;
//
//	std::this_thread::sleep_for(std::chrono::seconds(2));
//
//	time_t now1 = time(0);
//	cout << now1 << endl;
//
//	cout << now1 - now << endl;*/
//
//	auto now = std::chrono::system_clock::now();
//	std::this_thread::sleep_for(std::chrono::seconds(2));
//	auto now1 = std::chrono::system_clock::now();
//	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now1 - now);
//	cout << duration.count() << endl;
//
//	/*AA t;
//	Camera cam;
//	Comport port;
//	cam.col = 100;
//	port.baud = 9600;
//
//	t.cam = &cam;
//	t.port = &port;
//
//	test((void*)&t);*/
//
//	system("pause");
//	return;
//}
//

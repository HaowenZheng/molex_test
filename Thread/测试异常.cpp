//#include <iostream>
//using namespace std;
//
//#include <thread>
//
//void mythread()
//{
//	std::this_thread::sleep_for(std::chrono::microseconds(2000));
//	cout << "this_thread_id: " << std::this_thread::get_id() << endl;
//	return;
//}
//
//void main()
//{
//	const int num = 10000;
//	std::thread obj[num];
//	for (int i = 0;i < num;++i)
//	{
//		obj[i] = std::thread(mythread);
//	}
//
//	for (int i = 0;i < num;++i)
//	{
//		obj[i].join();
//	}
//	system("pause");
//	return;
//}
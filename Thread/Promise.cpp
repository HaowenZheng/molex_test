//#include <iostream>
//using namespace std;
//#include <future>
//#include <thread>
//
//void Add(int a, int b, std::promise<int> p)
//{
//	int sum = a + b;
//	p.set_value(sum);
//}
//
//void main()
//{
//	std::promise<int> prom;
//	auto fs = prom.get_future();
//
//	thread t(Add, 2, 3, std::move(prom));
//	cout << fs.get() << endl;
//	t.join();
//
//	system("pause");
//	return;
//}
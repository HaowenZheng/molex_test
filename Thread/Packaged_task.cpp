//#include <iostream>
//using namespace std;
//#include <future>
//
////���ʣ� packaged_task ��;
//
////template<class T>
//int Add(int a, int b)
//{
//	cout << "����: " << a << " " << b << endl;
//	cout<< "thread_id: " << std::this_thread::get_id() << endl; 
//	return a + b;
//}
//
//
//void main()
//{
//	cout << "���̣߳� thread_id: " << std::this_thread::get_id() << endl;
//
//	//std::packaged_task<int(int)> lambda_task([](int a) 
//	//{
//	//	cout << "lambda ����: " << a << " thread_id: " << std::this_thread::get_id() << endl; 
//	//	return 4;
//	//});
//	//std::future<int> lambda_f = lambda_task.get_future();
//
//	////1��ֱ�ӵ���lambda_task //�൱�ں������ã��߳�id��ͬ
//	////lambda_task(4);
//
//	////2��thread ����
//	//std::thread t(std::move(lambda_task),1);
//	//t.join();
//
//	//auto res = lambda_f.valid(); //valid() ��Ч�Լ�飬 ȷ���߳��Ƿ��������С� �����з���true ��������false
//	//cout << lambda_f.get() << endl;
//
//	//res = lambda_f.valid();
//
//	std::packaged_task<int(int,int)> task1(Add);
//
//	//std::shared_future<int> fs(task1.get_future());
//	std::future<int> fs = task1.get_future();
//
//	std::thread t(std::move(task1), 2, 5);
//	t.join();
//
//	cout << fs.get() << endl;
//
//	cout << "���߳� end" << endl;
//	system("pause");
//	return;
//}
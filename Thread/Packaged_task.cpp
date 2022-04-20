//#include <iostream>
//using namespace std;
//#include <future>
//
////疑问： packaged_task 用途
//
////template<class T>
//int Add(int a, int b)
//{
//	cout << "参数: " << a << " " << b << endl;
//	cout<< "thread_id: " << std::this_thread::get_id() << endl; 
//	return a + b;
//}
//
//
//void main()
//{
//	cout << "主线程： thread_id: " << std::this_thread::get_id() << endl;
//
//	//std::packaged_task<int(int)> lambda_task([](int a) 
//	//{
//	//	cout << "lambda 参数: " << a << " thread_id: " << std::this_thread::get_id() << endl; 
//	//	return 4;
//	//});
//	//std::future<int> lambda_f = lambda_task.get_future();
//
//	////1、直接调用lambda_task //相当于函数调用，线程id相同
//	////lambda_task(4);
//
//	////2、thread 调用
//	//std::thread t(std::move(lambda_task),1);
//	//t.join();
//
//	//auto res = lambda_f.valid(); //valid() 有效性检查， 确认线程是否还在运行中。 运行中返回true 结束返回false
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
//	cout << "主线程 end" << endl;
//	system("pause");
//	return;
//}
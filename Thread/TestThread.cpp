//
//#include "TestThread.h"
//
//std::mutex mtx;
//std::condition_variable data_cond;
//
//std::exception_ptr exptr = nullptr;
//
//void main()
//{
//	/*std::thread t1(func); //初始化构造函数
//
////	std::thread t2(std::move(t1));//move构造函数
//	t1.join();
//
//	std::thread threads[4]; 
//
//	for (int i = 0;i < 4;i++)
//	{
//		threads[i] = std::thread(func1,i+1);
//	}
//
//	for (int i = 0;i < 4;i++)
//	{
//		threads[i].join();
//	}*/
//
//	//std::thread* p1(new std::thread(func));
//
//	//p1->join();
//
//	/*auto some_func = []()
//	{
//		std::cout << "some func" << std::endl;
//		auto i = std::this_thread::get_id(); //标识线程
//	};
//
//	auto some_other_func = []()
//	{
//		std::cout << "some other func" << std::endl;
//	};
//
//	std::thread t1(some_func);
//
//	t1.get_id();*/
//
//	//auto t1 = std::async(func);
//	//auto t2 = std::async(std::launch::async, func1, 1);
//
//	std::packaged_task<int(int)> task1(func2);
//	auto res = task1.get_future();
//
//	auto t3 = std::thread(move(task1), 1);
//	t3.join();
//	
//	try
//	{
//		if (exptr != nullptr)
//		{
//			std::cout << "123" << std::endl;
//
//			std::rethrow_exception(exptr);
//		}
//	}
//	catch (const std::exception &ex)
//	{
//		std::cout << ex.what() << std::endl;
//	}
//
//
//	auto ret = res.valid();
//
//	system("pause");
//}
//
//void func()
//{
//	std::cout << "Hello World" << std::endl;
//	std::cout << std::this_thread::get_id() << std::endl;
//}
//
//void func1(int n)
//{
//
//	std::this_thread::sleep_for(std::chrono::seconds(n));
//	std::cout << "pause of " << n << " seconds " << std::endl;
//
//}
//
//int func2(int n)
//{
//	try
//	{
//		throw std::exception("抛出异常");
//	}
//	catch (...)
//	{
//		exptr = std::current_exception();
//	}
//	if (exptr != nullptr)
//		std::rethrow_exception(exptr);
//
//	std::this_thread::sleep_for(std::chrono::seconds(n));
//	std::cout << "pause of " << n << " seconds " << std::endl;
//}
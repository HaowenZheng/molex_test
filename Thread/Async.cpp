//#include <iostream>
//using namespace std;
//#include <thread>
//#include <future>
//
//
//int Print(int a)
//{
//	cout << "线程开始执行: " << " thread_id: " << std::this_thread::get_id() << endl;
//
//	std::this_thread::sleep_for(std::chrono::seconds(3));
//	cout << "传入参数: "<< a << endl;
//
//	cout << "线程结束执行" << endl;
//
//	return 5;
//}
//
//void Except()
//{
//
//	throw "Except";
//}
//
//
//
//
//void main()
//{
//	cout << "主线程 thread_id: " << std::this_thread::get_id() << endl;
//
//	//返回值通过get()函数获取
//	std::future<int> res = std::async(Print, 2); //默认std::launch::async | std::launch::deferred 策略
//	//std::future<int> res = std::async(std::launch::deferred, Print, 2);
//
//	//std::launch::async 线程立即执行   
//	//std::launch::deferred 线程延迟执行  std::async(std::launch::deferred, Print, 2);
//	//使用deferred形式启动线程时，该线程并未真正启动，需要使用wait()或get()函数启动。如果没调用，则不会启动。另外，不是重新开辟新线程，而是在主线程启动，相当于函数调用。
//	//可以通过线程id确认是主线程运行还是创建新线程运行
//	
//	//未调用get 或wait 函数时， 主线程会等待async执行完再退出
//	cout << res.get() << endl; //只能调用一次，多次调用报异常；
//
//	//等待一段时间，获得线程的状态
//	//std::future_status status = res.wait_for(std::chrono::seconds(5));
//	//if (status == std::future_status::ready)
//	//{
//	//	//线程执行完成，处于ready状态
//	//	cout << "线程 完毕 状态" << endl;
//	//}
//	//else if (status == std::future_status::timeout)
//	//{
//	//	//等待一段时间后，线程未执行完毕，判断为超时状态
//	//	cout << "线程 超时 状态" << endl;
//	//}
//	//else if (status == std::future_status::deferred)
//	//{
//	//	//线程延迟执行
//	//	cout << "线程 延迟 状态" << endl;
//	//	cout << res.get() << endl;
//	//}
//
//	if (!res.valid())
//	{
//		//std::shared_future<int> res_s(res.share());
//		std::shared_future<int> res_s(std::move(res)); //移动语义之后，res为空
//		//res_s 可以反复调用get();
//
//		cout << res_s.get() << endl;
//		cout << res_s.get() << endl;
//		cout << res_s.get() << endl;
//	}
//
//
//	////抛出异常
//	//try
//	//{
//	//	auto res = std::async(std::launch::async, Except);
//	//	res.get(); //抛出异常时，会给future捕获，调用get()时，再次抛出异常
//	//}
//	//catch (const std::exception &e)
//	//{
//	//	cout << "Exception from the thread: " << e.what() << endl;
//	//}
//	//catch (const char* tz)
//	//{
//	//	cout << tz << endl;
//	//}
//	//catch (...)
//	//{
//	//	cout << "error" << endl;
//	//}
//
//
//	system("pause");
//	return;
//}

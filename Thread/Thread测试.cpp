//#include <iostream>
//using namespace std;
//#include <thread>
//#include <mutex>
//#include <list>
//
//
//int g_v = 100;
//
////void Print()
////{
////	std::this_thread::sleep_for(std::chrono::seconds(1));
////	cout << "调用Print函数 " <<  "  thread_id:" << std::this_thread::get_id() << endl;
////	return;
////}
////
////class A
////{
////public:
////	void Print_a()
////	{
////		cout << "调用class A的函数 " <<this<<"  thread_id:"<<std::this_thread::get_id()<< endl;
////		return;
////	}
////
////	void operator()(int i)
////	{
////		cout << "输入参数为：" <<i <<  this << "  thread_id:" << std::this_thread::get_id() << endl;
////		return;
////	}
////};
//
////void PrintVal(const int & i)
////{
////	cout << "输入的参数为: " << i << "地址： " << &i  << endl;
////	return;
////}
//
//
////class A
////{
////public:
////	int m_i;
////
////	A(int a) :m_i(a)
////	{
////		cout << " A 初始化构造函数调用 " << this << " " << std::this_thread::get_id() << endl;
////	}
////	A(A&a) :m_i(a.m_i)
////	{
////		cout << " A 拷贝构造函数调用 " << this << " " << std::this_thread::get_id() << endl;
////	}
////	~A()
////	{
////		cout << " A 析构函数调用 " << this <<" "<< std::this_thread::get_id() << endl;
////	}
////
////	void Printa()
////	{
////		cout << m_i << endl;
////	}
////};
////
////void PrintRes(/*const */A& a)
////{
////	a.m_i = 10;
////	cout << a.m_i  << endl;
////}
//
//void Read1()
//{
//	for (int i = 0;i < 100;++i)
//	{
//		cout << std::this_thread::get_id() <<" g_v = " << g_v << endl;
//	}
//}
//
//class TestData
//{
//public:
//	void InsertData()
//	{
//		for (int i = 0;i < 1000;++i)
//		{
//			//std::lock_guard<std::mutex> obj(m_mtx);
//
//			//std::unique_lock<std::mutex> obj2(m_mtx); 完美替代 lock_guard;
//			//std::unique_lock<std::mutex> obj2(m_mtx, std::adopt_lock); // 提前锁好，提示构造函数不需要锁， 会自动释放锁
//			//std::unique_lock<std::mutex> obj2(m_mtx,std::try_to_lock); //尝试锁
//			//if (obj2.owns_lock)
//			//{
//			//	//锁成功继续 插入动作
//			//}
//			//else
//			//{
//			//	//没有获得锁，做其他事情
//			//}
//			//std::unique_lock<std::mutex> obj2(m_mtx,std::defer_lock); // 默认不上锁
//
//			//obj2.lock();
//			////做数据操作动作
//
//			////obj2.unlock();
//			//做其他事情
//
//			//obj2.lock();//继续上锁  后续会自动释放锁
//
//			//std::unique_lock<std::mutex> obj2(m_mtx);
//			//if (obj2.try_lock() == true) // 该成员函数和try_to_lock 一样
//			//{
//			//	//数据处理
//			//}
//			//else
//			//{
//			//	//其他操作
//			//}
//
//			/*std::unique_lock<std::mutex> obj2(m_mtx); // release释放，不再绑定mutex 只能自己lock和unlock
//			auto ptr  = obj2.release();
//			ptr->lock();
//			ptr->unlock();*/
//
//
//			//condition_variable 与 unique_lock 配合使用 
//			std::unique_lock<std::mutex> obj(m_mtx);
//
//
//			//m_mtx.lock();
//			m_data.push_back(i);
//			cout << "插入数据： " << i << endl;
//			//m_mtx.unlock();
//
//			m_cond.notify_one(); //通知其他线程 one 只有一个线程能获取  notify_all()通知所有线程
//
//			//深入考虑：
//			//并不是每次notify的时候，其他线程正在wait等待，所以有时候notify其他线程并没有操作。
//			//没有notify时，其他线程正卡在wait处，如何退出怎么线程
//		}
//	}
//
//	void PopData()
//	{
//		//使用notify_one()通知时，改为while(true)
//		//for (int i = 0;i < 1000;++i)
//		while(true)
//		{
//			//std::lock(lock1, lock2); 多个锁一起锁住   std::lock_guard<std::mutex> obj(m_mtx,std::adopt_lock); //第二个参数，表示已经锁住，不用锁， 配合std::lock 使用， 
//			//std::lock_guard<std::mutex> obj(m_mtx/*,std::adopt_lock*/);
//
//			std::unique_lock<std::mutex> obj(m_mtx);
//
//			//原理： 先lock住锁， wait函数运行时，如果返回true，继续进行；如果返回false，则解锁，在wait等待，直到有notify通知。
//			//当接收到通知时，先获得锁，再进行后续操作。 // 同样的，需要和其他线程竞争获取锁，并不是每次都能获取到锁。
//
//			m_cond.wait(obj, [this]()->bool
//			{
//				if (m_data.empty())
//					return false;
//				else
//					return true;
//			});
//			int num = m_data.front();
//			cout << "获取数据： " << num << endl;
//			m_data.pop_front();
//
//			//判断不为空，则进行操作
//			
//			//m_mtx.lock();
//			//if (m_data.empty())
//			//{
//			//	cout << "尝试获取数据，但是list为空" << endl;
//			//}
//			//else
//			//{
//			//	//list不为空，从头获取数据，并打印
//			//	int num = m_data.front();
//			//	cout <<"获取数据： "<<num << endl;
//			//	m_data.pop_front();
//			//}
//			//m_mtx.unlock();
//		}
//	}
//
//private:
//	std::list<int> m_data;
//	std::mutex m_mtx;
//
//	std::condition_variable m_cond;
//};
//
//void main()
//{
//	////thread 构造
//	////1、默认构造
//	//thread t1;
//	////2、初始化构造函数
//	//thread t2(Print);
//	//if (t2.joinable())
//	//{
//	//	t2.join();
//	//	//t2.detach();
//	//}
//
//	////3、拷贝构造  delete 禁用
//
//	////4、move构造 / 右值引用
//	////thread t4(std::move(t2));
//	////t4.join();
//
//	////用类函数初始化
//	//A testa;
//	//thread tt(&A::Print_a, &testa);
//	//tt.join();
//
//	////类对象
//	//A a;
//	//thread tt1(a, 1);
//	//tt1.join();
//
//	////swap
//	//thread s1(Print);
//	//thread s2(Print);
//	//auto id1 = s1.get_id();
//	//auto id2 = s2.get_id();
//	//cout << "id1: " << id1 << "  id2:" << id2 << endl;
//
//	////swap(s1, s2);
//	//s1.swap(s2);
//	//id1 = s1.get_id();
//	//id2 = s2.get_id();
//	//cout << "id1: " << id1 << "  id2:" << id2 << endl;
//
//	//s1.join();
//	//s2.join();
//
//	//unsigned int  n = thread::hardware_concurrency();
//	//cout << n << endl;
//
//
//	////验证thread 传递参数
//	//int val = 5;
//	//cout << "线程地址： " << this_thread::get_id() << "  变量地址: " << &val << endl;
//
//	////函数中的& 并未起作用
//	///*thread t1(PrintVal, val);
//	//t1.join();*/
//
//	////使用std::ref(), &起作用， 变量地址相同
//	//thread t1(PrintVal, std::ref(val));
//	//t1.join();
//
//	//cout << "主函数： " << std::this_thread::get_id() << endl;
//
//	//int i = 5;
//	//A a(i);
//	////thread t1(PrintRes, i);
//	////thread t1(PrintRes, a);
//	//thread t1(PrintRes, std::ref(a));
//	//t1.join();
//
//	//数据共享验证
//
//	//只读没有任何问题
//	/*thread t1(Read1);
//	thread t2(Read1);
//
//	t1.join();
//	t2.join();*/
//
//	//同时读写功能
//	TestData td;
//	thread t1(&TestData::InsertData, &td);
//	thread t2(&TestData::PopData, &td);
//
//	t1.join();
//	t2.join();
//	cout << "end" << endl;
//	system("pause");
//	return;
//}
//
//#include <iostream>
//using namespace std;
//#include <thread>
//
//void some_func()
//{
//	std::this_thread::sleep_for(std::chrono::seconds(5));
//	cout << "do some function" << endl;
//	return;
//}
//
//void some_other_func()
//{
//	cout << "do some other function" << endl;
//	return;
//}
//
//void main()
//{
//	thread t1(some_func);
//	thread t2(std::move(t1));
//	t2.join();
//	//如果thread 已经绑定一个线程，则不能用move 不能通过赋一个新值给 std::thread 对象的方式来”丢弃”一个线程
//	system("pause");
//	return;
//}
//#include <iostream>
//using namespace std;
//#include <mutex>
//#include <thread>
//
////为了防止多个线程同时getInstance，需要增加锁
//std::mutex m_mtx;
//
////如何析构m_Instance?
//
//class myClass
//{
//public:
//	static myClass* getInstance()
//	{
//
//		//效率低下， 每次调用instance都需要锁住，如果多个线程同时调用，效率低下； 使用双重锁定，提升效率
//
//		if (m_Instance == nullptr)
//		{
//			std::unique_lock<std::mutex> obj(m_mtx);
//			if (m_Instance == nullptr)
//			{
//				m_Instance = new myClass();
//
//				//创建析构m_Instance 
//				static CLR cl;
//			}
//		}
//
//		return m_Instance;
//	}
//
//	class CLR
//	{
//	public:
//		~CLR() //类的析构函数中delete
//		{
//			if (myClass::m_Instance)
//			{
//				delete myClass::m_Instance;
//				myClass::m_Instance = nullptr;
//			}
//		}
//	};
//
//private:
//	myClass() {}
//	static myClass* m_Instance;
//	
//
//};
//
//myClass* myClass::m_Instance = nullptr;
//
//void main()
//{
//	//myClass* ptr = myClass::getInstance();
//
//	auto func = []()
//	{
//		cout << "线程开始" << endl;
//		myClass* ptr = myClass::getInstance();
//		cout << "thread id: " << std::this_thread::get_id() << " ptr = " << ptr << endl;
//		cout << "线程结束" << endl;
//	};
//	thread t1(func);
//	thread t2(func);
//
//	t1.join();
//	t2.join();
//
//	system("pause");
//	return;
//}
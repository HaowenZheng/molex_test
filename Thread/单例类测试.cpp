//#include <iostream>
//using namespace std;
//#include <mutex>
//#include <thread>
//
////Ϊ�˷�ֹ����߳�ͬʱgetInstance����Ҫ������
//std::mutex m_mtx;
//
////�������m_Instance?
//
//class myClass
//{
//public:
//	static myClass* getInstance()
//	{
//
//		//Ч�ʵ��£� ÿ�ε���instance����Ҫ��ס���������߳�ͬʱ���ã�Ч�ʵ��£� ʹ��˫������������Ч��
//
//		if (m_Instance == nullptr)
//		{
//			std::unique_lock<std::mutex> obj(m_mtx);
//			if (m_Instance == nullptr)
//			{
//				m_Instance = new myClass();
//
//				//��������m_Instance 
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
//		~CLR() //�������������delete
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
//		cout << "�߳̿�ʼ" << endl;
//		myClass* ptr = myClass::getInstance();
//		cout << "thread id: " << std::this_thread::get_id() << " ptr = " << ptr << endl;
//		cout << "�߳̽���" << endl;
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
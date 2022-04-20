//#include <iostream>
//using namespace std;
//#include<list>
//#include<mutex>
//#include<thread>
//#include<future>
//
//#include<Windows.h>
//
//#define __WINDOWSJQ_
//
//class TestData
//{
//public:
//	void InsertData()
//	{
//		for (int i = 0;i < 1000;++i)
//		{
//#ifdef  __WINDOWSJQ_
//			EnterCriticalSection(&my_winsec);
//			m_data.push_back(i);
//			cout << "插入数据： " << i << endl;
//			LeaveCriticalSection(&my_winsec);
//
//#else
//			m_mtx.lock();
//			m_data.push_back(i);
//			cout << "插入数据： " << i << endl;
//			m_mtx.unlock();
//#endif
//		}
//	}
//
//	void PopData()
//	{
//		//使用notify_one()通知时，改为while(true)
//		for (int i = 0;i < 1000;++i)	
//		{
//#ifdef  __WINDOWSJQ_
//			EnterCriticalSection(&my_winsec);
//			if (m_data.empty())
//			{
//				cout << "尝试获取数据，但是list为空" << endl;
//			}
//			else
//			{
//				//list不为空，从头获取数据，并打印
//				int num = m_data.front();
//				cout << "获取数据： " << num << endl;
//				m_data.pop_front();
//			}
//			LeaveCriticalSection(&my_winsec);
//#else
//			m_mtx.lock();
//			if (m_data.empty())
//			{
//				cout << "尝试获取数据，但是list为空" << endl;
//			}
//			else
//			{
//				//list不为空，从头获取数据，并打印
//				int num = m_data.front();
//				cout <<"获取数据： "<<num << endl;
//				m_data.pop_front();
//			}
//			m_mtx.unlock();
//#endif
//		}
//	}
//
//	TestData()
//	{
//#ifdef  __WINDOWSJQ_
//		InitializeCriticalSection(&my_winsec); // 初始化临界区
//#endif //  __WINDOWSJQ_
//
//	}
//
//private:
//	std::list<int> m_data;
//	std::mutex m_mtx;
//
//	std::condition_variable m_cond;
//#ifdef __WINDOWSJQ_
//	CRITICAL_SECTION my_winsec;
//#endif // __WINDOWSJQ_
//
//};
//
//void main()
//{
//	TestData obj;
//
//	std::thread t1(&TestData::InsertData, &obj);
//	std::thread t2(&TestData::PopData, &obj);
//	t1.join();
//	t2.join();
//	system("pause");
//	return;
//}
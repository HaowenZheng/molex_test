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
//			cout << "�������ݣ� " << i << endl;
//			LeaveCriticalSection(&my_winsec);
//
//#else
//			m_mtx.lock();
//			m_data.push_back(i);
//			cout << "�������ݣ� " << i << endl;
//			m_mtx.unlock();
//#endif
//		}
//	}
//
//	void PopData()
//	{
//		//ʹ��notify_one()֪ͨʱ����Ϊwhile(true)
//		for (int i = 0;i < 1000;++i)	
//		{
//#ifdef  __WINDOWSJQ_
//			EnterCriticalSection(&my_winsec);
//			if (m_data.empty())
//			{
//				cout << "���Ի�ȡ���ݣ�����listΪ��" << endl;
//			}
//			else
//			{
//				//list��Ϊ�գ���ͷ��ȡ���ݣ�����ӡ
//				int num = m_data.front();
//				cout << "��ȡ���ݣ� " << num << endl;
//				m_data.pop_front();
//			}
//			LeaveCriticalSection(&my_winsec);
//#else
//			m_mtx.lock();
//			if (m_data.empty())
//			{
//				cout << "���Ի�ȡ���ݣ�����listΪ��" << endl;
//			}
//			else
//			{
//				//list��Ϊ�գ���ͷ��ȡ���ݣ�����ӡ
//				int num = m_data.front();
//				cout <<"��ȡ���ݣ� "<<num << endl;
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
//		InitializeCriticalSection(&my_winsec); // ��ʼ���ٽ���
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
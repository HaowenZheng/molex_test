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
////	cout << "����Print���� " <<  "  thread_id:" << std::this_thread::get_id() << endl;
////	return;
////}
////
////class A
////{
////public:
////	void Print_a()
////	{
////		cout << "����class A�ĺ��� " <<this<<"  thread_id:"<<std::this_thread::get_id()<< endl;
////		return;
////	}
////
////	void operator()(int i)
////	{
////		cout << "�������Ϊ��" <<i <<  this << "  thread_id:" << std::this_thread::get_id() << endl;
////		return;
////	}
////};
//
////void PrintVal(const int & i)
////{
////	cout << "����Ĳ���Ϊ: " << i << "��ַ�� " << &i  << endl;
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
////		cout << " A ��ʼ�����캯������ " << this << " " << std::this_thread::get_id() << endl;
////	}
////	A(A&a) :m_i(a.m_i)
////	{
////		cout << " A �������캯������ " << this << " " << std::this_thread::get_id() << endl;
////	}
////	~A()
////	{
////		cout << " A ������������ " << this <<" "<< std::this_thread::get_id() << endl;
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
//			//std::unique_lock<std::mutex> obj2(m_mtx); ������� lock_guard;
//			//std::unique_lock<std::mutex> obj2(m_mtx, std::adopt_lock); // ��ǰ���ã���ʾ���캯������Ҫ���� ���Զ��ͷ���
//			//std::unique_lock<std::mutex> obj2(m_mtx,std::try_to_lock); //������
//			//if (obj2.owns_lock)
//			//{
//			//	//���ɹ����� ���붯��
//			//}
//			//else
//			//{
//			//	//û�л����������������
//			//}
//			//std::unique_lock<std::mutex> obj2(m_mtx,std::defer_lock); // Ĭ�ϲ�����
//
//			//obj2.lock();
//			////�����ݲ�������
//
//			////obj2.unlock();
//			//����������
//
//			//obj2.lock();//��������  �������Զ��ͷ���
//
//			//std::unique_lock<std::mutex> obj2(m_mtx);
//			//if (obj2.try_lock() == true) // �ó�Ա������try_to_lock һ��
//			//{
//			//	//���ݴ���
//			//}
//			//else
//			//{
//			//	//��������
//			//}
//
//			/*std::unique_lock<std::mutex> obj2(m_mtx); // release�ͷţ����ٰ�mutex ֻ���Լ�lock��unlock
//			auto ptr  = obj2.release();
//			ptr->lock();
//			ptr->unlock();*/
//
//
//			//condition_variable �� unique_lock ���ʹ�� 
//			std::unique_lock<std::mutex> obj(m_mtx);
//
//
//			//m_mtx.lock();
//			m_data.push_back(i);
//			cout << "�������ݣ� " << i << endl;
//			//m_mtx.unlock();
//
//			m_cond.notify_one(); //֪ͨ�����߳� one ֻ��һ���߳��ܻ�ȡ  notify_all()֪ͨ�����߳�
//
//			//���뿼�ǣ�
//			//������ÿ��notify��ʱ�������߳�����wait�ȴ���������ʱ��notify�����̲߳�û�в�����
//			//û��notifyʱ�������߳�������wait��������˳���ô�߳�
//		}
//	}
//
//	void PopData()
//	{
//		//ʹ��notify_one()֪ͨʱ����Ϊwhile(true)
//		//for (int i = 0;i < 1000;++i)
//		while(true)
//		{
//			//std::lock(lock1, lock2); �����һ����ס   std::lock_guard<std::mutex> obj(m_mtx,std::adopt_lock); //�ڶ�����������ʾ�Ѿ���ס���������� ���std::lock ʹ�ã� 
//			//std::lock_guard<std::mutex> obj(m_mtx/*,std::adopt_lock*/);
//
//			std::unique_lock<std::mutex> obj(m_mtx);
//
//			//ԭ�� ��lockס���� wait��������ʱ���������true���������У��������false�����������wait�ȴ���ֱ����notify֪ͨ��
//			//�����յ�֪ͨʱ���Ȼ�������ٽ��к��������� // ͬ���ģ���Ҫ�������߳̾�����ȡ����������ÿ�ζ��ܻ�ȡ������
//
//			m_cond.wait(obj, [this]()->bool
//			{
//				if (m_data.empty())
//					return false;
//				else
//					return true;
//			});
//			int num = m_data.front();
//			cout << "��ȡ���ݣ� " << num << endl;
//			m_data.pop_front();
//
//			//�жϲ�Ϊ�գ�����в���
//			
//			//m_mtx.lock();
//			//if (m_data.empty())
//			//{
//			//	cout << "���Ի�ȡ���ݣ�����listΪ��" << endl;
//			//}
//			//else
//			//{
//			//	//list��Ϊ�գ���ͷ��ȡ���ݣ�����ӡ
//			//	int num = m_data.front();
//			//	cout <<"��ȡ���ݣ� "<<num << endl;
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
//	////thread ����
//	////1��Ĭ�Ϲ���
//	//thread t1;
//	////2����ʼ�����캯��
//	//thread t2(Print);
//	//if (t2.joinable())
//	//{
//	//	t2.join();
//	//	//t2.detach();
//	//}
//
//	////3����������  delete ����
//
//	////4��move���� / ��ֵ����
//	////thread t4(std::move(t2));
//	////t4.join();
//
//	////���ຯ����ʼ��
//	//A testa;
//	//thread tt(&A::Print_a, &testa);
//	//tt.join();
//
//	////�����
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
//	////��֤thread ���ݲ���
//	//int val = 5;
//	//cout << "�̵߳�ַ�� " << this_thread::get_id() << "  ������ַ: " << &val << endl;
//
//	////�����е�& ��δ������
//	///*thread t1(PrintVal, val);
//	//t1.join();*/
//
//	////ʹ��std::ref(), &�����ã� ������ַ��ͬ
//	//thread t1(PrintVal, std::ref(val));
//	//t1.join();
//
//	//cout << "�������� " << std::this_thread::get_id() << endl;
//
//	//int i = 5;
//	//A a(i);
//	////thread t1(PrintRes, i);
//	////thread t1(PrintRes, a);
//	//thread t1(PrintRes, std::ref(a));
//	//t1.join();
//
//	//���ݹ�����֤
//
//	//ֻ��û���κ�����
//	/*thread t1(Read1);
//	thread t2(Read1);
//
//	t1.join();
//	t2.join();*/
//
//	//ͬʱ��д����
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
//	//���thread �Ѿ���һ���̣߳�������move ����ͨ����һ����ֵ�� std::thread ����ķ�ʽ����������һ���߳�
//	system("pause");
//	return;
//}
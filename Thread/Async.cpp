//#include <iostream>
//using namespace std;
//#include <thread>
//#include <future>
//
//
//int Print(int a)
//{
//	cout << "�߳̿�ʼִ��: " << " thread_id: " << std::this_thread::get_id() << endl;
//
//	std::this_thread::sleep_for(std::chrono::seconds(3));
//	cout << "�������: "<< a << endl;
//
//	cout << "�߳̽���ִ��" << endl;
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
//	cout << "���߳� thread_id: " << std::this_thread::get_id() << endl;
//
//	//����ֵͨ��get()������ȡ
//	std::future<int> res = std::async(Print, 2); //Ĭ��std::launch::async | std::launch::deferred ����
//	//std::future<int> res = std::async(std::launch::deferred, Print, 2);
//
//	//std::launch::async �߳�����ִ��   
//	//std::launch::deferred �߳��ӳ�ִ��  std::async(std::launch::deferred, Print, 2);
//	//ʹ��deferred��ʽ�����߳�ʱ�����̲߳�δ������������Ҫʹ��wait()��get()�������������û���ã��򲻻����������⣬�������¿������̣߳����������߳��������൱�ں������á�
//	//����ͨ���߳�idȷ�������߳����л��Ǵ������߳�����
//	
//	//δ����get ��wait ����ʱ�� ���̻߳�ȴ�asyncִ�������˳�
//	cout << res.get() << endl; //ֻ�ܵ���һ�Σ���ε��ñ��쳣��
//
//	//�ȴ�һ��ʱ�䣬����̵߳�״̬
//	//std::future_status status = res.wait_for(std::chrono::seconds(5));
//	//if (status == std::future_status::ready)
//	//{
//	//	//�߳�ִ����ɣ�����ready״̬
//	//	cout << "�߳� ��� ״̬" << endl;
//	//}
//	//else if (status == std::future_status::timeout)
//	//{
//	//	//�ȴ�һ��ʱ����߳�δִ����ϣ��ж�Ϊ��ʱ״̬
//	//	cout << "�߳� ��ʱ ״̬" << endl;
//	//}
//	//else if (status == std::future_status::deferred)
//	//{
//	//	//�߳��ӳ�ִ��
//	//	cout << "�߳� �ӳ� ״̬" << endl;
//	//	cout << res.get() << endl;
//	//}
//
//	if (!res.valid())
//	{
//		//std::shared_future<int> res_s(res.share());
//		std::shared_future<int> res_s(std::move(res)); //�ƶ�����֮��resΪ��
//		//res_s ���Է�������get();
//
//		cout << res_s.get() << endl;
//		cout << res_s.get() << endl;
//		cout << res_s.get() << endl;
//	}
//
//
//	////�׳��쳣
//	//try
//	//{
//	//	auto res = std::async(std::launch::async, Except);
//	//	res.get(); //�׳��쳣ʱ�����future���񣬵���get()ʱ���ٴ��׳��쳣
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

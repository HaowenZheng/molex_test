//#include <iostream>
//#include <thread>
//
//void func(int i)
//{
//	if (i <= 0)
//	{
//		std::cout << "input i error" << std::endl;
//	}
//	else
//	{
//		while (i > 0)
//		{
//			std::cout << i << std::endl;
//			--i;
//		}
//	}
//}
//
//class Base 
//{
//public:
//	void operator()(int i)
//	{
//		if (i <= 0)
//		{
//			std::cout << "input i error" << std::endl;
//		}
//		else
//		{
//			while (i > 0)
//			{
//				std::cout << i << std::endl;
//				--i;
//			}
//		}
//	}
//
//public:
//	void func(int i)
//	{
//		if (i <= 0)
//		{
//			std::cout << "input i error" << std::endl;
//		}
//		else
//		{
//			while (i > 0)
//			{
//				std::cout << i << std::endl;
//				--i;
//			}
//		}
//	}
//
//	static void func2(int i)
//	{
//		if (i <= 0)
//		{
//			std::cout << "input i error" << std::endl;
//		}
//		else
//		{
//			while (i > 0)
//			{
//				std::cout << i << std::endl;
//				--i;
//			}
//		}
//	}
//};
//
//void main()
//{
//	//��ʽ1 ����ָ��
//	//std::thread th1(func,10);
//	//th1.join();
//
//	//��ʽ2 lambda���ʽ
//	/*std::thread th2([](int i) {
//		if (i <= 0)
//		{
//			std::cout << "input i error" << std::endl;
//		}
//		else
//		{
//			while (i > 0)
//			{
//				std::cout << i << std::endl;
//				--i;
//			}
//		}
//	}, 10);
//	th2.join();*/
//
//	//��ʽ3 ���()���з�
//	//std::thread th3(Base(), 10);
//	//th3.join();
//
//	//��ʽ4 ��ķǾ�̬����
//	//Base b;
//	////std::thread th4(&Base::func, &b, 10);
//	//std::thread th4(&Base::func, Base(), 10);
//	//th4.join();
//
//	//��ʽ5 ��ľ�̬����
//	std::thread th5(&Base::func2, 10);
//	th5.join();
//
//	system("pause");
//}
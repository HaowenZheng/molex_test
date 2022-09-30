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
//	//方式1 函数指针
//	//std::thread th1(func,10);
//	//th1.join();
//
//	//方式2 lambda表达式
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
//	//方式3 类的()运行符
//	//std::thread th3(Base(), 10);
//	//th3.join();
//
//	//方式4 类的非静态函数
//	//Base b;
//	////std::thread th4(&Base::func, &b, 10);
//	//std::thread th4(&Base::func, Base(), 10);
//	//th4.join();
//
//	//方式5 类的静态函数
//	std::thread th5(&Base::func2, 10);
//	th5.join();
//
//	system("pause");
//}
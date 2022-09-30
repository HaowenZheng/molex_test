////相关文章接口: https://blog.csdn.net/piggyxp/article/details/6922277
//
//#include<iostream>
//using namespace std;
//
//#include<WinSock2.h>
//#include<WS2tcpip.h>
//#include<MSWSock.h> //获取windows的AcceptEX函数指针需要
//#pragma comment(lib,"ws2_32.lib")
//
//#include <thread>
//
//typedef struct
//{
//	SOCKET SockHandle;
//	sockaddr_in Addr;
//}PER_HANDLE_STRUCT; //HANDLE结构题
//
//typedef struct
//{
//	OVERLAPPED ol;
//
//}PER_IO_STRUCT; //IO结构体
//
//void RecvLoop()
//{
//
//}
//
//void main()
//{
//
//	//第一步 创建一个完成端口
//	HANDLE m_hIOCompletionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0); //第四个参数0 表示cpu的个数，尽可能多的线程并发
//	if (m_hIOCompletionPort == INVALID_HANDLE_VALUE)
//	{
//		cout << "创建完成端口失败" << endl;
//		return;
//	}
//
//	//第二步 创建工作线程  
//	//根据系统有多少核，创建多少线程
//	{
//		SYSTEM_INFO si;
//		GetSystemInfo(&si);
//		int m_nProcessors = si.dwNumberOfProcessors;
//		cout << "系统内核数量: " << m_nProcessors << endl;
//
//		int m_nThreads = m_nProcessors * 2;
//		//std::shared_ptr<std::thread> RecvLoopThreads[m_nThreads];
//		std::shared_ptr<std::thread> RecvLoopThreads[4];
//		for (int i = 0;i < 4;++i)
//		{
//			RecvLoopThreads[i] = std::make_shared<std::thread>(RecvLoop);
//		}
//	}
//
//	//第三步 创建一个用于监听的socket
//	//用于缩放
//	{
//		WSADATA wsaData = { 0 };
//		auto ret = WSAStartup(MAKEWORD(2, 2), &wsaData);
//		if (ret != 0)
//		{
//			cout << "wsastartup error :" << WSAGetLastError() << endl;
//			return;
//		}
//		SOCKET listensock = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED); //协议为什么是0，不是写IPPROTO_TCP？
//		if (listensock == INVALID_SOCKET)
//		{
//			cout << "create socket error: " << WSAGetLastError() << endl;
//			WSACleanup();
//			return;
//		}
//		sockaddr_in addr;
//		memset(&addr, 0, sizeof(sockaddr_in));
//		addr.sin_family = AF_INET;
//		addr.sin_port = htons(27015);
//		addr.sin_addr.s_addr = htonl(INADDR_ANY);
//
//		ret = ::bind(listensock, (sockaddr*)&addr, sizeof(sockaddr));
//		/*解决办法：
//		1、不适用"using namespace std;", 因为模板函数bind就是定义在std这个作用域中。
//		实际应用时，应尽量少使用using namespace std, 而是使用std::来代替，否则会出现很多意向不到的结果。
//		2、在bind()函数前增加域操作符::，即::bind()，这样就能调用到socket 中的bind()函数了*/
//
//		if (ret != 0)
//		{
//			cout << "bind error: " << WSAGetLastError() << endl;
//			closesocket(listensock);
//			WSACleanup();
//			return;
//		}
//
//		ret = listen(listensock, 5 /*SOMAXCONN*/);
//		if (ret != 0)
//		{
//			cout << "listen error: " << WSAGetLastError() << endl;
//			closesocket(listensock);
//			WSACleanup();
//			return;
//		}
//	}
//
//	////第四步 创建Accep请求
//	//{
//	//	//可以创建一个新线程去accept 或者使用acceptex
//
//	//	//使用AcceptEX 是windows提供的扩展函数，
//	//	//我们应该用WSAIoctl 配合SIO_GET_EXTENSION_FUNCTION_POINTER参数来获取函数的指针，然后再调用AcceptEx
//
//	//	LPFN_ACCEPTEX m_lpfnAccepEx;
//	//	GUID GuideAcceptEx = WSAID_ACCEPTEX;
//	//	DWORD dwBytes = 0;
//	//	//WSAIoctl(listensock,)
//	//}
//
//	WSACleanup();
//	system("pause");
//	return;
//}
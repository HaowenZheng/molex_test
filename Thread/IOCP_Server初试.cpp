////������½ӿ�: https://blog.csdn.net/piggyxp/article/details/6922277
//
//#include<iostream>
//using namespace std;
//
//#include<WinSock2.h>
//#include<WS2tcpip.h>
//#include<MSWSock.h> //��ȡwindows��AcceptEX����ָ����Ҫ
//#pragma comment(lib,"ws2_32.lib")
//
//#include <thread>
//
//typedef struct
//{
//	SOCKET SockHandle;
//	sockaddr_in Addr;
//}PER_HANDLE_STRUCT; //HANDLE�ṹ��
//
//typedef struct
//{
//	OVERLAPPED ol;
//
//}PER_IO_STRUCT; //IO�ṹ��
//
//void RecvLoop()
//{
//
//}
//
//void main()
//{
//
//	//��һ�� ����һ����ɶ˿�
//	HANDLE m_hIOCompletionPort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0); //���ĸ�����0 ��ʾcpu�ĸ����������ܶ���̲߳���
//	if (m_hIOCompletionPort == INVALID_HANDLE_VALUE)
//	{
//		cout << "������ɶ˿�ʧ��" << endl;
//		return;
//	}
//
//	//�ڶ��� ���������߳�  
//	//����ϵͳ�ж��ٺˣ����������߳�
//	{
//		SYSTEM_INFO si;
//		GetSystemInfo(&si);
//		int m_nProcessors = si.dwNumberOfProcessors;
//		cout << "ϵͳ�ں�����: " << m_nProcessors << endl;
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
//	//������ ����һ�����ڼ�����socket
//	//��������
//	{
//		WSADATA wsaData = { 0 };
//		auto ret = WSAStartup(MAKEWORD(2, 2), &wsaData);
//		if (ret != 0)
//		{
//			cout << "wsastartup error :" << WSAGetLastError() << endl;
//			return;
//		}
//		SOCKET listensock = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED); //Э��Ϊʲô��0������дIPPROTO_TCP��
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
//		/*����취��
//		1��������"using namespace std;", ��Ϊģ�庯��bind���Ƕ�����std����������С�
//		ʵ��Ӧ��ʱ��Ӧ������ʹ��using namespace std, ����ʹ��std::�����棬�������ֺܶ����򲻵��Ľ����
//		2����bind()����ǰ�����������::����::bind()���������ܵ��õ�socket �е�bind()������*/
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
//	////���Ĳ� ����Accep����
//	//{
//	//	//���Դ���һ�����߳�ȥaccept ����ʹ��acceptex
//
//	//	//ʹ��AcceptEX ��windows�ṩ����չ������
//	//	//����Ӧ����WSAIoctl ���SIO_GET_EXTENSION_FUNCTION_POINTER��������ȡ������ָ�룬Ȼ���ٵ���AcceptEx
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
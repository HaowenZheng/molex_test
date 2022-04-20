//#include <iostream>
//using namespace std;
//#include <WinSock2.h>
//#pragma comment(lib,"ws2_32.lib")
//
//
//void main()
//{
//	WSAData wsaData;
//	int wsaRet = WSAStartup(MAKEWORD(2, 2), &wsaData);
//
//	if (wsaRet == SOCKET_ERROR)
//	{
//		char tempMsg[256] = { 0 };
//		sprintf_s(tempMsg, "WSAStartup错误，错误码:%d", GetLastError());
//		cout << tempMsg << endl;
//		return;
//	}
//
//	//1、创建socket
//	SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); //IPV4 数据流模式 tcp协议（写0也是tcp模式）
//
//	//2、设置复杂的结构体  //设置ip地址，设置端口号，设置ipv4协议
//	sockaddr_in sockAddr;
//	memset(&sockAddr, 0, sizeof(sockAddr));
//
//	sockAddr.sin_family = AF_INET;
//	sockAddr.sin_port = htons(1234);
//	//sockAddr.sin_addr.s_addr = inet_addr("10.220.48.126");
//	sockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
//
//	//3、绑定
//	int bindRet = bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
//	if (bindRet == SOCKET_ERROR)
//	{
//		char tempMsg[256] = { 0 };
//		sprintf_s(tempMsg, "bind错误，错误码:%d", GetLastError());
//		cout << tempMsg << endl;
//		return;
//	}
//
//	//4、监听
//	int listenRet = listen(servSock, 20);
//	if (listenRet == SOCKET_ERROR)
//	{
//		char tempMsg[256] = { 0 };
//		sprintf_s(tempMsg, "listen错误，错误码:%d", GetLastError());
//		cout << tempMsg << endl;
//		return;
//	}
//	
//	//5、接收客户端请求
//	sockaddr_in clientAddr;
//	int nlen = sizeof(clientAddr);
//	SOCKET client = accept(servSock, (sockaddr*)&clientAddr, &nlen); //线程卡住，等待listen队列中不为空，取出一个对象
//
//	//测试输出
//	cout << "客户端ip: "<< inet_ntoa(clientAddr.sin_addr) << endl;
//
//	//6、发送 接收
//	char* str = "hello world";
//	send(client, str, strlen(str) + 1, 0);
//	char buf[1024] = { 0 };
//	recv(client, buf, sizeof(buf), 0);
//	cout << buf << endl;
//
//	closesocket(client);
//
//	closesocket(servSock);
//
//	WSACleanup();
//
//	system("pause");
//}
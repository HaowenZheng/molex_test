//#include<iostream>
//using namespace std;
//#include<WinSock2.h>
//#pragma comment(lib,"ws2_32.lib")
//
//
//void main()
//{
//	WSAData wsaData;
//	int wsaRet = WSAStartup(MAKEWORD(2, 2), &wsaData);
//	if (wsaRet == SOCKET_ERROR)
//	{
//		cout << "WSAStartup异常，异常代码：" << GetLastError() << endl;
//		return;
//	}
//
//	SOCKET clientSock = socket(AF_INET, SOCK_STREAM, 0);
//	
//	sockaddr_in clientAddr;
//	memset(&clientAddr, 0, sizeof(sockaddr_in));
//
//	clientAddr.sin_family = AF_INET;
//	clientAddr.sin_port = htons(8888);
//	clientAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
//
//	int connRet = connect(clientSock, (SOCKADDR*)&clientAddr, sizeof(SOCKADDR));
//	if (connRet == SOCKET_ERROR)
//	{
//		cout << "connect异常，异常代码：" << GetLastError() << endl;
//		return;
//	}
//	char* msg = "client test";
//	send(clientSock, msg, strlen(msg) + 1, 0);
//	char buf[1024] = { 0 };
//	recv(clientSock, buf, sizeof(buf), 0);
//	cout << buf << endl;
//
//	closesocket(clientSock);
//
//	WSACleanup();
//
//	system("pause");
//}
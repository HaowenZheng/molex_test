//#include <iostream>
//using namespace std;
//
//#include<WinSock2.h>
//#pragma comment(lib,"ws2_32.lib")
//#include <ws2tcpip.h>
//
//
////失败，未了解清楚异常在哪里？
//
//
//#define MAX_FD 1024
//
//void main()
//{
//	WSADATA wsaData = { 0 };
//	auto ret = WSAStartup(MAKEWORD(2, 2), &wsaData);
//	if (ret != 0)
//	{
//		cout << "WSAStartup error" << endl;
//		WSACleanup();
//		return;
//	}
//
//	SOCKET listen_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//	if (listen_sock == INVALID_SOCKET)
//	{
//		cout << "创建socket error" << endl;
//		WSACleanup();
//		return;
//	}
//
//	sockaddr_in sock_addr;
//	memset(&sock_addr, 0, sizeof(sockaddr_in));
//
//	sock_addr.sin_family = AF_INET;
//	sock_addr.sin_port = htons(9090);
//	//sock_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
//	//sock_addr.sin_addr.s_addr = inet_addr(INADDR_ANY);
//	hostent* thisHost =  gethostbyname("");
//	char* ip = inet_ntoa(*(in_addr*)*thisHost->h_addr_list);
//
//	//sock_addr.sin_addr.s_addr = inet_addr(ip);
//	inet_pton(AF_INET, ip, &sock_addr.sin_addr.s_addr); //此函数在ws2tcpip.h头文件中
//
//	ret = bind(listen_sock, (sockaddr*)&sock_addr, sizeof(sockaddr));
//	if (ret != 0)
//	{
//		cout << "bind error" << endl;
//		closesocket(listen_sock);
//		WSACleanup();
//		return;
//	}
//
//	ret = listen(listen_sock, 5);
//	if (ret != 0)
//	{
//		cout << "listen error" << endl;
//		closesocket(listen_sock);
//		WSACleanup();
//		return;
//	}
//
//	//开始poll
//	pollfd clientfds[MAX_FD];
//
//	clientfds[0].fd = listen_sock;
//	clientfds[0].events = POLLIN;
//
//	for (int i = 1;i < MAX_FD;++i)
//	{
//		clientfds[i].fd = -1;
//	}
//
//	int maxnum = listen_sock;
//
//	while (1)
//	{
//		int nready = WSAPoll(reinterpret_cast<WSAPOLLFD*>(clientfds), MAX_FD, -1);
//
//		if (nready == -1)
//		{
//			cout << "poll error" << endl;
//			break;
//		}
//		//处理新链接
//		if (clientfds[0].events & POLLIN)
//		{
//			sockaddr_in client_addr;
//			memset(&client_addr, 0, sizeof(sockaddr_in));
//			int lens = sizeof(sockaddr_in);
//			SOCKET client_sock = accept(listen_sock, (sockaddr*)&client_addr, &lens);
//
//			if (client_sock == INVALID_SOCKET)
//			{
//				cout << "accept error" << endl;
//				break;
//			}
//
//			printf("new client ip: %s, port: %d \r\n", inet_ntoa(client_addr.sin_addr), client_addr.sin_port);
//
//			//找到空位，添加
//			int i = 1;
//			for (i = 1;i < MAX_FD;++i)
//			{
//				if (clientfds[i].fd <= 0)
//				{
//					clientfds[i].fd = client_sock;
//					break;
//				}
//			}
//
//			if (i == MAX_FD)
//			{
//				cout << "over max client" << endl;
//				break;
//			}
//
//			clientfds[i].events = POLLIN;
//			
//			//更新最大fd
//			maxnum = i > maxnum ? i : maxnum;
//
//			continue;
//		}
//		else //处理消息
//		{
//			char buf[1024] = { 0 };
//
//			for (int i = 1;i <= maxnum;++i)
//			{
//				if (clientfds[i].fd < 0)
//					continue;
//
//				if (clientfds[i].events & POLLIN)
//				{
//					int nread = recv(clientfds[i].fd, buf, 1024, 0);
//
//					if (nread <= 0)
//					{
//						//关闭socket
//						closesocket(clientfds[i].fd);
//						clientfds[i].fd = 0;
//						continue;
//					}
//
//					int nsend = send(clientfds[i].fd, buf, strlen(buf) + 1, 0);
//				}
//			}
//		}
//	}
//
//	closesocket(listen_sock);
//	WSACleanup();
//
//	system("pause");
//
//	return;
//}
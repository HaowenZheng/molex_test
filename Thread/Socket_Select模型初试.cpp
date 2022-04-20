//#include <iostream>
//using namespace std;
//
//#include<WinSock2.h>
//#pragma comment(lib,"ws2_32.lib")
//
//
//void main()
//{
//	WSADATA wsaData = { 0 };
//	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
//	{
//		cout << "WSAStartup error" << endl;
//		return;
//	}
//
//	SOCKET sock_listen = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//
//	if (sock_listen == INVALID_SOCKET)
//	{
//		cout << "创建socket异常" << endl;
//		WSACleanup();
//		return;
//	}
//
//	sockaddr_in sock_addr = { 0 };
//
//	sock_addr.sin_family = AF_INET;
//	sock_addr.sin_port = htons(8888);
//	//sock_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
//	sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);
//	/*hostent * thisHost;
//	char* ip;
//	thisHost = gethostbyname("");
//	if (thisHost == nullptr)
//	{
//		cout << "gethostbyname failed " << endl;
//		closesocket(sock_listen);
//		WSACleanup();
//		return;
//	}
//
//	ip = inet_ntoa(*(in_addr*)*thisHost->h_addr_list);
//	sock_addr.sin_addr.s_addr = inet_addr(ip);*/
//
//
//	if (bind(sock_listen, (SOCKADDR*)&sock_addr, sizeof(SOCKADDR)) == SOCKET_ERROR)
//	{
//		cout << "bind error" << endl;
//		closesocket(sock_listen);
//		WSACleanup();
//		return;
//	}
//
//	if (listen(sock_listen, 5) == SOCKET_ERROR)
//	{
//		cout << "bind error" << endl;
//		closesocket(sock_listen);
//		WSACleanup();
//		return;
//	}
//
//	//开始select
//	fd_set allsocket;
//	FD_ZERO(&allsocket);
//
//	//添加到bitmap中
//	FD_SET(sock_listen, &allsocket);
//	
//	int maxfd = sock_listen; //最大的sock号
//
//	while (1)
//	{
//		//定义临时 fd ，因为select会修改 fd内容
//		fd_set readfd = allsocket;
//		//auto ret = select(maxfd + 1, &readfd, nullptr, nullptr, nullptr);
//		auto ret = select(0, &readfd, nullptr, nullptr, nullptr); //第一个参数随意，主要为了兼容， linux上需要填写maxfd+1
//
//		if (ret < 0)
//		{
//			cout << "select error" << endl;
//			break;
//		}
//		else if (ret == 0)
//		{
//			cout << "time out" << endl;
//			continue;
//		}
//		else
//		{
//			//判断fd是否已经在bitmap中
//			if (FD_ISSET(sock_listen, &readfd) > 0)
//			{
//				//accept
//				sockaddr_in client_addr = { 0 };
//				int lens = sizeof(sockaddr_in);
//				SOCKET new_client = accept(sock_listen, (SOCKADDR*)&client_addr, &lens);
//				if (new_client < 0)
//				{
//					cout << "accept error" << endl;
//					exit(1);
//				}
//
//				//添加
//				FD_SET(new_client, &allsocket);
//
//				cout << "建立新链接, IP: " << inet_ntoa(client_addr.sin_addr) << endl;
//				//更新最大的sock号
//				maxfd = new_client > maxfd ? new_client : maxfd;
//
//			}
//			else
//			{
//				//处理消息
//				for (int i = 0;i <= maxfd;i++)
//				{
//					if (FD_ISSET(i, &readfd))
//					{
//						char temp[1024] = { 0 };
//						auto res = recv(i, temp, sizeof(temp) /*5*/, 0); //当发送字符超过第三个参数，会马上下一次触发（水平触发 ）
//														   // epoll 有边缘触发，如果第一次没有接收完，不会马上触发，直到下一次信号才会触发，数据并不会丢失
//
//						// 返回接收到的字符个数
//						//0 closesocket
//						//SOCKET_ERROR 异常 
//						//WSAGetLastError() 捕获
//
//						if (res <= 0)
//						{
//							//关闭socket						
//							closesocket(i);
//							FD_CLR(i, &allsocket);
//							cout<< " 断开链接 " << endl;
//							//更新maxfd
//							if (i == maxfd)
//							{
//								while (FD_ISSET(maxfd, &allsocket) == false)
//									--maxfd;
//								cout << "update maxfd :" << maxfd << endl;
//							}
//						}
//						else 
//						{
//							cout << "发送: "<< temp << endl;
//							send(i, temp, strlen(temp) + 1, 0);
//						}
//					}
//				}
//
//			}
//
//		}
//
//	}
//
//	closesocket(sock_listen);
//	WSACleanup();
//	return;
//}
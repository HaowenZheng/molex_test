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
//		cout << "����socket�쳣" << endl;
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
//	//��ʼselect
//	fd_set allsocket;
//	FD_ZERO(&allsocket);
//
//	//��ӵ�bitmap��
//	FD_SET(sock_listen, &allsocket);
//	
//	int maxfd = sock_listen; //����sock��
//
//	while (1)
//	{
//		//������ʱ fd ����Ϊselect���޸� fd����
//		fd_set readfd = allsocket;
//		//auto ret = select(maxfd + 1, &readfd, nullptr, nullptr, nullptr);
//		auto ret = select(0, &readfd, nullptr, nullptr, nullptr); //��һ���������⣬��ҪΪ�˼��ݣ� linux����Ҫ��дmaxfd+1
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
//			//�ж�fd�Ƿ��Ѿ���bitmap��
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
//				//���
//				FD_SET(new_client, &allsocket);
//
//				cout << "����������, IP: " << inet_ntoa(client_addr.sin_addr) << endl;
//				//��������sock��
//				maxfd = new_client > maxfd ? new_client : maxfd;
//
//			}
//			else
//			{
//				//������Ϣ
//				for (int i = 0;i <= maxfd;i++)
//				{
//					if (FD_ISSET(i, &readfd))
//					{
//						char temp[1024] = { 0 };
//						auto res = recv(i, temp, sizeof(temp) /*5*/, 0); //�������ַ�������������������������һ�δ�����ˮƽ���� ��
//														   // epoll �б�Ե�����������һ��û�н����꣬�������ϴ�����ֱ����һ���źŲŻᴥ�������ݲ����ᶪʧ
//
//						// ���ؽ��յ����ַ�����
//						//0 closesocket
//						//SOCKET_ERROR �쳣 
//						//WSAGetLastError() ����
//
//						if (res <= 0)
//						{
//							//�ر�socket						
//							closesocket(i);
//							FD_CLR(i, &allsocket);
//							cout<< " �Ͽ����� " << endl;
//							//����maxfd
//							if (i == maxfd)
//							{
//								while (FD_ISSET(maxfd, &allsocket) == false)
//									--maxfd;
//								cout << "update maxfd :" << maxfd << endl;
//							}
//						}
//						else 
//						{
//							cout << "����: "<< temp << endl;
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
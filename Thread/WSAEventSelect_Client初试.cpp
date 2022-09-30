//#include<iostream>
//using namespace std;
//
//#include<WinSock2.h>
//#include<WS2tcpip.h>
//#pragma comment(lib,"ws2_32.lib")
//
//
//
//void EventSelectClient()
//{
//	SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//	if (client == INVALID_SOCKET)
//	{
//		cout << "error socket : " << WSAGetLastError() << endl;
//		return;
//	}
//
//	sockaddr_in addr;
//	memset(&addr, 0, sizeof(sockaddr_in));
//
//	addr.sin_port = htons(27015);
//	addr.sin_family = AF_INET;
//	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
//
//	auto ret = connect(client, (sockaddr*)&addr, sizeof(addr));
//	if (ret != 0)
//	{
//		cout << "connect error: " << endl;
//		return;
//	}
//
//	cout << "Á´½Ó·þÎñÆ÷" << endl;
//
//	int nEvent = 0;
//	WSAEVENT event0 = WSACreateEvent();
//
//	WSAEventSelect(client, event0, FD_CLOSE | FD_READ);
//	nEvent++;
//	while (1)
//	{
//		int nindex = WSAWaitForMultipleEvents(nEvent, &event0, false, WSA_INFINITE, false);
//
//		nindex = nindex - WSA_WAIT_EVENT_0;
//		WSANETWORKEVENTS wsaEvent = { 0 };
//		WSAEnumNetworkEvents(client, event0, &wsaEvent);
//
//		if (wsaEvent.lNetworkEvents & FD_READ)
//		{
//			if (wsaEvent.iErrorCode[FD_READ_BIT] != 0)
//			{
//				cout << "read error" << endl;
//				continue;
//			}
//			char buf[1024] = { 0 };
//			int nRecv = recv(client, buf, 1024, 0);
//			cout << buf << endl;
//			if (nRecv > 0)
//			{
//				char temp[] = "receive your message\r\n";
//				send(client, temp, strlen(temp), 0);
//			}
//		}
//		else if (wsaEvent.lNetworkEvents & FD_CLOSE)
//		{
//			cout << "sever close" << endl;
//			WSACloseEvent(event0);
//			closesocket(client);
//			nEvent--;
//			break;
//		}
//	}
//}
//
//
//void main()
//{
//	WSADATA wsaData = { 0 };
//	auto ret = WSAStartup(MAKEWORD(2, 2), &wsaData);
//	if (ret != 0)
//	{
//		cout << "wsastartup error: " << WSAGetLastError() << endl;
//		return;
//	}
//
//	EventSelectClient();
//
//	WSACleanup();
//	system("pause");
//	return;
//}
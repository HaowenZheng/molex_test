//#include<iostream>
//using namespace std;
//#include<string>
//
//#include<WinSock2.h>
//#include<WS2tcpip.h>
//#pragma comment(lib,"ws2_32.lib")
//
//#define MAX_EVENTS WSA_MAXIMUM_WAIT_EVENTS //���64��
//#define MAX_BUF 4096
//
//void WSAEventSelectSocket()
//{
//	SOCKET listen_sock = socket(2, 1, 6);
//	//socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//	if (listen_sock == INVALID_SOCKET)
//	{
//		cout << "socket error" << endl;
//		return;
//	}
//
//	sockaddr_in sock_addr;
//	memset(&sock_addr, 0, sizeof(sockaddr_in));
//
//	sock_addr.sin_family = AF_INET;
//	sock_addr.sin_port = htons(27015);
//
//	hostent* thishost = gethostbyname("");
//	char* ip;
//	ip = inet_ntoa(*(in_addr*)*thishost->h_addr_list);
//	inet_pton(AF_INET, ip, &sock_addr.sin_addr.s_addr);
//
//	auto ret = bind(listen_sock, (sockaddr*)&sock_addr, sizeof(sockaddr));
//	if (ret != 0)
//	{
//		cout << "bind error" << endl;
//		return;
//	}
//
//	ret = listen(listen_sock, 5);
//	if (ret != 0)
//	{
//		cout << "listen error" << endl;
//		return;
//	}
//	cout << "�ɹ������˿�: " << ntohs(sock_addr.sin_port) << endl;
//
//	//�����������顢socket����
//	WSAEVENT eventArray[MAX_EVENTS];
//	SOCKET sockArray[MAX_EVENTS];
//
//	int nEvent = 0; // ��¼���ٸ�event
//	WSAEVENT event0 = WSACreateEvent();
//
//	WSAEventSelect(listen_sock, event0, FD_ACCEPT | FD_CLOSE);
//
//	
//	eventArray[nEvent] = event0;
//	sockArray[nEvent] = listen_sock;
//	nEvent++;
//
//	while (1)
//	{
//		auto nindex = WSAWaitForMultipleEvents(nEvent, eventArray, false, WSA_INFINITE, false);
//
//		if (nindex == WSA_WAIT_IO_COMPLETION || nindex == WSA_WAIT_TIMEOUT)
//		{
//			cout << "�ȴ�ʱ���ʹ���! ������룺" << WSAGetLastError() << endl;
//			break;
//		}
//
//		nindex = nindex - WSA_WAIT_EVENT_0;
//		WSANETWORKEVENTS wsaEvent = { 0 };
//		auto sock = sockArray[nindex];
//		auto hand = eventArray[nindex];
//		WSAEnumNetworkEvents(sock, hand, &wsaEvent);
//		//WSAEnumNetworkEvents(sock, NULL, &wsaEvent); //����hand�򲻻����event��һֱ��������Ҫ�ֶ�reset
//		//WSAResetEvent(hand);
//		//�жϷ��ؽ��
//
//		if (wsaEvent.lNetworkEvents & FD_ACCEPT) // ���տͻ���
//		{
//			if (wsaEvent.iErrorCode[FD_ACCEPT_BIT] != 0 || nindex >= MAX_EVENTS)
//			{
//				cout << "�¼�̫�࣬�ܾ�����" << endl;
//				continue;
//				
//			}
//
//			sockaddr_in addr;
//			int lens = sizeof(sockaddr_in);
//			auto client = accept(sock, (sockaddr*)&addr, &lens);
//			if (client != INVALID_SOCKET)
//			{
//				cout << "������һ���ͻ������ӣ� " << inet_ntoa(addr.sin_addr) << ":" << ntohs(addr.sin_port) << endl;
//
//				WSAEVENT newEvent = WSACreateEvent();
//
//				WSAEventSelect(client, newEvent, FD_ACCEPT | FD_READ | FD_CLOSE);
//
//				eventArray[nEvent] = newEvent;
//				sockArray[nEvent] = client;
//
//				nEvent++;
//
//			}
//		}
//		else if (wsaEvent.lNetworkEvents & FD_READ) //������
//		{
//			if (wsaEvent.iErrorCode[FD_READ_BIT] != 0)
//				continue;
//
//			char buf[MAX_BUF] = { 0 };
//			int nRecv = recv(sock, buf, sizeof(buf), 0); //�����ݷŵ������У������߳�ȥ��������//ʵ�����첽�Ľ��գ�����ȴ���ܽ����첽�ķ��� 
//			//����ʵ���첽���յ����ݣ�����
//			if (nRecv > 0)
//			{
//				cout << "�յ���Ϣ" << endl;
//				char strsend[] = "I recvied your message";
//				//send(sock, strsend, strlen(strsend), 0);
//				send(sock, buf, strlen(buf), 0);
//			}
//		}
//		else if (wsaEvent.lNetworkEvents & FD_CLOSE)
//		{
//			WSACloseEvent(eventArray[nindex]);
//			closesocket(sockArray[nindex]);
//			cout << "�Ͽ�һ������" << endl;
//
//			for (int j = nindex;j < nEvent - 1;++j)
//			{
//				eventArray[j] = eventArray[j + 1];
//				sockArray[j] = sockArray[j + 1];
//			}
//			nEvent--;
//		}
//	}
//		
//}
//
//
//void main()
//{
//	//string snno = "sn_";
//	////��ȡ���ڼ�ʱ�䣬����sn
//	//SYSTEMTIME sysTime;
//	//GetLocalTime(&sysTime);
//	////sysTime.wDay, sysTime.wHour, sysTime.wMinute, sysTime.wSecond
//	//char tsz[64] = { 0 };
//	//sprintf(tsz, "%02d:%02d:%02d", sysTime.wHour, sysTime.wMinute, sysTime.wSecond);
//	//snno.append(tsz);
//	//string snno1 = snno;
//	//if (snno == snno1)
//	//{
//	//	cout << "���" << endl;
//	//}
//	//system("pause");
//	//return;
//	WSAData wsaData;
//	auto ret = WSAStartup(MAKEWORD(2, 2), &wsaData);
//	if (ret != 0)
//	{
//		cout << "wsastartup error" << endl;
//		return;
//	}
//
//	WSAEventSelectSocket();
//
//	WSACleanup();
//	system("pause");
//	return;
//}
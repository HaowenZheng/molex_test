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
//		sprintf_s(tempMsg, "WSAStartup���󣬴�����:%d", GetLastError());
//		cout << tempMsg << endl;
//		return;
//	}
//
//	//1������socket
//	SOCKET servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP); //IPV4 ������ģʽ tcpЭ�飨д0Ҳ��tcpģʽ��
//
//	//2�����ø��ӵĽṹ��  //����ip��ַ�����ö˿ںţ�����ipv4Э��
//	sockaddr_in sockAddr;
//	memset(&sockAddr, 0, sizeof(sockAddr));
//
//	sockAddr.sin_family = AF_INET;
//	sockAddr.sin_port = htons(1234);
//	//sockAddr.sin_addr.s_addr = inet_addr("10.220.48.126");
//	sockAddr.sin_addr.s_addr = htonl(INADDR_ANY);
//
//	//3����
//	int bindRet = bind(servSock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
//	if (bindRet == SOCKET_ERROR)
//	{
//		char tempMsg[256] = { 0 };
//		sprintf_s(tempMsg, "bind���󣬴�����:%d", GetLastError());
//		cout << tempMsg << endl;
//		return;
//	}
//
//	//4������
//	int listenRet = listen(servSock, 20);
//	if (listenRet == SOCKET_ERROR)
//	{
//		char tempMsg[256] = { 0 };
//		sprintf_s(tempMsg, "listen���󣬴�����:%d", GetLastError());
//		cout << tempMsg << endl;
//		return;
//	}
//	
//	//5�����տͻ�������
//	sockaddr_in clientAddr;
//	int nlen = sizeof(clientAddr);
//	SOCKET client = accept(servSock, (sockaddr*)&clientAddr, &nlen); //�߳̿�ס���ȴ�listen�����в�Ϊ�գ�ȡ��һ������
//
//	//�������
//	cout << "�ͻ���ip: "<< inet_ntoa(clientAddr.sin_addr) << endl;
//
//	//6������ ����
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
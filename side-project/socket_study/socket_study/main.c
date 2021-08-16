#pragma comment(lib, "ws2_32.lib")
#include <stdio.h>
#include <WinSock2.h>
#include <Windows.h>

void server(int);
void client(int, char*);
void ErrorHandling(char*);

int  main(void)
{
	int menu = 0, port = 0;
	char ip[100];

	puts("0. server / 1. client");
	printf("메뉴 번호를 입력하세요: ");
	scanf("%d", &menu);

	switch (menu)
	{
	case 1:
		printf("포트 번호를 입력하세요: ");
		scanf("%d", &port);
		server(port);
		break;
	default:
		printf("설정하실 포트 번호를 입력하세요: ");
		scanf("%d", &port);
		printf("IP를 입력하세요: ");
		scanf("%s", &ip);
		client(port, ip);
		break;
	}

	system("PAUSE");
	return 0;
}

void ErrorHandling(char* Message)
{
	fputs(Message, stderr);
	fputc('\n', stderr);
	exit(1);
}

void server(int port)
{
	WSADATA wsaData;
	SOCKET listen_sock, connect_sock;
	SOCKADDR_IN listen_addr, connect_addr;
	int sockaddr_in_size;
	char message[100];

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error");

	listen_sock = socket(PF_INET, SOCK_STREAM, 0);

	if (listen_sock == INVALID_SOCKET)
		ErrorHandling("socket() error");

	memset(&listen_addr, 0, sizeof(listen_addr));
	listen_addr.sin_family = AF_INET;
	listen_addr.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	listen_addr.sin_port = htons(port);

	if (bind(listen_sock, (SOCKADDR*)&listen_addr, sizeof(listen_addr)) == SOCKET_ERROR)
		ErrorHandling("bind() error");

	if (listen(listen_sock, 5) == SOCKET_ERROR)
		ErrorHandling("listen() error");

	sockaddr_in_size = sizeof(connect_addr);
	connect_sock = accept(listen_sock, (SOCKADDR*)&connect_addr, &sockaddr_in_size);

	if (connect_sock == INVALID_SOCKET)
		ErrorHandling("accept() error");

	// send data
	recv(connect_sock, message, 12, 0);
	printf("server: %s\n", message);

	closesocket(connect_sock);
	closesocket(listen_sock);
	WSACleanup();
}

void client(int port, char* ip)
{
	WSADATA wsaData;
	SOCKET connect_sock;
	SOCKADDR_IN connect_addr;

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		ErrorHandling("WSAStartup() error");

	connect_sock = socket(PF_INET, SOCK_STREAM, 0);

	if (connect_sock == INVALID_SOCKET)
		ErrorHandling("socket() error");

	memset(&connect_addr, 0, sizeof(connect_addr));
	connect_addr.sin_family = AF_INET;
	connect_addr.sin_addr.S_un.S_addr = inet_addr(ip);
	connect_addr.sin_port = htons(port);

	if (connect(connect_sock, (SOCKADDR*)&connect_addr, sizeof(connect_addr)))
		ErrorHandling("connect() error");

	// send data
	send(connect_sock, "TEST", 12, 0);
	puts("Success");

	closesocket(connect_sock);
	WSACleanup();
	system("pause");
}
#pragma once
void server(int);
void client(int, char*);
void ErrorHandling(char*);

typedef struct
{
	int Data;
	int  Data2;
	char StringData1[100];
	char StringData2[100];
} SOCPACKET;
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "header.h"

void help(int screenNumber)
{
	system("cls");
	gotoxy(2, 28);
	printf("����ȭ������ ���ư��� | BACKSPACE");
	gotoxy(58, 28);
	printf("�� 2017-2021. chm209 all rights reserved.");

	char key = 0;

	switch (screenNumber)
	{
	case 0:
		drawContent(0);
		break;
	default:
		drawContent(1);
		break;
	}

	while (key != 8)
	{
		key = getch();
	}
}
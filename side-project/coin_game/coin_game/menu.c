#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int menu(void)
{
	int y = 11, key = 0;

	system("cls");
	gotoxy(46, 11);
	printf("���ӽ���");
	gotoxy(46, 13);
	printf("���ӹ��");
	gotoxy(47, 15);
	printf("ũ����");
	gotoxy(46, 17);
	printf("��������");
	gotoxy(2, 28);
	printf("�� �� �Ʒ� ��");

	while (key != 13)
	{
		gotoxy(56, y);
		printf("��");
		key = _getch();
		gotoxy(56, y);
		printf("  ");
		y = move(0, key, 56, y);
		gotoxy(56, y);
	}
	return y;
}
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int menu(void)
{
	int y = 11, key = 0;

	system("cls");
	gotoxy(46, 11);
	printf("게임시작");
	gotoxy(46, 13);
	printf("게임방법");
	gotoxy(47, 15);
	printf("크레딧");
	gotoxy(46, 17);
	printf("게임종료");
	gotoxy(2, 28);
	printf("위 ↑ 아래 ↓");

	while (key != 13)
	{
		gotoxy(56, y);
		printf("◀");
		key = _getch();
		gotoxy(56, y);
		printf("  ");
		y = move(0, key, 56, y);
		gotoxy(56, y);
	}
	return y;
}
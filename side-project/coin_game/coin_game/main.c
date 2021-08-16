#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(void)
{
	system("mode con cols=101 lines=30");
	system("title coin game");
	cursor(0);

	int MenuChoice = 0;

	while (MenuChoice != 17)
	{
		MenuChoice = menu();

		switch (MenuChoice)
		{
		case 11:
			game();
			break;
		case 13:
			help(0);
			break;
		case 15:
			help(1);
			break;
		default:
			break;
		}
	}
	return 0;
}
#include <stdio.h>
#include "header.h"

int move(int ScreenNumber, int key, int x, int y)
{
	switch (ScreenNumber)
	{
	case 0:
		switch (key)
		{
		case UP:
			y = (y <= 11) ? 11 : y - 2;
			break;
		case DOWN:
			y = (y >= 17) ? 17 : y + 2;
			break;
		}
		break;
	case 1:
		switch (key)
		{
		case UP:
			y = (y <= 12) ? 12 : y - 2;
			break;
		case DOWN:
			y = (y >= 16) ? 16 : y + 2;
			break;
		}
		break;
	case 2:
		switch (key)
		{
		case UP:
			y = (y <= 18) ? 18 : y - 2;
			break;
		case DOWN:
			y = (y >= 26) ? 26 : y + 2;
			break;
		}
		break;
	}
	return y;
}
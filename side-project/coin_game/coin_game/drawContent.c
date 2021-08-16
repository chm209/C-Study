#include <stdio.h>
#include "header.h"

void drawContent(int ScrennNumber)
{
	if (ScrennNumber == 0)
	{
		gotoxy(7, 6);
		printf("< °ÔÀÓ¼³¸í >");
		gotoxy(7, 8);
		printf("ÄÚÀÎ °ÔÀÓÀº ¾ÏÈ£È­Æó °¡»ó ÅõÀÚ °ÔÀÓ ÀÔ´Ï´Ù.");
		gotoxy(7, 10);
		printf("ÀÏÁ¤ÇÑ È®·ü·Î ÀÌº¥Æ®°¡ ¹ß»ýÇÏ¸ç, ÀÌ´Â \"¹Ì·¡´º½º\"¿¡¼­ È®ÀÎÇÒ ¼ö ÀÖ½À´Ï´Ù.");
		gotoxy(7, 12);
		printf("ÄÚÀÎÀÌ Æø¶ôÇÏ¸é »óÀåÆóÁöÀÇ °¡´É¼ºÀÌ ÀÖ½À´Ï´Ù.");
		gotoxy(7, 14);
		printf("ÀºÇà ÀÔÃâ±Ý ±â´ÉÀ¸·Î ÀÚ±ÝÀ» ¾ÈÀüÇÏ°Ô º¸°üÇÒ ¼ö ÀÖÀ¸¸ç, ÀÌÀÚÀ²Àº ³­ÀÌµµ¿¡ ´Ù¶ó ´Ù¸¨´Ï´Ù.");
		gotoxy(7, 16);
		printf("ÄÚÀÎ ¸Åµµ½Ã 7ÅÏ¸¶´Ù ¼¼±ÝÀÌ ºÎ°úµÇ¸ç, ÀÌ´Â ÀÚµ¿À¸·Î ³³ºÎ µË´Ï´Ù.");
		gotoxy(7, 18);
		printf("¼¼±ÝÀº ³­ÀÌµµ¿¡ µû¶ó ´Ù¸£¸ç, ¿¬Ã¼½Ã ¿¬Ã¼±ÝÀÌ ºÎ°ú µË´Ï´Ù.");
		gotoxy(7, 20);
		printf("¸¸¾à ¼ÒÁö±ÝÀÌ 0¿ø, ÀºÇà ÀÚ±Ý, º¸À¯ ÄÚÀÎÀÌ ÇÏ³ªµµ ¾ø´Ù¸é ÆÄ»êÇÏ°Ô µË´Ï´Ù.");
	}
	else if (ScrennNumber == 1)
	{
		gotoxy(24, 9);
		printf("< Å©·¹µ÷ >");
		gotoxy(24, 11);
		printf("¹öÀü: 1.0");
		gotoxy(24, 13);
		printf("Á¦ÀÛÀÚ: chm209");
		gotoxy(24, 15);
		printf("¶óÀÌ¼¾½º: GNU General Public License v3.0");
	}
	else if (ScrennNumber == 2)
	{
		gotoxy(0, 2);
		printf("¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬");
		gotoxy(0, 3);
		printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
		gotoxy(0, 4);
		printf("¦­                     ¦­                          ¦­¦­                                                ¦­");
		gotoxy(0, 5);
		printf("¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´¦­                                                ¦­");
		gotoxy(0, 6);
		printf("¦­                     ¦­                          ¦­¦­                                                ¦­");
		gotoxy(0, 7);
		printf("¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´¦­                                                ¦­");
		gotoxy(0, 8);
		printf("¦­                     ¦­                          ¦­¦­                                                ¦­");
		gotoxy(0, 9);
		printf("¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´¦­                                                ¦­");
		gotoxy(0, 10);
		printf("¦­                     ¦­                          ¦­¦­                                                ¦­");
		gotoxy(0, 11);
		printf("¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´¦­                                                ¦­");
		gotoxy(0, 12);
		printf("¦­                     ¦­                          ¦­¦­                                                ¦­");
		gotoxy(0, 13);
		printf("¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´¦­                                                ¦­");
		gotoxy(0, 14);
		printf("¦­                     ¦­                          ¦­¦­                                                ¦­");
		gotoxy(0, 15);
		printf("¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´¦­                                                ¦­");
		gotoxy(0, 16);
		printf("¦­                     ¦­                          ¦­¦­                                                ¦­");
		gotoxy(0, 17);
		printf("¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´");
		gotoxy(0, 18);
		printf("¦­                     ¦­                          ¦­¦­                       ¦­                        ¦­");
		gotoxy(0, 19);
		printf("¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´");
		gotoxy(0, 20);
		printf("¦­                     ¦­                          ¦­¦­                       ¦­                        ¦­");
		gotoxy(0, 21);
		printf("¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´");
		gotoxy(0, 22);
		printf("¦­                     ¦­                          ¦­¦­                       ¦­                        ¦­");
		gotoxy(0, 23);
		printf("¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´");
		gotoxy(0, 24);
		printf("¦­                     ¦­                          ¦­¦­                       ¦­                        ¦­");
		gotoxy(0, 25);
		printf("¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´");
		gotoxy(0, 26);
		printf("¦­                     ¦­                          ¦­¦­                       ¦­                        ¦­");
		gotoxy(0, 27);
		printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
		gotoxy(1, 28);
		printf("¸ÞÀÎÈ­¸éÀ¸·Î µ¹¾Æ°¡±â ¦­ BACKSPACE");
		gotoxy(62, 28);
		printf("Â÷Æ®: ÁÂ ¡ç ¿ì ¡æ ¦­ ¸Þ´º À§ ¡è ¾Æ·¡ ¡é");
		gotoxy(52, 18);
		printf("ÄÚÀÎ ¸Å¼ö");
		gotoxy(52, 20);
		printf("ÄÚÀÎ ¸Åµµ");
		gotoxy(52, 22);
		printf("ÀºÇà ÀÔ±Ý");
		gotoxy(52, 24);
		printf("ÀºÇà Ãâ±Ý");
		gotoxy(52, 26);
		printf("°Å·¡ Á¾·á");
	}
	else if (ScrennNumber == 3)
	{
		gotoxy(2, 28);
		printf("À§ ¡è ¾Æ·¡ ¡é ¿£ÅÍ");
		gotoxy(30, 7);
		printf("[10ÀÚ ÀÌ³»]");
		gotoxy(30, 8);
		printf("ÀÌ¸§À» ÀÔ·ÂÇÏ¼¼¿ä: ");
	}
	else if (ScrennNumber == 4)
	{
		gotoxy(30, 10);
		printf("³­ÀÌµµ¸¦ ¼³Á¤ÇÏ¼¼¿ä.");
		gotoxy(30, 11);
		printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦³¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯");
		gotoxy(30, 12);
		printf("¦­ ½¬¿ò        ¦­                        ¦­");
		gotoxy(30, 13);
		printf("¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´");
		gotoxy(30, 14);
		printf("¦­ º¸Åë        ¦­                        ¦­");
		gotoxy(30, 15);
		printf("¦²¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¶¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦´");
		gotoxy(30, 16);
		printf("¦­ ¾î·Á¿ò      ¦­                        ¦­");
		gotoxy(30, 17);
		printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦µ¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
	}
	else if (ScrennNumber == 5)
	{
		gotoxy(52, 18);
		printf("                      ");
		gotoxy(52, 20);
		printf("                      ");
		gotoxy(52, 22);
		printf("                      ");
		gotoxy(52, 24);
		printf("                      ");
		gotoxy(52, 26);
		printf("                      ");
		gotoxy(52, 18);
		printf("º¸À¯ ±Ý¾×");
		gotoxy(52, 20);
		printf("ÄÚÀÎ ¹øÈ£");
		gotoxy(52, 22);
		printf("ÇöÀç °¡°Ý");
		gotoxy(52, 24);
		printf("¸ÅÀÔ °¡´ÉÇÑ ¼ö·®");
		gotoxy(52, 26);
		printf("¸ÅÀÔ ¼ö·®");
	}
	else if (ScrennNumber == 6)
	{
		gotoxy(52, 18);
		printf("                      ");
		gotoxy(52, 20);
		printf("                      ");
		gotoxy(52, 22);
		printf("                      ");
		gotoxy(52, 24);
		printf("                      ");
		gotoxy(52, 26);
		printf("                      ");
		gotoxy(52, 18);
		printf("ÄÚÀÎ ¹øÈ£");
		gotoxy(52, 20);
		printf("ÇöÀç °¡°Ý");
		gotoxy(52, 22);
		printf("Æò±Õ ¸ÅÀÔ°¡");
		gotoxy(52, 24);
		printf("º¸À¯ ¼ö·®");
		gotoxy(52, 26);
		printf("ÆÇ¸Å ¼ö·®");
	}
	else if (ScrennNumber == 7)
	{
		gotoxy(52, 18);
		printf("¼ÒÁöÇÑ ±Ý¾×");
		gotoxy(52, 20);
		printf("±âÁ¸ ÅëÀå ÀÜ¾×");
		gotoxy(52, 22);
		printf("ÀÔ±Ý ±Ý¾×");
		gotoxy(52, 24);
		printf("ÇöÀç ÅëÀå ÀÜ¾×");
	}
	else if (ScrennNumber == 8)
	{
		gotoxy(52, 18);
		printf("¼ÒÁöÇÑ ±Ý¾×");
		gotoxy(52, 20);
		printf("±âÁ¸ ÅëÀå ÀÜ¾×");
		gotoxy(52, 22);
		printf("Ãâ±Ý ±Ý¾×");
		gotoxy(52, 24);
		printf("ÇöÀç ÅëÀå ÀÜ¾×");
	}
}
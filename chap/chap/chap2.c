#include <stdio.h>

void main(void)
{
	printf("연습문제 1\n");
	int jean = 0;
	jean = 1;
	jean += 1;
	printf("수량: %d\n구매완료", jean);
	printf("\n연습문제 2\n");
	int red = 1, blue = 2, yellow;
	printf("before\nred = %d, blue = %d\n", red, blue);
	yellow = red;
	red = blue;
	blue = yellow;
	printf("after\nred=%d, blue=%d", red, blue);
	printf("\n연습문제 3\n");
	int y, m, d;
	printf("년 월 일: " );
	scanf("%d %d %d", &y, &m, &d);
	printf("%d년%d월%d일", y,m,d);
}
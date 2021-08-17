#include<stdio.h>

int main(void)
{
	printf("연습문제 1\n");
	printf("  *\n ***\n*****\n ***\n  *\n");
	printf("\n연습문제2\n");
	printf("2 * 1 = %d\n", 2 * 1);
	printf("2 * 2 = %d\n", 2 * 2);
	printf("2 * 3 = %d\n", 2 * 3);
	printf("2 * 4 = %d\n", 2 * 4);
	printf("\n연습문제3\n");
	int a, b;
	printf("가로 길이 입력");
	scanf("%d", &a);
	printf("세로 길이 입력");
	scanf("%d", &b);
	printf("직사각형의 넓이: %d", a*b);
	printf("\n연습문제4\n");
	int r;
	double pi = 3.14;
	printf("반지름 입력: ");
	scanf("%d", &r);
	printf("원 넓이: %lf\n", r*r*pi);
	printf("\n연습문제4\n");
	int c, d;
	printf("숫자1, 2 입력: ");
	scanf("%d %d", &c, &d);
	printf("합: %d + %d = %d\n차: %d - %d = %d", c, d, c+d, c, d, c- d);

	return 0;
}
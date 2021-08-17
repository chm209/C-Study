#include <stdio.h>

void main()
{
	printf("연습문제 1\n");
	int x, y, z;
	printf("입력: ");
	scanf("%d %d %d", &x, &y, &z);
	printf("(x+y) * (x+z) / (y%z) = %d", (x + y) * (x + z) / (y % z));
	printf("\n연습문제 2\n");
	int a, b;
	printf("입력: ");
	scanf("%d %d", &a, &b);
	a > b ? printf("%d", b)
		: b < a ? printf("%d", a)
		: printf("같음");
	printf("\n연습문제 3\n");
	int kor = 1130, usa;
	printf("입력: ");
	scanf("%d" , &usa);
	printf("%d", kor*usa);
	printf("\n연습문제 4\n");
	int human = 19 ;
	human = 100 - (((2 * 7) * 4 * 12 * 20) / 60 / 24) - 19;
	printf("%d살까지 산다\n%d년 단축", human, (((2 * 7) * 4 * 12 * 20) / 60 / 24));
	printf("\n연습문제 5\n");
	double m = 0.45;
	printf("밀가루 150파운드 = %0.2lf kg", m * 150);
}
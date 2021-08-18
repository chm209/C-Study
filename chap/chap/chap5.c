#include <stdio.h>
typedef int myInt;
typedef double myDouble;

void main()
{
	printf("sizeof - 자료형 크기, typedef - 자료형 재정의\n");
	myInt a = 1;
	myDouble b = 1.1;
	printf("%d %lf\n", a, b);
	printf("int = %d 바이트\n", sizeof(a));
	// 문제
	printf("\n연습문제 1\n");
	double r = 2;
	int v = 4;
	printf("입력: ");
	scanf("%lf %d", &r, &v);
	printf("반지름 %lf, 시속 %d Km \n원둘레 = %lf\n한 바퀴를 완주하는데 걸리는 시간 %0.3lf", r, v, 2*r*3.14, (2 * r * 3.14) / v);
}
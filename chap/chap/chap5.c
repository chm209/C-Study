#include <stdio.h>
typedef int myInt;
typedef double myDouble;

void main()
{
	printf("sizeof - �ڷ��� ũ��, typedef - �ڷ��� ������\n");
	myInt a = 1;
	myDouble b = 1.1;
	printf("%d %lf\n", a, b);
	printf("int = %d ����Ʈ\n", sizeof(a));
	// ����
	printf("\n�������� 1\n");
	double r = 2;
	int v = 4;
	printf("�Է�: ");
	scanf("%lf %d", &r, &v);
	printf("������ %lf, �ü� %d Km \n���ѷ� = %lf\n�� ������ �����ϴµ� �ɸ��� �ð� %0.3lf", r, v, 2*r*3.14, (2 * r * 3.14) / v);
}
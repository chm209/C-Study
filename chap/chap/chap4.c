#include <stdio.h>

void main()
{
	printf("�������� 1\n");
	int x, y, z;
	printf("�Է�: ");
	scanf("%d %d %d", &x, &y, &z);
	printf("(x+y) * (x+z) / (y%z) = %d", (x + y) * (x + z) / (y % z));
	printf("\n�������� 2\n");
	int a, b;
	printf("�Է�: ");
	scanf("%d %d", &a, &b);
	a > b ? printf("%d", b)
		: b < a ? printf("%d", a)
		: printf("����");
	printf("\n�������� 3\n");
	int kor = 1130, usa;
	printf("�Է�: ");
	scanf("%d" , &usa);
	printf("%d", kor*usa);
	printf("\n�������� 4\n");
	int human = 19 ;
	human = 100 - (((2 * 7) * 4 * 12 * 20) / 60 / 24) - 19;
	printf("%d����� ���\n%d�� ����", human, (((2 * 7) * 4 * 12 * 20) / 60 / 24));
	printf("\n�������� 5\n");
	double m = 0.45;
	printf("�а��� 150�Ŀ�� = %0.2lf kg", m * 150);
}
#include<stdio.h>

int main(void)
{
	printf("�������� 1\n");
	printf("  *\n ***\n*****\n ***\n  *\n");
	printf("\n��������2\n");
	printf("2 * 1 = %d\n", 2 * 1);
	printf("2 * 2 = %d\n", 2 * 2);
	printf("2 * 3 = %d\n", 2 * 3);
	printf("2 * 4 = %d\n", 2 * 4);
	printf("\n��������3\n");
	int a, b;
	printf("���� ���� �Է�");
	scanf("%d", &a);
	printf("���� ���� �Է�");
	scanf("%d", &b);
	printf("���簢���� ����: %d", a*b);
	printf("\n��������4\n");
	int r;
	double pi = 3.14;
	printf("������ �Է�: ");
	scanf("%d", &r);
	printf("�� ����: %lf\n", r*r*pi);
	printf("\n��������4\n");
	int c, d;
	printf("����1, 2 �Է�: ");
	scanf("%d %d", &c, &d);
	printf("��: %d + %d = %d\n��: %d - %d = %d", c, d, c+d, c, d, c- d);

	return 0;
}
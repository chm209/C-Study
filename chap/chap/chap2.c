#include <stdio.h>

void main(void)
{
	printf("�������� 1\n");
	int jean = 0;
	jean = 1;
	jean += 1;
	printf("����: %d\n���ſϷ�", jean);
	printf("\n�������� 2\n");
	int red = 1, blue = 2, yellow;
	printf("before\nred = %d, blue = %d\n", red, blue);
	yellow = red;
	red = blue;
	blue = yellow;
	printf("after\nred=%d, blue=%d", red, blue);
	printf("\n�������� 3\n");
	int y, m, d;
	printf("�� �� ��: " );
	scanf("%d %d %d", &y, &m, &d);
	printf("%d��%d��%d��", y,m,d);
}
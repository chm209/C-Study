#include <stdio.h>

void main()
{
	printf("�������� 1\n");
	printf("�Է�(��������): ");
	int p1_a, p1_b = 0;
	scanf("%d", &p1_a);
	for (int i = 1; i <= 100; i++)
	{
		i% p1_a == 0 ? printf("%d ", i) : printf("");
		i% p1_a == 0 ? p1_b += 1 : p1_b;
	}
	printf("\n%d EA", p1_b);
	printf("\n�������� 2\n");
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k <= i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n�������� 3\n");
	for (int i = 7; i > 0 ; i -= 2)
	{
		for (int t = i; t < 7; t += 2)
		{
			printf(" ");
		}
		for (int k = 0; k < i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n�������� 4\n");
	int p4_a = 1, p4_sum = 0, p4_count = 0;
	while (p4_a != 0)
	{
		printf("�Է�: ");
		scanf("%d", &p4_a);
		p4_sum += p4_a;
		p4_count++;
	}
	printf("��: %d \nȽ��: %d", p4_sum, p4_count);
}
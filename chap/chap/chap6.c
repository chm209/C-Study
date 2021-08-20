#include <stdio.h>

void main()
{
	printf("연습문제 1\n");
	printf("입력(양의정수): ");
	int p1_a, p1_b = 0;
	scanf("%d", &p1_a);
	for (int i = 1; i <= 100; i++)
	{
		i% p1_a == 0 ? printf("%d ", i) : printf("");
		i% p1_a == 0 ? p1_b += 1 : p1_b;
	}
	printf("\n%d EA", p1_b);
	printf("\n연습문제 2\n");
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k <= i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("\n연습문제 3\n");
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
	printf("\n연습문제 4\n");
	int p4_a = 1, p4_sum = 0, p4_count = 0;
	while (p4_a != 0)
	{
		printf("입력: ");
		scanf("%d", &p4_a);
		p4_sum += p4_a;
		p4_count++;
	}
	printf("합: %d \n횟수: %d", p4_sum, p4_count);
}
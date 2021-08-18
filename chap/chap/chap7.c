#include <stdio.h>

void main()
{
	/* C 언어에서는 break; continue 키워드를 제공하는데
	*  break는 반복문이나 조건문을 종료하고 continue는 다시 조건식으로 돌아간다.
	*/


	printf("연습문제 1\n");
	int pb1_a, pb1_b, pb1_c;
	printf("입력: ");
	scanf("%d %d %d", &pb1_a, &pb1_b, &pb1_c);
	pb1_a % 2 == 0 ? printf("%d: 짝수 ", pb1_a) : printf("%d: 홀수 ", pb1_a);
	pb1_b % 2 == 0 ? printf("%d: 짝수 ", pb1_b) : printf("%d: 홀수 ", pb1_b);
	pb1_c % 2 == 0 ? printf("%d: 짝수 ", pb1_c) : printf("%d: 홀수 ", pb1_c);

	printf("\n연습문제 2\n");
	int pb2_a = 0;
	printf("입력: ");
	scanf("%d", &pb2_a);
	switch (pb2_a / 10)
	{
	case 10:
	case 9:
		printf("A");
		break;
	case 8:
		printf("B");
	default:
		printf("F");
		break;
	}

	printf("\n연습문제 3\n");
	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 != 0)
			printf("%d ", i);
		else
			continue;
	}
}
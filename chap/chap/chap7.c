#include <stdio.h>

void main()
{
	/* C ������ break; continue Ű���带 �����ϴµ�
	*  break�� �ݺ����̳� ���ǹ��� �����ϰ� continue�� �ٽ� ���ǽ����� ���ư���.
	*/


	printf("�������� 1\n");
	int pb1_a, pb1_b, pb1_c;
	printf("�Է�: ");
	scanf("%d %d %d", &pb1_a, &pb1_b, &pb1_c);
	pb1_a % 2 == 0 ? printf("%d: ¦�� ", pb1_a) : printf("%d: Ȧ�� ", pb1_a);
	pb1_b % 2 == 0 ? printf("%d: ¦�� ", pb1_b) : printf("%d: Ȧ�� ", pb1_b);
	pb1_c % 2 == 0 ? printf("%d: ¦�� ", pb1_c) : printf("%d: Ȧ�� ", pb1_c);

	printf("\n�������� 2\n");
	int pb2_a = 0;
	printf("�Է�: ");
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

	printf("\n�������� 3\n");
	for (int i = 1; i <= 100; i++)
	{
		if (i % 2 != 0)
			printf("%d ", i);
		else
			continue;
	}
}
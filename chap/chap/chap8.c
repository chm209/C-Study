#include <stdio.h>
void pb1(void);
void pb2(int, int);
void pb3(void);
void pb4(void);

void main()
{
	printf("�������� 1\n");
	pb1();
	printf("\n�������� 2\n");
	pb2(0, 1);
	printf("\n�������� 3\n");
	pb3();
	printf("\n�������� 4\n");
	int getNum = 0;
	printf("�Է�: ");
	scanf("%d", &getNum);
	pb4(getNum);
}

void pb1()
{
	int getNum;
	printf("�Է�: ");
	scanf("%d", &getNum);
	getNum > 0 ? printf("���밪�� %d �Դϴ�.", getNum)
		: printf("���밪�� %d �Դϴ�.", getNum - getNum * 2);		
}

void pb2(int rabbit, int leveret)
{
	static int count = 0;
	static int nextRabbit = 0;

	if (count == 12)
		return;

	printf("%d�� � �䳢:%d����, ���� �䳢:%d����, �� �䳢 %d����\n", count+1, rabbit + nextRabbit, leveret, rabbit + nextRabbit + leveret);

	// �����޿� ��ȭ�� �䳢 ��� ����
	if (nextRabbit > 0)
	{
		rabbit += nextRabbit;
		nextRabbit = 0;
	}

	// �ڽ� �䳢�� ������ � �䳢�� ��ȭ
	if (leveret > 0)
	{
		nextRabbit = leveret;
		leveret = 0;
	}

	// � �䳢�� ������ �ڽ� �䳢 ���
	if (rabbit > 0)
		leveret += rabbit;

	count++;
	pb2(rabbit, leveret);
}

void pb3()
{
	char alpha = 0;
	printf("�Է�: ");
	scanf("%c", &alpha);

	if(alpha >= 97)
		printf("�Է��� %C�� ���ĺ� ������ %d��° ���� �Դϴ�.", alpha, alpha - 96);
	else
		printf("�Է��� %C�� ���ĺ� ������ %d��° ���� �Դϴ�.", alpha, alpha - 64);	
}

void pb4(int getNum)
{
	static int sum = 0;
	int count = getNum;

	if (count < 1)
	{
		printf("%d",sum);
		return;
	}

	sum += getNum;
	pb4(getNum - 1);
}
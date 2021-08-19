#include <stdio.h>
void pb1(void);
void pb2(int, int);
void pb3(void);
void pb4(void);

void main()
{
	printf("연습문제 1\n");
	pb1();
	printf("\n연습문제 2\n");
	pb2(0, 1);
	printf("\n연습문제 3\n");
	pb3();
	printf("\n연습문제 4\n");
	int getNum = 0;
	printf("입력: ");
	scanf("%d", &getNum);
	pb4(getNum);
}

void pb1()
{
	int getNum;
	printf("입력: ");
	scanf("%d", &getNum);
	getNum > 0 ? printf("절대값은 %d 입니다.", getNum)
		: printf("절대값은 %d 입니다.", getNum - getNum * 2);		
}

void pb2(int rabbit, int leveret)
{
	static int count = 0;
	static int nextRabbit = 0;

	if (count == 12)
		return;

	printf("%d달 어른 토끼:%d마리, 새끼 토끼:%d마리, 총 토끼 %d마리\n", count+1, rabbit + nextRabbit, leveret, rabbit + nextRabbit + leveret);

	// 저번달에 진화한 토끼 출산 가능
	if (nextRabbit > 0)
	{
		rabbit += nextRabbit;
		nextRabbit = 0;
	}

	// 자식 토끼가 있으면 어른 토끼로 진화
	if (leveret > 0)
	{
		nextRabbit = leveret;
		leveret = 0;
	}

	// 어른 토끼가 있으면 자식 토끼 출산
	if (rabbit > 0)
		leveret += rabbit;

	count++;
	pb2(rabbit, leveret);
}

void pb3()
{
	char alpha = 0;
	printf("입력: ");
	scanf("%c", &alpha);

	if(alpha >= 97)
		printf("입력한 %C는 알파벳 순서로 %d번째 문자 입니다.", alpha, alpha - 96);
	else
		printf("입력한 %C는 알파벳 순서로 %d번째 문자 입니다.", alpha, alpha - 64);	
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
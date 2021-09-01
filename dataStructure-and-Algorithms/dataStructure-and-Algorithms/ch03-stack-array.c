#include <stdio.h>
#include <stdlib.h>
void push(struct STACK* pointer, int x);
int pop(struct STACK* pointer);

/*
* ������ ���������� �Էµ� �����Ͱ� ù��°�� ��µǴ� LIFO���� �ڷᱸ���̴�.
* ���ÿ� �ԷµǴ� �����ʹ� � ���µ� ���������, ������ ������ ���� 3������ ���еȴ�.
* 1. push ������ ������ top�� ���ο� �����͸� �Է�(�߰�)�Ѵ�.
* 2. pop ������ ������ top�� �ִ� �����͸� ���(����)�Ѵ�.
* 3. stack top�� ������ top�� �ִ� �����͸� ��������� ���������� �ʴ´�.
* ������ ������ �ڷᱸ���̱� ������ ������ ����� ���ѵȴ�.
* ���� ���� �����ʹ� push�� ������� ����Ǿ��ٰ� pop�� ���Ͽ� ����� �������� ��µȴ�.
*
*/
typedef struct {
	int size;
	int list[100];
} STACK;

void main(void)
{
	// # 1 �迭�� ����
	STACK* pointer;
	pointer = (STACK*)malloc(sizeof(STACK));
	pointer->size = 0;

	printf("���� ������ %d\n", sizeof(STACK));

	push(pointer, 10);
	push(pointer, 20);
	push(pointer, 30);
	push(pointer, 40);

	printf("%d\n", pop(pointer));
	printf("%d\n", pop(pointer));
	printf("%d\n", pop(pointer));
	printf("%d\n", pop(pointer));

	free(pointer);
}

void push(STACK* pointer, int x)
{
	if (pointer->size == 100)
	{
		printf("������");
	}
	else
	{
		pointer->list[pointer->size++] = x;
	}
}

int pop(STACK* pointer)
{
	if (pointer->size == 0)
	{
		printf("�ֺ�");
		return -1;
	}
	else
	{
		return pointer->list[--pointer->size];
	}
}
#include <stdio.h>
#include <stdlib.h>
void push(struct STACK* pointer, int x);
int pop(struct STACK* pointer);

/*
* 스택은 마지막으로 입력된 데이터가 첫반째로 출력되는 LIFO형의 자료구조이다.
* 스택에 입력되는 데이터는 어떤 형태든 상관없지만, 스택의 동작은 보통 3가지로 구분된다.
* 1. push 동작은 스택의 top에 새로운 데이터를 입력(추가)한다.
* 2. pop 동작은 스택의 top에 있는 데이터를 출력(제거)한다.
* 3. stack top은 스택의 top에 있는 데이터를 출력하지만 제거하지는 않는다.
* 스택은 간단한 자료구조이기 때문에 동작이 몇가지로 제한된다.
* 스택 안의 데이터는 push한 순서대로 적재되었다가 pop을 통하여 적재된 역순으로 출력된다.
*
*/
typedef struct {
	int size;
	int list[100];
} STACK;

void main(void)
{
	// # 1 배열로 구현
	STACK* pointer;
	pointer = (STACK*)malloc(sizeof(STACK));
	pointer->size = 0;

	printf("스택 사이즈 %d\n", sizeof(STACK));

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
		printf("가득참");
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
		printf("텅빔");
		return -1;
	}
	else
	{
		return pointer->list[--pointer->size];
	}
}
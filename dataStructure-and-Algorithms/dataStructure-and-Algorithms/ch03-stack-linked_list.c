#include <stdio.h>
#include <stdlib.h>
void push(struct STACK** head, int value);
int pop(struct STACK** head);

typedef struct stack {
	int data;
	struct stack* next;
} STACK;

void main(void)
{
	// # 2 링크드 리스트로 구현
	STACK* head;

	head = (STACK*)malloc(sizeof(STACK));
	head->next = NULL;

	push(&head, 10);
	push(&head, 20);
	push(&head, 30);
	push(&head, 40);

	printf("%d\n", pop (&head));
	printf("%d\n", pop(&head));
	printf("%d\n", pop(&head));
	printf("%d\n", pop(&head));
	printf("%d\n", pop(&head));

	free(head);
}

void push(STACK** head, int value)
{
	STACK* node = (STACK*)malloc(sizeof(STACK));

	if (node == NULL)
	{
		printf("공간없음\n");
	}
	else
	{
		node->data = value;
		node->next = *head;
		*head = node;
	}
}

int pop(STACK** head)
{
	if (*head == NULL)
	{
		printf("스택 언더플로우\n");
	}
	else
	{
		STACK* top = *head;
		int value = top->data;
		*head = top->next;
		free(top);
		return value;
	}
}
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "ch03-stack-node.h"

// ���� ���� (���� ����ü�� �޸� �Ҵ�)
STACK* stack_create(void)
{
	STACK* stack;
	stack = (STACK*)malloc(sizeof(STACK));

	if (stack)
	{
		stack->top = NULL;
		stack->count = 0;
	}
	return stack;
}

// ���� ���� (���� ����ü �޸𸮿��� ����)
STACK* stack_destroy(STACK* stack)
{
	NODE* node_temp;

	if (stack)
	{
		while (stack->count > 0)
		{
			free(stack->top->data);
			node_temp = stack->top;
			stack->top = stack->top->next;
			free(node_temp);
			(stack->count)--;
		}
		free(stack);
	}
	return NULL;
}

// ������ top�� push �Ѵ�.
int stack_push(STACK* stack, void* data_in)
{
	NODE* node_new;

	node_new = (NODE*)malloc(sizeof(NODE));
	if (!node_new)
	{
		return 0;
	}

	node_new->data = data_in;
	node_new->next = stack->top;

	stack->top = node_new;
	(stack->top)++;
	return 1;
}

// ���� top���� ������ ������
void* stack_pop(STACK* stack)
{
	void* data_out;

	NODE* node_temp;

	if (stack->count == 0)
	{
		data_out = NULL;
	}
	else
	{
		node_temp = stack->top;
		data_out = stack->top->data;
		stack->top = stack->top->next;
		free(node_temp);
		(stack->count)--;
	}
	return data_out;
}

void* stack_top(STACK* stack)
{
	if (stack->count == 0)
	{
		return NULL;
	}
	else
	{
		return stack->top->data;
	}
}

int stack_is_empty(STACK* stack)
{
	return (stack->count == 0);
}

int stack_is_full(STACK* stack)
{
	NODE* node_temp;

	if ((node_temp = (NODE*)malloc(sizeof(*(stack->top)))))
	{
		free(node_temp);
		return 0;
	}
	return 1;
}

int stack_count(STACK* stack)
{
	return stack->count; 
}
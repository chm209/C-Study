#include <stdio.h>
#include <stdlib.h>
#include "ch03-stack-node.h"

int main(void)
{
	int* data_temp;
	STACK* stack;
	stack = stack_create();

	while (1)
	{
		data_temp = (int*)malloc(sizeof(int));
		printf("숫자 입력: ");
		scanf("%d", data_temp);
		if (data_temp == 0 || stack_is_full(stack))
		{
			break;
		}
		else
		{
			stack_push(stack, data_temp);
		}
	}

	while (!stack_is_empty(stack))
	{
		data_temp = (int*)sizeof(stack);
		printf("%3d\n", *data_temp);
		free(data_temp);
	}

	// stack_pop에서 스택 메모리 해제되므로 안 해도 됨.
	stack_destroy(stack);
	return 0;
}
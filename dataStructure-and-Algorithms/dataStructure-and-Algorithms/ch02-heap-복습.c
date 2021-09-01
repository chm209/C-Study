#include <stdio.h>
void drawList(int list[], int list_size);
void heapsort(int list[], int list_size);

void main(void)
{
	int list[] = { 1, 9, 2, 8, 7, 3, 4, 6, 5, 10 };
	int list_size = sizeof(list) / sizeof(list[0]);

	printf("정렬 전: ");
	drawList(list, list_size);
	// 배열, 시작 번호, 끝 번호 전달
	heapsort(list, list_size);
	printf("정렬 후: ");
	drawList(list, list_size);
}

void drawList(int list[], int list_size)
{
	for (int i = 0; i < list_size; i++)
	{
		printf("%d ", list[i]);
	}
	printf("\n");
}

void heapsort(int list[], int list_size)
{
	for (int i = 1; i < list_size; i++)
	{
		int c = i;
		do
		{
			int root = (c - 1) / 2;
			if (list[root] < list[c])
			{
				int temp = list[root];
				list[root] = list[c];
				list[c] = temp;
			}
			c = root;
		} while (c != 0);
	}
}

void heapsort(int list[], int list_size)
{
	for (int i = 1; i < list_size; i++)
	{
		int c = i;
		do
		{
			int root = (c - 1) / 2;
			if (list[root] < list[c])
			{
				int temp = list[root];
				list[root] = list[c];
				list[c] = temp;
			}
			c = root;
		} while (c != 0);
	}

	for (int i = list_size - 1; i >= 0; i--)
	{
		int root = 0, c = 1;
		int temp = list[0];
		list[0] = list[i];
		list[i] = temp;

		do
		{
			c = 2 * root + 1;


			// for문에서 list_size-1은 배열 길이에서 -1을 해줘야 실제 마지막 배열이 나와서고
			// 밑에 if 문조건에 i-1을 하는 이유는 힙정렬에서 하나를 때버렸기 때문임
			// 왼쪽 오른쪽 비교해서 오른쪽이 더 크면 오른쪽으로 인덱스를 밈
			if (c < i - 1 && list[c] < list[c + 1])
			{
				c++;
			}

			// root랑 c랑 바꿔줌
			if (c < i && list[root] < list[c])
			{
				int temp = list[root];
				list[root] = list[c];
				list[c] = temp;
			}
			root = c;
			// 이제 다시 내려간 root를 아래랑 비교하는거임
		} while (c < i);
	}
}
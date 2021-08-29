#include<stdio.h>
void drawList(int list[], int list_size);
void merge_sort(int list[], int tmp[], int left, int right);
void merge(int list[], int tmp[], int left, int middle, int right);

void main(void)
{
	int list[] = { 1, 8, 2, 7, 3, 4, 6, 5, 9 };
	int list_size = sizeof(list) / sizeof(list[0]);
	int tmp[9];

	printf("정렬 전: ");
	drawList(list, list_size);
	merge_sort(list, tmp, 0, list_size - 1);
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

void merge_sort(int list[], int tmp[], int left, int right)
{
	int middle = 0;

	if (left < right)
	{
		middle = (left + right) / 2;
		merge_sort(list, tmp, left, middle);
		merge_sort(list, tmp, middle + 1, right);
		merge(list, tmp, left, middle, right);
	}
}

void merge(int list[], int tmp[], int left, int middle, int right)
{
	int part1 = left;
	int part2 = middle + 1;
	int index = left;

	while (part1 <= middle && part2 <= right)
	{
		if (list[part1] <= list[part2])
		{
			tmp[index++] = list[part1++];
		}
		else
		{
			tmp[index++] = list[part2++];
		}
	}

	if (part1 > middle)
	{
		for (int i = part2; i <= right; i++)
		{
			tmp[index++] = list[i];
		}
	}
	else
	{
		for (int i = part1; i <= middle; i++)
		{
			tmp[index++] = list[i];
		}
	}

	for (int i = left; i <= right; i++)
	{
		list[i] = tmp[i];
	}
}
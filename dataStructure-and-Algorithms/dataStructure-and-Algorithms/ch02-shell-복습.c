#include <stdio.h>
void drawList(int list[], int list_size);
void shellsort(int list[], int list_size);
void insertion_sort(int list[], int first, int last, int gap);

void main(void)
{
	int list[] = { 1,9,8,2,3,7,6,4,5 };
	int list_size = sizeof(list) / sizeof(list[0]);

	printf("정렬 전: ");
	drawList(list, list_size);
	shellsort(list, list_size);
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

void shellsort(int list, int list_size)
{
	for (int gap = list_size / 2; gap > 0; gap /= 2)
	{
		(gap % 2) == 0 ? gap++ : gap;

		// 갶 뒤에 숫자들에 관여하는애
		for (int i = 0; i < gap; i++)
		{
			insertion_sort(list, i, list_size-1, gap);
		}
	}
}

void insertion_sort(int list[], int first, int last, int gap)
{
	int key = 0, j = 0;

	// 여기서 갭 뒤에 숫자들, 갭 인덱스를 뒤로 밀어주는애
	for (int i = first + gap; i <= last; i += gap)
	{
		key = list[i];

		// 여기서 갭 앞에 숫자들 비교
		for (j = i - gap; j >= first && list[j] > key; j -= gap)
		{
			list[j + gap] = list[j];
		}
		list[j + gap] = key;
	}
}
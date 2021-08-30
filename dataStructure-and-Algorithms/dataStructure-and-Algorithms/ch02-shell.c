#include <stdio.h>
void drawList(int list[], int list_size);
void shellsort(int list[], int list_size);
void insertion_sort(int list[], int first, int last, int gap);

/* 셸정렬은 삽입 정렬을 보완한것이다.
* 8개의 요소를 가진 배열이 있다면 4, 2, 1 순으로 갭을 정해 갭을 기준으로 나눠진 파트들끼리 삽입 정렬을 해준다.
*/

void main(void)
{
	int list[] = { 1,9,8,2,3,7,6,4,5 };
	int list_size = sizeof(list) / sizeof(list[0]);

	printf("정렬 전: ");
	drawList(list, list_size);
	// 배열, 시작 번호, 끝 번호 전달
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

void shellsort(int list[], int list_size)
{
	// 갭은 배열의 중간으로 설정, 다 돌고 나면 갭을 다시 나누기 2 해서 계속 줄여나가다가 1까지만 함
	for (int gap = list_size / 2; gap > 0; gap = gap / 2)
	{
		// 갭이 짝수면 홀수로 만듬, 홀수로 해야 성능에 더 좋다고 함
		gap % 2 == 0 ? gap++ : gap;

		// 갭 갯수만큼 반복
		for (int i = 0; i < gap; i++)
		{
			// 배열, 현재 회차, 배열 길이, 갭 전달
			insertion_sort(list, i, list_size - 1, gap);
		}
	}
}

void insertion_sort(int list[], int first, int last, int gap)
{
	int key, j;

	// 갭만큼 반복
	// 갭이 5면 한번 반복하고 (지금 배열 기준)
	// 갭이 3이면 3번 반복
	for (int i = first + gap; i <= last; i = i + gap)
	{
		// 키값으로 갭 설정
		key = list[i];

		// 정렬
		for (j = i - gap; j >= first && list[j] > key; j = j - gap)
		{
			list[j + gap] = list[j];
		}
		list[j + gap] = key;
	}
}
#include <stdio.h>
void merge_sorter(int list[], int left, int right);
void merge(int list[], int left, int middle, int right);
// 임시 배열 전역변수
int sorted_list[9];

/* 병합 정렬
* 일단 전부 나눠서 정렬해오는 방법
* 책에 있는 코드가 너무 더러워서 예제 코드를 굳이 적지는 않겠음.
*/

void main(void)
{
	int list[] = { 9, 1, 8, 2, 7, 3, 4, 6, 5 };
	int array_size = sizeof(list) / sizeof(list[0]);

	printf("정렬전: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ", list[i]);
	}
	// 0 = 배열의 시작 , array_size-1 = 배열의 끝
	merge_sorter(list, 0, array_size - 1);
	printf("\n정렬후: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ", list[i]);
	}
}

void merge_sorter(int list[], int left, int right)
{
	int middle;

	if (left < right)
	{
		middle = (left + right) / 2; // 중간값 찾기
		merge_sorter(list, left, middle); // 중간값 기준 왼쪽으로 쪼개기
		merge_sorter(list, middle+1, right); // 중간값 기준 오른쪽으로 쪼개기
		merge(list, left, middle, right); // 병합
	}
}

void merge(int list[], int left, int middle, int right)
{
	int i = left; // 쪼갠 변수의 시작 주소를 위한 변수
	int j = middle + 1; // 병합할때 중간 기준으로 오른쪽 시작 주소를 위한 변수
	int k = left; // 임시 배열의 주소를 위한 변수

	// 작은 순서대로 정리
	while (i <= middle && j <= right)
	{
		if (list[i] <= list[j])
		{
			sorted_list[k] = list[i];
			i++;
		}
		else
		{
			sorted_list[k] = list[j];
			j++;
		}
		k++;
	}

	// 한쪽이 먼저 끝나면 반대쪽 남은거 삽입
	if (i > middle)
	{
		for (int t = j; t <= right; t++)
		{
			sorted_list[k] = list[t];
			k++;
		}
	}
	else
	{
		for (int t = i; t <= middle; t++)
		{
			sorted_list[k] = list[t];
			k++;
		}
	}

	// 임시 배열안에 있는걸 원래 배열에 복사
	for (int i = left; i <= right; i++)
	{
		list[i] = sorted_list[i];
	}
}
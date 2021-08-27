#include <stdio.h>
void ex01(void);
void pb1(void);
int bubble_sort(int array[], int left, int right);
void exchange(int array[], int num1, int num2);

void main(void)
{
	/*
	* 버블 정렬
	* 서로 인접한 것끼리 비교하면서 정렬 순서가 맞지 않으면 교환하는 방식으로 정렬한다.
	* 서로 붙어있는거 끼리만 비교한다고 착각했는데 0 1 2 3 4 있으면 0 1 비교 0 2 비교 0 3 비교 이런식으로 비교함
	*/

	printf("연습");
	ex01(); // 1,2,3,4 .. 좌-> 우 버블정렬
	pb1(); // 9, 8, 7, 6 .. 우 -> 좌 버블정렬
}

void exchange(int array[], int num1, int num2)
{
	int temp;

	temp = array[num1];
	array[num1] = array[num2];
	array[num2] = temp;
}

int bubble_sort(int array[], int left, int right) // 배열, 0, 9 넘어옴
{
	int num1, num2, num3 = 0;

	for(num1 = left ; num1 < right; num1++) // 0 ~ 8 까지 반복
	{
		for (num2 = num1 + 1; num2 < right; num2++) // num1 이 0부터 시작이라 - 0 ~ 8까지 반복함, 배열은 0부터 시작이니 전부 훑는거임
		{
			if (array[num1] > array[num2])
			{
				exchange(array, num1, num2);
			}
			num3++;
		}
	}
}

void ex01(void)
{
	int num1 = 0, num2 = 0;
	int array[] = { 2, 9, 4, 7, 1, 5 , 8, 3, 6 };
	int num3 = sizeof(array) / sizeof(array[0]); // 배열 요소 개수 알아냄

	num2 = bubble_sort(array, 0, num3);

	// 배열 출력
	for (num1 = 0; num1 < num3 - 1; num1++)
	{
		printf("%d", array[num1]);
	}
	printf("%d\n", num3);
}

int pb1_buuble_sorting(int array1[], int array_size)
{
	int count = 0;

	for (int i = 0; i < array_size; i++)
	{
		for (int j = i + 1; j < array_size; j++)
		{
			if (array1[i] < array1[j])
			{
				int temp = 0;
				temp = array1[i];
				array1[i] = array1[j];
				array1[j] = temp;
				count++;
			}
		}
	}
	return count;
}

void pb1(void)
{
	// 배열 선언
	int array1[] = { 9, 1, 4, 5, 8, 7, 3, 2, 6 };
	// 배열 요소 개수
	int array_size = sizeof(array1) / sizeof(array1[0]);
	// 정렬 횟수
	int count = 0;

	printf("정렬전: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ", array1[i]);
	}
	count = pb1_buuble_sorting(array1, array_size);
	printf("\n정렬후: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ", array1[i]);
	}
	printf("\n정렬 횟수: %d\n", count);
}
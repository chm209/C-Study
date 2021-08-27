#include <stdio.h>
void ex01(void);
int insertion_sort(int* array, int array_size);
void pb1(void);
int pb1_insertion(int array[], int array_size);
void pb2(void);
int pb2_insertion(int array[], int array_size);

void main(void)
{
	/* # 삽입 정렬
	* 정렬 대상이 소량일때 효율적이다.
	* 정렬 대상이 대량일때는 quick, heap, merge 정렬에 비해서 비효율적이다.
	* 장점
	* 1. 구현하기가 간단하다.
	* 2. 소량의 데이터 집합에 대해서 효율적이다.
	* 3. 입력 데이터가 이미 정렬된 순서라면 시간 복잡도가 O(n)으로 효율적이다.
	* 4. 정렬시 필요한 추가적인 공간이 O(1)만 있으면 되므로 메모리 낭비가 없다.
	* 5. 사람들이 손에 쥐고 있는 카드들을 순서대로 정렬하는 방법은 삽입 정렬과 유사하다.
	*/

	printf("연습");
	// ex01();
	// pb1();
	pb2(); // 반대로 정렬
}

int insertion_sort(int *array, int array_size)
{
	int k = 0, key = 0, count = 0;

	for (int i = 1; i < array_size; i++) // 0 ~ 8까지
	{
		key = array[i]; // 삽입할 값 집어넣고
		k = i - 1; //
		for (int i = 0; i < array_size; i++)
		{
			printf("%d ", array[i]);
		}
		printf("\n");
		while (k >= 0 && array[k] > key)
		{
			array[k + 1] = array[k];
			k--;
			count++;
			for (int i = 0; i < array_size; i++)
			{
				printf("%d ", array[i]);
			}
		}
		printf("key = %d, array[k] = %d\n", key, array[k]);
		array[k + 1] = key;
	}

	return count;
}

void ex01(void)
{
	int array[] = {2, 9, 7, 4, 8, 6, 5, 3, 1};
	int array_size = sizeof(array) / sizeof(array[0]);
	int* pointerArray = NULL, count = 0;

	pointerArray = array;
	printf("정렬전: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	count = insertion_sort(pointerArray, array_size);
	printf("\n정렬후: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n정렬 횟수: %d", count);
}

void pb1(void)
{
	int array[] = {9, 1, 8, 2, 7, 3, 4, 6, 5};
	int array_size = sizeof(array) / sizeof(array[0]);
	int count = 0;

	printf("정렬전: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ", array[i]);
	}
	count = pb1_insertion(array, array_size);
	printf("\n정렬후: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n정렬 횟수: %d", count);
}

pb1_insertion(int array[], int array_size)
{
	int count = 0, j = 0, temp = 0;

	for (int i = 1; i < array_size; i++)
	{
		temp = array[i];
		j = i - 1;
		// int array[] = {9, 1, 8, 2, 7, 3, 4, 6, 5}; temp가 1이고 j가 9임
		// int array[] = {1, 9, 8, 2, 7, 3, 4, 6, 5}; temp랑 j랑 바꿈
		// int array[] = {1, 8, 9, 2, 7, 3, 4, 6, 5}; temp가 8이고 j가 9였는데 j가 temp보다 커서 j를 temp 자리로 밀어넣음, 그리고 j-1을 했으니 다음 j는 1인데 1은 temp보다 작으니 바꿀 필요없음
		while (j >= 0 && array[j] > temp) // array[j] 가 temp보다 큰지도 검사하는 이유는 어차피 작은숫자대로 정렬해가는데 array[j]가 temp보다 작으면 바꿀 이유가 없어서
		{
			array[j + 1] = array[j]; // array[i]가 아닌 이유는 여기서 i는 temp에만 값을 주기 위해 존재, 비교는 temp랑 j만 씀
			// i를 써버리면 107번줄에서 만약에 10, 9, 8 이렇게 있다고 가정하면 9랑 8 바뀌고 8이랑 10 비교해서 10이 크기 때문에 9 들어갔는데 10 들어가기 때문에 문제 생김
			j--; // -1을 해주는 이유는 삽입 정렬은 배열기준 2번이 키값이면 1, 0 번과 비교하는거처럼 좌측 요소들과 비교해가기 때문
			count++;
		}
		array[j + 1] = temp; // j+1번 자리에 값을 저장하는 이유는 위에서 비교할때 조건이 temp보다 클때만 교체하도록 하는데 이미 저번 회전에서 j-1을 해버렸기 때문에 +1 해준 자리에 값을 저장함
	}
	return count;
}

void pb2(void)
{
	int array[] = { 9, 1, 8, 2, 7, 3, 4, 6, 5 };
	int array_size = sizeof(array) / sizeof(array[0]);
	int count = 0;

	printf("정렬전: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ", array[i]);
	}
	count = pb2_insertion(array, array_size);
	printf("\n정렬후: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n정렬 횟수: %d", count);
}

pb2_insertion(int array[], int array_size)
{
	int count = 0, j = 0, key = 0;

	for (int i = 1; i < array_size; i++)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] < key)
		{
			array[j+1] = array[j];
			j--;
			count++;
		}
		array[j + 1] = key;
	}
	return count;
}
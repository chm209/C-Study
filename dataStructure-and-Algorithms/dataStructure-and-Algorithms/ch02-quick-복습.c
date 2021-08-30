#include <stdio.h>
void drawList(int list[], int list_size);
void quicksort(int list[], int left, int right);

/* 퀵정렬은 임의값을 기준으로 기준값보다 작은애들은 왼쪽 큰애들은 오른쪽으로 정렬
* 갈라진 왼쪽, 오른쪽에서도 각각 기준값을 설정 마찬가지로 기준값보다 작은애들은 왼쪽 큰 애들은 오른쪽으로 정렬하는걸 반복한다.
* 그렇게 반복하다 보면 정렬이 끝난다.
*/

void quicksort(int list[], int left, int right)
{
	int part1 = left;
	int part2 = right;
	int pivot = list[(left + right) / 2];  // 기준값은 그냥 리스트의 중간으로 설정

	// 왼쪽 오른쪽이 서로 중간으로 몰리는데 위치가 역전되는지 검사
	// 갈라주는 역할이라고 생각
	while (part1 <= part2)
	{
		// 왼쪽부터 기준값보다 작은지 검사
		// 기준값보다 작으면 index를 계속 +1 해서 검사를 하는데
		// 기준값보다 크면 일단 멈춤
		while (list[part1] < pivot)
		{
			part1++;
		}
		// 오른쪽 끝에서 기준값보다 큰지 검사
		// 기준값보다 크면 index를 계속 -1 해서 검사한다
		// 기준값보다 작으면 멈춤
		while (list[part2] > pivot)
		{
			part2--;
		}

		// 왼쪽, 오른쪽 위치가 아직 역전 상태인지 검사
		// 이걸 안해주면 기준값 왼쪽으로 이미 작은값들이 몰려있는데 큰지 검사하는 애가 들어와서 위치를 바꿔버리기 때문
		if (part1 <= part2)
		{
			// swap 해줌
			int temp = list[part1];
			list[part1] = list[part2];
			list[part2] = temp;
			// 서로 바꿨으니 index를 각각 +1, -1 해줌
			part1++;
			part2--;
		} 
	}

	//             ↓ part2
	// □□□□■□□□□
	//                     ↑ part1
	// 중간값 기준으로 이렇게 정리했는데
	// index가 저렇게 있는거임
	// 왼쪽으로 한번더 갈라서 정리해야하니 left = 0, part2까지는 기준값전
	// 이렇게 갈라서 □■□□
	// 다시 정렬하고 가르고 정렬하고를 1개만 남을때까지 반복하는거임
	if (left < part2)
	{
		quicksort(list, left, part2);
	}
	// 얘도 마찬가지임 part1이 기준값+1이고 right가 마지막이니
	// 가르고 정렬하고 가르고 정렬하고를 끝까지가서 1개만 남을때까지 반복하는거임
	if (part1 < right)
	{
		quicksort(list, part1, right);
	}
}

void main(void)
{
	int list[] = { 1,9,8,2,3,7,6,4,5 };
	int list_size = sizeof(list) / sizeof(list[0]);

	printf("정렬 전: ");
	drawList(list, list_size);
	// 배열, 시작 번호, 끝 번호 전달
	quicksort(list, 0, list_size - 1);
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
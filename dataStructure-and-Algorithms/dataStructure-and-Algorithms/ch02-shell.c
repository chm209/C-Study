#include <stdio.h>
void drawList(int list[], int list_size);
void shellsort(int list[], int list_size);
void insertion_sort(int list[], int first, int last, int gap);

/* 셸정렬은 삽입 정렬을 보완한것이다.
* 8개의 요소를 가진 배열이 있다면 4, 2, 1 순으로 갭을 정해 갭을 기준으로 나눠진 파트들끼리 삽입 정렬을 해준다.
*/

void main(void)
{
	int list[] = { 1,9,8,2,3,7,6,4,5, 10 };
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

	// 갭 만큼 반복함, 갭이 2면 2,4,6,8 까지 4번 반복함
	// 방금 first 없어도 멀쩡하게 돌아는가는데 왜 굳이 first를 더하지 라고 생각 했는데
	// shellsort 함수에 insertion_sort 호출할때 반복문 보셈 fisrt값 변함
	// 그럼 없어도 왜 돌아는 가는가? 최종 갭이 1이기 때문
	for (int i = first + gap; i <= last; i = i + gap)
	{
		// 키 값으로 갭번째 값을 설정
		key = list[i];

		// 갭이 2이라고 가정하고 이미 두번 반복했다고 하면
		// 다음 키값은 6번째가 들어가있음
		// 즉 0번째, 2번째,  4번째랑 6번째가 비교하는데
		// 6번째 4번째, 6번째 2번째, 6번째 0번째 순으로 비교함
		for (j = i - gap; j >= first && list[j] > key; j = j - gap)
		{
			// 4번째가 6번째보다 클때 실행하는데 레코드를 6번째를 가르키게 해서 4번째 값을 집어 넣음
			// 즉 레코드를 gap 만큼 이동시키는거임
			list[j + gap] = list[j]; 
		}
		// 6번째에 4번째 값을 집어 넣었으니 key 안에 저장한 6번째 값을
		// 4번째에 넣는거임 (2번째 0번째가 더 작다는 가정하에)
		// 순간 j+gap이 6번째였는데 왜 4번째? 라고 생각했는데 for문 탈출하기 전에 j에서 2를 뺌
		// 즉 4가 2로 떨어져서 내려와서 다시 2를 더하니 4번째임
		list[j + gap] = key;
		// 지금 궁금한점
		// 키값이 6번째인데 4번째 2번째가 크면 어캄?
		// 6번째자리에 0번째를 넣고 내려오면 2번째랑 4번째는 그대로아님?
		// for 문 조건을 잘볼것. 6번째 자리에 4번째 값 넣고 나서 j = 4 - 2를 함
		// 다시 내려오묜 2 + 2 = 4번째자리에 2번째 값을 넣음 그리고 나서 j = 2-2를 함
		// 조건에서 0번째는 6번째보다 작으니깐 홀드하고 내려오면 2번째자리에 원래 6번째가 저장된 키값을 넣음
		// 
	}
}
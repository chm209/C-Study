#include <stdio.h>
void drawList(int list[], int list_size);
void heapsort(int list[], int list_size);

// 병합 정렬과 퀵 정렬 만큼 빠른 정렬 알고리즘
// 고급 프로그래밍 기법으로 갈 수록 힙의 개념이 자주 등장하기 때문에 반드시 알고 넘어가야 할 정렬 알고리즘
// 힙 정렬은 힙 트리 구조를 이용하는 정렬 방법이다.
// 1. 정렬해야 할 n개의 요소들로 최대 힙을(완전 이진 트리 형태) 만든다.
// 2. 그 다음으로 한 번에 하나씩 요소를 힙에서 꺼내서 배월의 뒤부터 저장하면 된다.
// 3. 삭제되는 요소들은 값이 감소되는 순서로 정렬되게 된다.


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
	// 힙 구성
	for (int i = 1; i < list_size; i++)
	{
		//                                  0
		//						  1                   2
		//                  3        4          5            6    
		//              7    8  9     10
		// for문 대충 돌려보면 0,1 / 0,2 / 1.3 -> 1,0 / 1,4 -> 1,0 이렇게 비교해가면서 힙 트리를 구성함
		// 트리 구성까지만 적용해서 돌려보면 10이 제일 위에 있는데 제일 최상층까지 비교해서 올라가는거임
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
	
	// 힙 트리를 구성하면 root에 가장 큰 값이 위치한다.
	// root 값을 배열의 마지막에 추가하고 트리의 제일 마지막 값을 root 값에 추가해준다.
	// 그리고 다시 부모자식간에 값 비교를 통해 root를 구성해주고
	// 배열 크기만큼 반복해준다.

	// 크기를 줄여가며 반복적으로 힙을 구성
	for (int i = list_size - 1; i >= 0; i--)
	{
		int root = 0, c = 1;
		int temp = list[0];
		list[0] = list[i];
		list[i] = temp;

		do
		{
			// C = 1
			// C = 2
			// root 2
			// C = 5
			// C = 5
			// root 5
			// C = 11 
			c = 2 * root + 1;

			// 자식들중에 더 큰값 검색
			// 0번은 root라서 1부터 시작함
			// 방금 0 / 1 2/ 3456 구조에서 1보다5가 더크면 어쩜이라고 생각했는데
			// 5가 1보다 컸으면 2도 5보다 커서 문제없음
			//  그리고 밑에 if문은 1,2 / 3,4 처럼 서로 붙어있는 애들끼리 비교한거임
			// 그리고 힙 트리 구성하면서 조금은 정렬했기 때문에 문제없
			if (c < i - 1 && list[c] < list[c + 1])
			{
				c++;
			}

			// 루트와 자식 노드끼리 비교해서 위치 변경
			if (c < i && list[root] < list[c])
			{
				int temp = list[root];
				list[root] = list[c];
				list[c] = temp;
			}
			// 루트와 자식을 바꿨으면 바뀐 자식과 그 자식의 자식도 비교를 하기 위해 root에 c를 대입
			// 트리 구성할때 같은 동작함
			root = c;
		} while (c < i);
	}
}
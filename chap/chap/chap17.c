#include <stdio.h>
#include <stdlib.h>

void ex1(void);
void ex2(void);
int* ex2Func(int num, ...);
void ex3(void);
void pb1(void);
int* pb1Func(int num);

void main()
{
	/* # 동적 메모리 할당과 가변 인자
	* 정적 메모리: 언제 할당되고 해제될지, 요구되는 메모리의 크기는 컴파일할 때 결정된다.
	* ㄴ 프로그램 실행중에 메모리의 크기를 변경하는 것이 불가능하다.
	* 동적 메모리 (힙 영역)
	* --- 동적 메모리 할당의 필요성
	* ㄴ 배열에서 크게 느낌 / 배열은 고정된 메모리를 할당받는데, 이에 대한 단점
	* 1. 선언된 배열 요소의 수가 사용된 요소 수보다 많은 경우 메모리의 낭비 발생
	* 2. 선언된 배열 요소의 수가 사용된 요소 수보다 작은 경우 메모리의 부족 에러 발생
	* 3. 배열 선언 시 배열 길이에 변수를 설정한 경우 에러 발생 (상수를 사용해야 함)
	* --- 메모리 할당 함수 stdlib.h
	* malloc() / calloc() / realloc() / free()
	* malloc() = 힙 영역에 동적 메모리를 할당하는 함수
	* ㄴ 호출 성공 시 메모리의 시작 주소를 반환하고 호출 실패(할당할 메모리 공간이 없는 경우)시 NULL을 반환 한다.
	* ㄴ 입력 형태가 size_t 는 typedef로 재정의해서 만들어진 사용자 정의 자료형이다. unsigned long이나 unsigned int 이기 때문에 0 보다 큰 정수를 입력해야 한다.
	* ㄴ 출력 형태는 void* 라서 어떤 자료형의 주소인지 결정하지 못하기 때문에 사용자가 필요한 자료형으로 형번환을 해야 한다.
	* free () = malloc() 함수를 통해 동적 메모리가 할당된 공간을 해제한다.
	* calloc() = malloc() 함수와 같은 기능을 한다. 사용 방법은 약간 다르다.
	* realloc() = malloc 함수와 calloc 함수는 동적 메모리를 할당한 후에 메모리의 크기를 변경하지 못한다. realloc은 가능
	* ㄴ 동적 메모리로 할당되어 있는 영역에서 size 만큼 재할당 해준다. 재할당된 메모리의 시작 주소를 반환한다.
	* --- 가변 인자
	* 함수 인자 수를 고정하지 않고 함수를 호출할 수 있는 방법이다.
	*/
	printf("테슷트 \n");
	// ex1();
	// ex2();
	printf("연습문제 1\n");
	pb1();
}

void ex1()
{
	int* p1 = (int*)calloc(1, sizeof(int)); // 1 * 4 만큼의 크기를 할당한다는 뜻
	int* p2 = (int*)malloc(4); // 4바이트 만큼의 크기를 할당한다는 뜻

	p1 = (int*)realloc(p1, sizeof(int) * 4); // 16바이트 재할당

	printf("p1: %d", p1); // calloc은 자동으로 0으로 초기화 한다. 다만 시간 낭비를 유발할 수 있다.
	printf("p2: %d", p2); // malloc은 자동으로 초기화하지 않는다.

	free(p1); // 할당한 메모리 해제
	p1 = NULL; // p1에 NULL을 가르키게함

	free(p2);
	p2 = NULL;
}

void ex2()
{
	int a = 4;
	int* point1 = NULL;

	point1 = ex2Func(1, a); // 가변인자 함수에 a를 넘김
	point1[0] = 10;
	printf("4바이트 힙 영역에 저장된 값: %d\n", point1[0]);

	free(point1);
	point1 = NULL;
}

int* ex2Func(int num, ...)
{
	int* point2 = &num + 1; // point2 포인터 변수에 num 주소에 + 1한 (4바이트) 주소를 할당함
	static int* heap = NULL; // return 값을 위한 포인터 변수

	if (num == 1)
	{
		heap = (int*)malloc(point2[0]); // point2[0]에 들어있던건 int형 변수의 주소 즉 4바이트를 int형에 할당할 수 있게 형변환 해서 heap에게 4바이트 만큼 동적 메모리를 할당함
		return heap; // 돌려보냄
	}
	else
	{
		printf("인자의 개수가 1개 이하 입니다.\n");
		return NULL;
	}
}

void pb1()
{
	int num = 0;
	int* point = NULL;

	printf("필요한 메모리 공간: ");
	scanf("%d", &num);

	point = pb1Func(num);
	printf("%d", _msize(point)); 
	// 힙 영역의 바이트 크기를 확인하는 함수는 _msize가 있는데 이는 VS에서만 지원하는 비공식 함수

	free(point);
	point = NULL;
}

int* pb1Func(int num)
{
	static int* heap = NULL;
	heap = (int*)malloc(num);

	return heap;
}
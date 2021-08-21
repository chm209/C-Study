#include <stdio.h>
void ex1(void);
void ex01Func(int(*p)[4], int num1, int num2);
void ex2(void);
void pb1(void);
void pb1_func(char c, char* str, int num1, double num2);
void pb2(void);
void pb2_func(int* array1, int* array2);
void pb3(void);
pb3_swap(int*, int);
void pb4(void);
void* add(int num1, int num2);
void* subtract(int a, int b);
void* multiply(int a, int b);
void* divide(int a, int b);

void main()
{
	/* # 포인터 함수 그리고 void형 포인터
	* 값에 의한 호출: 변수 (메모리 공간에 저장된 값) 또는 값을 복사해서 함수 호출
	* 주소에 의한 호출: 주소(메모리 공간의 주소)를 참조해서 함수 호출
	* EX) func(a) -> func(int i) { i+= i;} 변수 a에 저장한 값은 10인데, 10을 변수i로 복사해서 함수 func(int)를 호출한다. // 값에 의한 호출
	* EX) func(&a) -> func(int* i) { i+= i;} a의 주소를 저장한 포인터 변수 i를 통해 func() 함수에서도 변수 a에 저장된 값을 참조하거나 변경할 수 있다.
	* 주소에 의한 호출의 필요성 -> 값에 의한 호출을 할때 함수에 대량의 데이터를 전달해야 하는 경우, 함수의 매개변수들이 늘어나서 이들이 하나하나 스택 영역에 쌓이는데 많은 시간과 메모리 공간을 필요로 한다.
	* func(array, sizeof(array)/sizeof(int)) -> func(int* p, int num) => 배열의 주소를 전달하고 배열의 크기를 전달한다. 배열의 크기는 int 하나는 4바이트, 배열의 요소가 6개가 있다고 하면 6*4 = 24, 24를 int형 4바이트로 나눠주면 6. 요소의 개수가 나옴
	* sizeof(array) / 4 도 가능함
	* 배열 포인터를 이용한 주소에 의한 함수 호출
	* func(array, sizeof(array) / 16, sizeof(array) / 8) -> void func(int (*p)[4], int num1, int num2)
	*            ↑ 시작주소         ↑ 행                      ↑ 열
	* 다차원 배열을 배열 포인터 말고 포인터 변수에 저장했을 경우 출력할때 p[6], p[7] 이런식으로 출력해야함, p[1][2] 이런거 못함
	*  === 주소를 반환하는 함수
	* ## 주소 반환의 필요성과 주의 사항
	* 1. 배열이나 문자열과 같이 대량의 데이터를 반환할 때는 주소를 반환하는 함수를 사용한다.
	* 2. 지역 변수의 주소를 반환하면 경고가 발생한다. 이유는 함수가 종료되면서 지역 변수는 소멸되기 때문에 주소 또한 날아가기 때문이다.
	* 3. static 변수는 함수가 종료된 후에도 메모리 공간이 쇼멸되지 않고 남아 있기 때문에 진역 변수의 주소를 반환해서 생기는 문제를 해결할 수 있다.
	* main 함수에 인자가 있을 경우 예제는 13-1을 참고
	* void형 포인터 -> 자료형이 없는 포인터 변수, 즉 자료형에 제약을 받지 않고 아무 자료형의 주소라도 저장할 수 있는 포인터 변수
	* void형 포인터 변수는 주소만 저장할 수 있다. 값을 저장하거나 변경할 수 없다. 출력도 못함
	* 출력하고 싶으면 강제 형변환을 거쳐야함
	* ===== 정리
	* 1. 모든 자료형의 주소를 저장할 수 있는 자유로운 포인터
	* 2. void형 포인터를 통해 주소가 아닌 값을 참조할 수는 없다. 값을 참조하려면 강제 형변환을 해야 한다.
	*/
	printf("테슷트 \n");
	//ex1();
	//ex2();
	printf("연습문제 1\n");
	pb1();
	printf("\n연습문제 2\n");
	pb2();
	printf("\n연습문제 3\n");
	pb3();
	printf("\n연습문제 4\n");
	pb4();
}

void ex1()
{
	int array[2][4] = {10, 20, 30, 40, 50, 60, 70, 80};
	ex01Func(array, sizeof(array) / 16, sizeof(array) / 8);
}

void ex2()
{
	char c = 3;
	double d = 3.1;
	void* vx = NULL;
	vx = &c;
	printf("vx의 주소 값: %x\n", vx);
	// printf("vx의 값: %d\n", vx); // 에러남

	vx = &d;
	printf("vx의 주소 값: %x\n", vx);
	// printf("vx의 값: %lf\n", vx); // 에러남

	vx = &c;
	printf("vx의 주소 값: %x\n", vx);
	printf("vx의 값: %d\n", *(char*)vx);

	vx = &d;
	printf("vx의 주소 값: %x\n", vx);
	printf("vx의 값: %lf\n", *(double*)vx);
}

void ex01Func(int(*p)[4], int num1, int num2)
{
	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < num2; j++)
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
}

void pb1()
{
	char c = 'A';
	char* str = "ABCD";
	int num1 = 0;
	double num2 = 3.14;

	pb1_func(c, str, num1, num2);
}

void pb1_func(char c, char* str, int num1, double num2)
{
	
}

void pb2()
{
	int array1[4] = { 10, 20 ,30, 40 };
	int array2[4] = { 50, 60, 70, 80 };

	pb2_func(array1, array2);
}

void pb2_func(int* array1, int* array2)
{
	printf("%d %d %d %d\n", *(array1+0), *(array1 + 1), *(array1 + 2), *(array1 + 3));
	printf("%d %d %d %d\n", *(array2 + 0), *(array2 + 1), *(array2 + 2), *(array2 + 3));
 }

void pb3()
{
	int array[8] = { 1,2,3,4,5,6,7,8 };

	pb3_swap(array, sizeof(array) / sizeof(int));
}

pb3_swap(int* array, int num)
{
	int temp = 0, temp2 = 0;
	printf("실행 전: %d %d %d %d %d %d %d %d\n", *(array+0), *(array + 1), *(array + 2), *(array + 3), *(array + 4), *(array + 5), *(array + 6), *(array + 7));

	for (int i = 8; i > 0; i--)
	{
		if (i != 1)
		{
			temp = *(array + i - 1);
			*(array + i - 1) = *(array + i - 2);
			*(array + i - 2) = temp;
		}
	}
	printf("실행 후: %d %d %d %d %d %d %d %d\n", *(array + 0), *(array + 1), *(array + 2), *(array + 3), *(array + 4), *(array + 5), *(array + 6), *(array + 7));
}

void pb4()
{
	int num1, num2;

	printf("입력: ");
	scanf("%d %d", &num1, &num2);

	add(num1, num2);
	subtract(num1, num2);
	multiply(num1, num2);
	divide(num1, num2);
}

void* add(int a, int b)
{
	printf("%d + %d = %d\n", a, b, a + b);
}

void* subtract(int a, int b)
{
	printf("%d - %d = %d\n", a, b, a - b);
}

void* multiply(int a, int b)
{
	printf("%d * %d = %d\n", a, b, a * b);
}

void* divide(int a, int b)
{
	printf("%d / %d = %d\n", a, b, a / b);
}
#include <stdio.h>
void ex01(void);
long ex01FIB(long num);
void ex02(void);
void* larger(void* pointer1, void* pointer2, int(*pfn_compare)(void*, void*));
int compare_int(void* pointer1, void* pointer2);
int compare_float(void* pointer1, void* pointer2);

void main(void)
{
	/*
	* 알고리즘 공부를 위한 필수 기능 복습
	* 반복(생략), 재귀, 포인터
	* 생각해보니깐 저번 책에서 풀었던 토끼 문제가 피보나치수열이었음
	*/

	printf("연습");
	// ex01();
	ex02();
}

long ex01FIB(long num)
{
	if (num == 0 || num == 1)
	{
		return num;
	}
	return(ex01FIB(num - 1) + ex01FIB(num - 2));
}

void ex01(void)
{
	int num = 10;

	printf("재귀함수를 이용한 피보나치 수열\n");
	for (int i = 0; i < num; i++)
	{
		printf("%6ld\n", ex01FIB(i));
	}
}

int compare_int(void* pointer1, void* pointer2)
{
	if (*(int*)pointer1 >= *(int*)pointer2)
		return 1;
	else
		return -1;
}

int compare_float(void* pointer1, void* pointer2)
{
	if (*(float*)pointer1 >= *(float*)pointer2)
		return 1;
	else
		return -1;
}

void* larger(void* pointer1, void* pointer2, int(*pfn_compare)(void*, void*))
{
	if ((*pfn_compare)(pointer1, pointer2) > 0)
		return pointer1;
	else
		return pointer2;
}

void ex02(void)
{
	int num1 = 7, num2 = 8, result = 0;
	// 매개변수로 함수 포인터를 넘김
	result = (*(int*)larger(&num1, &num2, compare_int));
	printf("더 큰수: %d\n", result);

	float num3 = 3.1415, num4 = 2.7182, result2 = 0;
	result2 = (*(float*)larger(&num3, &num4, compare_float));
	printf("더 큰수: %f\n", result2);
}
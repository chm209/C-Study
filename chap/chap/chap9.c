#include <stdio.h>
void pb1(void);
void pb2(void);

void main()
{
	/* 참고: https://andjjip.tistory.com/226
	* C언어에서 char 배열로 string을 만들경우 배열의 마지막에 0 (Null) 이 들어가야 쓰레기 값이 안 나온다.
	* 마지막에 null 이 없으면 메모리에서 00이 나올때까지 쓰레기값을 출력하다가 끝냄
	*/
	printf("연습문제 1\n");
	pb1();
	printf("\n연습문제 2\n");
	pb2();
}

void pb1()
{
	char array[7] = {"ABCdef"};
	array[6] = 0;
	array[3] = *array+2;
	array[4] = *array+1;
	array[5] = *array+0;
	printf("%s", array);
}

void pb2()
{
	int array1[5] = {90, 78, 77, 98, 98};
	int array2[5] = {80, 45, 67, 88, 57};
	int array3[5] = {88, 99, 65, 55, 74};

	printf("가로합: %d %d %d", *&array1[0] + *&array1[1] + *&array1[2] + *&array1[3] + *&array1[4], *&array2[0] + *&array2[1] + *&array2[2] + *&array2[3] + *&array2[4], *&array3[0] + *&array3[1] + *&array3[2] + *&array3[3] + *&array3[4]);
	printf("세로합: %d %d %d %d %d", array1[0] + array2[0] + array3[0], array1[1] + array2[1] + array3[1], array1[2] + array2[2] + array3[2], array1[3] + array2[3] + array3[3], array1[4] + array2[4] + array3[4]);
}
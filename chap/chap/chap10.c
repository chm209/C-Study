#include <stdio.h>
void ex1(void);
void pb1(void);
void pb2(void);
void pb3(void);
void pb4(void);

void main()
{
	/* 1차원 배열에서는 *(array+1)은 해당 배열의 값을 참조한다는 의미
	*  2차원 배열에서는 *(array+1)은 해당 배열의 주소를 참도한다는 의미
	*  **(array+0)은 주소에 저장된 값을 참조한다는 의미 -> *array+0 으로 주소 참조 -> * 하나더로 값 참조
	*  & 로 주소 뽑을때는 array[0][0]으로 맞춰줘야 하는듯
	* **(array+1)+1 과 *( *(array+1)+1)은 다름 / 첫번째는 array+1 값에서 +1 하는것 / 두번째는 array[1][1] 주소의 값을 불러 오는것
	*/
	printf("테슷트 \n");
	ex1();
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
	int array[2][2] = { 10, 20, 30, 40 };

	printf("%x \n", array + 1);
	printf("%x \n", *(array + 1));
	printf("%x \n", *array);
	printf("%x \n", *array + 1);
	printf("%d \n", **(array + 1));
	printf("%d \n", **(array + 1) + 1);
	printf("%d \n", *(*(array + 1) + 1));
	printf("%x \n", &array[0][0]);
}

void pb1()
{
	int array1[2][4] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int array2[4][2];

	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			if (k == 0)
				array2[i][k + 1] = array1[k][i];
			else
				array2[i][k - 1] = array1[k][i];
		}
	}

	printf("%d %d %d %d\n%d %d %d %d\n", array1[0][0], array1[0][1], array1[0][2], array1[0][3], array1[1][0], array1[1][1], array1[1][2], array1[1][3]);
	printf("%d %d\n%d %d\n%d %d\n%d %d", array2[0][0], array2[0][1], array2[1][0], array2[1][1], array2[2][0], array2[2][1], array2[3][0], array2[3][1]);
}

void pb2()
{
	int array[8][9] = { 0 };

	for (int i = 2; i < 10; i++)
	{
		for (int k = 1; k < 10; k++)
		{
			array[i - 2][k - 1] = i * k;
			printf("%d * %d = %d\n", i, k, array[i - 2][k - 1]);
		}
		printf("\n");
	}
}

void pb3()
{
	int array1[4][3] = { 23, 75, 85, 12, 77, 51, 25, 66, 30, 19, 90, 88 };
	int array2[4][3] = { 11, 15, 47, 74, 85, 69, 57, 86, 28, 90, 22, 33 };

	for (int i = 0; i < 4; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			printf("%d행 %d열 합: %d / 차: %d\n", i, k, *(*(array1 + i) + k) + *(*(array2 + i) + k), *(*(array1 + i) + k) - *(*(array2 + i) + k));
		}
	}
}

void pb4()
{
	int array[2][3] = { 1,2,3,4,5,6 };

	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 3; k++)
		{
			printf("%d행 %d열 주소: %x 값: %d\n", i, k, *(array+i)+k, *(*(array + i) + k));
		}
	}
}
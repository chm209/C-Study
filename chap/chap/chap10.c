#include <stdio.h>
void ex1(void);
void pb1(void);
void pb2(void);
void pb3(void);
void pb4(void);

void main()
{
	/* 1���� �迭������ *(array+1)�� �ش� �迭�� ���� �����Ѵٴ� �ǹ�
	*  2���� �迭������ *(array+1)�� �ش� �迭�� �ּҸ� �����Ѵٴ� �ǹ�
	*  **(array+0)�� �ּҿ� ����� ���� �����Ѵٴ� �ǹ� -> *array+0 ���� �ּ� ���� -> * �ϳ����� �� ����
	*  & �� �ּ� �������� array[0][0]���� ������� �ϴµ�
	* **(array+1)+1 �� *( *(array+1)+1)�� �ٸ� / ù��°�� array+1 ������ +1 �ϴ°� / �ι�°�� array[1][1] �ּ��� ���� �ҷ� ���°�
	*/
	printf("�׽�Ʈ \n");
	ex1();
	printf("�������� 1\n");
	pb1();
	printf("\n�������� 2\n");
	pb2();
	printf("\n�������� 3\n");
	pb3();
	printf("\n�������� 4\n");
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
			printf("%d�� %d�� ��: %d / ��: %d\n", i, k, *(*(array1 + i) + k) + *(*(array2 + i) + k), *(*(array1 + i) + k) - *(*(array2 + i) + k));
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
			printf("%d�� %d�� �ּ�: %x ��: %d\n", i, k, *(array+i)+k, *(*(array + i) + k));
		}
	}
}
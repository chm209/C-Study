#include <stdio.h>
void ex01(void);
void pb1(void);
int bubble_sort(int array[], int left, int right);
void exchange(int array[], int num1, int num2);

void main(void)
{
	/*
	* ���� ����
	* ���� ������ �ͳ��� ���ϸ鼭 ���� ������ ���� ������ ��ȯ�ϴ� ������� �����Ѵ�.
	* ���� �پ��ִ°� ������ ���Ѵٰ� �����ߴµ� 0 1 2 3 4 ������ 0 1 �� 0 2 �� 0 3 �� �̷������� ����
	*/

	printf("����");
	ex01(); // 1,2,3,4 .. ��-> �� ��������
	pb1(); // 9, 8, 7, 6 .. �� -> �� ��������
}

void exchange(int array[], int num1, int num2)
{
	int temp;

	temp = array[num1];
	array[num1] = array[num2];
	array[num2] = temp;
}

int bubble_sort(int array[], int left, int right) // �迭, 0, 9 �Ѿ��
{
	int num1, num2, num3 = 0;

	for(num1 = left ; num1 < right; num1++) // 0 ~ 8 ���� �ݺ�
	{
		for (num2 = num1 + 1; num2 < right; num2++) // num1 �� 0���� �����̶� - 0 ~ 8���� �ݺ���, �迭�� 0���� �����̴� ���� �ȴ°���
		{
			if (array[num1] > array[num2])
			{
				exchange(array, num1, num2);
			}
			num3++;
		}
	}
}

void ex01(void)
{
	int num1 = 0, num2 = 0;
	int array[] = { 2, 9, 4, 7, 1, 5 , 8, 3, 6 };
	int num3 = sizeof(array) / sizeof(array[0]); // �迭 ��� ���� �˾Ƴ�

	num2 = bubble_sort(array, 0, num3);

	// �迭 ���
	for (num1 = 0; num1 < num3 - 1; num1++)
	{
		printf("%d", array[num1]);
	}
	printf("%d\n", num3);
}

int pb1_buuble_sorting(int array1[], int array_size)
{
	int count = 0;

	for (int i = 0; i < array_size; i++)
	{
		for (int j = i + 1; j < array_size; j++)
		{
			if (array1[i] < array1[j])
			{
				int temp = 0;
				temp = array1[i];
				array1[i] = array1[j];
				array1[j] = temp;
				count++;
			}
		}
	}
	return count;
}

void pb1(void)
{
	// �迭 ����
	int array1[] = { 9, 1, 4, 5, 8, 7, 3, 2, 6 };
	// �迭 ��� ����
	int array_size = sizeof(array1) / sizeof(array1[0]);
	// ���� Ƚ��
	int count = 0;

	printf("������: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ", array1[i]);
	}
	count = pb1_buuble_sorting(array1, array_size);
	printf("\n������: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ", array1[i]);
	}
	printf("\n���� Ƚ��: %d\n", count);
}
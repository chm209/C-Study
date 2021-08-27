#include <stdio.h>
void ex01(void);
int insertion_sort(int* array, int array_size);
void pb1(void);
int pb1_insertion(int array[], int array_size);
void pb2(void);
int pb2_insertion(int array[], int array_size);

void main(void)
{
	/* # ���� ����
	* ���� ����� �ҷ��϶� ȿ�����̴�.
	* ���� ����� �뷮�϶��� quick, heap, merge ���Ŀ� ���ؼ� ��ȿ�����̴�.
	* ����
	* 1. �����ϱⰡ �����ϴ�.
	* 2. �ҷ��� ������ ���տ� ���ؼ� ȿ�����̴�.
	* 3. �Է� �����Ͱ� �̹� ���ĵ� ������� �ð� ���⵵�� O(n)���� ȿ�����̴�.
	* 4. ���Ľ� �ʿ��� �߰����� ������ O(1)�� ������ �ǹǷ� �޸� ���� ����.
	* 5. ������� �տ� ��� �ִ� ī����� ������� �����ϴ� ����� ���� ���İ� �����ϴ�.
	*/

	printf("����");
	// ex01();
	// pb1();
	pb2(); // �ݴ�� ����
}

int insertion_sort(int *array, int array_size)
{
	int k = 0, key = 0, count = 0;

	for (int i = 1; i < array_size; i++) // 0 ~ 8����
	{
		key = array[i]; // ������ �� ����ְ�
		k = i - 1; //
		for (int i = 0; i < array_size; i++)
		{
			printf("%d ", array[i]);
		}
		printf("\n");
		while (k >= 0 && array[k] > key)
		{
			array[k + 1] = array[k];
			k--;
			count++;
			for (int i = 0; i < array_size; i++)
			{
				printf("%d ", array[i]);
			}
		}
		printf("key = %d, array[k] = %d\n", key, array[k]);
		array[k + 1] = key;
	}

	return count;
}

void ex01(void)
{
	int array[] = {2, 9, 7, 4, 8, 6, 5, 3, 1};
	int array_size = sizeof(array) / sizeof(array[0]);
	int* pointerArray = NULL, count = 0;

	pointerArray = array;
	printf("������: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
	count = insertion_sort(pointerArray, array_size);
	printf("\n������: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n���� Ƚ��: %d", count);
}

void pb1(void)
{
	int array[] = {9, 1, 8, 2, 7, 3, 4, 6, 5};
	int array_size = sizeof(array) / sizeof(array[0]);
	int count = 0;

	printf("������: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ", array[i]);
	}
	count = pb1_insertion(array, array_size);
	printf("\n������: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n���� Ƚ��: %d", count);
}

pb1_insertion(int array[], int array_size)
{
	int count = 0, j = 0, temp = 0;

	for (int i = 1; i < array_size; i++)
	{
		temp = array[i];
		j = i - 1;
		// int array[] = {9, 1, 8, 2, 7, 3, 4, 6, 5}; temp�� 1�̰� j�� 9��
		// int array[] = {1, 9, 8, 2, 7, 3, 4, 6, 5}; temp�� j�� �ٲ�
		// int array[] = {1, 8, 9, 2, 7, 3, 4, 6, 5}; temp�� 8�̰� j�� 9���µ� j�� temp���� Ŀ�� j�� temp �ڸ��� �о����, �׸��� j-1�� ������ ���� j�� 1�ε� 1�� temp���� ������ �ٲ� �ʿ����
		while (j >= 0 && array[j] > temp) // array[j] �� temp���� ū���� �˻��ϴ� ������ ������ �������ڴ�� �����ذ��µ� array[j]�� temp���� ������ �ٲ� ������ ���
		{
			array[j + 1] = array[j]; // array[i]�� �ƴ� ������ ���⼭ i�� temp���� ���� �ֱ� ���� ����, �񱳴� temp�� j�� ��
			// i�� ������� 107���ٿ��� ���࿡ 10, 9, 8 �̷��� �ִٰ� �����ϸ� 9�� 8 �ٲ�� 8�̶� 10 ���ؼ� 10�� ũ�� ������ 9 ���µ� 10 ���� ������ ���� ����
			j--; // -1�� ���ִ� ������ ���� ������ �迭���� 2���� Ű���̸� 1, 0 ���� ���ϴ°�ó�� ���� ��ҵ�� ���ذ��� ����
			count++;
		}
		array[j + 1] = temp; // j+1�� �ڸ��� ���� �����ϴ� ������ ������ ���Ҷ� ������ temp���� Ŭ���� ��ü�ϵ��� �ϴµ� �̹� ���� ȸ������ j-1�� �ع��ȱ� ������ +1 ���� �ڸ��� ���� ������
	}
	return count;
}

void pb2(void)
{
	int array[] = { 9, 1, 8, 2, 7, 3, 4, 6, 5 };
	int array_size = sizeof(array) / sizeof(array[0]);
	int count = 0;

	printf("������: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ", array[i]);
	}
	count = pb2_insertion(array, array_size);
	printf("\n������: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n���� Ƚ��: %d", count);
}

pb2_insertion(int array[], int array_size)
{
	int count = 0, j = 0, key = 0;

	for (int i = 1; i < array_size; i++)
	{
		key = array[i];
		j = i - 1;
		while (j >= 0 && array[j] < key)
		{
			array[j+1] = array[j];
			j--;
			count++;
		}
		array[j + 1] = key;
	}
	return count;
}
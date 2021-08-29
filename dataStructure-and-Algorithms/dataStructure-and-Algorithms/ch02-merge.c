#include <stdio.h>
void merge_sorter(int list[], int left, int right);
void merge(int list[], int left, int middle, int right);
// �ӽ� �迭 ��������
int sorted_list[9];

/* ���� ����
* �ϴ� ���� ������ �����ؿ��� ���
* å�� �ִ� �ڵ尡 �ʹ� �������� ���� �ڵ带 ���� ������ �ʰ���.
*/

void main(void)
{
	int list[] = { 9, 1, 8, 2, 7, 3, 4, 6, 5 };
	int array_size = sizeof(list) / sizeof(list[0]);

	printf("������: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ", list[i]);
	}
	// 0 = �迭�� ���� , array_size-1 = �迭�� ��
	merge_sorter(list, 0, array_size - 1);
	printf("\n������: ");
	for (int i = 0; i < array_size; i++)
	{
		printf("%d ", list[i]);
	}
}

void merge_sorter(int list[], int left, int right)
{
	int middle;

	if (left < right)
	{
		middle = (left + right) / 2; // �߰��� ã��
		merge_sorter(list, left, middle); // �߰��� ���� �������� �ɰ���
		merge_sorter(list, middle+1, right); // �߰��� ���� ���������� �ɰ���
		merge(list, left, middle, right); // ����
	}
}

void merge(int list[], int left, int middle, int right)
{
	int i = left; // �ɰ� ������ ���� �ּҸ� ���� ����
	int j = middle + 1; // �����Ҷ� �߰� �������� ������ ���� �ּҸ� ���� ����
	int k = left; // �ӽ� �迭�� �ּҸ� ���� ����

	// ���� ������� ����
	while (i <= middle && j <= right)
	{
		if (list[i] <= list[j])
		{
			sorted_list[k] = list[i];
			i++;
		}
		else
		{
			sorted_list[k] = list[j];
			j++;
		}
		k++;
	}

	// ������ ���� ������ �ݴ��� ������ ����
	if (i > middle)
	{
		for (int t = j; t <= right; t++)
		{
			sorted_list[k] = list[t];
			k++;
		}
	}
	else
	{
		for (int t = i; t <= middle; t++)
		{
			sorted_list[k] = list[t];
			k++;
		}
	}

	// �ӽ� �迭�ȿ� �ִ°� ���� �迭�� ����
	for (int i = left; i <= right; i++)
	{
		list[i] = sorted_list[i];
	}
}
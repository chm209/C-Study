#include <stdio.h>
void drawList(int list[], int list_size);
void shellsort(int list[], int list_size);
void insertion_sort(int list[], int first, int last, int gap);

/* �������� ���� ������ �����Ѱ��̴�.
* 8���� ��Ҹ� ���� �迭�� �ִٸ� 4, 2, 1 ������ ���� ���� ���� �������� ������ ��Ʈ�鳢�� ���� ������ ���ش�.
*/

void main(void)
{
	int list[] = { 1,9,8,2,3,7,6,4,5 };
	int list_size = sizeof(list) / sizeof(list[0]);

	printf("���� ��: ");
	drawList(list, list_size);
	// �迭, ���� ��ȣ, �� ��ȣ ����
	shellsort(list, list_size);
	printf("���� ��: ");
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

void shellsort(int list[], int list_size)
{
	// ���� �迭�� �߰����� ����, �� ���� ���� ���� �ٽ� ������ 2 �ؼ� ��� �ٿ������ٰ� 1������ ��
	for (int gap = list_size / 2; gap > 0; gap = gap / 2)
	{
		// ���� ¦���� Ȧ���� ����, Ȧ���� �ؾ� ���ɿ� �� ���ٰ� ��
		gap % 2 == 0 ? gap++ : gap;

		// �� ������ŭ �ݺ�
		for (int i = 0; i < gap; i++)
		{
			// �迭, ���� ȸ��, �迭 ����, �� ����
			insertion_sort(list, i, list_size - 1, gap);
		}
	}
}

void insertion_sort(int list[], int first, int last, int gap)
{
	int key, j;

	// ����ŭ �ݺ�
	// ���� 5�� �ѹ� �ݺ��ϰ� (���� �迭 ����)
	// ���� 3�̸� 3�� �ݺ�
	for (int i = first + gap; i <= last; i = i + gap)
	{
		// Ű������ �� ����
		key = list[i];

		// ����
		for (j = i - gap; j >= first && list[j] > key; j = j - gap)
		{
			list[j + gap] = list[j];
		}
		list[j + gap] = key;
	}
}
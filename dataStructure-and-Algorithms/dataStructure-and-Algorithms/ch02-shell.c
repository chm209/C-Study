#include <stdio.h>
void drawList(int list[], int list_size);
void shellsort(int list[], int list_size);
void insertion_sort(int list[], int first, int last, int gap);

/* �������� ���� ������ �����Ѱ��̴�.
* 8���� ��Ҹ� ���� �迭�� �ִٸ� 4, 2, 1 ������ ���� ���� ���� �������� ������ ��Ʈ�鳢�� ���� ������ ���ش�.
*/

void main(void)
{
	int list[] = { 1,9,8,2,3,7,6,4,5, 10 };
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

	// �� ��ŭ �ݺ���, ���� 2�� 2,4,6,8 ���� 4�� �ݺ���
	// ��� first ��� �����ϰ� ���ƴ°��µ� �� ���� first�� ������ ��� ���� �ߴµ�
	// shellsort �Լ��� insertion_sort ȣ���Ҷ� �ݺ��� ���� fisrt�� ����
	// �׷� ��� �� ���ƴ� ���°�? ���� ���� 1�̱� ����
	for (int i = first + gap; i <= last; i = i + gap)
	{
		// Ű ������ ����° ���� ����
		key = list[i];

		// ���� 2�̶�� �����ϰ� �̹� �ι� �ݺ��ߴٰ� �ϸ�
		// ���� Ű���� 6��°�� ������
		// �� 0��°, 2��°,  4��°�� 6��°�� ���ϴµ�
		// 6��° 4��°, 6��° 2��°, 6��° 0��° ������ ����
		for (j = i - gap; j >= first && list[j] > key; j = j - gap)
		{
			// 4��°�� 6��°���� Ŭ�� �����ϴµ� ���ڵ带 6��°�� ����Ű�� �ؼ� 4��° ���� ���� ����
			// �� ���ڵ带 gap ��ŭ �̵���Ű�°���
			list[j + gap] = list[j]; 
		}
		// 6��°�� 4��° ���� ���� �־����� key �ȿ� ������ 6��° ����
		// 4��°�� �ִ°��� (2��° 0��°�� �� �۴ٴ� �����Ͽ�)
		// ���� j+gap�� 6��°���µ� �� 4��°? ��� �����ߴµ� for�� Ż���ϱ� ���� j���� 2�� ��
		// �� 4�� 2�� �������� �����ͼ� �ٽ� 2�� ���ϴ� 4��°��
		list[j + gap] = key;
		// ���� �ñ�����
		// Ű���� 6��°�ε� 4��° 2��°�� ũ�� ��į?
		// 6��°�ڸ��� 0��°�� �ְ� �������� 2��°�� 4��°�� �״�ξƴ�?
		// for �� ������ �ߺ���. 6��° �ڸ��� 4��° �� �ְ� ���� j = 4 - 2�� ��
		// �ٽ� �������� 2 + 2 = 4��°�ڸ��� 2��° ���� ���� �׸��� ���� j = 2-2�� ��
		// ���ǿ��� 0��°�� 6��°���� �����ϱ� Ȧ���ϰ� �������� 2��°�ڸ��� ���� 6��°�� ����� Ű���� ����
		// 
	}
}
#include <stdio.h>
void drawList(int list[], int list_size);
void quicksort(int list[], int left, int right);

/* �������� ���ǰ��� �������� ���ذ����� �����ֵ��� ���� ū�ֵ��� ���������� ����
* ������ ����, �����ʿ����� ���� ���ذ��� ���� ���������� ���ذ����� �����ֵ��� ���� ū �ֵ��� ���������� �����ϴ°� �ݺ��Ѵ�.
* �׷��� �ݺ��ϴ� ���� ������ ������.
*/

void quicksort(int list[], int left, int right)
{
	int part1 = left;
	int part2 = right;
	int pivot = list[(left + right) / 2];  // ���ذ��� �׳� ����Ʈ�� �߰����� ����

	// ���� �������� ���� �߰����� �����µ� ��ġ�� �����Ǵ��� �˻�
	// �����ִ� �����̶�� ����
	while (part1 <= part2)
	{
		// ���ʺ��� ���ذ����� ������ �˻�
		// ���ذ����� ������ index�� ��� +1 �ؼ� �˻縦 �ϴµ�
		// ���ذ����� ũ�� �ϴ� ����
		while (list[part1] < pivot)
		{
			part1++;
		}
		// ������ ������ ���ذ����� ū�� �˻�
		// ���ذ����� ũ�� index�� ��� -1 �ؼ� �˻��Ѵ�
		// ���ذ����� ������ ����
		while (list[part2] > pivot)
		{
			part2--;
		}

		// ����, ������ ��ġ�� ���� ���� �������� �˻�
		// �̰� �����ָ� ���ذ� �������� �̹� ���������� �����ִµ� ū�� �˻��ϴ� �ְ� ���ͼ� ��ġ�� �ٲ������ ����
		if (part1 <= part2)
		{
			// swap ����
			int temp = list[part1];
			list[part1] = list[part2];
			list[part2] = temp;
			// ���� �ٲ����� index�� ���� +1, -1 ����
			part1++;
			part2--;
		} 
	}

	//             �� part2
	// ����������
	//                     �� part1
	// �߰��� �������� �̷��� �����ߴµ�
	// index�� ������ �ִ°���
	// �������� �ѹ��� ���� �����ؾ��ϴ� left = 0, part2������ ���ذ���
	// �̷��� ���� �����
	// �ٽ� �����ϰ� ������ �����ϰ� 1���� ���������� �ݺ��ϴ°���
	if (left < part2)
	{
		quicksort(list, left, part2);
	}
	// �굵 ���������� part1�� ���ذ�+1�̰� right�� �������̴�
	// ������ �����ϰ� ������ �����ϰ� ���������� 1���� ���������� �ݺ��ϴ°���
	if (part1 < right)
	{
		quicksort(list, part1, right);
	}
}

void main(void)
{
	int list[] = { 1,9,8,2,3,7,6,4,5 };
	int list_size = sizeof(list) / sizeof(list[0]);

	printf("���� ��: ");
	drawList(list, list_size);
	// �迭, ���� ��ȣ, �� ��ȣ ����
	quicksort(list, 0, list_size - 1);
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
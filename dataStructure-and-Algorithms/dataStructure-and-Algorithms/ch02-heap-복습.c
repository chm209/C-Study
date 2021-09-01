#include <stdio.h>
void drawList(int list[], int list_size);
void heapsort(int list[], int list_size);

void main(void)
{
	int list[] = { 1, 9, 2, 8, 7, 3, 4, 6, 5, 10 };
	int list_size = sizeof(list) / sizeof(list[0]);

	printf("���� ��: ");
	drawList(list, list_size);
	// �迭, ���� ��ȣ, �� ��ȣ ����
	heapsort(list, list_size);
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

void heapsort(int list[], int list_size)
{
	for (int i = 1; i < list_size; i++)
	{
		int c = i;
		do
		{
			int root = (c - 1) / 2;
			if (list[root] < list[c])
			{
				int temp = list[root];
				list[root] = list[c];
				list[c] = temp;
			}
			c = root;
		} while (c != 0);
	}
}

void heapsort(int list[], int list_size)
{
	for (int i = 1; i < list_size; i++)
	{
		int c = i;
		do
		{
			int root = (c - 1) / 2;
			if (list[root] < list[c])
			{
				int temp = list[root];
				list[root] = list[c];
				list[c] = temp;
			}
			c = root;
		} while (c != 0);
	}

	for (int i = list_size - 1; i >= 0; i--)
	{
		int root = 0, c = 1;
		int temp = list[0];
		list[0] = list[i];
		list[i] = temp;

		do
		{
			c = 2 * root + 1;


			// for������ list_size-1�� �迭 ���̿��� -1�� ����� ���� ������ �迭�� ���ͼ���
			// �ؿ� if �����ǿ� i-1�� �ϴ� ������ �����Ŀ��� �ϳ��� �����ȱ� ������
			// ���� ������ ���ؼ� �������� �� ũ�� ���������� �ε����� ��
			if (c < i - 1 && list[c] < list[c + 1])
			{
				c++;
			}

			// root�� c�� �ٲ���
			if (c < i && list[root] < list[c])
			{
				int temp = list[root];
				list[root] = list[c];
				list[c] = temp;
			}
			root = c;
			// ���� �ٽ� ������ root�� �Ʒ��� ���ϴ°���
		} while (c < i);
	}
}
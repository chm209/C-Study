#include <stdio.h>
void drawList(int list[], int list_size);
void heapsort(int list[], int list_size);

// ���� ���İ� �� ���� ��ŭ ���� ���� �˰���
// ��� ���α׷��� ������� �� ���� ���� ������ ���� �����ϱ� ������ �ݵ�� �˰� �Ѿ�� �� ���� �˰���
// �� ������ �� Ʈ�� ������ �̿��ϴ� ���� ����̴�.
// 1. �����ؾ� �� n���� ��ҵ�� �ִ� ����(���� ���� Ʈ�� ����) �����.
// 2. �� �������� �� ���� �ϳ��� ��Ҹ� ������ ������ ����� �ں��� �����ϸ� �ȴ�.
// 3. �����Ǵ� ��ҵ��� ���� ���ҵǴ� ������ ���ĵǰ� �ȴ�.


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
	// �� ����
	for (int i = 1; i < list_size; i++)
	{
		//                                  0
		//						  1                   2
		//                  3        4          5            6    
		//              7    8  9     10
		// for�� ���� �������� 0,1 / 0,2 / 1.3 -> 1,0 / 1,4 -> 1,0 �̷��� ���ذ��鼭 �� Ʈ���� ������
		// Ʈ�� ���������� �����ؼ� �������� 10�� ���� ���� �ִµ� ���� �ֻ������� ���ؼ� �ö󰡴°���
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
	
	// �� Ʈ���� �����ϸ� root�� ���� ū ���� ��ġ�Ѵ�.
	// root ���� �迭�� �������� �߰��ϰ� Ʈ���� ���� ������ ���� root ���� �߰����ش�.
	// �׸��� �ٽ� �θ��ڽİ��� �� �񱳸� ���� root�� �������ְ�
	// �迭 ũ�⸸ŭ �ݺ����ش�.

	// ũ�⸦ �ٿ����� �ݺ������� ���� ����
	for (int i = list_size - 1; i >= 0; i--)
	{
		int root = 0, c = 1;
		int temp = list[0];
		list[0] = list[i];
		list[i] = temp;

		do
		{
			// C = 1
			// C = 2
			// root 2
			// C = 5
			// C = 5
			// root 5
			// C = 11 
			c = 2 * root + 1;

			// �ڽĵ��߿� �� ū�� �˻�
			// 0���� root�� 1���� ������
			// ��� 0 / 1 2/ 3456 �������� 1����5�� ��ũ�� �����̶�� �����ߴµ�
			// 5�� 1���� ������ 2�� 5���� Ŀ�� ��������
			//  �׸��� �ؿ� if���� 1,2 / 3,4 ó�� ���� �پ��ִ� �ֵ鳢�� ���Ѱ���
			// �׸��� �� Ʈ�� �����ϸ鼭 ������ �����߱� ������ ������
			if (c < i - 1 && list[c] < list[c + 1])
			{
				c++;
			}

			// ��Ʈ�� �ڽ� ��峢�� ���ؼ� ��ġ ����
			if (c < i && list[root] < list[c])
			{
				int temp = list[root];
				list[root] = list[c];
				list[c] = temp;
			}
			// ��Ʈ�� �ڽ��� �ٲ����� �ٲ� �ڽİ� �� �ڽ��� �ڽĵ� �񱳸� �ϱ� ���� root�� c�� ����
			// Ʈ�� �����Ҷ� ���� ������
			root = c;
		} while (c < i);
	}
}
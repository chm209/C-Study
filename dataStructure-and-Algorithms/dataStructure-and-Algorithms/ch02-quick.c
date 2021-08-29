#include<stdio.h>
void drawList(int list[], int list_size);
void quicksort(int list[], int left, int right);

void quicksort(int list[], int left, int right)
{
    int part1 = left;
    int part2 = right;
    // ������ ���� �߰�������
    int pivot = list[(left + right) / 2];

    // pivot �������� ��,��� ũ�� ���� �� ����
    // part1�� part2���� ũ�� �����ȰŶ� ������ �̷�
    while (part1 <= part2)
    {
        // pivot�̶� ���ؼ� ������ �������� ũ�� ���������� ����
        while (list[part1] < pivot)
        {
            part1++;
        }
        while (list[part2] > pivot)
        {
            part2--;
        }

        // part1�� part2���� ũ�� ���� �����Ȱ���
        if (part1 <= part2)
        {
            // �������ְ� ���ʴ� ��ĭ�� �̵�
            int temp = list[part1];
            list[part1] = list[part2];
            list[part2] = temp;
            part1++;
            part2--;
        }
    }

    if (left < part2)
    {
        // ����
        quicksort(list, left, part2);
    }
    if (part1 < right)
    {
        // ������ 
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
    quicksort(list, 0, list_size-1);
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
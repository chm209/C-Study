#include<stdio.h>
void drawList(int list[], int list_size);
void quicksort(int list[], int left, int right);

void quicksort(int list[], int left, int right)
{
    int part1 = left;
    int part2 = right;
    // 임의의 값은 중간값으로
    int pivot = list[(left + right) / 2];

    // pivot 기준으로 좌,우로 크고 작은 값 나열
    // part1이 part2보다 크면 역전된거라서 조건이 이럼
    while (part1 <= part2)
    {
        // pivot이랑 비교해서 작으면 왼쪽으로 크면 오른쪽으로 나열
        while (list[part1] < pivot)
        {
            part1++;
        }
        while (list[part2] > pivot)
        {
            part2--;
        }

        // part1이 part2보다 크면 서로 역전된거임
        if (part1 <= part2)
        {
            // 스왑해주고 양쪽다 한칸씩 이동
            int temp = list[part1];
            list[part1] = list[part2];
            list[part2] = temp;
            part1++;
            part2--;
        }
    }

    if (left < part2)
    {
        // 왼쪽
        quicksort(list, left, part2);
    }
    if (part1 < right)
    {
        // 오른쪽 
        quicksort(list, part1, right);
    }
}

void main(void)
{
    int list[] = { 1,9,8,2,3,7,6,4,5 };
    int list_size = sizeof(list) / sizeof(list[0]);

    printf("정렬 전: ");
    drawList(list, list_size);
    // 배열, 시작 번호, 끝 번호 전달
    quicksort(list, 0, list_size-1);
    printf("정렬 후: ");
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
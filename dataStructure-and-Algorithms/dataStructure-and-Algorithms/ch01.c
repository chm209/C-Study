#include <stdio.h>
void ex01(void);
long ex01FIB(long num);
void ex02(void);
void* larger(void* pointer1, void* pointer2, int(*pfn_compare)(void*, void*));
int compare_int(void* pointer1, void* pointer2);
int compare_float(void* pointer1, void* pointer2);

void main(void)
{
	/*
	* �˰��� ���θ� ���� �ʼ� ��� ����
	* �ݺ�(����), ���, ������
	* �����غ��ϱ� ���� å���� Ǯ���� �䳢 ������ �Ǻ���ġ�����̾���
	*/

	printf("����");
	// ex01();
	ex02();
}

long ex01FIB(long num)
{
	if (num == 0 || num == 1)
	{
		return num;
	}
	return(ex01FIB(num - 1) + ex01FIB(num - 2));
}

void ex01(void)
{
	int num = 10;

	printf("����Լ��� �̿��� �Ǻ���ġ ����\n");
	for (int i = 0; i < num; i++)
	{
		printf("%6ld\n", ex01FIB(i));
	}
}

int compare_int(void* pointer1, void* pointer2)
{
	if (*(int*)pointer1 >= *(int*)pointer2)
		return 1;
	else
		return -1;
}

int compare_float(void* pointer1, void* pointer2)
{
	if (*(float*)pointer1 >= *(float*)pointer2)
		return 1;
	else
		return -1;
}

void* larger(void* pointer1, void* pointer2, int(*pfn_compare)(void*, void*))
{
	if ((*pfn_compare)(pointer1, pointer2) > 0)
		return pointer1;
	else
		return pointer2;
}

void ex02(void)
{
	int num1 = 7, num2 = 8, result = 0;
	// �Ű������� �Լ� �����͸� �ѱ�
	result = (*(int*)larger(&num1, &num2, compare_int));
	printf("�� ū��: %d\n", result);

	float num3 = 3.1415, num4 = 2.7182, result2 = 0;
	result2 = (*(float*)larger(&num3, &num4, compare_float));
	printf("�� ū��: %f\n", result2);
}
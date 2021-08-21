#include <stdio.h>
void ex1(void);
void ex01Func(int(*p)[4], int num1, int num2);
void ex2(void);
void pb1(void);
void pb1_func(char c, char* str, int num1, double num2);
void pb2(void);
void pb2_func(int* array1, int* array2);
void pb3(void);
pb3_swap(int*, int);
void pb4(void);
void* add(int num1, int num2);
void* subtract(int a, int b);
void* multiply(int a, int b);
void* divide(int a, int b);

void main()
{
	/* # ������ �Լ� �׸��� void�� ������
	* ���� ���� ȣ��: ���� (�޸� ������ ����� ��) �Ǵ� ���� �����ؼ� �Լ� ȣ��
	* �ּҿ� ���� ȣ��: �ּ�(�޸� ������ �ּ�)�� �����ؼ� �Լ� ȣ��
	* EX) func(a) -> func(int i) { i+= i;} ���� a�� ������ ���� 10�ε�, 10�� ����i�� �����ؼ� �Լ� func(int)�� ȣ���Ѵ�. // ���� ���� ȣ��
	* EX) func(&a) -> func(int* i) { i+= i;} a�� �ּҸ� ������ ������ ���� i�� ���� func() �Լ������� ���� a�� ����� ���� �����ϰų� ������ �� �ִ�.
	* �ּҿ� ���� ȣ���� �ʿ伺 -> ���� ���� ȣ���� �Ҷ� �Լ��� �뷮�� �����͸� �����ؾ� �ϴ� ���, �Լ��� �Ű��������� �þ�� �̵��� �ϳ��ϳ� ���� ������ ���̴µ� ���� �ð��� �޸� ������ �ʿ�� �Ѵ�.
	* func(array, sizeof(array)/sizeof(int)) -> func(int* p, int num) => �迭�� �ּҸ� �����ϰ� �迭�� ũ�⸦ �����Ѵ�. �迭�� ũ��� int �ϳ��� 4����Ʈ, �迭�� ��Ұ� 6���� �ִٰ� �ϸ� 6*4 = 24, 24�� int�� 4����Ʈ�� �����ָ� 6. ����� ������ ����
	* sizeof(array) / 4 �� ������
	* �迭 �����͸� �̿��� �ּҿ� ���� �Լ� ȣ��
	* func(array, sizeof(array) / 16, sizeof(array) / 8) -> void func(int (*p)[4], int num1, int num2)
	*            �� �����ּ�         �� ��                      �� ��
	* ������ �迭�� �迭 ������ ���� ������ ������ �������� ��� ����Ҷ� p[6], p[7] �̷������� ����ؾ���, p[1][2] �̷��� ����
	*  === �ּҸ� ��ȯ�ϴ� �Լ�
	* ## �ּ� ��ȯ�� �ʿ伺�� ���� ����
	* 1. �迭�̳� ���ڿ��� ���� �뷮�� �����͸� ��ȯ�� ���� �ּҸ� ��ȯ�ϴ� �Լ��� ����Ѵ�.
	* 2. ���� ������ �ּҸ� ��ȯ�ϸ� ��� �߻��Ѵ�. ������ �Լ��� ����Ǹ鼭 ���� ������ �Ҹ�Ǳ� ������ �ּ� ���� ���ư��� �����̴�.
	* 3. static ������ �Լ��� ����� �Ŀ��� �޸� ������ ������ �ʰ� ���� �ֱ� ������ ���� ������ �ּҸ� ��ȯ�ؼ� ����� ������ �ذ��� �� �ִ�.
	* main �Լ��� ���ڰ� ���� ��� ������ 13-1�� ����
	* void�� ������ -> �ڷ����� ���� ������ ����, �� �ڷ����� ������ ���� �ʰ� �ƹ� �ڷ����� �ּҶ� ������ �� �ִ� ������ ����
	* void�� ������ ������ �ּҸ� ������ �� �ִ�. ���� �����ϰų� ������ �� ����. ��µ� ����
	* ����ϰ� ������ ���� ����ȯ�� ���ľ���
	* ===== ����
	* 1. ��� �ڷ����� �ּҸ� ������ �� �ִ� �����ο� ������
	* 2. void�� �����͸� ���� �ּҰ� �ƴ� ���� ������ ���� ����. ���� �����Ϸ��� ���� ����ȯ�� �ؾ� �Ѵ�.
	*/
	printf("�׽�Ʈ \n");
	//ex1();
	//ex2();
	printf("�������� 1\n");
	pb1();
	printf("\n�������� 2\n");
	pb2();
	printf("\n�������� 3\n");
	pb3();
	printf("\n�������� 4\n");
	pb4();
}

void ex1()
{
	int array[2][4] = {10, 20, 30, 40, 50, 60, 70, 80};
	ex01Func(array, sizeof(array) / 16, sizeof(array) / 8);
}

void ex2()
{
	char c = 3;
	double d = 3.1;
	void* vx = NULL;
	vx = &c;
	printf("vx�� �ּ� ��: %x\n", vx);
	// printf("vx�� ��: %d\n", vx); // ������

	vx = &d;
	printf("vx�� �ּ� ��: %x\n", vx);
	// printf("vx�� ��: %lf\n", vx); // ������

	vx = &c;
	printf("vx�� �ּ� ��: %x\n", vx);
	printf("vx�� ��: %d\n", *(char*)vx);

	vx = &d;
	printf("vx�� �ּ� ��: %x\n", vx);
	printf("vx�� ��: %lf\n", *(double*)vx);
}

void ex01Func(int(*p)[4], int num1, int num2)
{
	for (int i = 0; i < num1; i++)
	{
		for (int j = 0; j < num2; j++)
		{
			printf("%d ", p[i][j]);
		}
		printf("\n");
	}
}

void pb1()
{
	char c = 'A';
	char* str = "ABCD";
	int num1 = 0;
	double num2 = 3.14;

	pb1_func(c, str, num1, num2);
}

void pb1_func(char c, char* str, int num1, double num2)
{
	
}

void pb2()
{
	int array1[4] = { 10, 20 ,30, 40 };
	int array2[4] = { 50, 60, 70, 80 };

	pb2_func(array1, array2);
}

void pb2_func(int* array1, int* array2)
{
	printf("%d %d %d %d\n", *(array1+0), *(array1 + 1), *(array1 + 2), *(array1 + 3));
	printf("%d %d %d %d\n", *(array2 + 0), *(array2 + 1), *(array2 + 2), *(array2 + 3));
 }

void pb3()
{
	int array[8] = { 1,2,3,4,5,6,7,8 };

	pb3_swap(array, sizeof(array) / sizeof(int));
}

pb3_swap(int* array, int num)
{
	int temp = 0, temp2 = 0;
	printf("���� ��: %d %d %d %d %d %d %d %d\n", *(array+0), *(array + 1), *(array + 2), *(array + 3), *(array + 4), *(array + 5), *(array + 6), *(array + 7));

	for (int i = 8; i > 0; i--)
	{
		if (i != 1)
		{
			temp = *(array + i - 1);
			*(array + i - 1) = *(array + i - 2);
			*(array + i - 2) = temp;
		}
	}
	printf("���� ��: %d %d %d %d %d %d %d %d\n", *(array + 0), *(array + 1), *(array + 2), *(array + 3), *(array + 4), *(array + 5), *(array + 6), *(array + 7));
}

void pb4()
{
	int num1, num2;

	printf("�Է�: ");
	scanf("%d %d", &num1, &num2);

	add(num1, num2);
	subtract(num1, num2);
	multiply(num1, num2);
	divide(num1, num2);
}

void* add(int a, int b)
{
	printf("%d + %d = %d\n", a, b, a + b);
}

void* subtract(int a, int b)
{
	printf("%d - %d = %d\n", a, b, a - b);
}

void* multiply(int a, int b)
{
	printf("%d * %d = %d\n", a, b, a * b);
}

void* divide(int a, int b)
{
	printf("%d / %d = %d\n", a, b, a / b);
}
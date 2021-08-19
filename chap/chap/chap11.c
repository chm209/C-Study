#include <stdio.h>
void ex1(void);
void pb1(void);
void pb2(void);
void pb3(void);
void pb4(void);

/*
* 1. ������ ������ �ּҸ� �����ϴ� ����
* 2. ������ ���� ������ �ʱ�ȭ�� NULL�� �ʱ�ȭ, �ٸ� ������ �ʱ�ȭ �����ϳ� ������ �ּҸ� ����
* 3. *&�� ���� ��� �ȴ�. �׷��� *&*&a == a / &*&a == &a�� �����ȴ�.
* 4. &cp -> ������ �ּ� / cp -> ������ �޸� ���� / *&cp -> ������ �޸� ���� / �޸� ������ ������ ������ �ִ� ���� �ٸ�
* 5. �޸� ���� ����غ��� 16������ ����
* 6. �Լ� ������ => �Լ��� ���� �ּҸ� �����ϴ� ����
* �� ������� �Լ��� ��ȯ �ڷ���
* int (*pointer) (int, int) �� ������� �Լ��� �μ�
*          �� �Լ� ������ �̸�
* int add(double) �Լ��� �Լ� ������ ������ ��´ٸ� �Լ� ������ ������ int (*pt) (double) �̷��� ����
*/

void main()
{
	printf("�׽�Ʈ \n");
	ex1();
	printf("�������� 1\n");
	pb1();
	printf("\n�������� 2\n");
	pb2();
	printf("\n�������� 3\n");
	pb3();
}

void ex1()
{
	int a = 0, b = 0, c = 0;
	int* cp = NULL;

	cp = &a;
	*cp = 10;
	printf("%d %d %d %d \n", a, b, c, *cp);

	cp = &b;
	*cp = 20;
	printf("%d %d %d %d \n", a, b, c, *cp);

	cp = &c;
	*cp = 30;
	printf("%d %d %d %d \n", a, b, c, *cp);
}

void pb1()
{
	int*** ip3 = NULL;
	int** ip2 = NULL;
	int* ip1 = NULL;
	int num = 10;	
	num = 10;
	ip1 = &num;
	ip2 = &ip1;
	ip3 = &ip2;
	
	printf("%x %x %x %x\n", &num, &ip1, &ip2, &ip3);
}

void pb2()
{
	int*** ip3 = NULL;
	int** ip2 = NULL;
	int* ip1 = NULL;
	int num = 10;
	printf("1�ܰ�: %d %x %x %x\n", num, &ip1, &ip2, &ip3);

	ip1 = &num;
	*ip1 = 20;
	printf("2�ܰ�: %d %x %x %x\n", num, &ip1, &ip2, &ip3);

	ip2 = &ip1;
	**ip2 = 30;
	printf("2�ܰ�: %d %x %x %x\n", num, &ip1, &ip2, &ip3);

	ip3 = &ip2;
	***ip3 = 40;
	printf("3�ܰ�: %d %x %x %x\n", num, &ip1, &ip2, &ip3);
}

void pb3()
{
	int** ipp = NULL;
	int* ip = NULL;
	int array[3] = { 10, 20, 30 };
	printf("%d %x %x\n", array[0], &ip, &ipp);

	ip = &array+0;
	ipp = &ip;
	printf("%d %x %x\n", array[0] , &ip, &ipp);
	printf("%d %d %x\n", array[0], *ip, &ipp);
	printf("%d %d %d\n", array[0], *ip, **ipp);

	**ipp = 30;
	printf("%d %d %d\n", array[0], *ip, **ipp);
	*ip = 20;
	printf("%d %d %d\n", array[0], *ip, **ipp);
	array[0] = 10;
	printf("%d %d %d\n", array[0], *ip, **ipp);

	printf("===========================\n");
	printf("%d %d %x\n", array[0], **&*&ip, &ipp); // �̷��� �ϸ� *&*& ��� �ι� �Ͼ�� ������ *ip�� ���Ƽ� ip ������ ������ ������ �ִ� array[0] ���� ����
	printf("%d %x %x\n", array[0], *&*&ip, &ipp); // �̷��� �ϸ� ip �����Ͱ� ������ �ִ� array[0]�� �ּҰ��� ����
	printf("%d %x %x\n", array[0], &*&ip, &ipp); // �̷��� �ϸ� ip ������ ������ �ּҰ� ����
	printf("%x %x %x\n", &array[0], *&ip, **&ipp); // �̷��� �ϸ� ip �����Ͱ� ������ �ִ� array[0]�� �ּҰ��� ����
	printf("%x %x %d\n", &array[0], *&ip, ***&*&ipp); // �̷��� �ϸ� *&*&�� ���� ������� ���� **ipp�� ipp �ȿ� ip ���� �ּ� / ip �����ȿ� array[o] �ּҰ� �������� array[0] ���� ����
}
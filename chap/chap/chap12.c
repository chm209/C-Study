#include <stdio.h>
void ex1(void);
void pb1(void);
void pb2(void);
void pb3(void);
void pb4(void);
void pb5(void);

void main()
{
	/*
	* 1���� �迭���� *(array+i) == *&(array[i]) == array[i]�� ���� ǥ���Ѵ�.
	* 2���� �迭���� *(array+i) == *&(array[i]) == array[i]�� �ּҸ� ǥ���Ѵ�.
	* 2���� �迭���� p(������ ����)=array, p=&array[0][0], p=array[0]�� ��� ���� ǥ��
	* �迭 ������ ������ �迭�� ����Ű�� ������ ������� �ǹ�
	* int (*p)[3]; �ڷ��� - �迭 ������ ���� �̸� - �� ����
	* ������ �迭�� �ǹ̴� �ּҸ� �����ϴ� �迭�� ����
	* int* pointer[3]; �ڷ��� - ������ �迭 �̸� - �迭 ����
	* ������ �迭�� ���� ������ ������ ������ �� �� �����ؼ� �Ϲ� ������ �ּҸ� �����ߴµ�
	* �����ؾ��� �ּ��� ������ �������� ������ ������ ���� ����� �Ǿ ������ ������ ������ �������� ������ �����ϴ� ����� ������ �迭�̴�.
	* ������ �迭�� �ּҸ� �����ϴ� �迭, ���ݱ��� �����ߴ� �迭�� ���� ����������, ������ �迭���� �ּҸ� �����Ѵ�.
	* ---- (����)
	* �迭 ������ ����: int (*p)[3] = NULL; => �迭 ������ ���� p�� 3��¥�� 2���� �迭�� �ּҸ� ������ �� �ִ� ����, �迭�� �ƴ϶� ������ �ʱ�ȭ�� NULL �ϳ��θ� ��.
	* ��> �⺻���� ���� 2���� �迭�� �ּҸ� �����ϴµ� ������ �迭�� �ּҸ� �����ϰ� ������ int (*p)[3][3] = NULL; �̷��� ������.
	* ������ �迭: int* p[3] = {NULL, NULL, NULL}; => �迭 �̸��� ��ȣ�� �����Ǿ� ������, �ּҸ� ������ �� �ִ� �迭
	* --- (���ڿ��� Ư¡)
	* "" ū����ǥ ���� ���Ե� �ϳ� �̻��� ����
	* ���ڿ��� ������ ���ڿ��� ���� �˸��� ���� ����  (\0)�� ����
	* ���ڿ��� �ּҷ� �����ǹǷ� ���ڿ��� ���� �ּҸ� �˸� ����� ���ڵ鿡 ������ ����
	* ���ڿ��� ���ڿ� ����� ���ڿ� ������ ����
	* ���ڿ��� ����ϰ� �Է��� ���� ���� ���� %s�� �ÿ�
	* �迭�� ���� ������ ���ڿ��� ������ �����ϳ� ������ ������ ���ڿ� ��� ("ABCD") �� ������ ���ڿ��� ������ �Ұ��ϴ�.
	* --- (������ ������ ���ȭ)
	* const Ű���带 �̿��ϸ� ������ ������ ���ȭ �� �� �ִ�.
	* 1. ������ ������ �ٸ� �޸� ������ �ּҸ� �������� ���ϰ� �Ѵ�. - ������ �ϳ��� �ּҸ� �����ϰ� �Ѵ�.
	* 2. ������ ������ ���� �޸� ������ ���� �������� ���ϰ� �Ѵ�. - �������� ������  ���ؼ��� ���� �����ϰ� �Ѵ�.
	* 3. 1���� 2�� ��� ���ϰ� �Ѵ�.
	*/
	printf("�׽�Ʈ \n");
	// ex1();
	printf("�������� 1\n");
	pb1();
	printf("\n�������� 2\n");
	pb2();
	printf("\n�������� 3\n");
	pb3();
	printf("\n�������� 4\n");
	pb4();
	printf("\n�������� 5\n");
	pb5();
}
 
void ex1()
{
	int* p = NULL;
	int array2[2][2] = { 10, 20, 30, 40 };
	p = array2;

	printf("%x %d \n", &p[0], p[0]);

	int array[2][3] = { 10, 20, 30, 40, 50, 60 };
	int(*pointer)[3] = NULL;

	pointer = array;
	printf("%d %d %d \n", pointer[0][0], pointer[0][1], pointer[0][2]);
	printf("%d %d %d \n", pointer[1][0], pointer[1][1], pointer[1][2]);
	printf("%x %x %x \n", &pointer[1][0], &pointer[1][1], &pointer[1][2]);
	printf("%d %d %d \n", *&pointer[1][0], *&pointer[1][1], *&pointer[1][2]);
	printf("%x %x %x \n", &*&pointer[1][0], &*&pointer[1][1], &*&pointer[1][2]);
	printf("%x %x \n", pointer, pointer+1); // �� ���� �ּ� ���
	printf("%x %x \n", pointer[0], pointer[1]); // �� ���� �ּ� ���
	printf("%x %x \n", *(pointer+0), *(pointer + 1)); // �� ���� �ּ� ���

	int a = 1, b = 2, c = 3;
	int* ptArray[3] = { NULL, NULL, NULL };

	ptArray[0] = &a;
	ptArray[1] = &b;
	ptArray[2] = &c;

	printf("%x %x %x \n", ptArray[0], ptArray[1], ptArray[2]);
	printf("%x %x %x \n", *(ptArray+0), *(ptArray + 1), *(ptArray + 2)); // (ptArray+0) �ȿ��� �ּҰ� ����־ * �����ڸ� ���� �ּҸ� ������
	printf("%d %d %d \n", *(ptArray + 0), *(ptArray + 1), *(ptArray + 2)); // ���� �ּҰ� ���־ %d�� ������ �ٸ� �� ����
	printf("%d %d %d \n", **(ptArray + 0), **(ptArray + 1), **(ptArray + 2)); // ���� * �����ڷ� �迭�ȿ� ���ִ� ���� �ּҸ� �������� �ٱ��� * �����ڷ� �ּҾ��� ���� �����´�.
	printf("%d %d %d \n", ptArray[0], ptArray[1], ptArray[2]); // ���� �ּҰ� ���־ %d�� ������ �ٸ� �� ����
	printf("%d %d %d \n", *ptArray[0], *ptArray[1], *ptArray[2]); // �迭�ȿ� ����ִ� �ּҸ� ���ܿͼ� * �����ڷ� �� �ּ��� ���� ���ܿ�

	char* char1 = "Hello HI";
	char* char2 = "ABCD EFGH";
	char* charArray[2] = { "Good morning", "C-language" };

	printf("%s \n", char1);
	printf("%s \n", char2);
	printf("%s \n", charArray[0]);
	printf("%s \n", charArray[1]);
	printf("%s \n", char1+6);
	printf("%s \n", char2 + 5);
	printf("%s \n", charArray[0] + 5);
	printf("%s \n", charArray[1]+2);

	char1 = "AAAAAAAAAAA";
	charArray[0] = char1;
	charArray[1] = char2;

	printf("===========================\n");
	printf("%s %x\n", char1, &char1);
	printf("%s %x\n", char2, &char2);
	printf("%s \n", charArray[0]);
	printf("%s \n", charArray[1]);
	printf("%s \n", char1 + 6);
	printf("%s \n", char2 + 5);
	printf("%s \n", charArray[0] + 5);
	printf("%s \n", charArray[1] + 2);

	char aaa = 'A';
	char bbb = 'Q';
	char* const ppp = &aaa;

	printf("\n%c\n", *ppp);
	printf("%c\n", aaa);
	*ppp = 'C'; // <- ���⼭�� ����
	printf("%c\n", *ppp);
	printf("%c\n", aaa);

	// ppp = &bbb;  <- ����

	aaa = 'T';
	const char* ppp2 = &aaa;
	printf("\n%c\n", *ppp2);
	printf("%c\n", aaa);
	
	ppp2 = &bbb; // <- ���⼭�� ����
	printf("%c\n", *ppp2);
	printf("%c\n", bbb);

	// *ppp2 = 'D'; <- ����

	aaa = 'V';
	bbb = 'N';

	const char* const ppp3 = &aaa;
	printf("\n%c\n", *ppp3);
	printf("%c\n", aaa);

	aaa = 'X';
	bbb = 'Z';
	printf("%c\n", aaa);
	printf("%c\n", bbb);

	// ppp3 = &bbb; <- ����
	// *ppp3 = 'G'; <- ����

	/*ù��°�� char* const ppp = &aaa; �� ppp = &aaa;�� ���ȭ �Ѱ�
	* ppp�� ������ &aaa �ּҰ��� ���� �������� �� �ּҿ� ����ִ� ���� ���������� �����ϴ°� ����
	* �ι�° const char* ppp2 = &aaa; �� char* ppp2�� ���ȭ �Ѱ�
	* ppp2�� ������ �ּҴ� ���� ���������� �� �ּҿ� ����ִ� ���� ���������� �����ϴ°� �Ұ���
	* ����° const char* const ppp3 = &aaa;�� char* ppp3 = &aaa; ��ü�� ���ȭ �Ѱ�
	* ppp3�� ������ �ּҰ��� ���� ���ϰ� �� �ּҿ� ����ִ� ���� ���������� �����ϴ°͵� ���Ѵ�.
	* 
	* ���ȭ�� ���� ������ϰ� �ϴ°ǵ� �� �̷��� ���̰� ���°��� ��� ��� ������ ���µ�
	* Ȥ�ö� ���߿� �Ȱ��� ���� �ұ�� �����
	* ���ȭ �ϸ� �� ���� ���ϴ°� �´µ� �� ���ȭ �ߴ����� ���� �޶���
	* �򰥸��� �ٽ� �ѹ� �� �о�� + ���ڿ��̶� ������ int ������ ������ ��������
	*/
} 

void pb1()
{
	int array[5] = {10, 30, 40, 30, 20};
	int* pointer = &array;
	int sum = 0;

	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", *&pointer[i]);
		sum += *&pointer[i];
	}
	printf("%d\n", sum);
}

void pb2()
{
	int array[5] = { 10, 20, 30, 40, 50 };
	int* pointer = &array;

	printf("%d %d %d %d %d \n", pointer[0], pointer[1], pointer[2], pointer[3], pointer[4]);
	printf("%d %d %d %d %d \n", *(pointer+0), *(pointer + 1), *(pointer + 2), *(pointer + 3), *(pointer + 4));
}

void pb3()
{
	int array[2][3] = {10, 20, 30, 40, 50, 60};
	int(*pointer)[3] = NULL;
	pointer = array;

	printf("%d %d %d \n", pointer[0][0], pointer[0][1], pointer[0][2]);
	printf("%d %d %d \n", *(*(pointer + 1) + 0), *(*(pointer + 1) + 1), *(*(pointer + 1) + 2));
}

void pb4()
{
	char* string[2] = {"I Love C", "Hello World"};

	printf("%s %s\n", string[0], string[1]+6);
	printf("%s %s\n", *(string+0), *(string + 1) + 6);
}

void pb5()
{
	char* array1 = "ABCD";
	char array2[] = "ABCD"; // �������� ������µ� �迭 ũ�� �� �����൵ ����

	// array1[0] = 'X'; <- ������ ������ ��� "ABCD"�� �����߱� ������ �� ���� �Ұ�
	array2[0] = 'X';
	array2[4] = 'Q'; // �������� ������µ� �迭 ũ�� �� ������ ������ �߰��ϴ°� ����

	printf("%C %C %C", array1[0], array2[0], array2[4]);
}
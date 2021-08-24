#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

void ex1(void);
void ex2(void);
void ex3(void);
void ex4(void);
void ex5(void);
void ex6(void);
void ex7(void);
void pb1(void);
void pb2(void);
void pb3(void);
void pb4(void);

void main()
{
	/* # �ܼ� ����°� ���� �����
	* --- ��Ʈ�� / �����͸� �Է��ϰ� ����ϱ� ���� �ٸ��̴�.
	* --- ����, ���۸�
	* ����: ó���� �����͸� �ӽ÷� �����ϴ� �����, ������ ���� �ӵ��� ������ ó�� �ӵ��� �ٸ� ��� �ӵ� ���̸� �޿� �ֱ� ���� �ӽ� ���� �������μ� ���� �Ѵ�.
	* ���۸��� �ϴ� ������ ���� ����� ���ؼ�
	* --- �ܼ� ǥ�� ����� �Լ�
	* getchar() / ����ڰ� Ű����κ��� ���ڸ� �Է��� ������ ��ٸ��� �ִٰ� ����ڰ� �� ���ڸ� �Է��ϰ� ����Ű�� ġ�� �Է� ���� �� ù ��° ������ Ű ���� int ������ ��ȯ�Ѵ�.
	* �� int ������ ��ȯ�ϴ� ������ �Է��ϴ� �߿� �߻��ϴ� ������ �˸��� ���� �������� ȣ���� �������� �� EOF�� ��ȯ�ϱ� ���ؼ���. (Ctrl + z)
	* EOF�� ������ ���� �Ǹ��ϴ� ��ũ�� ����� stdio.h�� -1�� ���ǵǾ� �ִ�.
	* putchar() / �ڽ��� ����� ������ �ڵ带 ��ȯ�Ѵ�. int ������ ��ȯ�ϴµ� �̵� ���������� ����߿� �߻��ϴ� ������ �˸��� ���� �����̴�.
	* --- �ܼ� ��ǥ�� ����� �Լ� / conio.h
	* getch() �� ����ڰ� �Է��� ���ڸ� ȭ�鿡 �������� ������ getche() �Լ��� ����ڰ� �Է��� ���ڸ� ȭ�鿡 �����ش�.
	* putch() ������ ����� ����ϴ� ��ǥ�� ��� �Լ��̰� kbhit()�� Ű������ Ű�� ���ȴ����� �����ϴ� ��ǥ�� Ű �Է� �Լ��̴�.
	* --- ���� ����� ex3 ~ ����
	*/
	printf("�׽�Ʈ \n");
	// ex1();
	// ex2();
	// ex3();
	// ex4();
	// ex5();
	// ex6();
}

void ex1()
{
	char ch = 0;

	while (ch != EOF)
	{
		ch = getchar();
		putchar(ch);
	}
}

void ex2()
{
	char ch = 0;
	printf("Ű �Է�\n");

	while (ch != 'q')
	{
		if (kbhit())
		{
			ch = getch();
			putch(ch);
		}
	}
}

void ex3()
{
	// STEP 1 / ���� ��Ʈ���� �����ϰ� ������ ����.
	FILE* stream; // ���� ��Ʈ�� ������ ���� ������ ���� ����
	int file_state; // ������ ���Ḧ ���� ���� üũ ���� ����

	stream = fopen("E:\data.txt", "rt"); // ���� ��Ʈ�� ������ �ؽ�Ʈ ���� ����
	// stream = fopen("E:\data.txt", "rb"); // ���� ��Ʈ�� ������  ���̳ʸ� ���� ����
	/* ���� ���� ��忡�� r (read), w (write), a (append) ������ ��尡 �����ϰ� r+, w+, a+ ��嵵 �ֱ� �ѵ� r,w,a�� �� ���� ����.
	* �ؽ�Ʈ ���� ���� ���̳ʸ� ���� ��尡 �ִ�. ���� t,b�� ǥ���ϴµ� t�� ���� �����ϴ�. �� wt�� w�� ���� ǥ��
	*/
	if (stream == NULL)
		puts("���� ���� ����");

	// fclose �Լ��� �Լ��� ���ڷ� ���� ��Ʈ���� �����ؼ� ������ �ݰ� ������ ���� �� ������ EOF�� ��ȯ�Ѵ�.
	file_state = fclose(stream);
	if (file_state == EOF)
		puts("���� �ݱ� ����");
}

void ex4()
{
	FILE* stream;
	FILE* stream2;
	int file_state;
	int input = 0;
	int age = 0;
	char buffer[50], name[10];

	stream = fopen("E:\\data.txt", "r");
	stream2 = fopen("E:\\data2.txt", "w");
	if (stream == NULL)
		puts("���� ���� ����");

	puts("������ �Է�");
	while (input != EOF)
	{
		input = fgetc(stdin); // ���� ���� �Է� �Լ�, Ű����Ӹ� �ƴ϶� ���Ͽ����� �����͸� �Է� ���� �� �ִ�.
		fputc(input, stream); // ����Ϳ� ���Ͽ� �����͸� ����� �� �ִ�.
	}

	fgets(buffer, sizeof(buffer), stdin); // ���ڿ� �Է� �Լ�
	fputs(buffer, stream); // ���ڿ� ���

	printf("�̸�: ");
	fscanf(stdin, "%s", name); // �ڷ��� ���� ǥ�� �Է�
	printf("����: ");
	fscanf(stdin, "%d", age); // �ڷ��� ���� ǥ�� �Է�

	fprintf(stream, "%s\n", name); // �ڷ��� ���� ǥ�� ���

	// ������ ���� �������� ���� ��� ��� data ���Ͽ��� �Է¹ް� data2�� ����ϴ� �ڵ�
	while (!feof(stream))
	{
		fgets(buffer, sizeof(buffer), stream);
		fputs(buffer, stream2);
	}
	fclose(stream);
	fclose(stream2);

	file_state = fclose(stream);
	if (file_state == EOF)
		puts("���� �ݱ� ����");

}

void ex5()
{
	int age;
	char name[50];

	printf("����: ");
	scanf("%d", &age);

	// fflush(stdin);
	// scanf �Լ��� ���̸� �Է¹��� �� ���ۿ� ������ \n�� ������ ȣ��Ǵ� fgets() �Լ��� �����ͷ� �޾Ƶ鿩���� ������ ���۸� ������ �Ѵ�.

	printf("�̸�: ");
	fgets(name, sizeof(name), stdin);

	printf("%d \n", age);
	printf("%s \n", name);
}

void ex6()
{
	int buffer1[5] = { 0xff, 0x56, 0x78, 0xfa, 0xf1 };
	int buffer2[5];

	FILE* stream;
	stream = fopen("student.dat", "wb");
	fwrite(buffer1, sizeof(int), 5, stream);
	fclose(stream);

	stream = fopen("student.dat", "rb");
	fread(buffer2, sizeof(int), 5, stream);
	printf("%x %x %x %x %x \n", buffer2[0], buffer2[1], buffer2[2], buffer2[3], buffer2[4]);
	fclose(stream);
}
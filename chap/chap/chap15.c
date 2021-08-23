#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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
	/* # ���ڿ� ǥ�� �Լ��� ��Ÿ ǥ�� �Լ�
	* --- gets() �Լ�, puts() �Լ� / stdio.h
	* gets() - �Լ��� ���ڷ� ���޹��� �޸�(�迭) �ּҿ� ���ڿ��� �Է��Ѵ�, ���������� �Էµ� Enter �� �ڵ����� �����ϰ� ���ڿ��� ���� �ڵ����� NULL�� �ٿ��ش�.
	* �� �Լ��� ����� �� �޸� �����÷ο찡 �߻����� �ʰ� ���ڿ��� ũ�⸦ �� �Ҵ��ؾ� �Ѵ�.
	* puts() - �Լ��� ���ڷ� ���޹��� �޸�(�迭) �ּҸ� �����Ͽ� NULL ���ڸ� ���������� ���ڿ��� ����Ѵ�, ����ϸ鼭 �ڵ����� \n�� �������ش�.
	* gets()�� scanf ���� �������� ���ڿ� asd asdaasd�� �Է¹����� scanf�� ������ ���� ���ڷ� �ν��ؼ� ����µ� gets�� �׷��� ����.
	* �� �ٸ� �������� �ڵ尡 ���������� ���,�Է� ���Ĺ��ڿ� �Ű澲�� �ʾƵ� �ȴٴ� ���̴�.
	* --- strlen() - ���ڿ��� ���̸� �˷��ִ� �Լ� / string.h
	* �޸� �ּҿ� ����� ���ں��� ���� ���ڸ� ���� ������ ����� ���ڿ��� ���̸� ��ȯ�ϴ� �Լ�. ���ڿ��� ���� �˸��� ���� ���ڴ� ���̿� ���Ե��� �ʴ´�.
	* --- strcpy(), strncpy() �Լ� - ���ڿ��� �����Ѵ�. / string.h
	* --- strcat(), strncat() �Լ� - ���ڿ��� �����Ѵ�. /string.h
	* --- strcmp(), strncmp() �Լ� - ���ڿ��� ���Ѵ�. / string.h
	* --- strchr(), strnchr() �Լ� - ���ڿ� ���ڿ��� ��ġ�� ã�´�. / string.h
	* --- strupr(), strlwr() �Լ� - ���ڿ��� �빮�ڷ� �ٲٰų��ҹ��ڷ� �ٲ۴�. / string.h
	* --- sscanf(), sprintf() - �޸𸮷κ��� ���ڿ��� �Է¹ް� ����Ѵ�.
	* --- strtok() - �����ڸ� �������� ���ڿ��� �и��� �� �ִ�.
	* ====================== ������ ǥ�� �Լ�
	* atof(); ���ڿ��� double�� �����ͷ� ��ȯ // stdlib.h
	* atoi(); ���ڿ��� int�� �����ͷ� ��ȯ // stdlib.h
	* atol(); ���ڿ��� long�� �����ͷ� ��ȯ // stdlib.h
	* toascii(); ���ڸ� �ƽ�Ű ���ڷ� ��ȯ // ctype.h
	* tolower(); ���ڸ� �ҹ��ڷ� ��ȯ // ctype.h
	* toupper(); ���ڸ� �빮�ڷ� ��ȯ // ctype.h
	* ===================== ���а��� ǥ���Լ� // math.h�� stdlib.h�� �����
	* double ceil(double x); x���� ū ���� ��ȯ
	* double floor(double x); x���� ���� ���� ��ȯ
	* double fabs(double x); x�� ���� ��ȯ
	* double pow(double x, double y); x�� y����
	* double sqrt(double x); x�� ��Ʈ
	* double exp(double x); e�� x���� / e�� �ڿ� ��� (���Ϸ��� ��)
	* double log(double x); log e x����
	* double log10(double x); log 10 x�� �İ�
	* ===================== ����
	* int rand(void); ������ ����
	* int srand(unsigned int seed); seed�� �����Ͽ� ������ ����
	*/
	printf("�׽�Ʈ \n");
	// ex1();
	// ex2();
	// ex3();
	// ex4();
	// ex5();
	// ex6();
	// ex7();
	printf("�������� 1\n");
	pb1();
}

void ex1()
{
	char string[20];
	char array1[20] = "ABCD";
	char array2[20] = "EFGH";
	char array3[20] = "IJKL";
	char array4[20] = "MNOP";
	gets(string);
	puts(string);
	printf("����: %d\n", strlen(string));
	strcpy(array2, array1); // array2�� array1�� ����
	strncpy(array4, array3, 3); // array4�� array3�� 3����Ʈ��ŭ ����

	puts(array1);
	puts(array2);
	puts(array3);
	puts(array4);
}

void ex2()
{
	char array1[20] = "ABCD";
	char array2[20] = "EFGH";
	char array3[20] = "IJKL";
	char array4[20] = "MNOP";

	strcat(array1, array2); // array1�� array2 ���ڿ��� ����
	strncat(array3, array4, 3); // array3�� array4 ���ڿ��� 3����Ʈ��ŭ ����

	puts(array1);
	puts(array3);
}

void ex3()
{
	int result1, result2;
	char array1[20] = "QWEQWEQWEQWEQWE";
	char array2[20] = "EFGHASDASD";
	char array3[20] = "IJKL";
	char array4[20] = "MNOP";

	result1= strcmp(array1, array2); // array1�� array2�� ��
	result2 = strncmp(array3, array4, 3); // array3�� array4 ���ڿ��� 3������ ��
	
	printf("%d\n", result1);
	printf("%d\n", result2);

	/*
	* ��ȯ�� ���(0���� ū��): array1 ���ڿ��� array2�� ���ڿ����� ũ��.
	* 0: array1�� ���ڿ��� array1�� ���ڿ��� ����.
	* -1: array1�� ���ڿ��� array1�� ���ڿ����� �۴�.
	* �� ����� �ƽ�Ű �ڵ�� ũ�⸦ ����
	*/
}

void ex4()
{
	char string1[40] = "GOOD MORNING, DDDASDASD";
	char string2[20] = "MORNING";
	char* p1 = NULL;
	char* p2 = NULL;

	p1 = strchr(string1,'D');
	p2 = strstr(string1, string2);

	printf("D�� ��ġ %x\n", p1);
	printf("���ڿ� %s\n", p1);
	printf("���ڿ��� ���� ��ġ %x\n", p2);
	printf("���ڿ� %s\n", p2);

	strlwr(string2);
	puts(string2);
	strupr(string2);
	puts(string2);
}

void ex5()
{
	char array[50] = "100 3.14 summer";
	char arrat2[50];
	int t;
	double d;
	char str[50];

	sscanf(array, "%d %lf %s", &t, &d, &str);
	printf("%d %lf %s\n", t, d, str);
	sprintf(arrat2, "%d, %lf, %s \n", t, d, str);
	printf("%s", arrat2);
}

void ex6()
{
	char array[50] = "ABCDEFG, asdasd, asdasd";
	char* p = NULL;
	int count = 0;

	p = strtok(array, ",");

	for (count = 0; p != NULL; count++)
	{
		puts(p);
		p = strtok(NULL, ","); // strtok() �Լ��� �ι�° ȣ����ʹ� NULL �����͸� �����ϸ� ���� ȣ�⿡�� ã�� ������ ���� ��ġ���� ���� �۾��� �ݺ��Ѵ�.
	}
	printf("%d\n", count);
}

void ex7()
{
	char* string1 = "122";
	char* string2 = "3.14";
	char* string3 = "1000000000";

	int num1 = 0;
	double num2 = 0;
	long num3 = 0;

	num1 = atoi(string1);
	num2 = atof(string2);
	num3 = atol(string3);

	printf("%d, %lf, %ld\n", num1, num2, num3);
}

void pb1()
{
	char string[50];
	int count = 0;

	printf("�Է�: ");
	gets(string);
	strlwr(string);

	for (int i = 97; i < 122; i++)
	{
		for (int k = 0; string[k] != 0; k++)
		{
			if (string[k] == toascii(i))
				count++;
		}
		printf("%c�� ���� %d��\n", toascii(i), count);
		count = 0;
	}
}
#include <stdio.h>
#include <stdlib.h>
#define EX1 100
#define EX2 "ASD"

void ex1(void);
void ex2(void);
void ex3(void);
void ex4(void);
void pb1(void);

void main()
{
	/* #��ó����� ���� ���� ������
	* ������ ���� ó���ؾ� �ϴ� ���� ��ó����� �ϰ� ��ó���� �����ϴ� ��ġ�� ��ó������ �Ѵ�.
	* #���� �����ϴ� ������ ��ó���� �����ڶ�� �Ѵ�.
	* #include / ��� ������ ��Ŭ����ϴ� ���
	* #define / ��ũ�θ� �����ϴ� ���
	* #undef / �̹� ���ǵ� ��ũ�θ� �����ϴ� ���
	* #if, #elif, #else, #endif / ���ǿ� ���� ������ �ϴ� ���
	* #def / ��ũ�ΰ� ���ǵ� ��쿡 ������ �ϴ� ���
	* #indef / ��ũ�ΰ� ���ǵ��� ���� ��쿡 ������ �ϴ� ���
	* --- ��ũ�� ���
	*                �� ��ũ�� ����� �̸�
	* #define PI 3.14 �� ��ũ�� ����� ġȯ�Ǵ� ���� ����
	*  �� ��ó���� ������
	* --- ��ũ�� �Լ�
	* �Լ�ó�� ���ڸ� ������ �� �ִ� ��ũ��, �ܼ��� ġȯ�ϱ⸸ �ϹǷ� ������ �Լ��� �ƴϴ�.
	*                �� ��ũ�� �Լ� �̸�
	* #define FUNC(a, b) a*b �� �Լ��� ���
	* ��ũ�� �Լ��� ������ �ڷ����� �Ű澲�� �ʴ´�. �� �ڷ����� �������� ����ȴ�.
	* --- # ������, ## ������
	* #�� ��ũ�� �Լ��� ���ڸ� ���ڿ��� �ٲ��ִ� ������
	* ## ��ū ���� ������, ��ũ�� �Լ� �ȿ��� ��ū�� �����ϴ� ����� �Ѵ�.
	* ��ū�̶� ���� �м��� ������ �ǹ�
	* ��ū�� �м��ϴ� ���α׷��� �ļ�(parser)��� �ϴµ� �����Ϸ��� ���ԵǾ� �ִ�.
	*/
	printf("�׽�Ʈ \n");
	// ex1();
	// ex2();
	// ex3();
	ex4();
}

#define ex1Func(x, y) x*y

void ex1()
{
	int a = EX1;
	char cc[20] = EX2;

	printf("%d %s\n", a, cc);
	printf("%d %s\n", EX1, EX2);

	// EX1 = 30; �����Ǵ� �Ұ�, ������ �ϰ� ������ undef�� �����ϰ� �ٽ� ��������, ���� ���� �ƴ�
	#undef EX1
	#undef EX2

	#define EX1 30
	#define EX2 "EFG"

	printf("%d %s\n", a, cc);
	printf("%d %s\n", EX1, EX2);

	int q =3, t =4;
	double p = 2.1, z = 5.1;

	printf("%d * %d = %d\n", q, t, ex1Func(q, t));
	printf("%0.3lf * %0.3lf = %0.3lf\n", p, z, ex1Func(p, z));
}

#define ex2Func(x) #x
#define ex3Func(x, y) #x "+" #y
#define ex4Func(x, y, z) x ## y ## z

void ex2()
{
	int a = 3;

	printf("%s\n", ex2Func(1234));
	printf("%s\n", ex3Func(12, 34));
	printf("%d\n", a);
	printf("%d\n", ex4Func(a, =, 5)); // ��ū�� 3���� �����ϸ�a=5��
	printf("%d\n", a);

	printf("%s\n", __FILE__);
	printf("%d\n", __LINE__);
	printf("%s\n", __DATE__);
	printf("%s\n", __TIME__);
}

#define CODE 3

void ex3()
{
	double num1 = 2.2, num2 = 3.0, result;

#if(CODE > 0) // ��ũ�ΰ� ���̳� �����̳ķ� ����
	result = num1 / num2;
	printf("����: %0.3lf\n", result);
#elif (CODE == 2)
	result = num1 * num2;
	printf("����: %0.3lf\n", result);
#else
	result = num1 + num2;
	printf("����: %0.3lf\n", result);
#endif
}

void ex4()
{
#define ex4A
#define ex4B
	double num1 = 1.0, num2 = 2.0, result = 0;
#ifdef ex4A // ��ũ�ΰ� ���ǵǾ� �ִ��ķ� �Ǵ�
	result = num1 + num2;
	printf("%0.3lf\n", result);
#endif

#ifdef ex4B
	result = num1 * num2;
	printf("%0.3lf\n", result);
#endif
}
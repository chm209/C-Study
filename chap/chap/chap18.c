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
	/* #전처리기와 파일 분할 컴파일
	* 컴파일 전에 처리해야 하는 일을 전처리라고 하고 전처리를 수행하는 장치를 전처리기라고 한다.
	* #으로 시작하는 문장을 전처리기 지시자라고 한다.
	* #include / 헤더 파일을 인클루드하는 기능
	* #define / 매크로를 정의하는 기능
	* #undef / 이미 정의된 매크로를 해제하는 기능
	* #if, #elif, #else, #endif / 조건에 따라 컴파일 하는 기능
	* #def / 매크로가 정의된 경우에 컴파일 하는 기능
	* #indef / 매크로가 정의되지 않은 경우에 컴파일 하는 기능
	* --- 매크로 상수
	*                ↓ 매크로 상수의 이름
	* #define PI 3.14 ← 매크로 상수에 치환되는 값을 지정
	*  ↑ 전처리기 지시자
	* --- 매크로 함수
	* 함수처럼 인자를 설정할 수 있는 매크로, 단순히 치환하기만 하므로 실제로 함수는 아니다.
	*                ↓ 매크로 함수 이름
	* #define FUNC(a, b) a*b ← 함수의 기능
	* 매크로 함수는 인자의 자료형을 신경쓰지 않는다. 즉 자료형의 독립성이 보장된다.
	* --- # 연산자, ## 연산자
	* #은 매크로 함수의 인자를 문자열로 바꿔주는 연산자
	* ## 토큰 결한 연산자, 매크로 함수 안에서 토큰을 결합하는 기능을 한다.
	* 토큰이란 문법 분석의 단위를 의미
	* 토큰을 분석하는 프로그램을 파서(parser)라고 하는데 컴파일러에 포함되어 있다.
	*/
	printf("테슷트 \n");
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

	// EX1 = 30; 재정의는 불가, 재정의 하고 싶으면 undef로 해제하고 다시 만들어야함, 흔한 경우는 아님
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
	printf("%d\n", ex4Func(a, =, 5)); // 토큰을 3개를 결합하면a=5라서
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

#if(CODE > 0) // 매크로가 참이냐 거짓이냐로 실행
	result = num1 / num2;
	printf("실행: %0.3lf\n", result);
#elif (CODE == 2)
	result = num1 * num2;
	printf("실행: %0.3lf\n", result);
#else
	result = num1 + num2;
	printf("실행: %0.3lf\n", result);
#endif
}

void ex4()
{
#define ex4A
#define ex4B
	double num1 = 1.0, num2 = 2.0, result = 0;
#ifdef ex4A // 매크로가 정의되어 있느냐로 판단
	result = num1 + num2;
	printf("%0.3lf\n", result);
#endif

#ifdef ex4B
	result = num1 * num2;
	printf("%0.3lf\n", result);
#endif
}
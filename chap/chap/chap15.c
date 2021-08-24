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
	/* # 문자열 표준 함수와 기타 표준 함수
	* --- gets() 함수, puts() 함수 / stdio.h
	* gets() - 함수의 인자로 전달받은 메모리(배열) 주소에 문자열을 입력한다, 마지막으로 입력된 Enter 는 자동으로 제거하고 문자열의 끝에 자동으로 NULL을 붙여준다.
	* ㄴ 함수를 사용할 때 메모리 오버플로우가 발생하지 않게 문자열의 크기를 잘 할당해야 한다.
	* puts() - 함수의 인자로 전달받은 메모리(배열) 주소를 참조하여 NULL 문자를 만날때까지 문자열을 출력한다, 출력하면서 자동으로 \n을 삽입해준다.
	* gets()가 scanf 보다 좋은점은 문자열 asd asdaasd를 입력받으면 scanf는 공백을 종료 문자로 인식해서 끊기는데 gets는 그런게 없다.
	* 또 다른 좋은점은 코드가 간결해지고 출력,입력 서식문자에 신경쓰지 않아도 된다는 점이다.
	* --- strlen() - 문자열의 길이를 알려주는 함수 / string.h
	* 메모리 주소에 저장된 문자부터 종료 문자를 만날 떄까지 저장된 문자열의 길이를 반환하는 함수. 문자열의 끝을 알리는 종료 문자는 길이에 포함되지 않는다.
	* --- strcpy(), strncpy() 함수 - 문자열을 복사한다. / string.h
	* --- strcat(), strncat() 함수 - 문자열을 결합한다. /string.h
	* --- strcmp(), strncmp() 함수 - 문자열을 비교한다. / string.h
	* --- strchr(), strnchr() 함수 - 문자와 문자열의 위치를 찾는다. / string.h
	* --- strupr(), strlwr() 함수 - 문자열을 대문자로 바꾸거나소문자로 바꾼다. / string.h
	* --- sscanf(), sprintf() - 메모리로부터 문자열을 입력받고 출력한다.
	* --- strtok() - 구분자를 기준으로 문자열을 분리할 수 있다.
	* ====================== 데이터 표준 함수
	* atof(); 문자열을 double형 데이터로 변환 // stdlib.h
	* atoi(); 문자열을 int형 데이터로 변환 // stdlib.h
	* atol(); 문자열을 long형 데이터로 변환 // stdlib.h
	* toascii(); 문자를 아스키 문자로 변환 // ctype.h
	* tolower(); 문자를 소문자로 변환 // ctype.h
	* toupper(); 문자를 대문자로 변환 // ctype.h
	* ===================== 수학관련 표준함수 // math.h나 stdlib.h를 사용함
	* double ceil(double x); x보다 큰 정수 반환
	* double floor(double x); x보다 작은 정수 반환
	* double fabs(double x); x의 절댓값 반환
	* double pow(double x, double y); x의 y제곱
	* double sqrt(double x); x의 루트
	* double exp(double x); e의 x제곱 / e는 자연 상수 (오일러의 수)
	* double log(double x); log e x제곱
	* double log10(double x); log 10 xㅈ ㅔ곱
	* ===================== 난수
	* int rand(void); 난수를 생성
	* int srand(unsigned int seed); seed를 지정하여 난수를 생성
	*/
	printf("테슷트 \n");
	// ex1();
	// ex2();
	// ex3();
	// ex4();
	// ex5();
	// ex6();
	// ex7();
	printf("연습문제 1\n");
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
	printf("길이: %d\n", strlen(string));
	strcpy(array2, array1); // array2에 array1을 복사
	strncpy(array4, array3, 3); // array4에 array3을 3바이트만큼 복사

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

	strcat(array1, array2); // array1에 array2 문자열을 결합
	strncat(array3, array4, 3); // array3에 array4 문자열을 3바이트만큼 결합

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

	result1= strcmp(array1, array2); // array1과 array2를 비교
	result2 = strncmp(array3, array4, 3); // array3과 array4 문자열을 3개까지 비교
	
	printf("%d\n", result1);
	printf("%d\n", result2);

	/*
	* 반환값 양수(0보다 큰값): array1 문자열이 array2의 문자열보다 크다.
	* 0: array1의 문자열이 array1의 문자열과 같다.
	* -1: array1의 문자열이 array1의 문자열보다 작다.
	* 비교 방법은 아스키 코드로 크기를 비교함
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

	printf("D의 위치 %x\n", p1);
	printf("문자열 %s\n", p1);
	printf("문자열의 시작 위치 %x\n", p2);
	printf("문자열 %s\n", p2);

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
		p = strtok(NULL, ","); // strtok() 함수의 두번째 호출부터는 NULL 포인터를 지정하면 이전 호출에서 찾은 구분자 다음 위치부터 닽은 작업을 반복한다.
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

	printf("입력: ");
	gets(string);
	strlwr(string);

	for (int i = 97; i < 122; i++)
	{
		for (int k = 0; string[k] != 0; k++)
		{
			if (string[k] == toascii(i))
				count++;
		}
		printf("%c의 개수 %d개\n", toascii(i), count);
		count = 0;
	}
}
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
	/* # 콘솔 입출력과 파일 입출력
	* --- 스트림 / 데이터를 입력하고 출력하기 위한 다리이다.
	* --- 버퍼, 버퍼링
	* 버퍼: 처리할 데이터를 임시로 저장하는 저장소, 데이터 생성 속도와 데이터 처리 속도가 다를 경우 속도 차이를 메워 주기 위한 임시 저장 공간으로서 역할 한다.
	* 버퍼링을 하는 이유는 성능 향상을 위해서
	* --- 콘솔 표준 입출력 함수
	* getchar() / 사용자가 키보드로부터 문자를 입력할 때까지 기다리고 있다가 사용자가 한 문자를 입력하고 엔터키를 치면 입력 문자 중 첫 번째 문자의 키 값을 int 형으로 반환한다.
	* ㄴ int 형으로 반환하는 이유는 입력하는 중에 발생하는 에러를 알리기 위한 목적으로 호출이 실패했을 때 EOF를 반환하기 위해서다. (Ctrl + z)
	* EOF는 파일의 끝을 의마하는 매크로 상수로 stdio.h에 -1로 정의되어 있다.
	* putchar() / 자신이 출력한 문자의 코드를 반환한다. int 형으로 반환하는데 이도 마찬가지로 출력중에 발생하는 에러를 알리기 위한 목적이다.
	* --- 콘솔 비표준 입출력 함수 / conio.h
	* getch() 는 사용자가 입력한 문자를 화면에 보여주지 않지만 getche() 함수는 사용자가 입력한 문자를 화면에 보여준다.
	* putch() 문자의 출력을 담당하는 비표준 출력 함수이고 kbhit()은 키보드의 키가 눌렸는지를 조사하는 비표준 키 입력 함수이다.
	* --- 파일 입출력 ex3 ~ 참고
	*/
	printf("테슷트 \n");
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
	printf("키 입력\n");

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
	// STEP 1 / 파일 스트림을 생성하고 파일을 연다.
	FILE* stream; // 파일 스트림 생성을 위한 포인터 변수 선언
	int file_state; // 파일의 종료를 위한 샅애 체크 변수 선언

	stream = fopen("E:\data.txt", "rt"); // 파일 스트림 생성과 텍스트 파일 열기
	// stream = fopen("E:\data.txt", "rb"); // 파일 스트림 생성과  바이너리 파일 열기
	/* 파일 접근 모드에는 r (read), w (write), a (append) 세가지 모드가 존재하고 r+, w+, a+ 모드도 있긴 한데 r,w,a를 더 자주 쓴다.
	* 텍스트 파일 모드와 바이너리 파일 모드가 있다. 각각 t,b로 표현하는데 t는 생략 가능하다. 즉 wt와 w는 같은 표현
	*/
	if (stream == NULL)
		puts("파일 열기 오류");

	// fclose 함수는 함수의 인자로 파일 스트림을 지정해서 파일을 닫고 파일을 닫을 수 없으면 EOF를 반환한다.
	file_state = fclose(stream);
	if (file_state == EOF)
		puts("파일 닫기 에러");
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
		puts("파일 열기 에러");

	puts("데이터 입력");
	while (input != EOF)
	{
		input = fgetc(stdin); // 문자 단위 입력 함수, 키보드뿐만 아니라 파일에서도 데이터를 입력 받을 수 있다.
		fputc(input, stream); // 모니터와 파일에 데이터를 출력할 수 있다.
	}

	fgets(buffer, sizeof(buffer), stdin); // 문자열 입력 함수
	fputs(buffer, stream); // 문자열 출력

	printf("이름: ");
	fscanf(stdin, "%s", name); // 자료형 단위 표준 입력
	printf("나이: ");
	fscanf(stdin, "%d", age); // 자료형 단위 표준 입력

	fprintf(stream, "%s\n", name); // 자료형 단위 표준 출력

	// 파일의 끝에 도달하지 않은 경우 계속 data 파일에서 입력받고 data2에 출력하는 코드
	while (!feof(stream))
	{
		fgets(buffer, sizeof(buffer), stream);
		fputs(buffer, stream2);
	}
	fclose(stream);
	fclose(stream2);

	file_state = fclose(stream);
	if (file_state == EOF)
		puts("파일 닫기 에러");

}

void ex5()
{
	int age;
	char name[50];

	printf("나이: ");
	scanf("%d", &age);

	// fflush(stdin);
	// scanf 함수가 나이를 입력받은 후 버퍼에 남겨진 \n가 다음에 호출되는 fgets() 함수의 데이터로 받아들여지기 때문에 버퍼를 비워줘야 한다.

	printf("이름: ");
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
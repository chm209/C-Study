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
	* 1차원 배열에서 *(array+i) == *&(array[i]) == array[i]는 값을 표현한다.
	* 2차원 배열에서 *(array+i) == *&(array[i]) == array[i]는 주소를 표현한다.
	* 2차원 배열에서 p(포인터 변수)=array, p=&array[0][0], p=array[0]은 모두 같은 표현
	* 배열 포인터 변수는 배열을 가리키는 포인터 변수라는 의미
	* int (*p)[3]; 자료형 - 배열 포인터 변수 이름 - 열 길이
	* 포인터 배열의 의미는 주소를 저장하는 배열을 말함
	* int* pointer[3]; 자료형 - 포인터 배열 이름 - 배열 길이
	* 포인터 배열을 배우기 전에는 포인터 변수를 세 개 선언해서 일반 변수의 주소를 저장했는데
	* 저장해야할 주소의 개수가 많아지면 포인터 변수를 많이 만들게 되어서 포인터 변수의 개수가 많아지는 단점을 보완하는 방법이 포인터 배열이다.
	* 포인터 배열은 주소를 저장하는 배열, 지금까지 공부했던 배열은 값을 저장하지만, 포인터 배열에는 주소를 저장한다.
	* ---- (정리)
	* 배열 포인터 변수: int (*p)[3] = NULL; => 배열 포인터 변수 p는 3열짜리 2차원 배열의 주소를 저장할 수 있는 변수, 배열이 아니라 변수라서 초기화를 NULL 하나로만 함.
	* ㄴ> 기본으로 쓰면 2차원 배열의 주소를 저장하는데 다차원 배열의 주소를 저장하고 싶으면 int (*p)[3][3] = NULL; 이렇게 선언함.
	* 포인터 배열: int* p[3] = {NULL, NULL, NULL}; => 배열 이름에 괄호가 생략되어 있으며, 주소를 저장할 수 있는 배열
	* --- (문자열의 특징)
	* "" 큰따옴표 내에 포함된 하나 이상의 문자
	* 문자열의 끝에는 문자열의 끝을 알리는 종료 문자  (\0)을 삽입
	* 문자열은 주소로 관리되므로 문자열의 시작 주소를 알면 저장된 문자들에 접근이 가능
	* 문자열은 문자열 상수와 문자열 변수로 구분
	* 문자열을 출력하고 입력할 때는 서식 문자 %s를 시용
	* 배열을 만들어서 저장한 문자열은 변경이 가능하나 포인터 변수에 문자열 상수 ("ABCD") 로 저장한 문자열은 변경이 불가하다.
	* --- (포인터 변수의 상수화)
	* const 키워드를 이용하면 포인터 변수를 상수화 할 수 있다.
	* 1. 포인터 변수에 다른 메모리 공간의 주소를 저장하지 못하게 한다. - 오로지 하나의 주소만 저장하게 한다.
	* 2. 포인터 변수를 통해 메모리 공간의 값을 변경하지 못하게 한다. - 직접적인 접근을  통해서만 값을 변경하게 한다.
	* 3. 1번과 2번 모두 못하게 한다.
	*/
	printf("테슷트 \n");
	// ex1();
	printf("연습문제 1\n");
	pb1();
	printf("\n연습문제 2\n");
	pb2();
	printf("\n연습문제 3\n");
	pb3();
	printf("\n연습문제 4\n");
	pb4();
	printf("\n연습문제 5\n");
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
	printf("%x %x \n", pointer, pointer+1); // 각 행의 주소 출력
	printf("%x %x \n", pointer[0], pointer[1]); // 각 행의 주소 출력
	printf("%x %x \n", *(pointer+0), *(pointer + 1)); // 각 행의 주소 출력

	int a = 1, b = 2, c = 3;
	int* ptArray[3] = { NULL, NULL, NULL };

	ptArray[0] = &a;
	ptArray[1] = &b;
	ptArray[2] = &c;

	printf("%x %x %x \n", ptArray[0], ptArray[1], ptArray[2]);
	printf("%x %x %x \n", *(ptArray+0), *(ptArray + 1), *(ptArray + 2)); // (ptArray+0) 안에는 주소가 들어있어서 * 연산자를 쓰면 주소를 가져옴
	printf("%d %d %d \n", *(ptArray + 0), *(ptArray + 1), *(ptArray + 2)); // 값에 주소가 들어가있어서 %d로 찍으면 다른 값 나옴
	printf("%d %d %d \n", **(ptArray + 0), **(ptArray + 1), **(ptArray + 2)); // 안쪽 * 연산자로 배열안에 들어가있는 값인 주소를 가져오고 바깥쪽 * 연산자로 주소안의 값을 가져온다.
	printf("%d %d %d \n", ptArray[0], ptArray[1], ptArray[2]); // 값에 주소가 들어가있어서 %d로 찍으면 다른 값 나옴
	printf("%d %d %d \n", *ptArray[0], *ptArray[1], *ptArray[2]); // 배열안에 들어있는 주소를 땡겨와서 * 연산자로 그 주소의 값을 땡겨옴

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
	*ppp = 'C'; // <- 여기서는 가능
	printf("%c\n", *ppp);
	printf("%c\n", aaa);

	// ppp = &bbb;  <- 에러

	aaa = 'T';
	const char* ppp2 = &aaa;
	printf("\n%c\n", *ppp2);
	printf("%c\n", aaa);
	
	ppp2 = &bbb; // <- 여기서는 가능
	printf("%c\n", *ppp2);
	printf("%c\n", bbb);

	// *ppp2 = 'D'; <- 에러

	aaa = 'V';
	bbb = 'N';

	const char* const ppp3 = &aaa;
	printf("\n%c\n", *ppp3);
	printf("%c\n", aaa);

	aaa = 'X';
	bbb = 'Z';
	printf("%c\n", aaa);
	printf("%c\n", bbb);

	// ppp3 = &bbb; <- 에러
	// *ppp3 = 'G'; <- 에러

	/*첫번째는 char* const ppp = &aaa; 는 ppp = &aaa;를 상수화 한것
	* ppp에 저장한 &aaa 주소값은 변경 못하지만 그 주소에 들어있는 값을 직접적으로 변경하는건 가능
	* 두번째 const char* ppp2 = &aaa; 는 char* ppp2를 상수화 한것
	* ppp2에 저장한 주소는 변경 가능하지만 그 주소에 들어있는 값을 직접적으로 변경하는건 불가능
	* 세번째 const char* const ppp3 = &aaa;는 char* ppp3 = &aaa; 전체를 상수화 한것
	* ppp3에 저장한 주소값도 변경 못하고 그 주소에 들어있는 값을 직접적으로 변경하는것도 못한다.
	* 
	* 상수화가 값을 변경못하게 하는건데 왜 이렇게 차이가 나는거지 라고 방금 생각이 났는데
	* 혹시라도 나중에 똑같은 생각 할까봐 적어둠
	* 상수화 하면 값 변경 못하는건 맞는데 뭘 상수화 했는지에 따라서 달라짐
	* 헷갈리면 다시 한번 잘 읽어보셈 + 문자열이랑 노상관임 int 포인터 변수도 마찬가지
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
	char array2[] = "ABCD"; // 문제랑은 상관없는데 배열 크기 안 정해줘도 가능

	// array1[0] = 'X'; <- 포인터 변수에 상수 "ABCD"로 저장했기 때문에 값 변경 불가
	array2[0] = 'X';
	array2[4] = 'Q'; // 문제랑은 상관없는데 배열 크기 안 정해져 있으면 추가하는거 가능

	printf("%C %C %C", array1[0], array2[0], array2[4]);
}
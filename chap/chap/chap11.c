#include <stdio.h>
void ex1(void);
void pb1(void);
void pb2(void);
void pb3(void);
void pb4(void);

/*
* 1. 포인터 변수는 주소를 저장하는 변수
* 2. 포인터 변수 선언후 초기화는 NULL로 초기화, 다른 값으로 초기화 가능하나 무조건 주소만 저장
* 3. *&는 서로 상쇄 된다. 그래서 *&*&a == a / &*&a == &a가 성립된다.
* 4. &cp -> 변수의 주소 / cp -> 변수의 메모리 공간 / *&cp -> 변수의 메모리 공간 / 메모리 공간과 변수가 가지고 있는 값은 다름
* 5. 메모리 공간 출력해보면 16진수로 나옴
* 6. 함수 포인터 => 함수의 시작 주소를 저장하는 변수
* ↓ 저장당한 함수의 반환 자료형
* int (*pointer) (int, int) ← 저장당한 함수의 인수
*          ↑ 함수 포인터 이름
* int add(double) 함수를 함수 포인터 변수에 담는다면 함수 포인터 변수는 int (*pt) (double) 이렇게 선언
*/

void main()
{
	printf("테슷트 \n");
	ex1();
	printf("연습문제 1\n");
	pb1();
	printf("\n연습문제 2\n");
	pb2();
	printf("\n연습문제 3\n");
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
	printf("1단계: %d %x %x %x\n", num, &ip1, &ip2, &ip3);

	ip1 = &num;
	*ip1 = 20;
	printf("2단계: %d %x %x %x\n", num, &ip1, &ip2, &ip3);

	ip2 = &ip1;
	**ip2 = 30;
	printf("2단계: %d %x %x %x\n", num, &ip1, &ip2, &ip3);

	ip3 = &ip2;
	***ip3 = 40;
	printf("3단계: %d %x %x %x\n", num, &ip1, &ip2, &ip3);
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
	printf("%d %d %x\n", array[0], **&*&ip, &ipp); // 이렇게 하면 *&*& 상쇠 두번 일어나서 나머지 *ip만 남아서 ip 포인터 변수가 가지고 있던 array[0] 값이 나옴
	printf("%d %x %x\n", array[0], *&*&ip, &ipp); // 이렇게 하면 ip 포인터가 가지고 있는 array[0]의 주소값이 나옴
	printf("%d %x %x\n", array[0], &*&ip, &ipp); // 이렇게 하면 ip 포인터 변수의 주소가 나옴
	printf("%x %x %x\n", &array[0], *&ip, **&ipp); // 이렇게 하면 ip 포인터가 가지고 있는 array[0]의 주소값이 나옴
	printf("%x %x %d\n", &array[0], *&ip, ***&*&ipp); // 이렇게 하면 *&*&가 상쇠로 사라지고 남은 **ipp로 ipp 안에 ip 변수 주소 / ip 변수안에 array[o] 주소가 들어가있으니 array[0] 값이 나옴
}
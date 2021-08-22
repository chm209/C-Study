#include <stdio.h>
#include <string.h>

void ex1(void);
void ex2(void);
void ex3(void);
void ex4(void);
void ex5(void);
void ex6(void);
void ex7(void);
void ex8(void);
void ex8func(struct ex08point* call);
void ex9(void);
struct ex9point ex9func(void);
void ex10(void);
void ex11(void);
struct ex10point* ex10func(void);
void ex12(void);
void pb1(void);
void pb2(void);
void pb3(void);
void pb4(void);
void pb5(void);
void pb6(void);
void pb6Func(struct pb6Point call);
struct pb6Point* pb6Func2(struct pb6Point call2);

void main()
{
	/* # 구조체와 공용체
	* 구조체란 하나 이상의 변수를 묶어 그룹화하는 사용자 정의 자료형이다.
	* 그룹화할 때 같은 자료형을 가진 변수들을 묶어 그룹화할 수 있고, 다른 자료형을 가진 변수들을 묶어 그룹화할 수 있다.
	* 보통은 main 함수 밖에서 선언함
	* --- 구조체 변수
	* 구조체 변수란 구조체 멤버 변수에 접근하게 해주는 변수를 말한다.
	* 구조체 변수도 변수라서 구조체 변수의 이름으로 메모리 공간이 생성되고 구조체 변수의 이름 앞에 & 연산자를 붙이면 구조체 변수의 시작 주소를 알 수 있다.
	* 구조체 변수안에 구조체 멤버 변수가 들어간다. 각자 다른 영역에 있기 때문에 다른 값으로 저장할 수 있다.
	* 구조체 변수의 시작 주소와 구조체의 첫 번째 멤버변수 주소는 동일하다.
	* --- 중첩 구조체
	* 구조체 내에 구조체가 포함되어 있다는 의미, 멤버 변수로 구조채 변수를 사용한다
	* typedef를 이용해서 구조체를 재정의 할 수 있다.
	* --- 배열
	* 구조체 멤버 변수로 배열이 사용 가능하며, 구조체 변수로도 사용 가능하다.
	* 주의해야 할 점은 구조체 변수를 만들고 초기화를 하지 않고 따로 초기화 할때 p1.s = "aaa" 이런식으로 하면 에러가 발생한다.
	* 배열 이름은 배열의 시작 주소인데 시작 주소에 문자열을 저장하고 있으니 당연히 에러가 발생한다.
	* 저장하고 싶으면 strcpy(p1.s, "aaa"); 를 사용해야 한다.
	* # 구조체와 포인터
	* --- 구조체에 포인터를 사용하는 경우
	* 1. 멤버 변수로 포인터 사용
	* 2. 구조체 변수로 포인터 사용
	* 3. 자기 참조 구조체와 외부 참조 구조체
	* -> 연산자는 포인터 변수에만 사용한다, 포인터 변수만으로 구조체의 멤버 변수에 접근할 때 사용한다.
	* 구조체 변수로 포인터가 선언되어 이 포인터를 이용하여 구조체의 멤버 변수에 접근할때 . 연산자보다 -> 연산자를 더 많이 사용한다.
	* -> 연산자는 구조체 포인터 변수에만 사용 가능하다.
	* --- 자기 참조 구조체와 외부 참조 구조체
	* 자기 참조 구조체: 구조체 내에서 자기 자신을 참조하는 것
	* 외부 참조 구조체: 구초제 내에서 다른 구조체를 참조하는것
	* --- 구조체의 크기
	* 구조체는 멤버변수 하나당 4바이트씩 메모리를 잡는다
	* int, char가 있으면 5바이트라고 생각하겠지만 8바이트로 잡는다
	* --- 구조체와 함수
	* 1. 구조체를 함수의 인자로 전달하기 (값에 의한 호출과 주소에 의한 호출)
	* 2. 구조체를 함수의 반환형으로 전달하기 (값 반환과 주소 반환)
	* 구조체 변수의 주소를 반환하는 함수의 형태는 모든 멤버 변수들을 참조할 수 있는 주소를 반환하는 함수의 형태이다.
	* --- 공용체
	* 공용체: 그룹으로 묶여진 여러 개의 멤버 변수들 중에 가장 큰 메모리 공간을 공유해서 사용하는 것
	* 구조체는 멤버 변수들이 각각의 독립적인 메모리 공간을 갖지만 공용체는 멤버 변수중 가장 큰 메모리 공간을 차지하는 자료형의 크기로 메모리가 생성되며 다른 변수들과 공유해서 사용한다.
	* 키워드는 union
	* 공용체는 임베디드나, 커널, 통신에서 주로 사용하고 평소에는 거의 사용안함
	* --- 열거형
	* 열거형: 변수가 갖는 값에 의미를 부여하는것, 키워드 enum
	* enum week {ONE, TWO, THREE, FOUR}; -> 이렇게 선언하면 컴파일러는 실제로 열거형 멤버들을 정수형 상수로 인식한다.
	*/
	printf("테슷트 \n");
	// ex1();
	// ex2();
	// ex3();
	// ex4();
	// ex5();
	// ex6();
	// ex7();
	// ex8();
	// ex9();
	// ex10();
	// ex11();
	// ex12();
	printf("연습문제 1\n");
	// pb1();
	printf("\n연습문제 2\n");
	pb2();
	printf("\n연습문제 3\n");
	pb3();
	printf("\n연습문제 4\n");
	pb4();
	printf("\n연습문제 5\n");
	pb5();
	printf("\n연습문제 6\n");
	pb6();
}

void ex1()
{
	// ↓ 구조체 키워드
	struct point // ← 구조체 이름
	{
		int x;  // ← 구조체 멤버 변수
		int y;  // ← 구조체 멤버 변수
	} p1, p2, p3; //  ← 구조체 변수, 구조체 정의와 변수 선언을 동시에 하는 방법

	struct point2
	{
		int xx;
		int yy;
	};

	// ↓ struct  point2가 자료형임
	struct  point2 pp1, pp2, pp3; // 구조체 변수를 개별적으로 선언하는 방법
	//                           ↑ 변수 이름

	struct  point p4 = {50, 60}; // 나중에도 다시 선언 가능, 선언하면서 초기화 가능
	p3 = p4; // 복사 가능
	p3.x = p4.x; // 복사 가능

	pp1.xx = 10;
	pp2.xx = 20;
	pp3.yy = 30;
	printf("%d %d %d\n", pp1.xx, pp2.xx, pp3.yy);

	printf("입력: ");
	scanf("%d %d %d", &pp1.xx, &pp2.xx, &pp3.yy);
	printf("%d %d %d\n", pp1.xx, pp2.xx, pp3.yy);
	printf("%d %d\n", p4.x, p4.y);
}

void ex2()
{
	struct point
	{
		int x;
	};

	struct point2
	{
		int t;
		struct point ppp1; // 구조체 변수 ppp1을 구조체 point2의 멤버 변수로 사용
	};

	struct point2 qqq1;
	qqq1.t = 20;
	qqq1.ppp1.x = 30; // 중첩으로 사용 가능

	printf("%d %d\n", qqq1.t, qqq1.ppp1.x);

	struct point2 qqq2 = { 666, { 777 } }; // 중첩 구조체 변수도 선언할때 초기화 가능
	printf("%d %d\n", qqq2.t, qqq2.ppp1.x);
}

void ex3()
{
	typedef struct score // 구조체에서 typedef를 사용하는 방법1
	{
		double math;
		double english;
		double average;
	} SCORE;

	struct  student
	{
		int xx;
		SCORE s; // struct score s;
	};

	typedef struct student STUDENT; // 구조체에서 typedef를 사용하는 방법2

	STUDENT stu = { 100, { 30, 40, 0 } };

	stu.s.average = (stu.s.math + stu.s.english) / 2;
	printf("%d %lf\n", stu.xx, stu.s.average);
}

void ex4()
{
	struct student
	{
		char name[20];
		int age;
	};

	struct  student std[2] = {
		{ "Park", 22},
		{ "Kim", 23}
	};

	printf("%s %d\n%s %d\n", std[0].name, std[0].age, std[1].name, std[1].age);
}

void ex5()
{
	struct pointer
	{
		int* a;
		int* b;
		int** c;
	} p1;

	int num = 1, num2 = 2;
	p1.a = &num;
	p1.b = &num2;
	p1.c = &p1.a;

	printf("%d %d %d\n%x %x %x\n", *p1.a, *(*&p1.b), **p1.c, &p1.a, p1.b, &p1.c);

	struct student
	{
		char name[20];
		int age;
	};

	struct student stu = { "kim", 20 };
	struct student* ppp1 = NULL;

	ppp1 = &stu;
	printf("%s %d\n%s %d\n%x %x %x %x\n", stu.name, stu.age, (*ppp1).name, (*ppp1).age, &stu.name, &stu.age, &(*ppp1).name, &(*ppp1).age);
	// (*ppp1).name -> 괄호를 사용한 이유는 . 연산자가 * 연산자보다 순위가 높아서 *ppp1을 먼저 처리하기 위해 괄호를 사용
	// *ppp1 인 이유는 ppp1 에는 &stu가 저장되어 있어서 (*ppp1).name == (*&)stu.name 이랑 동일하다. 즉 ppp1 안에 주소가 들어갔으니 그 주소의 값을 사용하기 위해 사용
	// -> 연산자는 포인터 변수에서만 사용한다.
	// (*ppp1).name == ppp1 -> name
	printf("%s %d\n", ppp1 -> name, ppp1 -> age);

	// 2차원 구조체 포인터 변수

	struct student* ppp2 = NULL;
	struct student** ppp3 = NULL;

	ppp2 = &stu;
	ppp3 = &ppp2;

	printf("%s %d %s %d\n", ppp2->name, ppp2->age, (*ppp2).name, (*ppp2).age);
	printf("%s %d %s %d\n", (**ppp3).name, (**ppp3).age, (*ppp3) -> name, (*ppp3) -> age);
}

void ex6()
{
	struct student
	{
		char name[20];
		int age;
		struct  student* link;
	};

	struct student stu1 = { "KIM", 20, NULL };
	struct student stu2 = { "PARK", 21, NULL };
	struct student stu3 = { "CHOI", 22, NULL };

	stu1.link = &stu2;
	stu2.link = &stu3;

	printf("%s %d\n", stu1.name, stu1.age);
	printf("%s %d\n", stu1.link->name, stu1.link->age);
	printf("%s %d\n", stu1.link->link->name, stu1.link->link->age);
}

void ex7()
{
	// 외부 참조 구조체

	struct point
	{
		int x;
		int y;
	};

	struct student
	{
		char name[20];
		struct  point* link;
	};

	struct student stu1 = { "KIM", NULL };
	struct student stu2 = { "PARK", NULL };
	struct point p1 = { 30, 40 };
	struct point p2 = { 8, 9 };

	stu1.link = &p1;
	stu2.link = &p2;
	stu2.link->y = 80; // 값 변경 가능

	printf("%s %d %d\n%s %d %d\n", stu1.name, stu1.link -> x, stu1.link->y, stu2.name, stu2.link -> x, stu2.link->y);
}

struct ex08point
{
	int x;
	int y;
};

void ex8()
{
	/*
	* 구조체로 함수를 호출할때는 무조건 main 함수 밖에서 만들어야 호출할 수 있음
	struct point
	{
		int x;
		int y;
	};
	*/

	struct ex08point p = {10,20};

	ex8func(&p); // 주소를 넘겨줘야함
}

void ex8func(struct ex08point* call)
{
	printf("%d %d\n", (*call).x, (*call).y);
}

struct ex9point
{
	int x;
	int y;
};

void ex9()
{
	struct ex9point p;
	p = ex9func();

	printf("%d %d\n", p.x, p.y);
}

struct ex9point ex9func(void)
{
	struct ex9point call = { 10, 20 };

	return call;
}

struct ex10point
{
	int x;
	int y;
};

void ex10(void)
{
	struct ex10point* p;
	p = ex10func();
	printf("%d %d\n%d %d\n", p -> x, p -> y, (*p).x, (*p).y);
}

struct ex10point* ex10func(void)
{
	static struct ex10point call = { 10, 20 }; // call을 정적화 해준 이유는 call은 지역변수이기 때문에 함수가 종료되면 주소또한 날아가서 함수는 닫혀도 call은 남겨두기 위해 static을 사용

	return &call;
}

void ex11()
{
	union point
	{
		int x;
		int y;
		double d;
	};

	struct point2
	{
		int x;
		int y;
		double d;
	};

	printf("%d %d\n", sizeof(union point), sizeof(struct point2));
}

enum ex12Week { ONE, TWO, THREE, FOUR };
enum ex12Season { SPR, SUM = 2, FALL, WIN };

void ex12()
{
	enum ex12Week p1, p2, p3;
	enum ex12Season s1, s2, s3, s4;

	p1 = ONE;
	p2 = TWO;
	p3 = THREE;

	printf("%d %d %d\n", ONE, TWO, THREE);
	printf("%d %d %d\n", p1, p2, p3);

	s1 = SPR;
	s2 = SUM;
	s3 = FALL;
	s4 = WIN;

	printf("%d %d %d %d\n", SPR, SUM, FALL, WIN);
	printf("%d %d %d %d\n", s1, s2, s3, s4);
	// SUM에 2를 저장했기 때문에 그다음부터는 자동으로 3, 4로 저장된다.
}

void pb1()
{
	struct student
	{
		int num;
		char blood[10];
		double eye;
		int weight;
	};

	struct student stu[5];

	for (int i = 0; i < 5; i++)
	{
		printf("학번: ");
		scanf("%d", &stu[i].num);
		printf("혈액형: ");
		scanf("%s", &stu[i].blood);
		printf("시력: ");
		scanf("%lf", &stu[i].eye);
		printf("몸무게: ");
		scanf("%d", &stu[i].weight);
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%d %s %0.3lf %d\n", stu[i].num, stu[i].blood, stu[i].eye, stu[i].weight);
	}
}

void pb2()
{
	struct point
	{
		int x;
		int y;
	};

	struct point s1 = {10, 10};
	struct point* sp = NULL;
	sp = &s1;
}

void pb3()
{
	struct point
	{
		int num;
		char name[20];
		double d;
	};

	struct  point stu;
	struct point* p = NULL;
	struct point** pp = NULL;

	stu.num = 1234;
	strcpy(stu.name, "PARK"); // 문자열 멤버변수에 값을 따로 초기화 할때는 strcpy를 사용해야 한다.
	stu.d = 160;
	p = &stu;
	pp = &p;

	printf("%d %s %0.3lf\n", p->num, p->name, p->d);
	printf("%d %s %0.3lf\n", (*pp)->num, (*pp)->name, (*pp)->d);
}

void pb4()
{
	struct data
	{
		int data;
		struct data* link;
	};

	struct  data n1, n2, n3;

	n1.data = 10;
	n1.link = &n2;
	n2.data = 20;
	n2.link = &n1;
	n3.data = 30;
	n3.link = &n2;

	printf("%d %d %d \n", n1.data, n2.data, n3.data);
	printf("%d %d %d \n", n1.link->data, n1.link -> link->data,  n3.link -> data);
}

void pb5()
{
	struct student
	{
		char name[20];
		int age;
		struct student* link1;
		struct student* link2;
	}stu1, stu2, stu3;

	strcpy(stu1.name, "Kim");
	strcpy(stu2.name, "Lee");
	strcpy(stu3.name, "Goo");
	stu1.age = 90;
	stu2.age = 80;
	stu3.age = 60;
	stu1.link1 = &stu2;
	stu1.link2 = &stu3;
	stu2.link1 = NULL;
	stu2.link2 = NULL;
	stu3.link1 = NULL;
	stu3.link2 = NULL;
}

struct pb6Point
{
	int x;
	int y;
};

void pb6()
{
	struct pb6Point p1 = { 10, 20 };
	struct pb6Point p2 = { 56, 789 };
	struct pb6Point* p3;

	pb6Func(p1);
	p3 = pb6Func2(p2);
	printf("%d %d\n", p3->x, p3->y);
}

void pb6Func(struct pb6Point call)
{
	printf("%d %d\n", call.x, call.y);
}

struct pb6Point* pb6Func2(struct pb6Point call2)
{
	static struct pb6Point call3;
	call3 = call2;
	printf("%d %d\n", call2.x, call2.y);

	call3.x = 1234;
	call3.y = 3135;
	printf("%d %d\n", call3.x, call3.y);

	return &call3;
}
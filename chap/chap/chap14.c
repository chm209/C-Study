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
	/* # ����ü�� ����ü
	* ����ü�� �ϳ� �̻��� ������ ���� �׷�ȭ�ϴ� ����� ���� �ڷ����̴�.
	* �׷�ȭ�� �� ���� �ڷ����� ���� �������� ���� �׷�ȭ�� �� �ְ�, �ٸ� �ڷ����� ���� �������� ���� �׷�ȭ�� �� �ִ�.
	* ������ main �Լ� �ۿ��� ������
	* --- ����ü ����
	* ����ü ������ ����ü ��� ������ �����ϰ� ���ִ� ������ ���Ѵ�.
	* ����ü ������ ������ ����ü ������ �̸����� �޸� ������ �����ǰ� ����ü ������ �̸� �տ� & �����ڸ� ���̸� ����ü ������ ���� �ּҸ� �� �� �ִ�.
	* ����ü �����ȿ� ����ü ��� ������ ����. ���� �ٸ� ������ �ֱ� ������ �ٸ� ������ ������ �� �ִ�.
	* ����ü ������ ���� �ּҿ� ����ü�� ù ��° ������� �ּҴ� �����ϴ�.
	* --- ��ø ����ü
	* ����ü ���� ����ü�� ���ԵǾ� �ִٴ� �ǹ�, ��� ������ ����ä ������ ����Ѵ�
	* typedef�� �̿��ؼ� ����ü�� ������ �� �� �ִ�.
	* --- �迭
	* ����ü ��� ������ �迭�� ��� �����ϸ�, ����ü �����ε� ��� �����ϴ�.
	* �����ؾ� �� ���� ����ü ������ ����� �ʱ�ȭ�� ���� �ʰ� ���� �ʱ�ȭ �Ҷ� p1.s = "aaa" �̷������� �ϸ� ������ �߻��Ѵ�.
	* �迭 �̸��� �迭�� ���� �ּ��ε� ���� �ּҿ� ���ڿ��� �����ϰ� ������ �翬�� ������ �߻��Ѵ�.
	* �����ϰ� ������ strcpy(p1.s, "aaa"); �� ����ؾ� �Ѵ�.
	* # ����ü�� ������
	* --- ����ü�� �����͸� ����ϴ� ���
	* 1. ��� ������ ������ ���
	* 2. ����ü ������ ������ ���
	* 3. �ڱ� ���� ����ü�� �ܺ� ���� ����ü
	* -> �����ڴ� ������ �������� ����Ѵ�, ������ ���������� ����ü�� ��� ������ ������ �� ����Ѵ�.
	* ����ü ������ �����Ͱ� ����Ǿ� �� �����͸� �̿��Ͽ� ����ü�� ��� ������ �����Ҷ� . �����ں��� -> �����ڸ� �� ���� ����Ѵ�.
	* -> �����ڴ� ����ü ������ �������� ��� �����ϴ�.
	* --- �ڱ� ���� ����ü�� �ܺ� ���� ����ü
	* �ڱ� ���� ����ü: ����ü ������ �ڱ� �ڽ��� �����ϴ� ��
	* �ܺ� ���� ����ü: ������ ������ �ٸ� ����ü�� �����ϴ°�
	* --- ����ü�� ũ��
	* ����ü�� ������� �ϳ��� 4����Ʈ�� �޸𸮸� ��´�
	* int, char�� ������ 5����Ʈ��� �����ϰ����� 8����Ʈ�� ��´�
	* --- ����ü�� �Լ�
	* 1. ����ü�� �Լ��� ���ڷ� �����ϱ� (���� ���� ȣ��� �ּҿ� ���� ȣ��)
	* 2. ����ü�� �Լ��� ��ȯ������ �����ϱ� (�� ��ȯ�� �ּ� ��ȯ)
	* ����ü ������ �ּҸ� ��ȯ�ϴ� �Լ��� ���´� ��� ��� �������� ������ �� �ִ� �ּҸ� ��ȯ�ϴ� �Լ��� �����̴�.
	* --- ����ü
	* ����ü: �׷����� ������ ���� ���� ��� ������ �߿� ���� ū �޸� ������ �����ؼ� ����ϴ� ��
	* ����ü�� ��� �������� ������ �������� �޸� ������ ������ ����ü�� ��� ������ ���� ū �޸� ������ �����ϴ� �ڷ����� ũ��� �޸𸮰� �����Ǹ� �ٸ� ������� �����ؼ� ����Ѵ�.
	* Ű����� union
	* ����ü�� �Ӻ���峪, Ŀ��, ��ſ��� �ַ� ����ϰ� ��ҿ��� ���� ������
	* --- ������
	* ������: ������ ���� ���� �ǹ̸� �ο��ϴ°�, Ű���� enum
	* enum week {ONE, TWO, THREE, FOUR}; -> �̷��� �����ϸ� �����Ϸ��� ������ ������ ������� ������ ����� �ν��Ѵ�.
	*/
	printf("�׽�Ʈ \n");
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
	printf("�������� 1\n");
	// pb1();
	printf("\n�������� 2\n");
	pb2();
	printf("\n�������� 3\n");
	pb3();
	printf("\n�������� 4\n");
	pb4();
	printf("\n�������� 5\n");
	pb5();
	printf("\n�������� 6\n");
	pb6();
}

void ex1()
{
	// �� ����ü Ű����
	struct point // �� ����ü �̸�
	{
		int x;  // �� ����ü ��� ����
		int y;  // �� ����ü ��� ����
	} p1, p2, p3; //  �� ����ü ����, ����ü ���ǿ� ���� ������ ���ÿ� �ϴ� ���

	struct point2
	{
		int xx;
		int yy;
	};

	// �� struct  point2�� �ڷ�����
	struct  point2 pp1, pp2, pp3; // ����ü ������ ���������� �����ϴ� ���
	//                           �� ���� �̸�

	struct  point p4 = {50, 60}; // ���߿��� �ٽ� ���� ����, �����ϸ鼭 �ʱ�ȭ ����
	p3 = p4; // ���� ����
	p3.x = p4.x; // ���� ����

	pp1.xx = 10;
	pp2.xx = 20;
	pp3.yy = 30;
	printf("%d %d %d\n", pp1.xx, pp2.xx, pp3.yy);

	printf("�Է�: ");
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
		struct point ppp1; // ����ü ���� ppp1�� ����ü point2�� ��� ������ ���
	};

	struct point2 qqq1;
	qqq1.t = 20;
	qqq1.ppp1.x = 30; // ��ø���� ��� ����

	printf("%d %d\n", qqq1.t, qqq1.ppp1.x);

	struct point2 qqq2 = { 666, { 777 } }; // ��ø ����ü ������ �����Ҷ� �ʱ�ȭ ����
	printf("%d %d\n", qqq2.t, qqq2.ppp1.x);
}

void ex3()
{
	typedef struct score // ����ü���� typedef�� ����ϴ� ���1
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

	typedef struct student STUDENT; // ����ü���� typedef�� ����ϴ� ���2

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
	// (*ppp1).name -> ��ȣ�� ����� ������ . �����ڰ� * �����ں��� ������ ���Ƽ� *ppp1�� ���� ó���ϱ� ���� ��ȣ�� ���
	// *ppp1 �� ������ ppp1 ���� &stu�� ����Ǿ� �־ (*ppp1).name == (*&)stu.name �̶� �����ϴ�. �� ppp1 �ȿ� �ּҰ� ������ �� �ּ��� ���� ����ϱ� ���� ���
	// -> �����ڴ� ������ ���������� ����Ѵ�.
	// (*ppp1).name == ppp1 -> name
	printf("%s %d\n", ppp1 -> name, ppp1 -> age);

	// 2���� ����ü ������ ����

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
	// �ܺ� ���� ����ü

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
	stu2.link->y = 80; // �� ���� ����

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
	* ����ü�� �Լ��� ȣ���Ҷ��� ������ main �Լ� �ۿ��� ������ ȣ���� �� ����
	struct point
	{
		int x;
		int y;
	};
	*/

	struct ex08point p = {10,20};

	ex8func(&p); // �ּҸ� �Ѱ������
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
	static struct ex10point call = { 10, 20 }; // call�� ����ȭ ���� ������ call�� ���������̱� ������ �Լ��� ����Ǹ� �ּҶ��� ���ư��� �Լ��� ������ call�� ���ܵα� ���� static�� ���

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
	// SUM�� 2�� �����߱� ������ �״������ʹ� �ڵ����� 3, 4�� ����ȴ�.
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
		printf("�й�: ");
		scanf("%d", &stu[i].num);
		printf("������: ");
		scanf("%s", &stu[i].blood);
		printf("�÷�: ");
		scanf("%lf", &stu[i].eye);
		printf("������: ");
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
	strcpy(stu.name, "PARK"); // ���ڿ� ��������� ���� ���� �ʱ�ȭ �Ҷ��� strcpy�� ����ؾ� �Ѵ�.
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
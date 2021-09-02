// �ܹ��� ���
typedef struct node
{
	void* data;
	struct node* next; // ��ũ
} NODE;

// ���� ����ü
typedef struct
{
	NODE* top;
	int count;
} STACK;

// ���û���(���� ����ü �޸� �Ҵ�)
STACK* stack_create(void);

// ���� ����(���� ����ü �޸𸮿��� ����)
STACK* stack_destroy(STACK* stack);

// ������ top�� push �Ѵ�
int stack_push(STACK* stack, void* data_in);

// ���� top���� �����͸� ������
void* stack_pop(STACK* stack);
void* stack_top(STACK* stack);
int stack_is_empty(STACK* stack);
int stack_is_full(STACK* stack);
int stack_count(STACK* stack);
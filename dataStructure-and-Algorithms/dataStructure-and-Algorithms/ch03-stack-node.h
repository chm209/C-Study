// 단반향 노드
typedef struct node
{
	void* data;
	struct node* next; // 링크
} NODE;

// 스택 구조체
typedef struct
{
	NODE* top;
	int count;
} STACK;

// 스택생성(스택 구조체 메모리 할당)
STACK* stack_create(void);

// 스택 삭제(스택 구조체 메모리에서 제거)
STACK* stack_destroy(STACK* stack);

// 스택의 top에 push 한다
int stack_push(STACK* stack, void* data_in);

// 스택 top에서 데이터를 가져옴
void* stack_pop(STACK* stack);
void* stack_top(STACK* stack);
int stack_is_empty(STACK* stack);
int stack_is_full(STACK* stack);
int stack_count(STACK* stack);
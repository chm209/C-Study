int menu(void);
void help(int);
void cursor(int);
void gotoxy(int, int);
void drawContent(int);
int move(int, int, int, int);
void game(void);

enum ControlKey
{
	UP = 72, DOWN = 80, ENTER = 13, LEFT = 75, RIGHT = 77, BACKSPACE = 8
};

typedef struct
{
	char name[255];
	int difficulty;
	unsigned long long money;
	unsigned long long bankMoney;
	double bankInterest;
	int tax;
}userInformation;
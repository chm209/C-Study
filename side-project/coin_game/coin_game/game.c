#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <Windows.h>
#include <io.h>
#include "header.h"

void writeUserDataFile(userInformation userData);
void writeCoinDataFile(int CoinArray[][5], int col, int row);
int(*loadCoinDataFile(int col))[5];
userInformation loadUserDataFile(userInformation userData);
void drawCoinChart(int CoinArray[][5], int page, int col, int row);
int inputTargetCoinNumber(int CoinArray[][5], int position);
int inputBuyCoinQuantity(int inputCoinNumber, int CoinArray[][5], userInformation userData);
int inputSellCoinQuantity(int inputCoinNumber, int CoinArray[][5]);
userInformation taxPayment(userInformation userData);
unsigned long long inputBankMoeny(userInformation userData, bool bankMode);
void drawFutureNews(int futureNewsCoin, int futureNewsPrice);
void refreshData(int CoinArray[][5], int futureNewsCoin, int futureNewsPrice);

int(*CoinFluctuations(int col))[5];

void game(void)
{
	bool isGameOver = false;
	int y = 12, key = 0, tax = 0, Deadline = 0;
	int(*CoinArray)[5];
	srand(time(NULL));

	userInformation userData =
	{
		"name", 0, 0, 0, 0.0, 0
	};

	if (_access("유저 데이터.txt", 0) == 0 && _access("코인 데이터.txt", 0) == 0)
	{
		userData = loadUserDataFile(userData);
		CoinArray = loadCoinDataFile(12);
	}
	else
	{
		int CoinArray[12][5] =
		{
			// 가격, 변동율, 매입량, 매입가, 가격변동
			{ 100,     10, 0, 0, 0},
			{ 100,     10, 0, 0, 0},
			{ 1000,    100, 0, 0, 0},
			{ 1000,    100, 0, 0, 0},
			{ 10000,   1000, 0, 0, 0},
			{ 10000,   1000, 0, 0, 0},
			{ 10000,   1000, 0, 0, 0},
			{ 10000,   1000, 0, 0, 0},
			{ 100000,  10000, 0, 0, 0},
			{ 100000,  10000, 0, 0, 0},
			{ 100000,  10000, 0, 0, 0},
			{ 1000000, 100000, 0, 0, 0}
		};

		remove("코인 데이터.txt");
		remove("유저 데이터.txt");

		system("cls");
		drawContent(3);
		cursor(1);
		gets(userData.name);
		cursor(0);
		drawContent(4);

		while (key != ENTER)
		{
			gotoxy(57, y);
			printf("√");
			key = _getch();
			gotoxy(57, y);
			printf("  ");
			y = move(1, key, 57, y);
			gotoxy(57, y);
		}

		switch (y)
		{
		case 12:
			userData.difficulty = 0;
			userData.money = 10000;
			userData.bankMoney = 1000;
			userData.bankInterest = 0.1;
			break;
		case 14:
			userData.difficulty = 1;
			userData.money = 5000;
			userData.bankMoney = 500;
			userData.bankInterest = 0.05;
			break;
		case 16:
			userData.difficulty = 2;
			userData.money = 1000;
			userData.bankInterest = 0.01;
			break;
		}

		gotoxy(30, 19);
		printf("시작 금액: %llu", userData.money);
		gotoxy(30, 21);
		printf("은행 예금: %llu", userData.bankMoney);
		gotoxy(30, 23);
		printf("은행 이자: %.2lf", userData.bankInterest);
		gotoxy(2, 28);
		system("pause");

		writeUserDataFile(userData);
		writeCoinDataFile(CoinArray, 5, 12);
	}
	CoinArray = loadCoinDataFile(12);

	while (key != BACKSPACE && isGameOver == false)
	{
		int inputQuantity = 0, inputCoinNumber = 0;
		int futureNewsCoin = rand() % 11 + 0, futureNewsPrice = rand() % 40 + 0;;
		unsigned long long inputBankAmount = 0;
		y = 18, key = 0;

		system("cls");
		drawContent(2);
		gotoxy(2, 1);
		printf("이름: %s ┃ 금액: %llu ┃ 은행 예금: %llu | 세금: %d", userData.name, userData.money, userData.bankMoney, userData.tax);
		drawCoinChart(CoinArray, 0, 5, 12);
		gotoxy(52, 4);
		printf("%d턴 후에 세금을 납부합니다.", 7 - Deadline);
		drawFutureNews(futureNewsCoin, futureNewsPrice);

		while (key != ENTER && key != BACKSPACE)
		{
			gotoxy(87, y);
			printf("√");
			key = _getch();
			gotoxy(87, y);
			printf("  ");
			y = move(2, key, 87, y);
			gotoxy(87, y);

			if (key == LEFT)
			{
				drawCoinChart(CoinArray, 0, 5, 12);
			}
			else if (key == RIGHT)
			{
				drawCoinChart(CoinArray, 1, 5, 12);
			}
		}

		// 백스페이스시 통과를 위해
		if (key == BACKSPACE)
		{
			y = 0;
		}

		switch (y)
		{
		case 18:
			drawContent(5);
			gotoxy(77, 18);
			printf("%llu", userData.money);
			inputCoinNumber = inputTargetCoinNumber(CoinArray, 20);

			if (inputCoinNumber == 100)
			{
				break;
			}

			gotoxy(77, 22);
			printf("%d", CoinArray[inputCoinNumber][0], 0);
			gotoxy(77, 24);
			printf("%d", userData.money / CoinArray[inputCoinNumber][0]);
			inputQuantity = inputBuyCoinQuantity(inputCoinNumber, CoinArray, userData);

			if (inputQuantity == 0)
			{
				break;
			}

			CoinArray[inputCoinNumber][3] = ((CoinArray[inputCoinNumber][2] * CoinArray[inputCoinNumber][3]) + (inputQuantity * CoinArray[inputCoinNumber][0])) / (inputQuantity + CoinArray[inputCoinNumber][2]);
			CoinArray[inputCoinNumber][2] += inputQuantity;
			userData.money -= (long long)(inputQuantity * CoinArray[inputCoinNumber][0]);

			if (userData.difficulty == 1)
			{
				userData.tax += (CoinArray[inputCoinNumber][0] * inputQuantity / 100) * 0.8;
			}
			else if (userData.difficulty == 2)
			{
				userData.tax += (CoinArray[inputCoinNumber][0] * inputQuantity / 100) * 2;
			}
			else
			{
				userData.tax += (CoinArray[inputCoinNumber][0] * inputQuantity / 100) * 5;
			}
			break;
		case 20:
			drawContent(6);
			inputCoinNumber = inputTargetCoinNumber(CoinArray, 18);

			if (inputCoinNumber == 100)
			{
				break;
			}

			gotoxy(77, 20);
			printf("%d", CoinArray[inputCoinNumber][0]);
			gotoxy(77, 22);
			printf("%d", CoinArray[inputCoinNumber][3]);
			gotoxy(77, 24);
			printf("%d", CoinArray[inputCoinNumber][2]);
			inputQuantity = inputSellCoinQuantity(inputCoinNumber, CoinArray);

			if (inputQuantity == 0)
			{
				break;
			}

			CoinArray[inputCoinNumber][2] -= inputQuantity;
			if (CoinArray[inputCoinNumber][2] == 0)
			{
				CoinArray[inputCoinNumber][3] = 0;
			}
			userData.money += inputQuantity * CoinArray[inputCoinNumber][0];

			if (userData.difficulty == 1)
			{
				userData.tax += (CoinArray[inputCoinNumber][0] * inputQuantity / 100) * 5;
			}
			else if (userData.difficulty == 2)
			{
				userData.tax += (CoinArray[inputCoinNumber][0] * inputQuantity / 100) * 7;
			}
			else
			{
				userData.tax += (CoinArray[inputCoinNumber][0] * inputQuantity / 100) * 12;
			}
			break;
		case 22:
			drawContent(7);
			gotoxy(52, 26);
			printf("적용받는 이자(%.2lf)", userData.bankInterest);
			gotoxy(77, 18);
			printf("%llu", userData.money);
			gotoxy(77, 20);
			printf("%llu", userData.bankMoney);
			inputBankAmount = inputBankMoeny(userData, false);

			if (inputBankAmount == 0)
			{
				break;
			}

			userData.money -= inputBankAmount;
			userData.bankMoney += inputBankAmount;
			gotoxy(77, 24);
			printf("%llu", userData.bankMoney);
			gotoxy(77, 26);
			printf("%.0lf", (long double)userData.bankMoney * userData.bankInterest);
			Sleep(1000);
			break;
		case 24:
			drawContent(8);
			gotoxy(52, 26);
			printf("적용받는 이자(%.2lf)", userData.bankInterest);
			gotoxy(77, 18);
			printf("%llu", userData.money);
			gotoxy(77, 20);
			printf("%llu", userData.bankMoney);
			inputBankAmount = inputBankMoeny(userData, true);

			if (inputBankAmount == 0)
			{
				break;
			}

			userData.money += inputBankAmount;
			userData.bankMoney -= inputBankAmount;
			gotoxy(77, 24);
			printf("%llu", userData.bankMoney);
			gotoxy(77, 26);
			printf("%.0lf", (long double)userData.bankMoney * userData.bankInterest);
			Sleep(1000);
			break;
		case 26:
			// 거래 종료
			Deadline++;

			if (Deadline == 7)
			{
				Deadline = 0;
				userData = taxPayment(userData);
				userData.bankMoney = userData.bankMoney + (long double)userData.bankMoney * userData.bankInterest;
			}

			writeCoinDataFile(CoinArray, 5, 12);
			refreshData(CoinArray, futureNewsCoin, futureNewsPrice);
			CoinArray = CoinFluctuations(12);
			break;
		default:
			break;
		}

		// 파산 체크
		if (userData.money < 1 && userData.bankMoney == 0)
		{
			int CoinCount = 0;

			for (int i = 0; i < 12; i++)
			{
				if (CoinArray[i][2] > 0)
				{
					CoinCount++;
				}
			}

			if (CoinCount == 0)
			{
				isGameOver = true;
			}
		}
	}
	// 데이터 저장
	writeUserDataFile(userData);
	writeCoinDataFile(CoinArray, 5, 12);

	if (isGameOver == true)
	{
		// 기록 보여주기
		system("cls");
		gotoxy(18, 8);
		printf("%s님은 인생역전을 위해 코인시장에 뛰어들었으나,", userData.name);
		gotoxy(18, 10);
		printf("알수없는 세력의 작전에 휘말려 흑색 말랑카우로 떡락 하셨습니다.");
		gotoxy(18, 12);
		printf("플레이 해주셔서 감사합니다.");
		// 파일 삭제
		int nResult = remove("코인 데이터.txt");

		if (nResult == 0)
		{
			gotoxy(18, 14);
			printf("코인 데이터 삭제 성공");
		}
		else if (nResult == -1)
		{
			gotoxy(18, 14);
			perror("코인 데이터 삭제 실패");
			gotoxy(18, 22);
			perror("파일을 지워주시기 바랍니다.");
		}

		nResult = remove("유저 데이터.txt");

		if (nResult == 0)
		{
			gotoxy(18, 16);
			printf("유저 데이터 삭제 성공");
		}
		else if (nResult == -1)
		{
			gotoxy(18, 16);
			perror("유저 데이터 삭제 실패");
			gotoxy(18, 22);
			perror("파일을 지워주시기 바랍니다.");
		}
		gotoxy(18, 20);
		system("pause");
	}
}

void writeUserDataFile(userInformation userData)
{
	FILE* userDataFile;
	userDataFile = fopen("유저 데이터.txt", "wt");
	if (userDataFile == NULL)
	{
		exit(1);
	}
	fprintf(userDataFile, "%s ", userData.name);
	fprintf(userDataFile, "%d ", userData.difficulty);
	fprintf(userDataFile, "%llu ", userData.money);
	fprintf(userDataFile, "%llu ", userData.bankMoney);
	fprintf(userDataFile, "%lf ", userData.bankInterest);
	fprintf(userDataFile, "%d ", userData.tax);
	fclose(userDataFile);
}

void writeCoinDataFile(int CoinArray[][5], int col, int row)
{
	FILE* CoinFile;
	CoinFile = fopen("코인 데이터.txt", "wt");

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			fprintf(CoinFile, "%d ", CoinArray[i][j]);
		}
	}
	fclose(CoinFile);
}

userInformation loadUserDataFile(userInformation userData)
{
	FILE* userFile;
	userFile = fopen("유저 데이터.txt", "r");

	fscanf(userFile, "%s %d %llu %llu %lf %d", &userData.name, &userData.difficulty, &userData.money, &userData.bankMoney, &userData.bankInterest, &userData.tax);
	fclose(userFile);

	return userData;
}

int(*loadCoinDataFile(int col))[5]
{
	static int CoinArray[12][5] =
	{
		// 가격, 변동율, 매입량, 매입가, 가격변동
		{ 100,     10, 0, 0, 0},
		{ 100,     10, 0, 0, 0},
		{ 1000,    100, 0, 0, 0},
		{ 1000,    100, 0, 0, 0},
		{ 10000,   1000, 0, 0, 0},
		{ 10000,   1000, 0, 0, 0},
		{ 10000,   1000, 0, 0, 0},
		{ 10000,   1000, 0, 0, 0},
		{ 100000,  10000, 0, 0, 0},
		{ 100000,  10000, 0, 0, 0},
		{ 100000,  10000, 0, 0, 0},
		{ 1000000, 100000, 0, 0, 0}
	};

	FILE* CoinFile;
	CoinFile = fopen("코인 데이터.txt", "r");
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			fscanf(CoinFile, "%d", &CoinArray[i][j]);
		}
	}
	fclose(CoinFile);

	return CoinArray;
}

void drawCoinChart(int CoinArray[][5], int page, int col, int row)
{
	int CoinNumber = 0;

	for (int i = 4; i <= 24; i += 4)
	{
		gotoxy(2, i);
		printf("                    ");
		gotoxy(24, i);
		printf("                    ");
		gotoxy(2, i + 2);
		printf("                    ");
		gotoxy(24, i + 2);
		printf("                    ");
	}

	switch (page)
	{
	case 0:
		for (int i = 4; i <= 24; i += 4)
		{
			gotoxy(2, i);
			switch (CoinNumber)
			{
			case 0:
				printf("0. 비트코인");
				break;
			case 1:
				printf("1. 도지코인");
				break;
			case 2:
				printf("2. 이더리움");
				break;
			case 3:
				printf("3. 나노코인");
				break;
			case 4:
				printf("4. 비트골드");
				break;
			case 5:
				printf("5. 스팀코인");
				break;
			}
			gotoxy(24, i);
			if (CoinArray[CoinNumber][4] == 1)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
			}
			else if (CoinArray[CoinNumber][4] == 0)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			}
			printf("%d원", CoinArray[CoinNumber][0]);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(2, i + 2);
			printf("매입량: %d", CoinArray[CoinNumber][2]);
			gotoxy(24, i + 2);
			printf("평균 매입가: %d", CoinArray[CoinNumber][3]);
			CoinNumber++;
		}
		break;
	default:
		CoinNumber = 6;

		for (int i = 4; i <= 24; i += 4)
		{
			gotoxy(2, i);
			switch (CoinNumber)
			{
			case 6:
				printf("6. 이머코인");
				break;
			case 7:
				printf("7. 시빅코인");
				break;
			case 8:
				printf("8. 에터니티");
				break;
			case 9:
				printf("9. 웨이브즈");
				break;
			case 10:
				printf("10. 디앱코이");
				break;
			case 11:
				printf("11. 디피니티");
				break;
			}
			gotoxy(24, i);
			if (CoinArray[CoinNumber][4] == 1)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
			else if (CoinArray[CoinNumber][4] == 0)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
			printf("%d원", CoinArray[CoinNumber][0]);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			gotoxy(2, i + 2);
			printf("매입량: %d", CoinArray[CoinNumber][2]);
			gotoxy(24, i + 2);
			printf("평균 매입가: %d", CoinArray[CoinNumber][3]);
			CoinNumber++;
		}
		break;
	}
}

int inputTargetCoinNumber(int CoinArray[][5], int position)
{
	int inputCoinNumber = 0;
	bool isCheck = false, stopTrade = false;

	cursor(1);
	while (isCheck != true)
	{
		gotoxy(77, position);
		scanf("%d", &inputCoinNumber);

		if (inputCoinNumber >= 0 && inputCoinNumber < 12)
		{
			isCheck = true;
			if (CoinArray[inputCoinNumber][0] < 10)
			{
				cursor(0);
				gotoxy(77, position);
				printf("서킷브레이커 발동");
				stopTrade = true;
				Sleep(1000);
			}
		}
		else
		{
			gotoxy(77, position);
			printf("다시 입력하세요.");
			Sleep(1000);
			gotoxy(77, position);
			printf("                  ");
		}
	}
	cursor(0);

	if (stopTrade == true)
	{
		inputCoinNumber = 100;
	}
	return inputCoinNumber;
}

int inputBuyCoinQuantity(int inputCoinNumber, int CoinArray[][5], userInformation userData)
{
	int inputQuantity = 0;
	bool isCheck = false;

	cursor(1);

	while (isCheck != true)
	{
		gotoxy(77, 26);
		scanf("%d", &inputQuantity);

		if (inputQuantity == 0)
		{
			isCheck = true;
			break;
		}
		else if (inputQuantity * CoinArray[inputCoinNumber][0] <= userData.money)
		{
			isCheck = true;
			break;
		}
		else
		{
			gotoxy(77, 26);
			printf("다시 입력하세요.");
			Sleep(1000);
			gotoxy(77, 26);
			printf("                  ");
		}
	}
	cursor(0);

	return inputQuantity;
}

int inputSellCoinQuantity(int inputCoinNumber, int CoinArray[][5])
{
	int inputQuantity = 0;
	bool isCheck = false;

	cursor(1);

	while (isCheck != true)
	{
		gotoxy(77, 26);
		scanf("%d", &inputQuantity);

		if (inputQuantity <= CoinArray[inputCoinNumber][2])
		{
			isCheck = true;
			break;
		}
		else
		{
			gotoxy(77, 26);
			printf("다시 입력하세요.");
			Sleep(1000);
			gotoxy(77, 26);
			printf("                  ");
		}
	}
	cursor(0);

	return inputQuantity;
}

userInformation taxPayment(userInformation userData)
{
	if (userData.tax > userData.money)
	{
		userData.tax -= userData.money;
		userData.money = 0;

		if (userData.tax > userData.bankMoney)
		{
			userData.tax -= userData.bankMoney;
			userData.bankMoney = 0;
		}
		else
		{
			userData.bankMoney -= userData.tax;
			userData.tax = 0;
		}
	}
	else
	{
		userData.money -= userData.tax;
		userData.tax = 0;
	}

	if (userData.tax != 0)
	{
		userData.tax += userData.tax * 0.5;
	}

	return userData;
}

unsigned long long inputBankMoeny(userInformation userData, bool bankMode)
{
	// bankMode . true: 출금 / false: 입금
	bool isCheck = false;
	unsigned long long inputBankAmount = 0;

	cursor(1);
	while (isCheck != true)
	{
		gotoxy(77, 22);
		scanf("%llu", &inputBankAmount);
		if (bankMode == false && inputBankAmount <= userData.money)
		{
			isCheck = true;
			break;
		}
		else if (bankMode == true && inputBankAmount <= userData.bankMoney)
		{
			isCheck = true;
			break;
		}
		else
		{
			gotoxy(77, 22);
			printf("다시 입력하세요.");
			Sleep(1000);
			gotoxy(77, 22);
			printf("                  ");
		}
	}
	cursor(0);

	return inputBankAmount;
}

int(*CoinFluctuations(int col))[5]
{
	static int CoinArray[12][5] =
	{
		{ 100,     10, 0, 0, 0},
		{ 100,     10, 0, 0, 0},
		{ 1000,    100, 0, 0, 0},
		{ 1000,    100, 0, 0, 0},
		{ 10000,   1000, 0, 0, 0},
		{ 10000,   1000, 0, 0, 0},
		{ 10000,   1000, 0, 0, 0},
		{ 10000,   1000, 0, 0, 0},
		{ 100000,  10000, 0, 0, 0},
		{ 100000,  10000, 0, 0, 0},
		{ 100000,  10000, 0, 0, 0},
		{ 1000000, 100000, 0, 0, 0}
	};

	FILE* readCoinFile;
	readCoinFile = fopen("코인 데이터.txt", "r");
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			fscanf(readCoinFile, "%d", &CoinArray[i][j]);
		}
	}
	fclose(readCoinFile);

	for (int i = 0; i < 12; i++)
	{
		int CoinPriceRand = rand() % 100 + 1;

		if (CoinPriceRand % 2 == 0)
		{
			CoinPriceRand = CoinArray[i][1];
			CoinArray[i][0] += rand() % CoinPriceRand + 1;
			CoinArray[i][4] = 1;
		}
		else
		{
			CoinPriceRand = CoinArray[i][1];
			CoinArray[i][0] -= rand() % CoinPriceRand + 1;
			CoinArray[i][4] = 0;

			if (CoinArray[i][0] < 0)
			{
				CoinArray[i][0] = 10;
			}
		}

		if (i <= 1)
		{
			CoinArray[i][1] = 10;
		}
		else if (i > 1 && i <= 3)
		{
			CoinArray[i][1] = 100;
		}
		else if (i > 3 && i <= 7)
		{
			CoinArray[i][1] = 1000;
		}
		else if (i > 7 && i <= 10)
		{
			CoinArray[i][1] = 10000;
		}
		else
		{
			CoinArray[i][1] = 100000;
		}
	}

	FILE* writeCoinFile;
	writeCoinFile = fopen("코인 데이터.txt", "wt");

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			fprintf(writeCoinFile, "%d ", CoinArray[i][j]);
		}
	}
	fclose(writeCoinFile);

	return CoinArray;
}

void drawFutureNews(int futureNewsCoin, int futureNewsPrice)
{
	gotoxy(52, 6);
	printf("< 찌라시 >");
	gotoxy(52, 8);
	switch (futureNewsCoin)
	{
	case 0:
		printf("0. 비트코인");
		break;
	case 1:
		printf("1. 도지코인");
		break;
	case 2:
		printf("2. 이더리움");
		break;
	case 3:
		printf("3. 나노코인");
		break;
	case 4:
		printf("4. 비트골드");
		break;
	case 5:
		printf("5. 스팀코인");
		break;
	case 6:
		printf("6. 이머코인");
		break;
	case 7:
		printf("7. 시빅코인");
		break;
	case 8:
		printf("8. 에터니티");
		break;
	case 9:
		printf("9. 웨이브즈");
		break;
	case 10:
		printf("10. 디앱코이");
		break;
	case 11:
		printf("11. 디피니티");
		break;
	}

	switch (futureNewsPrice)
	{
	case 0:
		gotoxy(52, 10);
		printf("미국이 암호화폐를 인정한다는 소문이 있습니다.");
		gotoxy(52, 12);
		printf("사실이라면 주가가 크게 상승합니다.");
		break;
	case 8:
		gotoxy(52, 10);
		printf("일론 머스크가 트위터 계정을 뺏겼습니다.");
		gotoxy(52, 12);
		printf("주가가 안정됩니다.");
		break;
	case 15:
		gotoxy(52, 10);
		printf("중국에서 암호화폐를 규제한다고 합니다.");
		gotoxy(52, 12);
		printf("사실이라면 주가가 크게 하락 합니다.");
		break;
	case 27:
		gotoxy(52, 10);
		printf("정부 규제안에 대한 소문이 들립니다.");
		gotoxy(52, 12);
		printf("주가가 요동치기 시작합니다.");
		break;
	case 31:
		gotoxy(52, 10);
		printf("일론 머스크가 트윗을 작성 했습니다.");
		gotoxy(52, 12);
		printf("주가가 크게 요동칩니다.");
		break;
	case 39:
		gotoxy(52, 10);
		printf("테슬라가 암호화폐 결제를 취소한다고 합니다.");
		gotoxy(52, 12);
		printf("주가가 크게 요동칩니다.");
		break;
	default:
		gotoxy(52, 8);
		printf("오늘은 기사가 없습니다.");
		break;
	}
}

void refreshData(int CoinArray[][5], int futureNewsCoin, int futureNewsPrice)
{
	bool isRandom = false, haveNews = false;
	switch (futureNewsPrice)
	{
	case 0:
		isRandom = false;
		haveNews = true;
		break;
	case 8:
		isRandom = true;
		haveNews = true;
		break;
	case 15:
		isRandom = false;
		haveNews = true;
		break;
	case 27:
		isRandom = false;
		haveNews = true;
		break;
	case 31:
		isRandom = false;
		haveNews = true;
		break;
	case 39:
		isRandom = false;
		haveNews = true;
		break;
	default:
		haveNews = false;
		break;
	}

	if (haveNews != false)
	{
		if (isRandom == false)
		{
			if (CoinArray[futureNewsCoin][1] < 100)
			{
				CoinArray[futureNewsCoin][1] += 100;
			}
			else if (CoinArray[futureNewsCoin][1] < 1000)
			{
				CoinArray[futureNewsCoin][1] += 1000;
			}
			else if (CoinArray[futureNewsCoin][1] < 10000)
			{
				CoinArray[futureNewsCoin][1] += 10000;
			}
			else if (CoinArray[futureNewsCoin][1] < 100000)
			{
				CoinArray[futureNewsCoin][1] += 100000;
			}
			else
			{
				CoinArray[futureNewsCoin][1] += 100000;
			}
		}
		else
		{
			if (CoinArray[futureNewsCoin][1] <= 0)
			{
				CoinArray[futureNewsCoin][1] = 5;
			}
			else if (CoinArray[futureNewsCoin][1] < 10)
			{
				CoinArray[futureNewsCoin][1] -= 5;
			}
			else if (CoinArray[futureNewsCoin][1] < 100)
			{
				CoinArray[futureNewsCoin][1] -= 50;
			}
			else if (CoinArray[futureNewsCoin][1] < 1000)
			{
				CoinArray[futureNewsCoin][1] -= 500;
			}
			else if (CoinArray[futureNewsCoin][1] < 10000)
			{
				CoinArray[futureNewsCoin][1] -= 5000;
			}
			else if (CoinArray[futureNewsCoin][1] < 100000)
			{
				CoinArray[futureNewsCoin][1] -= 50000;
			}
			else
			{
				CoinArray[futureNewsCoin][1] -= 50000;
			}
		}

		FILE* writeCoinFile;
		writeCoinFile = fopen("코인 데이터.txt", "wt");

		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				fprintf(writeCoinFile, "%d ", CoinArray[i][j]);
			}
		}
		fclose(writeCoinFile);
	}
}
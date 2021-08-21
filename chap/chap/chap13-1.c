// main 함수에 인자가 있을 경우 예제
#include <stdio.h>

int main(int argc, char* argv[ ])
{
	printf("문자열의 수: %d\n", argc);

	for (int i = 0; i < argc; i++)
	{
		printf("%d 번째 문자열: %s\n", i, argv[i]);
	}

	if (argc > 4)
	{
		return 1; // 운영체제가 main() 함수를 호출했기 때문에 C 프로그램이 운영제체에게 1을 반환하고 프로그램을 종료한다는 의미
	}

	/*
	* chap->속성 - > 디버깅->명령 인수에 추가하면 실행할때 뜸
	* int argc 문자열의 수를 저장
	* char* argv[ ] 문자열의 첫 번째 주소를 저장
	* 
	* 개발환경에서 main() 함수의 인자를 설정하기도 하고 cmd 에서 main() 함수의 인자를 전달하기도한다. 
	* 실행파일을 직접 명령어로 실행할때 전달 가능하다. EX) MAIN.exe Good Morning
	*/
}
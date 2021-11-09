#include "lex.h"

int expr_count=0;
void expr(); //함수 정의
void exprx();
void term();
void termx();
void termx();
void factor();

int main() { //메인 함수
	printf("$까지 한 문장으로 인식합니다. 문장을 입력하세요.\n");
	while (1) {
		if (c == ' ') //띄어쓰기 검출
			while (c == ' ')
				c = getc(stdin);
		if (c == '$') { //문자가 $이면
			printf("\ncorrect!\n"); //correct출력
			return 0; //종료
		}
		expr_count++; //expr_count증가
		if (expr_count >= 2) { //2번 이상이면 즉, 한 문장에 두 문장이상 들어오면
			printf("error"); //오류 출력
			return 0; //종료
		}
		c = getc(stdin); //다음 문자를 읽는다.
		expr(); //expr호출
	}
}

void expr() { //expr함수
	printf("1 "); //문법 1번
	term(); //term호출
	exprx(); //exprx호출
}

void exprx() { //exprx함수
	if (c == '+') { //+이면
		printf("2 "); //2번 문법
		c = getc(stdin); //다음 문자를 읽는다
		if (c == ' ') //띄어쓰기 검출
			while (c == ' ') //공백이면 반복
				c = getc(stdin); //다음문자 읽기
		term(); //term호출
		exprx(); //exprx호출
	}
	else if (c == '-') { //-이면
		printf("3 "); //3번 문법
		c = getc(stdin); //다음 문자를 읽는다
		if (c == ' ') //띄어쓰기 검출
			while (c == ' ') //공백이면 반복
				c = getc(stdin); //다음문자 읽기
		term(); //term호출
		exprx(); //exprx호출
	}
	else
		printf("7 "); //7번 문법
}

void term() { //term함수
	printf("4 "); //4번 문법
	factor(); //factor호출
	termx(); //termx호출
}

void termx() { //termx 함수
	if (c == '*') { //*이면
		printf("5 "); //5번 문법
		c = getc(stdin); //다음 문자를 읽는다
		if (c == ' ') //띄어쓰기 검출
			while(c==' ') //공백이면 반복
				c = getc(stdin); //다음문자 읽기
		factor(); //factor호출
		termx(); //termx호출
	}
	else if (c == '/') { // /이면
		printf("6 "); //6번 문법
		c = getc(stdin); //다음 문자를 읽는다
		if (c == ' ') //띄어쓰기 검출
			while (c == ' ') //공백이면 반복
				c = getc(stdin); //다음문자 읽기
		factor(); //factor호출
		termx(); //termx호출
	}
	else { //나머지
		printf("8 "); //8번 문법
	}
}

void factor() { //factor 함수
	if (isdigit(c)) { //숫자이면
		printf("9 "); //9번 문법
		digit(&c); //과제2 모듈인 lex의 digit함수 사용
		if (c == ' ') //띄어쓰기 검출
			while (c == ' ') //공백이면 반복
				c = getc(stdin); //다음문자 읽기
	}
	else if (isalpha(c)) { //알파벳이면
		printf("10 "); //10번 문법
		alpha(&c); //과제2 모듈인 lex의 alpha함수 사용
		if (c == ' ') //띄어쓰기 검출
			while (c == ' ') //공백이면 반복
				c = getc(stdin); //다음문자 읽기
	}
	else if (c == '(') { // (이면
		printf("11 "); //11번 문법
		c = getc(stdin); //다음 문자를 읽는다
		if (c == ' ') //띄어쓰기 검출
			while (c == ' ') //공백이면 반복
				c = getc(stdin); //다음문자 읽기
		expr(); //expr호출
		if (c == ' ') //띄어쓰기 검출
			while (c == ' ') //공백이면 반복
				c = getc(stdin); //다음문자 읽기
		if (c != ')') { // )가 아니면
			printf("error"); //에러 출력
			exit(0); //종료
		}
		c = getc(stdin); //다음 문자를 읽어
		if (c == ' ') //띄어쓰기 검출
			while (c == ' ') //공백이면 반복
				c = getc(stdin); //다음문자 읽기
	}
	else { //나머지 특수문자이면
		printf("error"); //에러 출력
		exit(0); //종료
	}
}
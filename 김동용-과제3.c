#include <stdio.h> //표준입출력 헤더파일
#include <ctype.h> //getc사용

char lookahead; //문자를 읽을 변수

void expr(); //함수 정의
void exprx();
void term();
void termx();
void termx();
void factor();

int main() { //메인 함수
	while (1) {
		if (lookahead == '$') { //문자가 $이면
			printf("\ncorrect!\n"); //correct출력
			return 0; //종료
		}
		lookahead = getc(stdin); //다음 문자를 읽는다.
		expr(); //expr호출
	}
}

void expr() { //expr함수
	printf("1 "); //문법 1번
	term(); //term호출
	exprx(); //exprx호출
}

void exprx() { //exprx함수
	if (lookahead == '+') { //+이면
		printf("2 "); //2번 문법
		lookahead = getc(stdin); //다음 문자를 읽는다
		//if (!(isdigit(lookahead)||isalpha(lookahead)||lookahead=='(')) { //숫자, 문자, (가 아니면
		//	printf("error"); //오류
		//	exit(0); //종료
		//}
		term(); //term호출
		exprx(); //exprx호출
	}
	else if (lookahead == '-') { //-이면
		printf("3 "); //3번 문법
		lookahead = getc(stdin); //다음 문자를 읽는다
		//if (!(isdigit(lookahead) || isalpha(lookahead) || lookahead == '(')) { //숫자, 문자, (가 아니면
		//	printf("error"); //에러 출력
		//	exit(0); //종료
		//}
		term(); //term호출
		exprx(); //exprx호출
	}
	else if (lookahead == '$' || lookahead == ')') {
		printf("7 ");
	}
	else {
		printf("error");
		exit(0);
	}
}

void term() { //term함수
	printf("4 "); //4번 문법
	factor(); //factor호출
	termx(); //termx호출
}

void termx() { //termx 함수
	if (lookahead == '*') { //*이면
		printf("5 "); //5번 문법
		lookahead = getc(stdin); //다음 문자를 읽는다
		//if (!(isdigit(lookahead) || isalpha(lookahead) || lookahead == '(')) { //숫자, 문자, (가 아니면
		//	printf("error"); //에러 출력
		//	exit(0); //종료
		//}
		factor(); //factor호출
		termx(); //termx호출
	}
	else if (lookahead == '/') { // /이면
		printf("6 "); //6번 문법
		lookahead = getc(stdin); //다음 문자를 읽는다
		//if (!(isdigit(lookahead) || isalpha(lookahead) || lookahead == '(')) { //숫자, 문자, (가 아니면
		//	printf("error"); //에러 출력
		//	exit(0); //종료
		//}
		factor(); //factor호출
		termx(); //termx호출
	}
	else { //나머지
		printf("8 "); //8번 문법
	}
}

void factor() { //factor 함수
	if (isdigit(lookahead)) { //숫자이면
		printf("9 "); //9번 문법
		while (isdigit(lookahead)) { //숫자이면 반복
			lookahead = getc(stdin); //다음 문자를 읽는다
		}
		if (lookahead == '(') { // (이면
			printf("error"); //에러 출력
			exit(0); //종료
		}
	}
	else if (isalpha(lookahead)) { //알파벳이면
		printf("10 "); //10번 문법
		while (isdigit(lookahead) || isalpha(lookahead)) { //숫자나 문자이면 반복
			lookahead = getc(stdin); //다음 문자를 읽는다
		}
		if (lookahead == '('){ // (이면
			printf("error"); //에러 출력
			exit(0); //종료
		}
	}
	else if (lookahead == '(') { // (이면
		printf("11 "); //11번 문법
		lookahead = getc(stdin); //다음 문자를 읽는다
		expr(); //expr호출
		if (lookahead != ')') { // )가 아니면
			printf("error"); //에러 출력
			exit(0); //종료
		}
		lookahead = getc(stdin); //다음 문자를 읽어
		if (!(lookahead == '+' || lookahead == '-' || lookahead == '*' || lookahead == '/' || lookahead == '$'||lookahead==')')) { //연산자, $, )가 아니면
			printf("error"); //에러 출력
			exit(0); //종료
		}
	}
	else { //나머지 특수문자이면
		printf("error"); //에러 출력
		exit(0); //종료
	}
}

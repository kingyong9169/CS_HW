#ifndef LEX //과제 2 소스파일을 모듈화
#define LEX


#include <stdio.h> //표준 입출력 헤더파일 포함
#include <ctype.h> //isdigit, isalpha사용을 위한 헤더파일

static int count = 0; //맨 처음에 연산자가 나오는지 판단하는 변수
static int button1 = 0, button2 = 0; //괄호의 갯수를 세는 변수
static char c; //문자를 읽을 변수

void digit(char* c); //함수 정의
void alpha(char* c);
void left_para(char* c);
void right_para(char* c);
void oper(char* c);

#endif // !ANALYZER
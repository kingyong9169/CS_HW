#include "lex.h" //과제 2 소스파일을 모듈화

void alpha(char* c) {
    while (isdigit(*c) || isalpha(*c)) //숫자나 알파벳이면 반복
       *c = getc(stdin); //다음 문자를 하나씩 읽는다.
    if (!((*c) == '+' || (*c) == '-' || (*c) == '*' || (*c) == '/' || (*c) == ' ' || (*c) == '\t' || (*c) == '$' || (*c) == ')')) { //연산자, 공백, 탭, $, 엔터, )이면
        printf("error\n"); //문법오류
        exit(0); //프로그램 종료
    }
}

void digit(char* c) {
    while (1) { //무한루프
        if ((*c) == '+' || (*c) == '-' || (*c) == '*' || (*c) == '/' || (*c) == ' ' || (*c) == '\t' || (*c) == '$' || (*c) == ')') { //연산자, 공백, 탭, $, 엔터, )이면
            break; //반복문 탈출
        }
        else if (isdigit(*c)) { //숫자이면
            *c = getc(stdin); //뒤의 문자를 하나씩 읽는다.
            continue; //반복문의 다음 사이클로
        }
        else { //나머지
            printf("error\n"); //문법오류
            exit(0); //프로그램 종료
        }
    }
}

void oper(char* c) {
    if (count == 1) { //카운트가 1이면
        printf("\ngrammar error!\n"); //문법 오류
        exit(0); //프로그램 종료
    }
    printf("%c", *c); //바로 출력
    c = getc(stdin); //연산자 뒤의 문자를 하나 읽는다.
    if (!(isdigit(*c) || isalpha(*c) || (*c) == ' ' || (*c) == '\t' || (*c) == '(')) { //숫자, 알파벳, 공백, 탭이 아니면
        printf("\ngrammar error!\n"); //문법 오류
        exit(0); //프로그램 종료
    }
    ungetc(*c, stdin); //ungetc로 읽었던 문자 되돌리기
}

void left_para(char* c) {
    button1++; //button1 1증가
    if (!(isdigit(*c) || isalpha(*c) || (*c) == ' ' || (*c) == '\t' || (*c) == '(')) { //문자, 숫자, 공백, 탭, (이 아니면
        printf("\ngrammar error!\n"); //문법 오류
        exit(0); //프로그램 종료
    }
    printf("("); //여는 괄호입력
    ungetc(*c, stdin); //ungetc로 읽었던 문자 되돌리기
}

void right_para(char* c) {
    button2++; //button2 1증가
    if (!((*c) == '+' || (*c) == '-' || (*c) == '*' || (*c) == '/' || (*c) == ' ' || (*c) == '\t' || (*c) == '$' || (*c) == '\n' || (*c) == ')')) { //연산자, 공백, 탭, 엔터, $, )가 아니면
        printf("\ngrammar error!\n"); //문법 오류
        exit(0); //프로그램 종료
    }
    printf(")"); //닫는 괄호입력
    ungetc(*c, stdin); //ungetc로 읽었던 문자 되돌리기
}
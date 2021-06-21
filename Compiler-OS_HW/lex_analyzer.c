#include <stdio.h> //표준입출력 헤더파일
#include <ctype.h> //isdigit, isalpha사용을 위한 헤더파일

int main()
{
    char c; //문자를 읽을 변수
    int count = 0; //맨 처음에 연산자가 나오는지 판단하는 변수
    int button1=0, button2=0; //괄호의 갯수를 세는 변수
    printf("$를 입력해야 프로그램을 종료합니다.\n");
    printf("입력 : ");
    
    while (1) //무한루프
    {
        c = getc(stdin); //프로그램 첫 실행에 문자열 입력, 이후에 문자 하나씩 읽는다.
        count++; //카운트 증가
        if (c == ' ' || c == '\t' || c == '\n') { //공백, 탭, 엔터의 경우
            if (c == '\n') {//엔터이면
                printf("\n"); //개행문자입력
                count = 0; //초기화
                if (button1 != button2) {
                    printf("\ngrammar error!\n"); //문법오류
                    return 0; //프로그램 종료
                }
            }
            continue; //무시하고 반복문의 다음 사이클로
        }

        else if (isalpha(c)) { //알파벳이면
            c = getc(stdin); //알파벳 다음 문자를 하나씩 읽는다.
            while (isdigit(c) || isalpha(c)) //숫자나 알파벳이면 반복
                c = getc(stdin); //다음 문자를 하나씩 읽는다.
            if (c == '(') {
                printf("\ngrammar error!\n"); //문법오류
                return 0; //프로그램 종료
            }
            printf("ID"); //ID출력
            ungetc(c, stdin); //ungetc로 읽었던 문자 되돌리기
        }

        else if (isdigit(c)) //숫자이면
        {
            c = getc(stdin); //숫자 뒤의 문자를 하나씩 읽는다.
            while (1) { //무한루프
                if (c == '+' || c == '-' || c == '*' || c == '/' || c == ' ' || c == '\t' || c == '$'||c=='\n'||c==')') { //연산자, 공백, 탭, $, 엔터, )이면
                    break; //반복문 탈출
                }
                else if (isdigit(c)) { //숫자이면
                    c = getc(stdin); //뒤의 문자를 하나씩 읽는다.
                    continue; //반복문의 다음 사이클로
                }
                else { //나머지
                    printf("\ngrammar error!\n"); //문법오류
                    return 0; //프로그램 종료
                }
            }
            printf("NUM"); //NUM출력
            ungetc(c, stdin); //ungetc로 읽었던 문자 되돌리기
            continue; //반복문 다음 사이클로
        }

        else if (c == '+' || c == '-' || c == '*' || c == '/') //연산자이면
        {
            if (count == 1) { //카운트가 1이면
                printf("\ngrammar error!\n"); //문법 오류
                return 0; //프로그램 종료
            }
            printf("%c", c); //바로 출력
            c = getc(stdin); //연산자 뒤의 문자를 하나 읽는다.
            if (!(isdigit(c) || isalpha(c) || c == ' ' || c=='\t' || c == '(')) { //숫자, 알파벳, 공백, 탭이 아니면
                printf("\ngrammar error!\n"); //문법 오류
                return 0; //프로그램 종료
            }
            ungetc(c, stdin); //ungetc로 읽었던 문자 되돌리기
        }

        else if (c == '$'&&button1==button2) { //$이고 button이 서로 같으면
            printf("$"); //출력
            return 0; //프로그램 종료
        }

        else if (c == '$' && button1 != button2) { //$이고 button이 서로 다르면
            printf("\ngrammar error!\n"); //문법 오류
            return 0; //프로그램 종료
        }

        else if (c == '('||c==')') { //괄호의 경우
            if (c == '(') {//여는 괄호이면
                button1++; //button1 1증가
                c = getc(stdin); //연산자 뒤의 문자를 하나 읽는다.
                if (!(isdigit(c) || isalpha(c) || c == ' ' || c == '\t' || c == '(')) { //문자, 숫자, 공백, 탭, (이 아니면
                    printf("\ngrammar error!\n"); //문법 오류
                    return 0; //프로그램 종료
                }
                printf("("); //여는 괄호입력
                ungetc(c, stdin); //ungetc로 읽었던 문자 되돌리기
                continue; //무시하고 반복문의 다음 사이클로
            }
            else if (')') { //닫는 괄호이면
                button2++; //button2 1증가
                c = getc(stdin); //연산자 뒤의 문자를 하나 읽는다.
                if (!( c == '+' || c == '-' || c == '*' || c == '/' || c == ' ' || c == '\t'||c=='$'|| c == '\n'||c==')')) { //연산자, 공백, 탭, 엔터, $, )가 아니면
                    printf("\ngrammar error!\n"); //문법 오류
                    return 0; //프로그램 종료
                }
                printf(")"); //닫는 괄호입력
                ungetc(c, stdin); //ungetc로 읽었던 문자 되돌리기
                continue; //무시하고 반복문의 다음 사이클로
            }
        }

        else { //나머지의 경우
            printf("\ngrammar error!\n"); //문법 오류
            return 0; //프로그램 종료
        }
    } //반복문의 끝

    return 0; //프로그램 종료
}

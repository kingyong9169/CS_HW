#ifndef LEX //���� 2 �ҽ������� ���ȭ
#define LEX


#include <stdio.h> //ǥ�� ����� ������� ����
#include <ctype.h> //isdigit, isalpha����� ���� �������

static int count = 0; //�� ó���� �����ڰ� �������� �Ǵ��ϴ� ����
static int button1 = 0, button2 = 0; //��ȣ�� ������ ���� ����
static char c; //���ڸ� ���� ����

void digit(char* c); //�Լ� ����
void alpha(char* c);
void left_para(char* c);
void right_para(char* c);
void oper(char* c);

#endif // !ANALYZER
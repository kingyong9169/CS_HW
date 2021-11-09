#include "lex.h" //���� 2 �ҽ������� ���ȭ

void alpha(char* c) {
    while (isdigit(*c) || isalpha(*c)) //���ڳ� ���ĺ��̸� �ݺ�
       *c = getc(stdin); //���� ���ڸ� �ϳ��� �д´�.
    if (!((*c) == '+' || (*c) == '-' || (*c) == '*' || (*c) == '/' || (*c) == ' ' || (*c) == '\t' || (*c) == '$' || (*c) == ')')) { //������, ����, ��, $, ����, )�̸�
        printf("error\n"); //��������
        exit(0); //���α׷� ����
    }
}

void digit(char* c) {
    while (1) { //���ѷ���
        if ((*c) == '+' || (*c) == '-' || (*c) == '*' || (*c) == '/' || (*c) == ' ' || (*c) == '\t' || (*c) == '$' || (*c) == ')') { //������, ����, ��, $, ����, )�̸�
            break; //�ݺ��� Ż��
        }
        else if (isdigit(*c)) { //�����̸�
            *c = getc(stdin); //���� ���ڸ� �ϳ��� �д´�.
            continue; //�ݺ����� ���� ����Ŭ��
        }
        else { //������
            printf("error\n"); //��������
            exit(0); //���α׷� ����
        }
    }
}

void oper(char* c) {
    if (count == 1) { //ī��Ʈ�� 1�̸�
        printf("\ngrammar error!\n"); //���� ����
        exit(0); //���α׷� ����
    }
    printf("%c", *c); //�ٷ� ���
    c = getc(stdin); //������ ���� ���ڸ� �ϳ� �д´�.
    if (!(isdigit(*c) || isalpha(*c) || (*c) == ' ' || (*c) == '\t' || (*c) == '(')) { //����, ���ĺ�, ����, ���� �ƴϸ�
        printf("\ngrammar error!\n"); //���� ����
        exit(0); //���α׷� ����
    }
    ungetc(*c, stdin); //ungetc�� �о��� ���� �ǵ�����
}

void left_para(char* c) {
    button1++; //button1 1����
    if (!(isdigit(*c) || isalpha(*c) || (*c) == ' ' || (*c) == '\t' || (*c) == '(')) { //����, ����, ����, ��, (�� �ƴϸ�
        printf("\ngrammar error!\n"); //���� ����
        exit(0); //���α׷� ����
    }
    printf("("); //���� ��ȣ�Է�
    ungetc(*c, stdin); //ungetc�� �о��� ���� �ǵ�����
}

void right_para(char* c) {
    button2++; //button2 1����
    if (!((*c) == '+' || (*c) == '-' || (*c) == '*' || (*c) == '/' || (*c) == ' ' || (*c) == '\t' || (*c) == '$' || (*c) == '\n' || (*c) == ')')) { //������, ����, ��, ����, $, )�� �ƴϸ�
        printf("\ngrammar error!\n"); //���� ����
        exit(0); //���α׷� ����
    }
    printf(")"); //�ݴ� ��ȣ�Է�
    ungetc(*c, stdin); //ungetc�� �о��� ���� �ǵ�����
}
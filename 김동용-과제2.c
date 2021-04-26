#include <stdio.h> //ǥ������� �������
#include <ctype.h> //isdigit, isalpha����� ���� �������

int main()
{
    char c; //���ڸ� ���� ����
    int count = 0; //�� ó���� �����ڰ� �������� �Ǵ��ϴ� ����
    int button1=0, button2=0; //��ȣ�� ������ ���� ����
    printf("$�� �Է��ؾ� ���α׷��� �����մϴ�.\n");
    printf("�Է� : ");
    
    while (1) //���ѷ���
    {
        c = getc(stdin); //���α׷� ù ���࿡ ���ڿ� �Է�, ���Ŀ� ���� �ϳ��� �д´�.
        count++; //ī��Ʈ ����
        if (c == ' ' || c == '\t' || c == '\n') { //����, ��, ������ ���
            if (c == '\n') {//�����̸�
                printf("\n"); //���๮���Է�
                count = 0; //�ʱ�ȭ
                if (button1 != button2) {
                    printf("\ngrammar error!\n"); //��������
                    return 0; //���α׷� ����
                }
            }
            continue; //�����ϰ� �ݺ����� ���� ����Ŭ��
        }

        else if (isalpha(c)) { //���ĺ��̸�
            c = getc(stdin); //���ĺ� ���� ���ڸ� �ϳ��� �д´�.
            while (isdigit(c) || isalpha(c)) //���ڳ� ���ĺ��̸� �ݺ�
                c = getc(stdin); //���� ���ڸ� �ϳ��� �д´�.
            if (c == '(') {
                printf("\ngrammar error!\n"); //��������
                return 0; //���α׷� ����
            }
            printf("ID"); //ID���
            ungetc(c, stdin); //ungetc�� �о��� ���� �ǵ�����
        }

        else if (isdigit(c)) //�����̸�
        {
            c = getc(stdin); //���� ���� ���ڸ� �ϳ��� �д´�.
            while (1) { //���ѷ���
                if (c == '+' || c == '-' || c == '*' || c == '/' || c == ' ' || c == '\t' || c == '$'||c=='\n'||c==')') { //������, ����, ��, $, ����, )�̸�
                    break; //�ݺ��� Ż��
                }
                else if (isdigit(c)) { //�����̸�
                    c = getc(stdin); //���� ���ڸ� �ϳ��� �д´�.
                    continue; //�ݺ����� ���� ����Ŭ��
                }
                else { //������
                    printf("\ngrammar error!\n"); //��������
                    return 0; //���α׷� ����
                }
            }
            printf("NUM"); //NUM���
            ungetc(c, stdin); //ungetc�� �о��� ���� �ǵ�����
            continue; //�ݺ��� ���� ����Ŭ��
        }

        else if (c == '+' || c == '-' || c == '*' || c == '/') //�������̸�
        {
            if (count == 1) { //ī��Ʈ�� 1�̸�
                printf("\ngrammar error!\n"); //���� ����
                return 0; //���α׷� ����
            }
            printf("%c", c); //�ٷ� ���
            c = getc(stdin); //������ ���� ���ڸ� �ϳ� �д´�.
            if (!(isdigit(c) || isalpha(c) || c == ' ' || c=='\t' || c == '(')) { //����, ���ĺ�, ����, ���� �ƴϸ�
                printf("\ngrammar error!\n"); //���� ����
                return 0; //���α׷� ����
            }
            ungetc(c, stdin); //ungetc�� �о��� ���� �ǵ�����
        }

        else if (c == '$'&&button1==button2) { //$�̰� button�� ���� ������
            printf("$"); //���
            return 0; //���α׷� ����
        }

        else if (c == '$' && button1 != button2) { //$�̰� button�� ���� �ٸ���
            printf("\ngrammar error!\n"); //���� ����
            return 0; //���α׷� ����
        }

        else if (c == '('||c==')') { //��ȣ�� ���
            if (c == '(') {//���� ��ȣ�̸�
                button1++; //button1 1����
                c = getc(stdin); //������ ���� ���ڸ� �ϳ� �д´�.
                if (!(isdigit(c) || isalpha(c) || c == ' ' || c == '\t' || c == '(')) { //����, ����, ����, ��, (�� �ƴϸ�
                    printf("\ngrammar error!\n"); //���� ����
                    return 0; //���α׷� ����
                }
                printf("("); //���� ��ȣ�Է�
                ungetc(c, stdin); //ungetc�� �о��� ���� �ǵ�����
                continue; //�����ϰ� �ݺ����� ���� ����Ŭ��
            }
            else if (')') { //�ݴ� ��ȣ�̸�
                button2++; //button2 1����
                c = getc(stdin); //������ ���� ���ڸ� �ϳ� �д´�.
                if (!( c == '+' || c == '-' || c == '*' || c == '/' || c == ' ' || c == '\t'||c=='$'|| c == '\n'||c==')')) { //������, ����, ��, ����, $, )�� �ƴϸ�
                    printf("\ngrammar error!\n"); //���� ����
                    return 0; //���α׷� ����
                }
                printf(")"); //�ݴ� ��ȣ�Է�
                ungetc(c, stdin); //ungetc�� �о��� ���� �ǵ�����
                continue; //�����ϰ� �ݺ����� ���� ����Ŭ��
            }
        }

        else { //�������� ���
            printf("\ngrammar error!\n"); //���� ����
            return 0; //���α׷� ����
        }
    } //�ݺ����� ��

    return 0; //���α׷� ����
}
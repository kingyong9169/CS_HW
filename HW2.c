#include <stdio.h> //ǥ������� �������
#include <ctype.h> //isdigit, isalpha����� ���� �������

int main()
{
    char c; //���ڸ� ���� ����
    printf("$�� �Է��ϸ� ���α׷��� �����մϴ�.\n");
    printf("�Է� : ");
    
    while (1) //���ѷ���
    {
        c = getc(stdin); //���α׷� ù ���࿡ ���ڿ� �Է�, ���Ŀ� ���� �ϳ��� �д´�.

        if (c == ' ' || c == '\t' || c == '\n') { //����, ��, ������ ���
            if (c == '\n')//�����̸�
                printf("\n"); //���๮���Է�
            continue; //�����ϰ� �ݺ����� ���� ����Ŭ��
        }

        else if (isalpha(c)) { //���ĺ��̸�
            c = getc(stdin); //���ĺ� ���� ���ڸ� �ϳ��� �д´�.
            while (isdigit(c) || isalpha(c)) //���ڳ� ���ĺ��̸� �ݺ�
                c = getc(stdin); //���� ���ڸ� �ϳ��� �д´�.
            printf("ID"); //ID���
            ungetc(c, stdin); //ungetc�� �о��� ���� �ǵ�����
        }

        else if (isdigit(c)) //�����̸�
        {
            c = getc(stdin); //���� ���� ���ڸ� �ϳ��� �д´�.
            while (1) { //���ѷ���
                if (c == '+' || c == '-' || c == '*' || c == '/' || c == ' ' || c == '\t' || c == '$'||c=='\n') { //������, ����, ��, $, �����̸�
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
            printf("%c", c); //�ٷ� ���
            c = getc(stdin); //������ ���� ���ڸ� �ϳ� �д´�.
            if (!(isdigit(c) || isalpha(c) || c == ' ' || c=='\t')) { //����, ���ĺ�, ����, ���� �ƴϸ�
                printf("\ngrammar error!\n"); //���� ����
                return 0; //���α׷� ����
            }
            ungetc(c, stdin); //ungetc�� �о��� ���� �ǵ�����
        }

        else if (c == '$') { //$�̸�
            printf("$"); //���
            return 0; //���α׷� ����
        }

        else { //�������� ���
            printf("\ngrammar error!\n"); //���� ����
            return 0; //���α׷� ����
        }
    } //�ݺ����� ��

    return 0; //���α׷� ����
}
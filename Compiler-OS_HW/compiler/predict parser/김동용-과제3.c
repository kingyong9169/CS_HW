#include "lex.h"

int expr_count=0;
void expr(); //�Լ� ����
void exprx();
void term();
void termx();
void termx();
void factor();

int main() { //���� �Լ�
	printf("$���� �� �������� �ν��մϴ�. ������ �Է��ϼ���.\n");
	while (1) {
		if (c == ' ') //���� ����
			while (c == ' ')
				c = getc(stdin);
		if (c == '$') { //���ڰ� $�̸�
			printf("\ncorrect!\n"); //correct���
			return 0; //����
		}
		expr_count++; //expr_count����
		if (expr_count >= 2) { //2�� �̻��̸� ��, �� ���忡 �� �����̻� ������
			printf("error"); //���� ���
			return 0; //����
		}
		c = getc(stdin); //���� ���ڸ� �д´�.
		expr(); //exprȣ��
	}
}

void expr() { //expr�Լ�
	printf("1 "); //���� 1��
	term(); //termȣ��
	exprx(); //exprxȣ��
}

void exprx() { //exprx�Լ�
	if (c == '+') { //+�̸�
		printf("2 "); //2�� ����
		c = getc(stdin); //���� ���ڸ� �д´�
		if (c == ' ') //���� ����
			while (c == ' ') //�����̸� �ݺ�
				c = getc(stdin); //�������� �б�
		term(); //termȣ��
		exprx(); //exprxȣ��
	}
	else if (c == '-') { //-�̸�
		printf("3 "); //3�� ����
		c = getc(stdin); //���� ���ڸ� �д´�
		if (c == ' ') //���� ����
			while (c == ' ') //�����̸� �ݺ�
				c = getc(stdin); //�������� �б�
		term(); //termȣ��
		exprx(); //exprxȣ��
	}
	else
		printf("7 "); //7�� ����
}

void term() { //term�Լ�
	printf("4 "); //4�� ����
	factor(); //factorȣ��
	termx(); //termxȣ��
}

void termx() { //termx �Լ�
	if (c == '*') { //*�̸�
		printf("5 "); //5�� ����
		c = getc(stdin); //���� ���ڸ� �д´�
		if (c == ' ') //���� ����
			while(c==' ') //�����̸� �ݺ�
				c = getc(stdin); //�������� �б�
		factor(); //factorȣ��
		termx(); //termxȣ��
	}
	else if (c == '/') { // /�̸�
		printf("6 "); //6�� ����
		c = getc(stdin); //���� ���ڸ� �д´�
		if (c == ' ') //���� ����
			while (c == ' ') //�����̸� �ݺ�
				c = getc(stdin); //�������� �б�
		factor(); //factorȣ��
		termx(); //termxȣ��
	}
	else { //������
		printf("8 "); //8�� ����
	}
}

void factor() { //factor �Լ�
	if (isdigit(c)) { //�����̸�
		printf("9 "); //9�� ����
		digit(&c); //����2 ����� lex�� digit�Լ� ���
		if (c == ' ') //���� ����
			while (c == ' ') //�����̸� �ݺ�
				c = getc(stdin); //�������� �б�
	}
	else if (isalpha(c)) { //���ĺ��̸�
		printf("10 "); //10�� ����
		alpha(&c); //����2 ����� lex�� alpha�Լ� ���
		if (c == ' ') //���� ����
			while (c == ' ') //�����̸� �ݺ�
				c = getc(stdin); //�������� �б�
	}
	else if (c == '(') { // (�̸�
		printf("11 "); //11�� ����
		c = getc(stdin); //���� ���ڸ� �д´�
		if (c == ' ') //���� ����
			while (c == ' ') //�����̸� �ݺ�
				c = getc(stdin); //�������� �б�
		expr(); //exprȣ��
		if (c == ' ') //���� ����
			while (c == ' ') //�����̸� �ݺ�
				c = getc(stdin); //�������� �б�
		if (c != ')') { // )�� �ƴϸ�
			printf("error"); //���� ���
			exit(0); //����
		}
		c = getc(stdin); //���� ���ڸ� �о�
		if (c == ' ') //���� ����
			while (c == ' ') //�����̸� �ݺ�
				c = getc(stdin); //�������� �б�
	}
	else { //������ Ư�������̸�
		printf("error"); //���� ���
		exit(0); //����
	}
}
#include <stdio.h> //ǥ������� �������
#include <ctype.h> //getc���

char lookahead; //���ڸ� ���� ����

void expr(); //�Լ� ����
void exprx();
void term();
void termx();
void termx();
void factor();

int main() { //���� �Լ�
	while (1) {
		if (lookahead == '$') { //���ڰ� $�̸�
			printf("\ncorrect!\n"); //correct���
			return 0; //����
		}
		if(lookahead!=' ') //��ū �и��� ���� �ʴ´ٸ�
			lookahead = getc(stdin); //���� ���ڸ� �д´�.
		expr(); //exprȣ��
	}
}

void expr() { //expr�Լ�
	printf("1 "); //���� 1��
	term(); //termȣ��
	exprx(); //exprxȣ��
}

void exprx() { //exprx�Լ�
	if (lookahead == '+') { //+�̸�
		printf("2 "); //2�� ����
		lookahead = getc(stdin); //���� ���ڸ� �д´�
		//if (!(isdigit(lookahead)||isalpha(lookahead)||lookahead=='(')) { //����, ����, (�� �ƴϸ�
		//	printf("error"); //����
		//	exit(0); //����
		//}
		term(); //termȣ��
		exprx(); //exprxȣ��
	}
	else if (lookahead == '-') { //-�̸�
		printf("3 "); //3�� ����
		lookahead = getc(stdin); //���� ���ڸ� �д´�
		//if (!(isdigit(lookahead) || isalpha(lookahead) || lookahead == '(')) { //����, ����, (�� �ƴϸ�
		//	printf("error"); //���� ���
		//	exit(0); //����
		//}
		term(); //termȣ��
		exprx(); //exprxȣ��
	}
	else { //������
		printf("7 "); //7�� ����
	}
}

void term() { //term�Լ�
	printf("4 "); //4�� ����
	factor(); //factorȣ��
	termx(); //termxȣ��
}

void termx() { //termx �Լ�
	if (lookahead == '*') { //*�̸�
		printf("5 "); //5�� ����
		lookahead = getc(stdin); //���� ���ڸ� �д´�
		//if (!(isdigit(lookahead) || isalpha(lookahead) || lookahead == '(')) { //����, ����, (�� �ƴϸ�
		//	printf("error"); //���� ���
		//	exit(0); //����
		//}
		factor(); //factorȣ��
		termx(); //termxȣ��
	}
	else if (lookahead == '/') { // /�̸�
		printf("6 "); //6�� ����
		lookahead = getc(stdin); //���� ���ڸ� �д´�
		//if (!(isdigit(lookahead) || isalpha(lookahead) || lookahead == '(')) { //����, ����, (�� �ƴϸ�
		//	printf("error"); //���� ���
		//	exit(0); //����
		//}
		factor(); //factorȣ��
		termx(); //termxȣ��
	}
	else { //������
		printf("8 "); //8�� ����
	}
}

void factor() { //factor �Լ�
	if (isdigit(lookahead)) { //�����̸�
		printf("9 "); //9�� ����
		while (isdigit(lookahead)) { //�����̸� �ݺ�
			lookahead = getc(stdin); //���� ���ڸ� �д´�
		}
		if (lookahead == '(') { // (�̸�
			printf("error"); //���� ���
			exit(0); //����
		}
	}
	else if (isalpha(lookahead)) { //���ĺ��̸�
		printf("10 "); //10�� ����
		while (isdigit(lookahead) || isalpha(lookahead)) { //���ڳ� �����̸� �ݺ�
			lookahead = getc(stdin); //���� ���ڸ� �д´�
		}
		if (lookahead == '('){ // (�̸�
			printf("error"); //���� ���
			exit(0); //����
		}
	}
	else if (lookahead == '(') { // (�̸�
		printf("11 "); //11�� ����
		lookahead = getc(stdin); //���� ���ڸ� �д´�
		expr(); //exprȣ��
		if (lookahead != ')') { // )�� �ƴϸ�
			printf("error"); //���� ���
			exit(0); //����
		}
		lookahead = getc(stdin); //���� ���ڸ� �о�
		if (!(lookahead == '+' || lookahead == '-' || lookahead == '*' || lookahead == '/' || lookahead == '$'||lookahead==')')) { //������, $, )�� �ƴϸ�
			printf("error"); //���� ���
			exit(0); //����
		}
	}
	else { //������ Ư�������̸�
		printf("error"); //���� ���
		exit(0); //����
	}
}
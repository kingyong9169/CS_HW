/*
 * postfix.c
 *
 *  Created on: 2020. 4. 19.
 *      Author: kingyong
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 10
#define MAX_EXPRESSION_SIZE 20

/* stack 내에서 우선순위, lparen = 0 가장 낮음 */
typedef enum{
	lparen=0,  /* ( 왼쪽 괄호 */
	rparen=1,  /* ) 오른쪽 괄호*/
	times=5,   /* * 곱셈 */
	divide=4,  /* / 나눗셈 */
	plus=2,    /* + 덧셈 */
	minus=3,   /* - 뺄셈 */
	operand=6  /* 피연산자 */
} precedence;


char infixExp[MAX_EXPRESSION_SIZE];   	/* infix expression을 저장하는 배열 */
char postfixExp[MAX_EXPRESSION_SIZE];	/* postfix로 변경된 문자열을 저장하는 배열 */
char postfixStack[MAX_STACK_SIZE];	/* postfix로 변환을 위해 필요한 스택 */
int evalStack[MAX_STACK_SIZE];		/* 계산을 위해 필요한 스택 */

int postfixStackTop = -1;  /* postfixStack용 top */
int evalStackTop = -1;	   /* evalStack용 top */

int evalResult = 0;	   /* 계산 결과를 저장 */

void postfixPush(char x) //후위표기식으로 나타낼 때 push함수
{
    postfixStack[++postfixStackTop] = x; //탑에 x값 대입
}

char postfixPop() //후위표기식으로 나타낼 때 pop함수
{
    char x;
    if(postfixStackTop == -1) //top의 위치가 -1이면
        return '\0'; //NULL 반환
    else { //아니면
    	x = postfixStack[postfixStackTop--]; //x에 탑의 위치에 있는 값 대입 후 다음문장에서 top-1적용
    }
    return x; //x반환
}


void evalPush(int x) //후위표기식 연산할 때 push함수
{
    evalStack[++evalStackTop] = x; //탑에 x값 대입
}

int evalPop() //후위표기식 연산할 때 pop함수
{
    if(evalStackTop == -1) //top의 위치가 -1이면
        return -1; //-1반환
    else //아니면
        return evalStack[evalStackTop--]; //탑의 위치에 있는 값 반환 후 다음문장에서 top-1적용
}


/**
 * infix expression을 입력받는다.
 * infixExp에는 입력된 값을 저장한다.
 */
void getInfix() //중위표기식을 사용할 때 값 입력받는 함수
{
    printf("Type the expression >>> ");
    scanf("%s",infixExp); //값을 받는다
}

precedence getToken(char symbol) //토큰을 분리하는 함수
{
	switch(symbol) { //symbol을 비교
	case '(' : return lparen; // (
	case ')' : return rparen; // )
	case '+' : return plus; // +
	case '-' : return minus; // -
	case '/' : return divide; // /
	case '*' : return times; // *
	default : return operand; //피연산자
	}
}
int isp[]={0,19,12,12,13,13,0}; //스택 내부에 있는 연산자들의 초기화
int icp[]={20,19,12,12,13,13,0}; //스택에 들어올 연산자들의 초기화

precedence getPriority(char x) //연산자의 우선순위를 얻는 함수
{
	return getToken(x); //토큰분리함수 호출
}

/**
 * 문자하나를 전달받아, postfixExp에 추가
 */
void charCat(char* c)
{
	if (postfixExp == '\0') //postfixExp에 아무것도 없으면
		strncpy(postfixExp, c, 1); //postfixExp에 하나씩 c를 저장
	else //아니면
		strncat(postfixExp, c, 1); //postfixExp에 하나씩 c를 저장
}

/**
 * infixExp의 문자를 하나씩 읽어가면서 stack을 이용하여 postfix로 변경한다.
 * 변경된 postfix는 postFixExp에 저장된다.
 */
void toPostfix()
{
	/* infixExp의 문자 하나씩을 읽기위한 포인터 */
	char *exp = infixExp; //infixexp의 주소를 exp에 저장
	char a;/* 문자하나를 임시로 저장하기 위한 변수 */
	precedence token; //precedence헝 변수 선언
	/* exp를 증가시켜가면서, 문자를 읽고 postfix로 변경 */
	while(*exp != '\0') //*exp가 NULL이 아닌 동안
	{
		/* 필요한 로직 완성 */
		token=getToken(*exp); //token에 *exp를 토큰시킨 값을 대입한다
		if(token==operand) //token이 숫자이면
			charCat(exp); //postfixexp에 *exp값 대입
		else if(token==rparen){ //token이 )이면
			while(getToken(postfixStack[postfixStackTop])!=lparen){ //스택에 있는 토큰이 (가 아닌 동안
				a=postfixPop();
				charCat(&a); }//exp에 스택에서 pop한 값을 넣어준다
			getToken(postfixPop()); //(를 pop해준다
		}
		else {
			while(isp[getToken(postfixStack[postfixStackTop])]>=icp[getToken(*exp)]){ //스택안의 토큰이 들어올 토큰보다 크거나 같으면
				a=postfixPop();
				charCat(&a);} //exp에 스택에서 pop한 값을 넣어준다
			postfixPush(*exp); //*exp값을 스택에 push한다
			}
		exp++; //exp를 하나 증가시킨다
		}
	while((token=postfixPop()) != '\0'){ //스택에서 pop시킨값을 대입한 token이 NULL이 아닌 동안
		if(token=='(') //만약 토큰이 (이면
			continue; //다시 반복문에 들어간다
		a=token;
		charCat(&a);} //아니면 토큰을 exp에 넣어준다
	printf("%s",postfixExp); //exp를 출력한다
	printf("\n");
	/* 필요한 로직 완성 */
}

void debug()
{
	printf("\n---DEBUG\n");
	printf("infixExp =  %s\n", infixExp); //중위표기법배열을 출력
	printf("postExp =  %s\n", postfixExp); //후위표기법배열을 출력
	printf("eval result = %d\n", evalResult); //계산결과를 출력

	printf("postfixStack : ");
	for(int i = 0; i < MAX_STACK_SIZE; i++)
		printf("%c ", postfixStack[i]); //스택에 있는 문자들을 출력

	printf("\n");

}

void reset()
{
	infixExp[0] = '\0'; //infix배열 첫 원소를 NULL로 초기화
	postfixExp[0] = '\0'; //postfix배열 첫 원소를 NULL로 초기화

	for(int i = 0; i < MAX_STACK_SIZE; i++) //stack에 있는 연산자들을 모두 NULL로 초기화
		postfixStack[i] = '\0';
	for(int i = 0; i < MAX_EXPRESSION_SIZE; i++) //exp에 있는 문자들을 모두 NULL로 초기화
		postfixExp[i]='\0';
	postfixStackTop = -1; //stack의 탑을 -1로 초기화
	evalStackTop = -1; //계산stack의 탑을 -1로 초기화
	evalResult = 0; //계산결과를 0으로 초기화
}

void evaluation()
{
	/* postfixExp, evalStack을 이용한 계산 */
	precedence token; //토큰 선언
	char *exp=postfixExp; //exp의 주소에 후위표기법배열의 주소를 대입
	int op1,op2; //피연산자 선언
	while(*exp!='\0'){ //exp가 NULL이 아닌 동안 반복
		token=getToken(*exp); //토큰분리
		if(token==operand) //피연산자이면
			evalPush(*exp-'0'); //피연산자의 아스키코드숫자-0의 아스키코드숫자를 스택에 push
		else{
			op2=evalPop(); //스택에서 pop한 값을 피연산자op2에 대입
			op1=evalPop(); //스택에서 pop한 값을 피연산자op1에 대입
			switch(token){ //토큰을 비교
				case plus: evalPush(op1+op2); //+연산
					break;
				case minus:evalPush(op1-op2); //-연산
					break;
				case times: evalPush(op1*op2); //*연산
					break;
				case divide: evalPush(op1/op2); // /연산
					break;
			}
		}
		exp++; //exp=exp+1대입
	}
	evalResult=evalPop(); //스택에서 pop한 값을 계산결과에 대입
}

int main()
{
	char command; //사용자가 사용할 기능을 입력

	do{
		printf("----------------------------------------------------------------\n");
		printf("               Infix to Postfix, then Evaluation               \n");
		printf("----------------------------------------------------------------\n");
		printf(" Infix=i,   Postfix=p,  Eval=e,   Debug=d,   Reset=r,   Quit=q \n");
		printf("----------------------------------------------------------------\n");
		printf("====== [김동용] [2017038064] ======\n");
		printf("Command = ");
		scanf(" %c", &command); //입력

		switch(command) {
		case 'i': case 'I':
			getInfix(); //중위표기법 입력
			break;
		case 'p': case 'P':
			toPostfix(); //후위표기법
			break;
		case 'e': case 'E':
			evaluation(); //계산
			break;
		case 'd': case 'D':
			debug(); //디버그
			break;
		case 'r': case 'R':
			reset(); //리셋
			break;
		case 'q': case 'Q': //종료
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n"); //그 이외의 값을 입력하면 주의 표시
			break;
		}
	}while(command != 'q' && command != 'Q'); //q가 입력될 때까지 반복
	return 0;
}

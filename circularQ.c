/*
 * circularQ.c
 *
 *  Created on: 2020. 4. 19.
 *      Author: kingyong
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4 //큐의 크기를 4로 정의한다

typedef char element; //문자형 변수선언
typedef struct {
	element queue[MAX_QUEUE_SIZE]; //문자형 배열 선언
	int front, rear; //정수형 변수 선언
	}QueueType; //구조체 선언

QueueType *createQueue(); //반환형을 QueueType형의 주소로 하는 함수 선언
int isEmpty(QueueType *cQ); //큐가 비어있는지 검사하는 함수
int isFull(QueueType *cQ); //큐가 가득 차 있는지 검사하는 함수
void enQueue(QueueType *cQ, element item); //큐를 push하는 함수
void deQueue(QueueType *cQ, element* item); //큐를 pop하는 함수
void printQ(QueueType *cQ); //큐를 출력하는 함수
void debugQ(QueueType *cQ); //큐를 검사하는 함수

element getElement(); //값을 입력 받는 함수

int main(void)
{
	QueueType *cQ = createQueue();
	element data;
	char command;

	do{ //실행한다
		printf("\n-----------------------------------------------------\n");
		printf(" Circular Q \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i, Delete=d, PrintQ=p, Dubug=b, Quit=q \n");
		printf("------------------------------------------------------\n");
		printf("Command = ");
		scanf(" %c", &command); //입력
		switch(command) { //command의 값에 따라 함수를 호출하도록 한다
			case 'i': case 'I': //i나 I일 때
				data = getElement(); //값을 입력받아 data에 저장한다
				enQueue(cQ, data); //data를 큐에 push한다
				break;
			case 'd': case 'D': //d나 D일 때
				deQueue(cQ,&data); //큐에서 front에 있는 값을 제거한다
				break;
			case 'p': case 'P': //p나 P일 때
				printQ(cQ); //큐를 출력한다
				break;
			case 'b': case 'B': //b나 B일 때
				debugQ(cQ); //큐를 디버그한다
				break;
			case 'q': case 'Q': //q나 Q일 때
				break;
			default: //그 이외 일 때
				printf("\n >>>>> Concentration!! <<<<< \n");
				break;
			}
		}while(command != 'q' && command != 'Q'); //q나 Q가 아닐 때까지 반복한다.
	return 1;
}

QueueType *createQueue()
{
	QueueType *cQ; //QueueType형의 포인터 변수를 선언
	cQ = (QueueType *)malloc(sizeof(QueueType)); //QueueType의 크기만큼 동적할당한다
	cQ->front = 0; //front를 0으로 놓는다
	cQ->rear = 0; //rear를 0으로 놓는다
	return cQ; //큐의 시작주소를 반환한다
}

element getElement()
{
	element item; //element형의 변수를 선언한다
	printf("Input element = ");
	scanf(" %c", &item); //입력
	return item; //입력한 값을 반환한다
}

int isEmpty(QueueType *cQ)
{
	if(cQ->rear==cQ->front) //rear==front이면
		return 1; //1반환
	return 0; //아니면 0반환
}

int isFull(QueueType *cQ)
{
	if(cQ->rear==cQ->front) //rear==front이면
		return 1; //1반환
	return 0; //아니면 0반환
}

void enQueue(QueueType *cQ, element item)
{
	cQ->rear=((cQ->rear)+1)%MAX_QUEUE_SIZE; //rear 값 1증가
	if(isFull(cQ)==1){ //큐가 가득 찼으면
		printf("큐가 가득찼습니다.");
		cQ->rear=((cQ->rear)+MAX_QUEUE_SIZE-1)%MAX_QUEUE_SIZE; //다시 rear값 되돌리기
	}
	else //아니면
		cQ->queue[cQ->rear]=item; //큐에 문자 저장
}

void deQueue(QueueType *cQ, element* item)
{
	if(isEmpty(cQ)==1) //큐가 비어있으면
		printf("큐가 비어있습니다.");
	else //아니면
		cQ->front=((cQ->front)+1)%MAX_QUEUE_SIZE; //front증가
}

void printQ(QueueType *cQ)
{
	int i, first, last;
	first = (cQ->front + 1)%MAX_QUEUE_SIZE; //first front+1값 대입
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE; //last에 rear+1값 대입
	printf("=======[김동용 [2017038064]=======\n");
	printf("Circular Queue : [");
	i = first; //i에 first대입
	while(i != last){ //i와 last가 다를 동안
		printf("%3c", cQ->queue[i]); //출력
		i = (i+1)%MAX_QUEUE_SIZE; //i를 1증가
	}
	printf(" ]\n");
}

void debugQ(QueueType *cQ)
{
	printf("\n---DEBUG\n");
	for(int i = 0; i < MAX_QUEUE_SIZE; i++) //0~3까지 반복
	{
		if(i == cQ->front) { //i와 front값이 같으면
			printf(" [%d] = front\n", i); //출력, 한 칸 비워두는 것
			continue; //밑으로 내려가지 않고 다시 반복문으로 들어감
		}
		printf(" [%d] = %c\n", i, cQ->queue[i]); //출력
	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear); //출력
}

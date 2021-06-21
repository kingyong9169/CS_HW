/*
 * doubly-linked-list.c
 *
 *  Created on: 2020. 4. 28.
 *      Author: kingyong
 */
#include<stdio.h>
#include<stdlib.h>
// 필요한 헤더파일 추가 if necessary

typedef struct Node {
	int key; //키 값
	struct Node* llink; //왼쪽 링크
	struct Node* rlink; //오른쪽 링크
} listNode;

listNode* trail; //리스트의 맨 마지막에서 두 번째 노드를 가리키는 변수

typedef struct Head {
	struct Node* first; //첫번째 노드를 가리키느 포인터 변수
}headNode;

// 함수 리스트

// note: initialize는 이중포인터를 매개변수로 받음
//singly-linked-list의 initialize와 차이점을 이해 할것
int initialize(headNode** h);

// note: freeList는 싱글포인터를 매개변수로 받음
//- initialize와 왜 다른지 이해 할것
//- 이중포인터를 매개변수로 받아도 해제할 수 있을 것

int freeList(headNode* h);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);
int insertFirst(headNode* h, int key);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int deleteFirst(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);


int main()
{
	char command;
	int key;
	headNode* headnode=NULL;

	do{
	printf("----------------------------------------------------------------\n");
	printf(" Doubly Linked List \n");
	printf("----------------------------------------------------------------\n");
	printf("--------------------[김동용] [2017038064]------------------------\n");
	printf(" Initialize = z Print = p \n");
	printf(" Insert Node = i Delete Node = d \n");
	printf(" Insert Last = n Delete Last = e\n");
	printf(" Insert First = f Delete First = t\n");
	printf(" Invert List = r Quit = q\n");
	printf("----------------------------------------------------------------\n");

	printf("Command = ");
	scanf(" %c", &command);

	switch(command) {
		case 'z': case 'Z':
			initialize(&headnode);
			break;
		case 'p': case 'P':
			printList(headnode);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insertNode(headnode, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(headnode, key);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insertLast(headnode, key);
			break;
		case 'e': case 'E':
			deleteLast(headnode);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			insertFirst(headnode, key);
			break;
		case 't': case 'T':
			deleteFirst(headnode);
			break;
		case 'r': case 'R':
			invertList(headnode);
			break;
		case 'q': case 'Q':
			freeList(headnode);
			break;
		default:
			printf("\n >>>>> Concentration!! <<<<< \n");
			break;
	}

	}while(command != 'q' && command != 'Q');

	return 1;
	}


int initialize(headNode** h) {
	// headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제
	if((*h) != NULL) //headnode가 null이 아니면
		freeList(*h); //freelist함수를 호출한다
	headNode* temp = (headNode*)malloc(sizeof(headNode)); //temp라는 하나의 헤드노드를 생성한다
	*h=temp; //temp를 *h에 대입한다
	(*h)->first = NULL; //temp의 주소가 들어간 *h가 가리키는 first가 NULL을 가리키도록 한다
	return 1;
	}

int freeList(headNode* h){
	// h와 연결된 listNode 메모리 해제
	// headNode도 해제되어야 함.
	listNode* p = h->first; //p가 h가 가리키는 값 first가 가리키는 노드를 가리킨다
	listNode* prev = NULL; //prev가 NULL를 가리킨다
	while(p != NULL) {
		prev = p; //prev가 p가 가리키는 노드를 가리킨다
		p = p->rlink; //p가 다음 노드를 가리킨다
		free(prev); //prev가 가리키는 노드를 free한다
	}
	free(h); //모든 노드가 free되고 h를 해제한다
	return 0;
	}

void printList(headNode* h) {
	int i = 0;
	listNode* p;
	printf("\n---PRINT\n");
	if(h == NULL) { //빈 노드이면
		printf("Nothing to print....\n");
		return; //리턴
	}
	p = h->first; //p가 첫 번째 노드를 가리키고
	while(p != NULL) {
		printf("[ [%d]=%d ] ", i, p->key); //출력
		p = p->rlink; //다음 노드
		i++; //몇 개의 노드가 있는지 저장하는 변수
	}
	printf(" items = %d\n", i);
}

	//list에 key에 대한 노드하나를 추가
int insertLast(headNode* h, int key) {
	listNode* temp=(listNode*)malloc(sizeof(listNode));
	listNode* p;
	if(h->first==NULL){ //노드가 존재하지 않으면
		temp->rlink=NULL; //temp의 오른쪽링크는 NULL을 가리키고
		temp->llink=NULL; //temp의 왼쪽링크는 NULL을 가리키고
		h->first=temp; //맨 처음 노드를 가리키는 포인터는 temp를 가리킨다
		temp->key=key; //키값을 temp의 키값에 대입한다
	}
	else if(h->first!=NULL){ //노드가 존재하면
		p=h->first; //p가 맨 처음 노드를 가리킨다
		while(p!=NULL){ //p가 NULL이 아닐 때까지
			trail=p; //trail이 p를 가리킨다
			p=p->rlink;} //p가 다음 노드를 가리킨다
		if(p==NULL){ //trail의 위치를 정하면
			trail->rlink=temp; //trail의 링크가 temp를 가리킨다
			temp->rlink=NULL; //temp의 링크가 NULL을 가리킨다
			temp->llink=p; //temp의 왼쪽오른쪽링크가 p를 가리킨다
			temp->key=key;} //키값을 temp의 키값에 대입한다
	}
	return 0;
}

	//list의 마지막 노드 삭제
int deleteLast(headNode* h) {
	listNode* p;
	if(h->first!=NULL){ //만약 리스트 안에 노드가 있으면
		p=h->first; //p가 맨 처음 노드를 가리킨다
		if(p->rlink==NULL) //리스트 안에 노드가 한 개이면
			h->first=NULL; //맨 처음 노드를 가리키는 포인터가 NULL을 가리킨다
		else { //리스트 안에 노드가 여러 개이면
			while(p!=NULL){ //p가 NULL이 아닐 때까지
				if(p->rlink==NULL){ //만약 p의 링크가 NULL이면
					trail->rlink=NULL; //trail의 오른쪽 링크는 NULL을 가리킨다
					p->llink=NULL; //p의 왼쪽링크가 NULL을 가리킨다
					break;} //반복문을 빠져 나온다
				else{ //만약 p의 링크가 NULL이 아니면
					trail=p; //trail을 p로 나타내고
					p=p->rlink;} //p가 다음 노드를 가리키도록 한다
			}
		}
	}
	else
		printf("CANNOT FIND THE NODE\n"); //리스트 안에 노드가 없으면
	return 0;
}

	//list 처음에 key에 대한 노드하나를 추가
int insertFirst(headNode* h, int key) {
	listNode* node = (listNode*)malloc(sizeof(listNode)); //node를 동적할당해준다
	node->key = key; //node가 가리키는 값의 key에 key값을 넣어준다
	node->rlink = h->first; //노드가 가리키는 값의 왼쪽링크가 헤더노드가 가리키는 값의 first를 가리킨다
	node->llink=NULL; //노드가 가리키는 값의 왼쪽링크가 헤더노드가 NULL을 가리킨다
	h->first = node; //헤더노드가 가리키는 값의 first가 노드를 가리킨다
	trail=node;
	return 0;
}

	//list의 첫번째 노드 삭제
int deleteFirst(headNode* h) {
	listNode* p;
	if(h->first!=NULL){ //노드가 존재하면
		p=h->first; //p가 맨 처음 노드를 가리킨다
		if(p->rlink==NULL){
			h->first=p->rlink; //맨 처음 노드를 가리키는 포인터가 p의 다음 노드를 가리킨다
			p->rlink=NULL; //p의 링크는 NULL을 가리킨다
			free(p);} //p를 해제한다
		else{
			h->first=p->rlink; //맨 처음 노드를 가리키는 포인터가 p의 다음 노드를 가리킨다
			h->first->llink=NULL; //맨 처음 노드의 왼쪽 링크가 NULL을 가리킨다
			p->rlink=NULL; //p의 오른쪽 링크는 NULL을 가리킨다
			free(p);} //p를 해제한다
	}
	else //리스트 안에 노드가 없으면
		printf("CANNOT FIND THE NODE\n"); //찾지 못한다고 알린다
	return 0;
}

	//리스트의 링크를 역순으로 재 배치
int invertList(headNode* h) {
	listNode* middle,*last,*p;
	if(h->first!=NULL){ //만약 리스트 안에 노드가 있으면
		p=h->first; //p가 노드의 맨 처음을 나타낸다
		trail=p->rlink; //trail은 리스트의 두 번째 노드를 나타낸다
		middle=NULL; //middle은 NULL을 나타낸다
		while(p){ //p가 NULL이 아니면
			last=middle; //last가 middle을 나타내고
			middle=p; //middle이 p를 나타내며
			p=p->rlink; //p가 다음 노드를 가리키고
			middle->rlink=last; //middle의 링크가 last를 가리킨다
			if(last!=NULL) //last가 NULL이 아니면
				last->llink=middle; //last의 왼쪽링크가 middle을 가리킨다
		}
		h->first=middle; }//맨 처음 노드를 처음 리스트의 맨 마지막 노드로 해준다
	else //만약 리스트 안에 노드가 없으면
		printf("CANNOT INVERT THE LIST\n"); //인버트 할 수 없다고 알림
	return 0;
}

	// 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입
int insertNode(headNode* h, int key) {
	listNode* temp=(listNode*)malloc(sizeof(listNode));
	listNode* ep;
	if(h->first==NULL) //리스트에 노드가 없으면
	{
		temp->key=key;  //키값을 temp의 키값에 대입한다
		temp->rlink=NULL; //temp의 링크가 NULL을 가리킨다
		temp->llink=NULL; //temp의 링크가 NULL을 가리킨다
		h->first=temp; //맨 처음노드를 가리키는 포인터가 temp를 가리킨다
		trail=temp; //trail이 temp를 가리킨다
	}
	else if(h->first!=NULL) //리스트에 노드가 있으면
	{
		ep=h->first; //ep가 맨 처음 노드를 가리킨다
		if(ep->rlink==NULL){ //리스트에 노드가 한 개이면
			if(ep->key>=key){ //노드 안의 키가 입력한 키보다 값이 크거나 같으면
				temp->rlink=ep; //temp의 오른쪽 링크가 ep를 가리킨다
				ep->llink=temp; //ep의 왼쪽링크가 temp를 가리킨다
				temp->key=key; //키값을 temp의 키값에 대입한다
				h->first=temp; //맨 처음노드를 가리키는 포인터가 temp를 가리킨다
				ep->rlink=NULL; //ep의 오른쪽 링크가 NULL을 가리킨다
				trail=temp; //trail이 temp를 가리킨다
			}
			else{ //노드 안의 키가 입력한 키보다 값이 작으면
				ep->rlink=temp; //ep의 오른쪽 링크가 temp을 가리킨다
				temp->rlink=NULL; //temp의 오른쪽 링크가 NULL을 가리킨다
				temp->llink=ep; //temp의 왼쪽 링크가 ep를 가리킨다
				temp->key=key; //키값을 temp의 키값에 대입한다
				trail=ep; //trail이 ep를 가리킨다
			}
		}
		else if(ep->rlink!=NULL){ //리스트에 노드가 여러 개이면
			while(ep!=NULL) //ep가 NULL이 아닐 때까지
			{
				if(ep->key>=key){ //노드 안의 키가 입력한 키보다 값이 크거나 같으면
					if(ep==h->first){ //ep가 맨 처음노드와 동일하다면
						temp->key=key; //키값을 temp의 키값에 대입한다
						temp->rlink=ep; //temp의 오른쪽 링크가 ep를 가리킨다
						temp->llink=NULL; //temp의 왼쪽 링크가 NULL을 가리킨다
						h->first=temp; //맨 처음노드를 가리키는 포인터가 temp를 가리킨다
						break;} //반복문 탈출
					else if(ep!=h->first) //ep가 맨 처음노드와 같지 않으면
					{
						temp->key=key; //키값을 temp의 키값에 대입한다
						temp->llink=trail; //temp의 왼쪽 링크가 trail을 가리킨다
						temp->rlink=trail->rlink; //temp의 오른쪽 링크가 trail의 오른쪽 링크 즉, trail다음 노드를 가리킨다
						trail->rlink->llink=temp; //trail의 오른쪽링크 즉 trail다음노드의 왼쪽링크가 temp를 가리킨다
						trail->rlink=temp; //trail의 링크가 temp를 가리킨다
						trail=temp; //trail이 temp를 가리킨다
						break; //반복문 탈출
					}
				}
				else if(ep->key<key){ //노드 안의 키가 입력한 키보다 값이 작으면
					trail=ep; //trail이 ep를 가리킨다
					temp->rlink=NULL; //temp의 링크가 NULL을 가리킨다
					ep=ep->rlink; //ep가 다음 노드를 가리킨다
				}
			}
			if(temp->rlink==NULL){ //while에서 탐색하고 노드에 있는 키보다 입력한 키가 더 클 때
				trail->rlink=temp; //trail의 오른쪽 링크가 temp를 가리킨다
				temp->llink=trail; //temp의 왼쪽 링크가 trail을 가리킨다
				temp->key=key; //키값을 temp의 키값에 대입한다
				temp->rlink=NULL;} //temp의 오른쪽링크가 NULL을 가리킨다
		}
	}
	return 0;
}

	//list에서 key에 대한 노드 삭제
int deleteNode(headNode* h, int key) {
	listNode* p;
	listNode* front; //p의 앞 노드를 가리키는 변수
	if(h->first!=NULL){ //맨 앞노드가 존재하면
		p=h->first; //p가 맨 처음 노드를 가리킨다
		if(p->rlink!=NULL){ //리스트 안에 두 개 이상의 노드가 있으면
			while(p!=NULL){ //p가 NULL이 아닐 때까지
				if(key==h->first->key){ //key와 맨 처음 노드의 key가 동일하면
					h->first=p->rlink; //맨처음 노드를 가리키는 포인터가 다음 노드를 가리킨다
					h->first->llink=NULL; //맨 처음 노드의 왼쪽링크가 NULL을 가리킨다
					p->rlink=NULL; //p의 오른쪽 링크는 NULL을 가리키고
					p->llink=NULL; //p의 왼쪽 링크가 NULL을 가리킨다
					free(p); //p를 해제한다
					break;} //반복문 탈출
				else if(key==p->key){ //key가 p의 key와 동일하면
					front->rlink=p->rlink; //front의 링크가 p의 다음 노드를 가리키고
					if(p->rlink!=NULL) //만약 p의 오른쪽링크가 NULL이 아니면
						p->rlink->llink=front; //p의 오른쪽링크 즉, p의 다음 노드의 왼쪽 링크가 front를 가리킨다
					p->rlink=NULL; //p의 오른쪽링크가 NULL을 가리킨다
					p->llink=NULL; //p의 왼쪽링크가 NULL을 가리킨다
					free(p); //p를 해제한다
					break;}
				else{
					front=p; //p를 front에 대입하고
					p=p->rlink;} //p가 다음 노드를 가리킨다
			}
			if(p==NULL) //만약 리스트에 있는 노드의 키를 못찾으면
				printf("CANNOT FIND THE NODE FOR KEY=%d\n",key); //찾을 수 없다고 알린다
		}
		else{ //리스트 안에 한 개의 노드가 존재하면
			if(key==p->key){ //key가 노드의 키와 일치하면
				p->rlink=NULL; //p의 오른쪽링크는 NULL을 가리키고
				p->llink=NULL; //p의 왼쪽링크는 NULL을 가리킨다
				h->first=NULL; //맨 처음 노드를 가리키는 포인터가 NULL을 가리킨다
				free(p);} //p를 해제한다
			else //key가 노드의 키와 일치하지 않으면
				printf("CANNOT FIND THE NODE FOR KEY=%d\n",key);	} //찾지 못한다고 알린다
	}
	else //노드가 한 개도 존재하지 않으면
			printf("CANNOT FIND THE NODE FOR KEY=%d\n",key); //찾지 못한다고 알린다
	return 1;
}

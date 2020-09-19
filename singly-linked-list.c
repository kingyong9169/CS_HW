/*
 * d.c
 *
 *  Created on: 2020. 4. 26.
 *      Author: kingyong
 */
#include<stdio.h>
#include<stdlib.h>

// 필요한 헤더파일 추가

typedef struct Node {
	int key; //노드의 데이터
	struct Node* link; //노드의 링크
} listNode; //데이터 타입 네임

typedef struct Head {
	struct Node* first; //헤드 노드의 링크
}headNode; //데이터 타입 네임

listNode* trail; //리스트의 맨 마지막에서 두 번째 노드를 가리키는 변수

// 함수 리스트 선언
headNode* initialize(headNode* h);
int freeList(headNode* h);

int insertFirst(headNode* h, int key);
int insertNode(headNode* h, int key);
int insertLast(headNode* h, int key);

int deleteFirst(headNode* h);
int deleteNode(headNode* h, int key);
int deleteLast(headNode* h);
int invertList(headNode* h);

void printList(headNode* h);

int main()
{
	char command; //입력할 명령
	int key; //입력할 정수
	headNode* headnode=NULL; //헤드노드의 주소를 NULL로 초기화
	do{
		printf("----------------------------------------------------------------\n");
		printf("                     Singly Linked List                         \n");
		printf("----------------------------------------------------------------\n");
		printf("--------------------[김동용] [2017038064]------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); //값을 입력받는다

		switch(command) {
		case 'z': case 'Z': //초기화
			headnode = initialize(headnode);
			break;
		case 'p': case 'P':
			printList(headnode); //리스트를 출력한다
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key); //키 값을 입력한다
			insertNode(headnode, key); //키를 넣어준다
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key); //지울 키 값을 입력한다
			deleteNode(headnode, key); //지운다
			break;
		case 'n': case 'N': //리스트를 추가한다
			printf("Your Key = ");
			scanf("%d", &key); //키를 입력하고
			insertLast(headnode, key); //입력한 키를 함수에 인자로 하여 넣어준다
			break;
		case 'e': case 'E':
			deleteLast(headnode); //맨 뒤의 노드를 삭제한다
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key); //키 값을 입력
			insertFirst(headnode, key); //맨 처음 키 값을 넣어준다
			break;
		case 't': case 'T':
			deleteFirst(headnode); //맨 처음 노드를 삭제한다
			break;
		case 'r': case 'R':
			invertList(headnode); //노드를 인버트한다
			break;
		case 'q': case 'Q':
			freeList(headnode); //리스트를 초기화한다
			break;
		default: //그 이외의 값이 입력되면
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q'); //q를 입력하기 전까지 반복

	return 1;
}

headNode* initialize(headNode* h) {

	// headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제
	if(h != NULL) //headnode가 null이 아니면
		freeList(h); //freelist함수를 호출한다

	// headNode에 대한 메모리를 할당하여 리턴
	headNode* temp = (headNode*)malloc(sizeof(headNode));
	temp->first = NULL; //temp가 가리키는 first가 NULL을 가리키도록 한다
	return temp; //temp를 리턴한다
}

int freeList(headNode* h){
	// h와 연결된 listNode 메모리 해제
	// headNode도 해제되어야 함.
	listNode* p = h->first; //p가 h가 가리키는 값 first가 가리키는 노드를 가리킨다
	listNode* prev = NULL; //prev가 NULL를 가리킨다
	while(p != NULL) {
		prev = p; //prev가 p가 가리키는 노드를 가리킨다
		p = p->link; //p가 다음 노드를 가리킨다
		free(prev); //prev가 가리키는 노드를 free한다
	}
	free(h); //모든 노드가 free되고 h를 해제한다
	return 0;
}

 // list 처음에 key에 대한 노드하나를 추가
int insertFirst(headNode* h, int key) {
	listNode* node = (listNode*)malloc(sizeof(listNode)); //node를 동적할당해준다
	node->key = key; //node가 가리키는 값의 key에 key값을 넣어준다
	node->link = h->first; //노드가 가리키는 값의 링크가 헤더노드가 가리키는 값의 first를 가리킨다
	h->first = node; //헤더노드가 가리키는 값의 first가 노드를 가리킨다
	trail=node;
	return 0;
}

// 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입
int insertNode(headNode* h, int key) {
	listNode* temp=(listNode*)malloc(sizeof(listNode));
	listNode* ep;
	if(h->first==NULL) //리스트에 노드가 없으면
	{
		temp->key=key;  //키값을 temp의 키값에 대입한다
		temp->link=NULL; //temp의 링크가 NULL을 가리킨다
		h->first=temp; //맨 처음노드를 가리키는 포인터가 temp를 가리킨다
		trail=temp; //trail이 temp를 가리킨다
	}
	else if(h->first!=NULL) //리스트에 노드가 있으면
	{
		ep=h->first; //ep가 맨 처음 노드를 가리킨다
		if(ep->link==NULL){ //리스트에 노드가 한 개이면
			if(ep->key>=key){ //노드 안의 키가 입력한 키보다 값이 크거나 같으면
				temp->link=ep; //temp의 링크가 ep를 가리킨다
				temp->key=key; //키값을 temp의 키값에 대입한다
				h->first=temp; //맨 처음노드를 가리키는 포인터가 temp를 가리킨다
				ep->link=NULL; //ep의 링크가 NULL을 가리킨다
				trail=temp; //trail이 temp를 가리킨다
			}
			else{ //노드 안의 키가 입력한 키보다 값이 작으면
				ep->link=temp; //ep의 링크가 temp을 가리킨다
				temp->link=NULL; //temp의 링크가 NULL을 가리킨다
				temp->key=key; //키값을 temp의 키값에 대입한다
				trail=ep; //trail이 ep를 가리킨다
			}
		}
		else if(ep->link!=NULL){ //리스트에 노드가 여러 개이면
			while(ep!=NULL) //ep가 NULL이 아닐 때까지
			{
				if(ep->key>=key){ //노드 안의 키가 입력한 키보다 값이 크거나 같으면
					if(ep==h->first){ //ep가 맨 처음노드와 동일하다면
						temp->key=key; //키값을 temp의 키값에 대입한다
						temp->link=ep; //temp의 링크가 ep를 가리킨다
						h->first=temp; //맨 처음노드를 가리키는 포인터가 temp를 가리킨다
						break;} //반복문 탈출
					else if(ep!=h->first) //ep가 맨 처음노드와 같지 않으면
					{
						temp->key=key; //키값을 temp의 키값에 대입한다
						trail->link=temp; //trail의 링크가 temp를 가리킨다
						temp->link=ep; //temp의 링크가 ep를 가리킨다
						trail=temp; //trail이 temp를 가리킨다
						break; //반복문 탈출
					}
				}
				else if(ep->key<key){ //노드 안의 키가 입력한 키보다 값이 작으면
					trail=ep; //trail이 ep를 가리킨다
					temp->link=NULL; //temp의 링크가 NULL을 가리킨다
					ep=ep->link; //ep가 다음 노드를 가리킨다
				}
			}
			if(temp->link==NULL){ //while에서 탐색하고 노드에 있는 키보다 입력한 키가 더 클 때
				trail->link=temp; //trail의 링크가 temp를 가리킨다
				temp->key=key; //키값을 temp의 키값에 대입한다
				temp->link=NULL;} //temp의 링크가 NULL을 가리킨다
		}
	}
	return 0;
}

//list에 key에 대한 노드하나를 추가
int insertLast(headNode* h, int key) {
	listNode* temp=(listNode*)malloc(sizeof(listNode));
	listNode* p;
	if(h->first==NULL){ //노드가 존재하지 않으면
		temp->link=NULL; //temp의 링크는 NULL을 가리키고
		h->first=temp; //맨 처음 노드를 가리키는 포인터는 temp를 가리킨다
		temp->key=key; //키값을 temp의 키값에 대입한다
	}
	else if(h->first!=NULL){ //노드가 존재하면
		p=h->first; //p가 맨 처음 노드를 가리킨다
		while(p!=NULL){ //p가 NULL이 아닐 때까지
			trail=p; //trail이 p를 가리킨다
			p=p->link;} //p가 다음 노드를 가리킨다
		if(p==NULL){ //trail의 위치를 정하면
			trail->link=temp; //trail의 링크가 temp를 가리킨다
			temp->link=NULL; //temp의 링크가 NULL을 가리킨다
			temp->key=key;} //키값을 temp의 키값에 대입한다
	}
	return 0;
}

 // list의 첫번째 노드 삭제
int deleteFirst(headNode* h) {
	if(h->first!=NULL){ //노드가 존재하면
		listNode* p;
		p=h->first; //p가 맨 처음 노드를 가리킨다
		h->first=p->link; //맨 처음 노드를 가리키는 포인터가 p의 다음 노드를 가리킨다
		p->link=NULL; //p의 링크는 NULL을 가리킨다
		free(p);} //p를 해제한다
	else //리스트 안에 노드가 없으면
		printf("CANNOT FIND THE NODE\n"); //찾지 못한다고 알린다
	return 0;
}

 // list에서 key에 대한 노드 삭제
int deleteNode(headNode* h, int key) {
	listNode* p;
	listNode* front; //p의 앞 노드를 가리키는 변수
	if(h->first!=NULL){ //맨 앞노드가 존재하면
		p=h->first; //p가 맨 처음 노드를 가리킨다
		if(p->link!=NULL){ //리스트 안에 두 개 이상의 노드가 있으면
			while(p!=NULL){ //p가 NULL이 아닐 때까지
				if(key==h->first->key){ //key와 맨 처음 노드의 key가 동일하면
					h->first=p->link; //맨처음 노드를 가리키는 포인터가 다음 노드를 가리킨다
					p->link=NULL; //p의 링크는 NULL을 가리키고
					free(p); //p를 해제한다
					break;} //반복문 탈출
				else if(key==p->key){ //key가 p의 key와 동일하면
					front->link=p->link; //front의 링크가 p의 다음 노드를 가리키고
					p->link=NULL; //p의 링크가 NULL을 가리킨다
					free(p); //p를 해제한다
					break;}
				else{
					front=p; //p를 front에 대입하고
					p=p->link;} //p가 다음 노드를 가리킨다
			}
			if(p==NULL) //만약 리스트에 있는 노드의 키를 못찾으면
				printf("CANNOT FIND THE NODE FOR KEY=%d\n",key); //찾을 수 없다고 알린다
		}
		else{ //리스트 안에 한 개의 노드가 존재하면
			if(key==p->key){ //key가 노드의 키와 일치하면
				p->link=NULL; //p의 링크는 NULL을 가리키고
				h->first=NULL; //맨 처음 노드를 가리키는 포인터가 NULL을 가리킨다
				free(p);} //p를 해제한다
			else //key가 노드의 키와 일치하지 않으면
				printf("CANNOT FIND THE NODE FOR KEY=%d\n",key);	} //찾지 못한다고 알린다
	}
	else //노드가 한 개도 존재하지 않으면
		printf("CANNOT FIND THE NODE FOR KEY=%d\n",key); //찾지 못한다고 알린다
	return 0;
}

 // list의 마지막 노드 삭제
int deleteLast(headNode* h) {
	listNode* p;
	if(h->first!=NULL){ //만약 리스트 안에 노드가 있으면
		p=h->first; //p가 맨 처음 노드를 가리킨다
		if(p->link==NULL) //리스트 안에 노드가 한 개이면
			h->first=NULL; //맨 처음 노드를 가리키는 포인터가 NULL을 가리킨다
		else { //리스트 안에 노드가 여러 개이면
			while(p!=NULL){ //p가 NULL이 아닐 때까지
				if(p->link==NULL){ //만약 p의 링크가 NULL이면
					trail->link=NULL; //trail의 링크는 NULL을 가리킨다
					break;} //반복문을 빠져 나온다
				else{ //만약 p의 링크가 NULL이 아니면
					trail=p; //trail을 p로 나타내고
					p=p->link;} //p가 다음 노드를 가리키도록 한다
			}
		}
	}
	else
		printf("CANNOT FIND THE NODE\n"); //리스트 안에 노드가 없으면
	return 0;
}

 // 리스트의 링크를 역순으로 재 배치
int invertList(headNode* h) {
	listNode* middle,*last,*p;
	if(h->first!=NULL){ //만약 리스트 안에 노드가 있으면
		p=h->first; //p가 노드의 맨 처음을 나타낸다
		trail=p->link; //trail은 리스트의 두 번째 노드를 나타낸다
		middle=NULL; //middle은 NULL을 나타낸다
		while(p){ //p가 NULL이 아니면
			last=middle; //last가 middle을 나타내고
			middle=p; //middle이 p를 나타내며
			p=p->link; //p가 다음 노드를 가리키고
			middle->link=last; //middle의 링크가 last를 가리킨다
		}
		h->first=middle; }//맨 처음 노드를 처음 리스트의 맨 마지막 노드로 해준다
	else //만약 리스트 안에 노드가 없으면
		printf("CANNOT INVERT THE LIST\n"); //인버트 할 수 없다고 알림
	return 0;
}

void printList(headNode* h) {
	int i = 0;
	listNode* p; //노드를 가리키는 p를 선언
	printf("\n---PRINT\n");
	if(h == NULL) { //헤더노드가 NULL을 가리키면
		printf("Nothing to print....\n");
		return; //종료
	}
	p = h->first; //p가 h가 가리키는 first가 가리키는 노드를 가리킨다
	while(p != NULL) { //p가 NULL이 아닐 때까지
		printf("[ [%d]=%d ] ", i, p->key); //p가 가리키는 노드의 key를 출력해준다
		p = p->link; //다음 노드를 가리킨다
		i++; //i를 증가하여 몇 번째 노드인지 알린다
	}
	printf("  items = %d\n", i); //몇 개의 노드가 있는지 출력한다
}


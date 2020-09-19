/*
 * circular-linked-list.c
 *
 *  Created on: 2020. 5. 6.
 *      Author: kingyong
 */

#include<stdio.h>
#include<stdlib.h>
// 필요한 헤더파일 추가



typedef struct Node {
	int key;
	struct Node* llink;
	struct Node* rlink;
} listNode;

listNode* trail; //리스트의 맨 마지막에서 두 번째 노드를 가리키는 변수

// 함수 리스트
int initialize(listNode** h);
int freeList(listNode* h);
int insertLast(listNode* h, int key);
int deleteLast(listNode* h);
int insertFirst(listNode* h, int key);
int deleteFirst(listNode* h);
int invertList(listNode* h);

int insertNode(listNode* h, int key);
int deleteNode(listNode* h, int key);

void printList(listNode* h);



int main()
{
	char command;
	int key;
	listNode* headnode=NULL;

	do{
		printf("----------------------------------------------------------------\n");
		printf("                  Doubly Circular Linked List                   \n");
		printf("----------------------------------------------------------------\n");
		printf("--------------------[김동용] [2017038064]------------------------\n");
		printf(" Initialize    = z           Print         = p \n");
		printf(" Insert Node   = i           Delete Node   = d \n");
		printf(" Insert Last   = n           Delete Last   = e\n");
		printf(" Insert First  = f           Delete First  = t\n");
		printf(" Invert List   = r           Quit          = q\n");
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
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}
	}while(command != 'q' && command != 'Q');
	return 1;
}

int initialize(listNode** h) {
	// headNode가 NULL이 아니면, freeNode를 호출하여 할당된 메모리 모두 해제
	if(*h != NULL) //*h가 노드를 가리킨다면
		freeList(*h); //*h 해제
	// headNode에 대한 메모리를 할당하여 리턴
	*h = (listNode*)malloc(sizeof(listNode)); //*h동적할당
	(*h)->rlink = *h; //헤드노드의 오른쪽링크가 헤드노드를 가리킨다
	(*h)->llink = *h; //헤드노드의 왼쪽링크가 헤드노드를 가리킨다
	(*h)->key = -9999; //헤드노드의 키 값으로 이 값을 넣어준다
	return 1;
}

// 메모리 해제
int freeList(listNode* h){
	// h와 연결된 listNode 메모리 해제
	// headNode도 해제되어야 함.
	listNode* p = h->rlink; //p가 h가 가리키는 값 first가 가리키는 노드를 가리킨다
	listNode* prev = NULL; //prev가 NULL를 가리킨다
	while(p != h) {
		prev = p; //prev가 p가 가리키는 노드를 가리킨다
		p = p->rlink; //p가 다음 노드를 가리킨다
		free(prev); //prev가 가리키는 노드를 free한다
	}
	h->llink=h; //헤드노드의 왼쪽링크가 헤드노드를 가리킨다
	h->rlink=h; //헤드노드의 오른쪽링크가 헤드노드를 가리킨다
	free(h); //모든 노드가 free되고 h를 해제한다
	return 0;
}

void printList(listNode* h) {
	int i = 0;
	listNode* p;
	printf("\n---PRINT\n");
	if(h == NULL) { //노드가 없으면
		printf("Nothing to print....\n");
		return;
	}
	p = h->rlink; //p가 첫 번째 노드를 가리킨다
	while(p != NULL && p != h) { //p가 널이 아니고 마지막 노드가 가리키는 헤드노드가 아닐 때까지
		printf("[ [%d]=%d ] ", i, p->key); //값 출력
		p = p->rlink; //다음 노드를 가리킴
		i++; //i증가
	}
	printf("  items = %d\n", i);
	// print addresses
	printf("\n---checking addresses of links\n");
	printf("-------------------------------\n");
	printf("head node: [llink]=%p, [head]=%p, [rlink]=%p\n", h->llink, h, h->rlink); //헤드노드의 주소출력
	i = 0; //i초기화
	p = h->rlink; //p가 첫 번째 노드를 가리킴
	while(p != NULL && p != h) { //p가 널이 아니고 마지막 노드가 가리키는 헤드노드가 아닐 때까지
		printf("[ [%d]=%d ] [llink]=%p, [node]=%p, [rlink]=%p\n", i, p->key, p->llink, p, p->rlink); //노드의 주소출력
		p = p->rlink; //다음 노드를 가리킴
		i++;
	}
}

// list에 key에 대한 노드하나를 추가
int insertLast(listNode* h, int key) {
	listNode* temp=(listNode*)malloc(sizeof(listNode));
	listNode* p;
	if(h->rlink==h){ //노드가 존재하지 않으면
		temp->rlink=h; //temp의 오른쪽링크는 NULL을 가리키고
		temp->llink=h; //temp의 왼쪽링크는 NULL을 가리키고
		h->rlink=temp; //h의 오른쪽 링크가 temp를 가리킨다
		h->llink=temp; //맨 처음 노드를 가리키는 포인터는 temp를 가리킨다
		temp->key=key; //키값을 temp의 키값에 대입한다
	}
	else if(h->rlink!=h){ //노드가 존재하면
		p=h->rlink; //p가 맨 처음 노드를 가리킨다
		while(p!=h){ //p가 NULL이 아닐 때까지
			trail=p; //trail이 p를 가리킨다
			p=p->rlink;} //p가 다음 노드를 가리킨다
		if(p==h){ //trail의 위치를 정하면
			trail->rlink=temp; //trail의 링크가 temp를 가리킨다
			temp->rlink=h; //temp의 링크가 NULL을 가리킨다
			temp->llink=h->llink; //temp의 왼쪽오른쪽링크가 p를 가리킨다
			h->llink=temp; //h의 왼쪽 링크가 temp를 가리킨다
			temp->key=key;} //키값을 temp의 키값에 대입한다
	}
	return 1;
}

// list의 마지막 노드 삭제
int deleteLast(listNode* h) {
	listNode* p;
	if(h->rlink!=h){ //만약 리스트 안에 노드가 있으면
		p=h->rlink; //p가 맨 처음 노드를 가리킨다
		if(p->rlink==h){ //리스트 안에 노드가 한 개이면
			h->rlink=h; //맨 처음 노드를 가리키는 포인터가 헤드노드를 가리킨다
			h->llink=h;} //h의 왼쪽 링크가 헤드노드를 가리킨다
		else { //리스트 안에 노드가 여러 개이면
			while(p!=h){ //p가 NULL이 아닐 때까지
				if(p->rlink==h){ //만약 p의 링크가 NULL이면
					trail->rlink=h; //trail의 오른쪽 링크는 NULL을 가리킨다
					p->llink=NULL; //p의 왼쪽링크가 NULL을 가리킨다
					h->llink=trail; //h의 왼쪽링크가 trail을 가리킨다
					break;} //반복문을 빠져 나온다
				else{ //만약 p의 링크가 NULL이 아니면
					trail=p; //trail을 p로 나타내고
					p=p->rlink;} //p가 다음 노드를 가리키도록 한다
			}
		}
	}
	else
		printf("CANNOT FIND THE NODE\n"); //리스트 안에 노드가 없으면
	return 1;
}

// list 처음에 key에 대한 노드하나를 추가
int insertFirst(listNode* h, int key) {
	listNode* node = (listNode*)malloc(sizeof(listNode)); //node를 동적할당해준다
	node->key = key; //node가 가리키는 값의 key에 key값을 넣어준다
	node->rlink = h->rlink; //노드가 가리키는 값의 왼쪽링크가 헤더노드가 가리키는 값의 first를 가리킨다
	node->llink=h; //노드가 가리키는 값의 왼쪽링크가 헤더노드가 NULL을 가리킨다
	h->rlink->llink=node; //노드를 삽입하기 전 맨 처음 노드의 왼쪽링크가 삽입한 노드를 가리킨다
	h->rlink = node; //헤더노드가 가리키는 값의 first가 노드를 가리킨다
	trail=node; //trail은 노드를 의미한다

	return 1;
}

// list의 첫번째 노드 삭제
int deleteFirst(listNode* h) {
	listNode* p;
	if(h->rlink!=h){ //노드가 존재하면
		p=h->rlink; //p가 맨 처음 노드를 가리킨다
		if(p->rlink==h){ //노드에 한 개의 노드만 존재할 때
			h->llink=p->rlink; //맨 처음 노드를 가리키는 포인터가 p의 다음 노드를 가리킨다
			h->rlink=p->rlink; //즉, h를 가리키도록 한다
			p->rlink=NULL; //p의 링크는 NULL을 가리킨다
			p->llink=NULL; //p의 링크는 NULL을 가리킨다
			free(p);} //p를 해제한다
		else{ //노드에 여러 개의 노드만 존재할 때
			h->rlink=p->rlink; //맨 처음 노드를 가리키는 포인터가 p의 다음 노드를 가리킨다
			h->rlink->llink=h; //맨 처음 노드의 왼쪽 링크가 NULL을 가리킨다
			p->rlink=NULL; //p의 오른쪽 링크는 NULL을 가리킨다
			p->llink=NULL; //p의 왼쪽 링크는 NULL을 가리킨다
			free(p);} //p를 해제한다
	}
	else //리스트 안에 노드가 없으면
		printf("CANNOT FIND THE NODE\n"); //찾지 못한다고 알린다
	return 1;
}

// 리스트의 링크를 역순으로 재 배치
int invertList(listNode* h) {
	listNode* middle,*last,*p;
	if(h->rlink!=h){ //만약 리스트 안에 노드가 있으면
		p=h->rlink; //p가 노드의 맨 처음을 나타낸다
		h->llink=p;
		middle=h; //middle은 NULL을 나타낸다
		while(p!=h){ //p가 헤드노드가 아니면
			last=middle; //last가 middle을 나타내고
			middle=p; //middle이 p를 나타내며
			p=p->rlink; //p가 다음 노드를 가리키고
			middle->rlink=last; //middle의 링크가 last를 가리킨다
			if(last!=h) //last가 헤드노드가 아니면
				last->llink=middle; //last의 왼쪽링크가 middle을 가리킨다
		}
		h->rlink=middle; //h의 오른쪽 링크가 middle을 가리킨다
		middle->llink=h; //middle의 왼쪽 링크가 h를 가리킨다
	}
	else //만약 리스트 안에 노드가 없으면
		printf("CANNOT INVERT THE LIST\n"); //인버트 할 수 없다고 알림
	return 0;
}

// 리스트를 검색하여, 입력받은 key보다 큰값이 나오는 노드 바로 앞에 삽입
int insertNode(listNode* h, int key) {
	listNode* temp=(listNode*)malloc(sizeof(listNode));
	listNode* ep;
	if(h->rlink==h) //리스트에 노드가 없으면
	{
		temp->key=key;  //키값을 temp의 키값에 대입한다
		temp->rlink=h; //temp의 링크가 NULL을 가리킨다
		temp->llink=h; //temp의 링크가 NULL을 가리킨다
		h->rlink=temp; //헤더노드의 오른쪽 링크가 temp를 가리킨다
		h->llink=temp; //헤더노드의 왼쪽 링크가 temp를 가리킨다
		trail=temp; //trail이 temp를 가리킨다
	}
	else if(h->rlink!=h) //리스트에 노드가 있으면
	{
		ep=h->rlink; //ep가 맨 처음 노드를 가리킨다
		if(ep->rlink==h){ //리스트에 노드가 한 개이면
			if(ep->key>=key){ //노드 안의 키가 입력한 키보다 값이 크거나 같으면
				temp->rlink=ep; //temp의 오른쪽 링크가 ep를 가리킨다
				ep->llink=temp; //ep의 왼쪽링크가 temp를 가리킨다
				temp->key=key; //키값을 temp의 키값에 대입한다
				h->rlink=temp; //맨 처음노드를 가리키는 포인터가 temp를 가리킨다
				h->llink=ep; //h의 왼쪽링크가 ep를 가리킨다
				temp->llink=h; //temp의 왼쪽링크가 헤드노드를 가리킨다
				ep->rlink=h; //ep의 오른쪽 링크가 NULL을 가리킨다
				trail=temp; //trail이 temp를 가리킨다
			}
			else{ //노드 안의 키가 입력한 키보다 값이 작으면
				ep->llink=h; //ep의 왼쪽링크가 헤드노드를 가리킨다
				ep->rlink=temp; //ep의 오른쪽 링크가 temp을 가리킨다
				temp->rlink=h; //temp의 오른쪽 링크가 NULL을 가리킨다
				temp->llink=ep; //temp의 왼쪽 링크가 ep를 가리킨다
				h->llink=temp; //헤드노드의 왼쪽링크가 temp를 가리킨다
				h->rlink=ep; //헤드노드의 오른쪽링크가 ep를 가리킨다
				temp->key=key; //키값을 temp의 키값에 대입한다
				trail=ep; //trail이 ep를 가리킨다
			}
		}
		else if(ep->rlink!=h){ //리스트에 노드가 여러 개이면
			while(ep!=h) //ep가 NULL이 아닐 때까지
			{
				if(ep->key>=key){ //노드 안의 키가 입력한 키보다 값이 크거나 같으면
					if(ep==h->rlink){ //ep가 맨 처음노드와 동일하다면
						temp->key=key; //키값을 temp의 키값에 대입한다
						temp->rlink=ep; //temp의 오른쪽 링크가 ep를 가리킨다
						ep->llink=temp; //ep의 왼쪽링크가 temp를 가리킨다
						temp->llink=h; //temp의 왼쪽 링크가 헤드노드를 가리킨다
						h->rlink=temp; //맨 처음노드를 가리키는 포인터가 temp를 가리킨다
						break;} //반복문 탈출
					else if(ep!=h->rlink) //ep가 맨 처음노드와 같지 않으면
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
			if(temp->rlink==NULL){ //입력한 키가 모든 노드에 있는 키보다 값이 클 때
				trail->rlink=temp; //trail의 오른쪽 링크가 temp를 가리킨다
				temp->llink=trail; //temp의 왼쪽 링크가 trail을 가리킨다
				temp->rlink=h; //temp의 오른쪽 링크가 헤드노드를 가리킨다
				temp->key=key; //키값을 temp의 키값에 대입한다
				h->llink=trail->rlink;} //temp의 오른쪽링크가 NULL을 가리킨다
		}
	}
	return 0;
}

// list에서 key에 대한 노드 삭제
int deleteNode(listNode* h, int key) {
	listNode* p;
	listNode* front; //p의 앞 노드를 가리키는 변수
	if(h->rlink!=h){ //노드가 존재하면
		p=h->rlink; //p가 맨 처음 노드를 가리킨다
		if(p->rlink!=h){ //리스트 안에 두 개 이상의 노드가 있으면
			while(p!=h){ //p가 헤드노드가 아닐 때까지
				if(key==h->rlink->key){ //key와 맨 처음 노드의 key가 동일하면
					h->rlink=p->rlink; //맨처음 노드를 가리키는 포인터가 다음 노드를 가리킨다
					h->rlink->llink=h; //맨 처음 노드의 왼쪽링크가 NULL을 가리킨다
					p->rlink=NULL; //p의 오른쪽 링크는 NULL을 가리키고
					p->llink=NULL; //p의 왼쪽 링크가 NULL을 가리킨다
					free(p); //p를 해제한다
					break;} //반복문 탈출
				else if(key==p->key){ //key가 p의 key와 동일하면
					front->rlink=p->rlink; //front의 링크가 p의 다음 노드를 가리키고
					if(p->rlink!=h){ //만약 p가 마지막 노드가 아니라면
						p->rlink->llink=front; //p의 오른쪽링크 즉, p의 다음 노드의 왼쪽 링크가 front를 가리킨다
						p->rlink=h;} //p의 오른쪽링크가 헤드노드를 가리킨다
					p->rlink=NULL; //p의 오른쪽링크가 NULL을 가리킨다
					p->llink=NULL; //p의 왼쪽링크가 NULL을 가리킨다
					free(p); //p를 해제한다
					break;}
				else{
					front=p; //p를 front에 대입하고
					p=p->rlink;} //p가 다음 노드를 가리킨다
			}
			if(p==h) //만약 리스트에 있는 노드의 키를 못찾으면
				printf("CANNOT FIND THE NODE FOR KEY=%d\n",key); //찾을 수 없다고 알린다
		}
		else{ //리스트 안에 한 개의 노드가 존재하면
			if(key==p->key){ //key가 노드의 키와 일치하면
				p->rlink=NULL; //p의 오른쪽링크는 NULL을 가리키고
				p->llink=NULL; //p의 왼쪽링크는 NULL을 가리킨다
				h->rlink=h; //맨 처음 노드를 가리키는 링크가 NULL을 가리킨다
				h->llink=h; //맨 처음 노드를 가리키는 링크가 NULL을 가리킨다
				free(p);} //p를 해제한다
			else //key가 노드의 키와 일치하지 않으면
				printf("CANNOT FIND THE NODE FOR KEY=%d\n",key);	} //찾지 못한다고 알린다
	}
	else //노드가 한 개도 존재하지 않으면
		printf("NODES DON'T EXIST\n"); //찾지 못한다고 알린다
	return 0;
}

/*
 * binary-search-tree-2.c
 *
 *  Created on: 2020. 5. 27.
 *      Author: kingyong
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key;
	struct node* left;
	struct node* right;
} Node;

/* for stack */
#define MAX_STACK_SIZE		20
Node* stack[MAX_STACK_SIZE]; //스택
int top = -1; //top=-1

Node* pop();
void push(Node* aNode);

/* for queue */
#define MAX_QUEUE_SIZE		20
Node* queue[MAX_QUEUE_SIZE]; //큐
int front = -1;
int rear = -1;

Node* deQueue();
void enQueue(Node* aNode);

int initializeBST(Node** h);

void recursiveInorder(Node* ptr);	  /* recursive inorder traversal */
void iterativeInorder(Node* ptr);     /* iterative inorder traversal */
void levelOrder(Node* ptr);	          /* level order traversal */
int insert(Node* head, int key);      /* insert a node to the tree */
int deleteNode(Node* head, int key);  /* delete the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

int main()
{
	char command;
	int key;
	Node* head = NULL;

	do {
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #2                        \n");
		printf("----------------------------------------------------------------\n");
		printf("-------------------[김동용] [2017038064]------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = i      Delete Node                  = d \n");
		printf(" Recursive Inorder    = r      Iterative Inorder (Stack)    = t \n");
		printf(" Level Order (Queue)  = l      Quit                         = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch (command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'i': case 'I':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteNode(head, key);
			break;
		case 'r': case 'R':
			recursiveInorder(head->left);
			break;
		case 't': case 'T':
			iterativeInorder(head->left);
			break;
		case 'l': case 'L':
			levelOrder(head->left);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}
	} while (command != 'q' && command != 'Q');
	return 1;
}

int initializeBST(Node** h) {
	if (*h != NULL) //헤더노드가 NULL이 아니면
		freeBST(*h); //free함수호출
	*h = (Node*)malloc(sizeof(Node)); //동적할당
	(*h)->left = NULL; //헤더노드의 왼쪽노드가 NULL을 가리킨다
	(*h)->right = *h; //헤더노드의 오른쪽노드가 헤더노드를 가리킨다
	(*h)->key = -9999; //헤더노드의 키가 쓰레기값을 갖는다
	top = -1; //top은 -1
	front = rear = -1; //front,rear=-1;
	return 1; //종료
}

void recursiveInorder(Node* ptr) //재귀 중위순회함수
{
	if (ptr) { //ptr이 NULL이 아니면
		recursiveInorder(ptr->left); //ptr의 왼쪽노드를 인자로 함수호출
		printf(" [%d] ", ptr->key); //프린트
		recursiveInorder(ptr->right); //ptr의 오른쪽노드를 인자로 함수호출
	}
}

void iterativeInorder(Node* node)
{
	int num = 0; //반복횟수
	for (;;) { //무한루프
		for (; node; node = node->left){ //node가 NULL이면 종료
			push(node); //node를 push
			num+=1;} //횟수증가
		node = pop(); //노드를 pop한다
		if (!node) { //node가 NULL이면
			break; //반복문 종료
		}
		printf(" [%d] ", node->key); //키 값출력
		node = node->right; //노드가 노드의 오른쪽 노드를 가리킨다
	}
	if(num==0) //노드가 없으면
		printf("노드가 비어 있습니다"); //메시지 출력
}

void levelOrder(Node* ptr) //레벨오더함수
{
	if (!ptr) //ptr이 NULL이면
	{
		printf("노드가 없습니다."); //메시지출력
		return; //종료
	}
	enQueue(ptr); //큐에 ptr추가
	for (;;) //무한루프
	{
		ptr = deQueue(); //큐에서 ptr제거
		if (ptr) { //ptr이 NULL이 아니면
			printf(" [%d] ", ptr->key); //키 값 출력
			if (ptr->left) //ptr의 왼쪽노드가 있으면
				enQueue(ptr->left); //ptr의 왼쪽노드를 인자로 함수 호출
			if (ptr->right) //ptr의 오른쪽노드가 있으면
				enQueue(ptr->right); //ptr의 오른쪽노드를 인자로 함수 호출
		}
		else //ptr이 NULL이면
			break; //반복문 종료
	}
}

int insert(Node* head, int key) //삽입함수
{
	Node* newNode = (Node*)malloc(sizeof(Node)); //새로 추가하려는 노드
	newNode->key = key; //노드의 키는 입력한 키값
	newNode->left = NULL; //노드의 왼쪽노드는 NULL
	newNode->right = NULL; //노드의 오른쪽노드는 NULL

	if (head->left == NULL) { //루트노드가 없으면
		head->left = newNode; //헤더노드가 새로운노드를 가리킨다
		return 1; //종료
	}
	Node* ptr = head->left; //루트노드를 가리키는 ptr
	Node* parentNode = NULL; //부모노드
	while (ptr != NULL) { //ptr이 NULL이 아니면
		if (ptr->key == key) return 1; //ptr의 키가 입력한 키값과 같으면 함수 종료
		parentNode = ptr; //부모노드가 ptr을 가리킨다
		if (ptr->key < key) //ptr의 키값이 입력한 키값보다 작으면
			ptr = ptr->right; //ptr은 ptr의 오른쪽노드를 가리킨다
		else //ptr의 키값이 입력한 키값보다 크면
			ptr = ptr->left; //ptr은 ptr의 왼쪽노드를 가리킨다
	}
	if (parentNode->key > key) //부모노드의 키값이 입력한 키값보다 크면
		parentNode->left = newNode; //부모노드의 왼쪽노드가 새로운 노드가 된다
	else //부모노드의 키값이 입력한 키값보다 작으면
		parentNode->right = newNode; //부모노드의 왼쪽노드가 새로운 노드가 된다
	return 1;
}

int deleteNode(Node* head, int key)
{
	Node* curr1 = head->left; //현재노드 즉, 삭제하려는 노드
	Node* parent = NULL; //현재노드의 부모노드
	Node* left_parent = NULL; //자식이 두 개일때의 부모노드
	Node* lefttemp = NULL; //자식이 두 개일때 삭제하려는 노드
	int while_time = 0; //반복 횟수
	while (curr1) //노드의 키값과 입력한 키값이 같으면 종료
	{
		if(key==curr1->key)
			break;
		if (key > curr1->key) //노드의 키값이 입력한 키값보다 크면
		{
			parent = curr1; //부모노드는 현재노드를 가리킴
			curr1 = curr1->right; //현재노드는 현재노드의 오른쪽 노드를 가리킴
		}
		else if (key < curr1->key) //노드의 키값이 입력한 키값보다 작으면
		{
			parent = curr1; //부모노드는 현재노드를 가리킴
			curr1 = curr1->left; //현재노드는 현재노드의 왼쪽 노드를 가리킴
		}
	}
	if(curr1==NULL){
		printf("cannot find the node"); //못찾았다고 메시지
		return 0;} //함수종료
	if (curr1->left == NULL && curr1->right == NULL) //현재노드의 자식노드가 없을 때
	{
		if(parent==NULL) //현재노드가 루트노드일 때
		{
			head->left = NULL; //헤더의 왼쪽노드는 NULL을 가리키고
			head->right = head; //헤더의 오른쪽 노드는 헤드를 가리킨다
			return 0; //종료
		}
		if (parent->left == curr1) //부모노드의 왼쪽 노드가 현재노드이면
			parent->left = NULL; //부모노드의 왼쪽노드는 NULL을 가리킨다
		if (parent->right == curr1) //부모노드의 오른쪽 노드가 현재노드이면
			parent->right = NULL; //부모노드의 오른쪽노드는 NULL을 가리킨다
		free(curr1); //현재노드를 해제한다
		return 0; //종료
	}
	else if ((curr1->left != NULL && curr1->right == NULL)||(curr1->left == NULL && curr1->right != NULL))
	{ //현재노드의 자식노드가 한 개일 때
		if(parent==NULL) //현재노드가 헤더노드일 때
		{
			if(curr1->left!=NULL) //현재노드의 왼쪽노드가 NULL이 아니면
			{
				head->left=curr1->left; //루트노드가 현재노드의 왼쪽노드를 가리킴
				free(curr1); //현재노드를 해제
				return 0; //종료
			}
			else if(curr1->right!=NULL) //현재노드의 오른쪽노드가 NULL이 아니면
			{
				head->right=curr1->left; //루트노드가 현재노드의 오른쪽노드를 가리킴
				free(curr1); //현재노드를 해제
				return 0; //종료
			}
		}
		if (curr1 == parent->left) { //현재노드가 부모노드의 왼쪽노드일 때
			if (curr1->left != NULL) //현재노드의 왼쪽노드가 NULL이 아니면
			{
				parent->left = curr1->left; //부모노드의 왼쪽노드가 현재노드의 왼쪽노드를 가리킨다
				free(curr1); //현재노드 해제
				return 0; //종료
			}
			else if (curr1->right != NULL)  //현재노드의 오른쪽노드가 NULL이 아니면
			{
				parent->left = curr1->right; //부모노드의 왼쪽노드가 현재노드의 오른쪽노드를 가리킨다
				free(curr1); //현재노드 해제
				return 0; //종료
			}
		}
		else if (curr1 == parent->right) //현재노드가 부모노드의 오른쪽노드일 때
		{
			if (curr1->left != NULL) //현재노드의 왼쪽노드가 NULL이 아니면
			{
				parent->right = curr1->left; //부모노드의 오른쪽노드가 현재노드의 왼쪽노드를 가리킨다
				free(curr1); //현재노드 해제
				return 0; //종료
			}
			else if (curr1->right != NULL) //현재노드의 오른쪽노드가 NULL이 아니면
			{
				parent->right = curr1->right; //부모노드의 오른쪽노드가 현재노드의 오른쪽노드를 가리킨다
				free(curr1); //현재노드 해제
				return 0; //종료
			}
		}
	}
	else if (curr1->left != NULL && curr1->right != NULL) //자식이 두 개 일때
	{
		lefttemp = curr1; //삭제하려는 노드가 현재노드값을 갖는다
		while_time=0; //반복횟수는 0
		while (lefttemp != NULL) { //삭제하려는 노드가 NULL이 아니면
			while_time += 1; //반복횟수 증가
			if(lefttemp->left==NULL) //삭제하려는 노드의 왼쪽노드가 NULL이면
				break; //반복문 종료
			if (while_time == 1){ //처음 반복문을 들어왔을 때
				left_parent = lefttemp; //삭제하려는 노드의 부모노드는 삭제하려는 노드를 가리킨다
				lefttemp = lefttemp->right; //삭제하려는 노드는 삭제하려는 노드의 오른쪽노드를 가리킨다
			}
			else if(while_time > 1){ //처음 반복문이 아닐 때
				left_parent = lefttemp; //삭제하려는 노드의 부모노드는 삭제하려는 노드를 가리킨다
				lefttemp = lefttemp->left; //삭제하려는 노드는 삭제하려는 노드의 왼쪽노드를 가리킨다
			}
		}
		if (while_time>=3) //자식노드의 왼쪽자식노드가 있을 때
		{
			curr1->key = lefttemp->key; //현재노드의 키는 삭제하려는 노드의 키값을 갖는다
			left_parent->left = NULL; //삭제하려는 노드의 부모노드의 왼쪽노드는 NULL을 가리킨다
			free(lefttemp); //삭제하려는 노드를 해제
			return 0; //종료
		}
		else if (while_time == 2)  //자식노드의 왼쪽자식노드가 없을 때
		{
			if(lefttemp->right!=NULL)
			{
				curr1->key = lefttemp->key; //현재노드의 키는 삭제하려는 노드의 키값을 갖는다
				curr1->right=lefttemp->right;
				free(lefttemp);
				return 0;
			}
			else if(lefttemp->right==NULL){
				curr1->key = lefttemp->key; //현재노드의 키는 삭제하려는 노드의 키값을 갖는다
				left_parent->right = NULL; //삭제하려는 노드의 부모노드의 오른쪽노드는 NULL을 가리킨다
				free(lefttemp); //삭제하려는 노드를 해제
				return 0; //종료
			}
		}
	}
	return 0; //종료
}

void freeNode(Node* ptr)
{
	if (ptr) { //ptr이 NULL이 아니면
		freeNode(ptr->left); //ptr의 왼쪽노드를 인자로 다시 함수 호출
		freeNode(ptr->right); //ptr의 오른쪽노드를 인자로 다시 함수 호출
		free(ptr); //ptr해제
	}
}

int freeBST(Node* head) //freeBST함수
{
	if (head->left == head) //루트노드가 없으면
	{
		free(head); //헤드를 해제한다
		return 1; //종료
	}
	Node* p = head->left; //p는 루트노드를 가리킨다
	freeNode(p); //루트노드 해체함수 호출
	free(head); //헤드를 해제
	return 1; //종료
}

Node* pop() //pop함수
{
	if (top == -1) { //스택이 비어있으면
		return 0; //종료
	}
	return stack[top--]; //스택을 반환하고 top을 -1한다
}

void push(Node* aNode) //push함수
{
	if (top >= MAX_STACK_SIZE - 1) //top이 인덱스값의 최대일 때
		printf("\n스택이 가득 찼습니다."); //가득 찼다는 메시지출력
	stack[++top] = aNode; //스택에 aNode를 넣어주고 top을 먼저 증가시킨다
}

Node* deQueue() //큐에서 빼는함수
{
	if (front == rear) { //front와 rear가 동일하면
		return 0; //종료
	}
	front = (front + 1) % MAX_QUEUE_SIZE; //front증가
	return queue[front]; //front값을 -1한 값을 인자로 한 큐를 반환
}

void enQueue(Node* aNode) //큐에 더하는 함수
{
	rear = (rear + 1) % MAX_QUEUE_SIZE; //rear 증가
	if (front == rear) //front와 rear가 동일하면
		printf("\n큐가 가득 찼습니다."); //메시지 출력
	queue[rear] = aNode; //큐의 마지막을 가리키는 큐에 aNode삽입
}

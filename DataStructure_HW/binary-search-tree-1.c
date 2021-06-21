/*
 * binary-search-tree-1.c
 *
 *  Created on: 2020. 5. 12.
 *      Author: kingyong
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int key; //데이터값
	struct node *left; //왼쪽노드
	struct node *right; //오른쪽노드
} Node;

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()
{
	char command;
	int key;
	Node* head = NULL;
	Node* ptr = NULL;	/* temp */

	do{
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf("--------------------[김동용] [2017038064]------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Node                  = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f \n");
		printf(" Postorder Traversal  = t      Quit                         = q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'z': case 'Z':
			initializeBST(&head);
			break;
		case 'q': case 'Q':
			freeBST(head);
			break;
		case 'n': case 'N':
			printf("Your Key = ");
			scanf("%d", &key);
			insert(head, key);
			break;
		case 'd': case 'D':
			printf("Your Key = ");
			scanf("%d", &key);
			deleteLeafNode(head, key);
			break;
		case 'f': case 'F':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchIterative(head, key); //search함수를 통해 나온 결과를 ptr에 저장
			if(ptr != NULL) //ptr이 NULL이 아니면
				printf("\n node [%d] found at %p\n", ptr->key, ptr); //노드가 존재한다는 문구 출력
			else //ptr이 NULL이면
				printf("\n Cannot find the node [%d]\n", key); //노드가 존재하지 않는다는 문구 출력
			break;
		case 's': case 'S':
			printf("Your Key = ");
			scanf("%d", &key);
			ptr = searchRecursive(head->left, key); //search함수를 통해 나온 결과를 ptr에 저장
			if(ptr != NULL) //ptr이 NULL이 아니면
				printf("\n node [%d] found at %p\n", ptr->key, ptr); //노드가 존재한다는 문구 출력
			else //ptr이 NULL이면
				printf("\n Cannot find the node [%d]\n", key); //노드가 존재하지 않는다는 문구 출력
			break;

		case 'i': case 'I':
			inorderTraversal(head->left);
			break;
		case 'p': case 'P':
			preorderTraversal(head->left);
			break;
		case 't': case 'T':
			postorderTraversal(head->left);
			break;
		default:
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

int initializeBST(Node** h) {

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL) //*h가 NULL이 아니면
		freeBST((*h)); //free함수 호출

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node)); //동적할당
	(*h)->left = NULL; //왼쪽노드는 NULL을 가리킨다
	(*h)->right = *h; //오른쪽노드는 자기자신을 가리킨다
	(*h)->key = -9999; //키 값은 이 값을 갖는다
	return 1;
}



void inorderTraversal(Node* ptr)
{
	if(ptr){ //ptr이 NULL이 아니면
		inorderTraversal(ptr->left); //ptr의 왼쪽노드를 인자로 재귀호출
		printf("[%d] ",ptr->key); //ptr의 키값을 프린트
		inorderTraversal(ptr->right); //ptr의 오른쪽노드를 인자로 재귀호출
	}
}

void preorderTraversal(Node* ptr)
{
	if(ptr) //ptr이 NULL이 아니면
	{
		printf("[%d] ",ptr->key); //ptr의 키값을 프린트
		preorderTraversal(ptr->left); //ptr의 왼쪽노드를 인자로 재귀호출
		preorderTraversal(ptr->right); //ptr의 오른쪽노드를 인자로 재귀호출
	}
}

void postorderTraversal(Node* ptr)
{
	if(ptr) //ptr이 NULL이 아니면
	{
		postorderTraversal(ptr->left); //ptr의 왼쪽노드를 인자로 재귀호출
		postorderTraversal(ptr->right); //ptr의 오른쪽노드를 인자로 재귀호출
		printf("[%d] ",ptr->key); //ptr의 키값을 프린트
	}
}


int insert(Node* head, int key)
{
	Node* curr=(Node*)malloc(sizeof(Node)); //현재노드
	Node* newnode=(Node*)malloc(sizeof(Node)); //새로운 노드
	Node* ptr=searchIterative(head,key); //새로 입력한 노드가 트리에 존재하는지 검사
	if(head->left==NULL) //노드가 없으면
	{
		newnode->left=NULL; //새로운 노드의 왼쪽노드는 NULL을 가리킨다
		newnode->right=NULL; //새로운 노드의 오른쪽노드는 NULL을 가리킨다
		newnode->key=key; //새로운 노드의 키값은 키값을 갖는다
		head->left=newnode; //루트노드가 새로운노드를 가리킨다
		return 0;
	}
	if(ptr!=NULL) //ptr이 NULL이 아니면
		return 0; //종료
	newnode->left=NULL; //새로운 노드의 왼쪽노드는 NULL을 가리킨다
	newnode->right=NULL; //새로운 노드의 오른쪽노드는 NULL을 가리킨다
	newnode->key=key; //새로운 노드의 키값은 키값을 갖는다
	curr=head->left; //현재노드는 루트노드를 가리킨다
	while(1) //무한루프
	{
		if(curr->key<key) //현재노드의 키가 입력한 키보다 작으면
		{
			if(curr->right==NULL) //현재노드의 오른쪽노드가 NULL이면
			{
				curr->right=newnode; //현재노드의 오른쪽노드가 새로운노드를 가리킨다
				return 0; //종료
			}
			curr=curr->right; //현재노드는 현재노드의 오른쪽노드가 된다
		}
		else if(curr->key>key){ //현재노드의 키가 입력한 키보다 크면
			if(curr->left==NULL) //현재노드의 왼쪽노드가 NULL이면
			{
				curr->left=newnode; //현재노드의 왼쪽노드가 새로운노드를 가리킨다
				return 0; //종료
			}
			curr=curr->left; //현재노드는 현재노드의 왼쪽노드가 된다
		}
	}
}

int deleteLeafNode(Node* head, int key)
{
	Node* curr1=head->left; //현재노드는 루트노드가 된다
	Node* parent=NULL; //아버지노드는 NULL값이다
	if(searchIterative(head,key)==NULL) //입력한 키를 검색해서 NULL이 나오면
	{
		printf("cannot found %d for key",key); //키값이 트리에 없다고 출력
		return 0; //종료
	}
	while(curr1->key!=key) //현재노드의 키값과 입력한 키값이 같으면 종료
	{
		if(key>curr1->key) //현재노드의 키가 입력한 키보다 작으면
		{
			parent=curr1; //아버지노드는 현재노드의 값을 갖는
			curr1=curr1->right; //현재노드는 현재노드의 오른쪽노드가 된다
		}
		else if(key<curr1->key) //현재노드의 키가 입력한 키보다 크면
		{
			parent=curr1; //아버지노드는 현재노드의 값을 갖는다
			curr1=curr1->left; //현재노드는 현재노드의 왼쪽노드가 된다
		}
	}
	if(parent==NULL&&curr1->left==NULL&&curr1->right==NULL) //삭제할 노드가 루트노드이고 트리에 노드가 유일할 때
	{
		head->left=NULL; //루트노드가 NULL을 가리키고
		head->right=head; //루트노드의 오른쪽노드가 루트노드를 가리킨다
		return 0; //종료
	}
	if(curr1->left==NULL&&curr1->right==NULL) //현재노드의 왼쪽노드와 오른쪽노드가 NULL이면 즉, 리프노드이면
	{
		if(parent->left==curr1) //아버지노드의 왼쪽노드가 현재노드이면
			parent->left=NULL; //아버지노드의 왼쪽노드를 없앤다
		if(parent->right==curr1) //아버지노드의 오른쪽노드가 현재노드이면
			parent->right=NULL; //아버지노드의 왼쪽노드를 없앤다
		free(curr1); //현재노드 해제
		return 0; //종료
	}
	else //현재노드의 왼쪽노드와 오른쪽노드가 NULL가 아니면 즉, 리프노드가 아니면
		return 0; //종료
}

Node* searchRecursive(Node* ptr, int key)
{
	if(!ptr) //ptr이 NULL이면
		return NULL; //NULL반환
	if(key==ptr->key) //key값과 일치하면
		return ptr; //ptr반환
	if(key<ptr->key) //key보다 크면
		return searchRecursive(ptr->left,key); //함수호출
	return searchRecursive(ptr->right,key); //key보다 작으면 함수호출
}

Node* searchIterative(Node* head, int key)
{
	Node* ptr=head->left; //ptr은 루트노드
	while(ptr) //ptr이 NULL이면 종료
	{
		if(key==ptr->key) //key값과 같으면
			return ptr; //ptr반환
		if(key<ptr->key) //key보다 크면
			ptr=ptr->left; //ptr은 ptr의 왼쪽노드를 가리킨다
		else if(key>ptr->key) //key보다 작으면
			ptr=ptr->right; //ptr은 ptr의 오른쪽노드를 가리킨다
	}
	return NULL; //못찾으면 NULL반환
}


int freeBST(Node* head)
{
	if(head){ //head가 NULL이 아니면
		freeBST(head->left); //head의 왼쪽노드를 인자로 함수호출
		if(head->right!=head) //head의 오른쪽노드가 head가 아니면 즉, head의 위치가 head가 아닐때
			freeBST(head->right); //head의 오른쪽노드를 인자로 함수호출
		head->left=NULL; //head의 왼쪽노드가 NULL을 가리킨다
		if(head->right==head) //head가 head를 가리키면 즉, head의 위치가 head 일때
			head->right=head; //head의 오른쪽노드가 head를 가리킨다
		else //노드가 존재하면
			head->right=NULL; //head의 오른쪽노드가 NULL을 가리킨다
		free(head); //head해제
	}
	return 0;
}

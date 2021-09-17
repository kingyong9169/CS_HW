#define _CRT_SECURE_NO_WARNINGS //fopen 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h> //fopn, fgets, fclose 함수가 선언된 헤더 파일
#include <stdlib.h>

typedef struct NODE { //연결리스트의 노드 구조체
	struct NODE* next; //다음 노드의 주소를 저장할 포인터
	long long int key;
}node;

int main() {
	int check = 0;
	int list_count = 0, over_count = 0;
	int i=0;
	long long key;
	FILE* fp = fopen("input.txt", "r");

	node* head = malloc(sizeof(node));
	node* curr = malloc(sizeof(node));
	node* tail = malloc(sizeof(node));

	for (i = 0; i < 100000; i++) {
		fscanf(fp, "%lld", &key);
		if (key > 5000)
			over_count++;
		if (i == 0) {
			node* headNode = (node*)malloc(sizeof(node));
			headNode->key = key;
			headNode->next = NULL;

			list_count++;
			head = headNode;
			tail = headNode;
		}
		curr = head;

		if (i != 0) {
			while (curr) {
				if (curr->key==key)
				{
					check = 1;
					break;
				}
				curr = curr->next;
			}
			if (check == 1) {
				check = 0;
				continue;
			}
			node* newNode = (node*)malloc(sizeof(node));
			newNode->key = key;
			newNode->next = NULL;

			tail->next = newNode;
			tail = newNode;
			list_count++;
		}
	}
	printf("The total number of nodes: %d\n", list_count);
	printf("More than 5000 values: %d", over_count);

	node* temp = head;

	while (temp) { //free
		free(temp);
		temp = temp->next;
	}
	free(head);
	free(curr);
	free(tail);

	fclose(fp);
}

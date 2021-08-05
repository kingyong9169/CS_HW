#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct node {
  int data;
  struct node* next;
}node;

node* head;
node* tail;
node* cur;

int k = 0;
int nodenum;

void freenode() {
  cur = head;
  tail = head;

  while (cur != NULL) {
     tail = tail->next;
     free(cur);
     cur = tail;
  }

}

void add(int key) {

  for (; k < 1; k++) {
     node* firstnode = (node*)malloc(sizeof(node));
     firstnode->data = key;
     firstnode->next = NULL;

     nodenum++;
     head = firstnode;
     tail = firstnode;
  }


  cur = head;

  while (cur != NULL) {
     if (key == cur->data)
        return;
     cur = cur->next;
  }

  node* newnode = (node*)malloc(sizeof(node));
  newnode->data = key;
  newnode->next = NULL;
  tail->next = newnode;
  tail = newnode;
  nodenum++;
}

int main(void) {
  struct timeval startTime, endTime; // 시간을 측정해주는 timeval 구조체를 시작시간과 끝났을 때 시간으로 사용하기 위해 두 개 만들어 줌 
  gettimeofday(&startTime, NULL); // 시작할 때의 시간을 구함 

  node* head = (node*)malloc(sizeof(node));
  node* tail = (node*)malloc(sizeof(node));
  node* cur = (node*)malloc(sizeof(node));
  int i, over5000 = 0;
  FILE* fp;

  fp = fopen("input.txt", "r");
  long long int data;

  for (i = 0; i < 100000; i++) {
     fscanf(fp, "%lld", &data);
     if (data > 5000)
        over5000++;
     add(data);
  }

  freenode();

  printf("5000 이상의 수 개수 : %d\n", over5000);
  printf("노드 개수 : %d\n", nodenum);

  fclose(fp);

  gettimeofday(&endTime, NULL); // 끝났을 때의 시간을 구함 

  endTime.tv_usec = endTime.tv_usec - startTime.tv_usec; // usec은 마이크로초, sec은 초, 끝났을 때 시간에서 시작할 때의 시간을 빼서 실행시간을 구함 
  endTime.tv_sec = endTime.tv_sec - startTime.tv_sec; //  마찬가지로 끝났을 때의 시간에서 시작할 때의 시간을 빼서 실행시간을 구함 

  endTime.tv_usec += (endTime.tv_sec * 1000000); // endTime.tv_usec에 sec을 더해 총 실행시간을 저장함 
  printf("Execution Time: %lf sec\n", endTime.tv_usec / 1000000.0); // 실행 시간을 출력해줌, 1000000.0으로 나눠서 초와 마이크로초의 자릿수를 맞춰줌

  return 0;
}
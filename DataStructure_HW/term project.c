/*
 * term project.c
 *
 *  Created on: 2020. 6. 11.
 *      Author: kingyong
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 20 //최대vertex수

int VisitVertex[MAX_VERTEX]={0}; //vertex생성을 판별하는 배열
int visited[MAX_VERTEX]={0}; //visitflag
typedef struct Vertex { //vertex구조체
	int num;
	struct Vertex* link;
} Vertex;

typedef struct VertexHead{ //vertexhead구조체
	Vertex* head;
} VertexHead;

typedef struct Graph{ //그래프 구조체
	VertexHead* vlist;
} Graph;


typedef struct queue{ //큐구조체
	int vertex; //큐의 숫자
	struct queue* link; //큐의 링크
}queue;
queue* front, *rear; //큐 포인터

typedef struct stack{ //스택 구조체
	int vertex; //스택의 숫자
	struct stack* link; //스택의 링크
}stack;
stack* top; //top포인터

Graph* createGraph(void);
void destroyGraph(Graph* G);
void insertVertex(Graph* G, int v_num);
int deleteVertex(Graph* G, int v_num);
int insertEdge(Graph* G, int v_num1, int v_num2);
int deleteEdge(Graph* G, int v_num1, int v_num2);
void printGraph(Graph* G);
void addq(int num);
int deleteq();
void breadthFS(Graph* G);
void push(int num);
int pop(void);
void depthFS(Graph* G);

int main()
{
	char command; //명령
	int v_num;
	int v_num1; //vertex 입력변수
	int v_num2; //vertex 입력변수
	Graph* G=NULL; //그래프 포인터 초기화

	do{
		printf("----------------------------------------------------------------\n");
		printf("  Graph : ADJ list \n");
		printf("--[김동용]----[2017038064]---------------------------------------\n");
		printf("  CreateGraph = z destroyGraph & quit = q\n");
		printf(" insertVertex = i        deleteVertex = d\n");
		printf("   insertEdge = e          deleteEdge = x\n");
		printf("      DepthFS = f           BreadthFS = b\n");
		printf("   printGraph = p\n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command); //명령할 값 입력

		switch(command) {
			case 'z': case 'Z':
				G=createGraph(); //그래프 생성
				break;
			case 'q': case 'Q':
				destroyGraph(G); //그래프 초기화
				break;
			case 'i': case 'I':
				printf("Vertex number to add = ");
				scanf("%d",&v_num);
				insertVertex(G,v_num); //insertvertex
				break;
			case 'd': case 'D':
				printf("Vertex number to delete = ");
				scanf("%d",&v_num);
				deleteVertex(G,v_num); //deletevertex
				break;
			case 'e': case 'E':
				printf("Edge를 추가하기 위해 Vertex number두 개를 입력하세요 = ");
				scanf("%d",&v_num1);
				scanf("%d",&v_num2);
				insertEdge(G,v_num1,v_num2); //insertedge
				break;
			case 'x': case 'X':
				printf("Edge를 삭제하기 위해 Vertex number두 개를 입력하세요 = ");
				scanf("%d",&v_num1);
				scanf("%d",&v_num2);
				deleteEdge(G,v_num1,v_num2); //deletevertex
				break;
			case 'f': case 'F':
				printf("depthFS\n");
				depthFS(G); //DFS
				break;
			case 'b': case 'B':
				printf("breadthFS\n");
				breadthFS(G); //BFS
				break;
			case 'p': case 'P':
				printf("\nPrint adj list: \n");
				printf("----------------------------------------------------------------\n");
				printGraph(G);
				printf("----------------------------------------------------------------\n\n");
				break;
		}

	}while(command != 'q' && command != 'Q'); //q가 입력되기 전까지 지속
	return 1;
}

Graph* createGraph(void) //그래프생성 및 초기화 함수
{
	Graph* NewGraph=(Graph*)malloc(sizeof(Graph)); //새로운 그래프 동적할당
	VertexHead* list=(VertexHead*)malloc(sizeof(VertexHead)*MAX_VERTEX); //vertexhead 동적할당
	NewGraph->vlist=list; //그래프의 루트가 vertexhead의 첫 번째 주소를 가리킨다
	return NewGraph; //새로운 그래프의 주소 반환
}

void destroyGraph(Graph* G) //그래프 파괴 및 종료 함수
{
	VertexHead* temp=G->vlist; //temp가 vertexhead의 첫 번째 주소를 가리킨다
	for(int i=0;i<MAX_VERTEX;i++) //MAX만큼 반복
	{
		deleteVertex(G,i); //i vertex를 삭제
	}
	free(temp); //temp 해제
	G->vlist=NULL; //그래프의 루트가 NULL을 가리킨다
	free(G); //그래프 해제
}

void insertVertex(Graph* G, int v_num) //vertex삽입함수
{
	VertexHead* temp=G->vlist; //temp가 vertexhead의 첫 번째 주소를 가리킨다
	if(VisitVertex[v_num]!=1){ //vertexhead가 비활성화되어 있으면
		VisitVertex[v_num]=1; //vertexhead 활성화
		(temp+v_num)->head=NULL; //vertexhead[v_num]의 head가 NULL을 가리킨다
	}
	else //vertexhead가 활성화되어 있으면
		printf("이미 존재하는 vertex입니다.\n"); //오류출력
}

int deleteVertex(Graph* G, int v_num) //vertex삭제 함수
{
	VertexHead* temp=G->vlist; //temp가 vertexhead의 첫 번째 주소를 가리킨다
	Vertex* p=(temp+v_num)->head; //p가 vertexhead[v_num]의 첫 번째 edge를 가리킨다
	Vertex* prev=NULL; //prev초기화
	Vertex* d=NULL; //d초기화
	if((temp+v_num)->head!=NULL&&VisitVertex[v_num]==1) //vertexhead[v_num]이 edge를 갖고 있고 vertex가 활성화되어 있으면
	{
		while(p!=NULL){ //p가 NULL이 아니면
			prev=p; //prev가 p를 가리킨다
			p=p->link; //p가 다음p를 가리킨다
			prev->link=NULL; //prev의 링크가 NULL을 가리킨다
			free(prev); //prev 해제
		}
		(temp+v_num)->head=NULL; //vertexhead[v_num]의 head가 NULL을 가리킨다
		VisitVertex[v_num]=0; //vertex비활성화
		for(int i=0;i<MAX_VERTEX;i++) //MAX만큼 반복
		{
			d=(temp+i)->head; //d는 vertexhead[i]의 첫 번째 edge를 가리킨다
			if(VisitVertex[i]==0) //vertex가 비활성화이면
				continue; //다음 반복문
			else if(VisitVertex[i]!=0&&d!=NULL){ //vertex가 활성화되어있고 edge도 존재하면
				if(d->num==v_num){ //첫 번째 edge의 num이 v_num이면
					(temp+i)->head=d->link; //vertexhead[i]의 head가 d의 다음 edge를 가리킨다
					free(d); //d해제
					d->link=NULL; //d의 링크가 NULL을 가리킨다
				}
				else if(d->num!=v_num){ //첫 번째 edge의 num이 v_num아니면
					while(d!=NULL){ //d가 NULL이 아니면
						if(d->link==NULL&&d->num!=v_num) //d의 링크가 NULL이고 d의 num이 v_num이 아니면
						{
							//printf("삭제하려는 vertex가 존재하지 않습니다.\n");
							break; //반복문 탈출
						}
						else if(d->num==v_num) //d의 num이 v_num과 일치하면
							break; //반복문 중지
						prev=d; //prev가 d를 가리킨다
						d=d->link; //d는 다음 d를 가리킨다
					}
					if(d->num==v_num){ //d의 num이 v_num이면
						prev->link=d->link; //prev의 링크가 d의 다음 edge를 가리킨다
						d->link=NULL; //d의 링크가 NULL을 가리킨다
						free(d); //d해제
					}
					else if(d->num!=v_num) //d의 num이 v_num이 아니면
						continue; //반복문 계속
				}
			}
			else if(VisitVertex[i]!=0&&d==NULL) //vertex가 활성화되어있고 edge가 없을 때
				continue; //반복문 계속
		}
	}
	else if(VisitVertex[v_num]==0) //vertex가 활성화되어 있지 않으면
	{
		printf("%d vertex가 존재하지 않습니다.\n",v_num); //오류 출력
		return 0; //출력
	}
	else if((temp+v_num)->head==NULL&&VisitVertex[v_num]==1) //vertexhead[v_num]이 edge를 갖고 있지 않고 vertex가 활성화되어 있으면
	{
		VisitVertex[v_num]=0; //vertex가 비활성화
		return 0; //종료
	}
	return 1; //종료
}

int insertEdge(Graph* G, int v_num1, int v_num2) //edge삽입 함수
{
	VertexHead* temp=G->vlist; //temp가 vertexhead의 첫 번째 주소를 가리킨다
	Vertex* p=(temp+v_num1)->head; //vertexhead[v_num1]의 첫 번째 edge를 가리키는 변수
	Vertex* t=(temp+v_num2)->head; //vertexhead[v_num2]의 첫 번째 edge를 가리키는 변수
	Vertex* NewVertex1=(Vertex*)malloc(sizeof(Vertex)); //새로운 edge1
	Vertex* NewVertex2=(Vertex*)malloc(sizeof(Vertex)); //새로운 edge2
	if((VisitVertex[v_num1]==1&&VisitVertex[v_num2]==1)&&(v_num2>=0&&v_num2<MAX_VERTEX)&& //두 인자 모두 활성화가 되어있고 모두 MAX_VERTEX범위에 있으며
			(v_num1>=0&&v_num1<MAX_VERTEX)&&(v_num1!=v_num2)) //두 인자의 값이 다를 때
		{
			if((temp+v_num1)->head==NULL&&(temp+v_num2)->head==NULL){ //vertexhead[v_num1]이 edge를 갖지 않고 vertexhead[v_num2]가 edge를 갖지 않을 때
				NewVertex1->num=v_num2; //vertex의 숫자를 인자로 초기화
				NewVertex1->link=NULL; //vertex의 링크 초기화
				(temp+v_num1)->head=NewVertex1; //vertexhead[v_num1]이 새로운vertex1을 가리킨다
				NewVertex2->num=v_num1; //vertex의 숫자를 인자로 초기화
				NewVertex2->link=NULL; //vertex의 링크 초기화
				(temp+v_num2)->head=NewVertex2; //vertexhead[v_num2]이 새로운vertex2을 가리킨다
			}
			else if((temp+v_num1)->head!=NULL&&(temp+v_num2)->head!=NULL) //vertexhead[v_num1]이 edge를 갖고 vertexhead[v_num2]가 edge를 가질 때
			{
				while(p!=NULL){ //p의 링크가 NULL이 아니면 반복
					if(p->num==v_num1||p->num==v_num2){ //p의 num이 v_num1과 같거나 v_num2와 같으면
						printf("다른 vertex값을 입력하시오.\n"); //오류 출력
						return 0; //종료
					}
					if(p->link==NULL)
						break;
					p=p->link; //p가 다음 edge를 가리킴
				}
				while(t!=NULL){ //t의 링크가 NULL이 아니면 반복
					if(t->num==v_num1||t->num==v_num2){ //t의 num이 v_num1과 같거나 v_num2와 같으면
						printf("다른 vertex값을 입력하시오.\n"); //오류 출력
						return 0; //종료
					}
					if(t->link==NULL)
						break;
					t=t->link; //t가 다음 edge를 가리킴
				}
				NewVertex1->num=v_num2; //vertex의 숫자를 인자로 초기화
				p->link=NewVertex1; //p의 링크가 새로운vertex1을 가리킨다
				NewVertex1->link=NULL; //vertex의 링크 초기화
				NewVertex2->num=v_num1; //vertex의 숫자를 인자로 초기화
				t->link=NewVertex2; //t의 링크가 새로운vertex2을 가리킨다
				NewVertex2->link=NULL; //vertex의 링크 초기화
			}
			else if((temp+v_num1)->head==NULL&&(temp+v_num2)->head!=NULL) //vertexhead[v_num1]이 edge를 갖지 않고 vertexhead[v_num2]가 edge를 가질 때
			{
				NewVertex1->num=v_num2; //vertex의 숫자를 인자로 초기화
				(temp+v_num1)->head=NewVertex1; //vertexhead[v_num1]이 새로운vertex1을 가리킨다
				NewVertex1->link=NULL; //vertex의 링크 초기화
				if(t->num==v_num1||t->num==v_num2){ //p의 num이 v_num1과 같거나 v_num2와 같으면
					printf("다른 vertex값을 입력하시오.\n"); //오류 출력
					return 0; //종료
				}
				while(t!=NULL){ //t의 링크가 NULL이 아니면 반복
					if(t->num==v_num1||t->num==v_num2){ //p의 num이 v_num1과 같거나 v_num2와 같으면
						printf("다른 vertex값을 입력하시오.\n"); //오류 출력
						return 0; //종료
					}
					if(t->link==NULL)
						break;
					t=t->link; //t가 다음 edge를 가리킴
				}
				NewVertex2->num=v_num1; //vertex의 숫자를 인자로 초기화
				t->link=NewVertex2; //t의 링크가 새로운vertex2를 가리킨다
				NewVertex2->link=NULL; //vertex의 링크 초기화
			}
			else if((temp+v_num1)->head!=NULL&&(temp+v_num2)->head==NULL){ //vertexhead[v_num1]이 edge를 갖고 vertexhead[v_num2]가 edge를 갖지 않을 때
				NewVertex2->num=v_num1; //vertex의 숫자를 인자로 초기화
				(temp+v_num2)->head=NewVertex2; //vertexhead[v_num2]이 새로운vertex2을 가리킨다
				NewVertex2->link=NULL; //vertex의 링크 초기화
				if(p->num==v_num1||p->num==v_num2){ //p의 num이 v_num1과 같거나 v_num2와 같으면
					printf("다른 vertex값을 입력하시오.\n"); //오류 출력
					return 0; //종료
				}
				while(p!=NULL) //p의 링크가 NULL이 아니면 반복
				{
					if(p->num==v_num1||p->num==v_num2){ //p의 num이 v_num1과 같거나 v_num2와 같으면
						printf("다른 vertex값을 입력하시오.\n"); //오류 출력
						return 0; //종료
					}
					if(p->link==NULL)
						break;
					p=p->link; //p가 다음 edge를 가리킴
				}
				NewVertex1->num=v_num2; //vertex의 숫자를 인자로 초기화
				p->link=NewVertex1; //p의 링크가 새로운vertex1을 가리킨다
				NewVertex1->link=NULL; //vertex의 링크 초기화

			}
		}
	else if((v_num2<0||v_num2>=MAX_VERTEX)||(v_num1<0||v_num1>=MAX_VERTEX)){ //둘 중 하나라도 MAX_VERTEX의 범위를 벗어난 값을 입력했을 때
		printf("올바른 vertex값을 입력하시오\n"); //오류 출력
		return 0; //종료
	}
	else if((v_num1==v_num2)){ //vertex가 서로 같은 값을 입력했을 때
		printf("서로 다른 vertex값을 입력하시오\n"); //오류 출력
		return 0; //종료
	}
	else if(VisitVertex[v_num1]!=1||VisitVertex[v_num2]!=1){ //vertex가 활성화 되지 않았을 때
		printf("insert_vertex를 하시오\n"); //오류 출력
		return 0; //종료
	}
	return 1; //종료
}

int deleteEdge(Graph* G, int v_num1, int v_num2) //edge를 지우는 함수
{
	VertexHead* temp=G->vlist; //vertexhead를 가리킴
	Vertex* p=(temp+v_num1)->head; //vertex1
	Vertex* t=(temp+v_num2)->head; //vertex2
	Vertex* prev1=NULL; //vertex1 이전 vertex
	Vertex* prev2=NULL; //vertex2 이전 vertex
	if((VisitVertex[v_num1]==1&&VisitVertex[v_num2]==1)&&v_num1!=v_num2
			&&(v_num1>=0&&v_num1<MAX_VERTEX)
			&&(v_num2>=0&&v_num2<MAX_VERTEX)){ //vertexhead가 활성화 되어있으면
		if(p!=NULL&&t!=NULL)
		{
			if(p->num==v_num2&&t->num==v_num1) //삭제하려는 edge가 맨 앞에 존재할 때
			{
				(temp+v_num1)->head=p->link; //헤드가 삭제하려는 edge의 다음 edge를 가리킨다
				free(p); //해제
				(temp+v_num2)->head=t->link; //헤드가 삭제하려는 edge의 다음 edge를 가리킨다
				free(t); //해제
			}
			else if(p->num!=v_num2&&t->num==v_num1) //삭제하려는 edge가 첫 번째 vertex의 맨 앞에 존재하고 두 번째는 없을 때
			{
				while(p->num!=v_num2) //첫 번째 edge의 num이 인자값이 아니면 반복
				{
					if(p->link==NULL) //p의 링크가 NULL일 때
					{
						printf("삭제하려는 edge를 다시 입력하시오.\n"); //오류 출력
						return 0; //종료
					}
					prev1=p; //전 edge는 p를 가리키고
					p=p->link; //p는 다음 edge를 가리킨다
				}
				prev1->link=p->link; //prev1의 link가 p의 다음 vertex를 가리킨다
				free(p); //p해제
				(temp+v_num2)->head=t->link; //vertexhead[v_num2]가 t의 다음 vertex를 가리킨
				free(t); //p해제
			}
			else if(p->num==v_num2&&t->num!=v_num1) //삭제하려는 edge가 두 번째 vertex의 맨 앞에 존재하고 첫 번째는 없을 때
			{
				while(t->num!=v_num1) //두 번째 edge의 num이 인자값이 아니면 반복
				{
					if(t->link==NULL) //t의 링크가 NULL일 때
					{
						printf("삭제하려는 edge를 다시 입력하시오.\n"); //오류출력
						return 0;
					}
					prev2=t; //prev2가 t를 가리킨다
					t=t->link; //다음 t를 가리킨다
				}
				prev2->link=t->link; //prev2의 link가 t의 다음 vertex를 가리킨다
				free(t); //t해제
				(temp+v_num1)->head=p->link; //vertexhead[v_num1]이 p의 다음 vertex를 가리킨다
				free(p); //p해제
			}
			else if(p->num!=v_num2&&t->num!=v_num1) //삭제하려는 edge가 둘 다 맨 앞에 없을 때
			{
				while(t->num!=v_num1) //두 번째 edge의 num이 인자값이 아니면 반복
				{
					if(t->link==NULL) //t의 링크가 NULL일 때
					{
						printf("삭제하려는 edge를 다시 입력하시오.\n"); //오류 출력
						return 0; //종료
					}
					prev2=t; //prev2가 t를 가리킨다
					t=t->link; //t가 다음 t를 가리킨다
				}
				while(p->num!=v_num2) //첫 번째 edge의 num이 인자값이 아니면 반복
				{
					if(p->link==NULL) //p의 링크가 NULL일 때
					{
						printf("삭제하려는 edge를 다시 입력하시오.\n"); //오류 출력
						return 0; //종료
					}
					prev1=p; //prev1가 p를 가리킨다
					p=p->link; //p가 다음 p를 가리킨다
				}
				prev1->link=p->link; //prev1의 link가 p의 다음 vertex를 가리킨다
				free(p); //p해제
				prev2->link=t->link; //prev2의 link가 t의 다음 vertex를 가리킨다
				free(t); //t해제
			}
		}
		else if(p==NULL||t==NULL)
			printf("삭제하려는 edge를 다시 입력하시오.\n"); //오류 출력
	}
	else if((VisitVertex[v_num1]==0||VisitVertex[v_num2]==0)
			||(v_num1<0||v_num1>=MAX_VERTEX)
			||(v_num2<0||v_num2>=MAX_VERTEX)||v_num1==v_num2){ //인자에 이상이 있을 때
		printf("올바른 edge를 입력하시오.\n"); //오류 프린트
		return 0; //종료
	}
	return 1;
}

void push(int num) //push함수
{
	stack* temp=(stack*)malloc(sizeof(stack)); //temp초기화
	temp->vertex=num; //temp의 vertex가 num값을 갖는다
	temp->link=top; //temp의 link가 top을 가리킨다
	top=temp; //top은 temp를 가리킨다
}

int pop(void) //pop함수
{
	stack* temp=top; //temp가 top을 가리킨다
	int item; //추출할 변수를 저장
	item=temp->vertex; //item이 temp의 vertex를 갖는다
	top=temp->link; //top은 temp의 link를 가리킨다
	free(temp); //temp해제
	return item; //item반환
}

void depthFS(Graph* G) //깊이우선탐색
{
	VertexHead* temp=G->vlist; //vertexhead를 가리킴
	Vertex* w; //vertex
	int v;
	int i;
	top=NULL; //초기화
	for(i=0;i<MAX_VERTEX;i++) //MAX만큼 반복
	{
		if(VisitVertex[i]==1) //vertex가 존재하면 visited를 0으로 표시
			visited[i]=0;
		else if(VisitVertex[i]==0) //vertex가 존재하지 않으면 visited를 1로 표시
			visited[i]=1;
	}
	for(i=0;i<MAX_VERTEX;i++) //MAX만큼 반복
	{
		if(VisitVertex[i]==1){ //vertex가 활성화되어 있으면
			if((temp+i)->head==NULL)//만약 edge가 없으면
				continue; //다음 반복문
			else if(visited[i]==0) //방문하지 않았으면
			{
				push(i); //i를 푸쉬
				visited[i]=1; //i를 방문했다고 표시
				while(top!=NULL){ //top이 NULL이 아니면
					v=pop(); //v에 pop한 값을 대입
					printf("%d ",v); //v프린트
					for(w=(temp+v)->head;w;w=w->link) //인접노드를 모두 탐색
					{
						if(!visited[w->num]) //방문하지 않았으면
						{
							visited[w->num]=1; //방문했다고 표시
							push(w->num); //푸쉬한다
						}
					}
				}
			}
			else if(visited[i]==1) //vertex에 방문했으면
				continue; //다음 반복문
		}
		else if(VisitVertex[i]==0) //vertex가 활성화되어 있지 않으면
			continue; //다음 반복문
	}
	printf("\n"); //다음 줄
}

void addq(int num) //큐에 삽입
{
	queue* temp=(queue*)malloc(sizeof(queue)); //동적할당
	temp->vertex=num; //temp의 vertex에 num을 삽입
	temp->link=NULL; //temp의 link가 NULL을 가리킨다
	if(front){ //front가 NULL이 아니면
		rear->link=temp; //rear의 link가 temp를 가리킨다
		rear=temp; //rear가 temp를 가리킨다
	}
	else{ //front가 NULL이면
		front=temp; //front는 temp의 값을 갖는다
		rear=temp; //rear는 temp의 값을 갖는다
	}
}

int deleteq() //큐에서 추출
{
	queue* temp=front; //temp가 front를 가리킨다
	int item; //추출할 변수를 저장
	if(!temp) //temp가 NULL이면
		printf("큐가 비어있습니다."); //프린트
	item=temp->vertex; //item에 temp의 vertex를 삽입
	front=front->link; //front가 다음을 가리킴
	if(front==NULL) //front가 NULL이면
		rear=NULL; //rear도 NULL을 가리킴
	free(temp); //temp를 해제
	return item; //item반환
}

void breadthFS(Graph* G) //넓이우선탐색
{
	VertexHead* temp=G->vlist; //vertexhead접근
	Vertex* w; //vertex
	int v;
	int i;
	front=rear=NULL; //초기화
	for(i=0;i<MAX_VERTEX;i++) //MAX만큼 반복
	{
		if(VisitVertex[i]==1) //vertexhead가 활성화되어있으면
			visited[i]=0; //visited 비방문으로 초기화
		else if(VisitVertex[i]==0) //vertexhead가 비활성화
			visited[i]=1; //visited 방문으로 초기화
	}
	for(i=0;i<MAX_VERTEX;i++) //MAX만큼 반복
	{
		if(VisitVertex[i]==1){ //vertexhead가 활성화되어있으면
			if((temp+i)->head==NULL) //만약 edge가 없으면
				continue; //다음 반복문
			else if(visited[i]==0) //방문하지 않았으면
			{
				addq(i); //큐에 삽입
				while(front) //front가 NULL이 아니면
				{
					v=deleteq(); //v에 큐에서 추출한 값 대입
					if(visited[v]==0) //방문하지 않았으면
						printf("%d ",v); //프린트
					i=v; //i에 v대입
					visited[v]=1; //방문으로 표시
					for(w=(temp+i)->head;w;w=w->link) //w가 NULL이 아니면 반복
					{
						if(visited[w->num]==0){ //방문하지 않았다면
							addq(w->num); //큐에 삽입
						}
					}
				}
			}
			else if(visited[i]!=0) //방문했다면
				continue; //다음 반복문
		}
		else if(VisitVertex[i]!=1) //vertex가 비활성화이면
			continue; //다음 반복문
	}
	printf("\n"); //다음 줄
}

void printGraph(Graph* G)
{
	int i=0; //반복문 용도
	VertexHead* temp=G->vlist; //vertexhead접근
	for(i=0;i<MAX_VERTEX;i++) //MAX만큼 반복
	{
		Vertex* p=(temp+i)->head; //vertex에 접근
		if(VisitVertex[i]==1){ //vertexhead가 존재하면
			printf("VertexHead[%d] ",i); //vertexhead출력
			while(p!=NULL) //p가 NULL이 아니면 반복
			{
				printf("[%d] ",p->num); //p의 num출력
				p=p->link; //다음 p를 가리킴
			}
			printf("\n"); //다음 줄
		}
	}
}

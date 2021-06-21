#include <iostream> //표준입출력
#include <vector> //vector 클래스를 사용하기 위함
#include <algorithm> //sort를 사용하기 위함
using namespace std;

#define VERTEX_N 5 //vertex 갯수
#define EDGE_M 6 //edge 갯수
class Edge { //edge 클래스
public:
	int node[2]; //노드 2개 선언
	int weight; //weight 선언
	Edge(int x, int y, int weight) { //edge 생성자
		this->node[0] = x; //x로 초기화
		this->node[1] = y; //y로 초기화
		this->weight = weight; //weight로 초기화
	} 
	bool operator<(Edge& edge) {
		return this->weight < edge.weight;
	}
};
 
void makeset(int rank[], int x) //makeset함수
{
	rank[x] = 0; //랭크를 0으로 정해준다
}

int find(int parent[], int x) //노드의 위치를 찾는 역할을 하는 find함수
{
	while (x != parent[x]) { //x!=parent[x]이면 반복
		x=parent[x]; //x=parent[x]
	}
	return x; //x리턴
}

void unionset(int rank[], int parent[], int x, int y) //vertex 2개를 union
{
	x = find(parent, x); 
	y = find(parent, y);
	if (x == y)
		return; //같으면 union을 하지 않는다
	if (x > y)
		parent[y] = x;
	else if(x < y){ //y가 x보다 크면
		parent[x] = y;
		if (rank[x] == rank[y]) //x의 랭크와 y의 랭크가 같으면
			rank[y] = rank[y] + 1; //y의 랭크를 1증가
	}
}

void main()
{
	vector<Edge> v; //edge vector선언
	vector<Edge> tree; //tree vector선언
	int sum = 0; //weight의 합

	v.push_back(Edge(1, 0, 6));
	v.push_back(Edge(4, 0, 7));
	v.push_back(Edge(4, 1, 5));
	v.push_back(Edge(2, 3, 3));
	v.push_back(Edge(1, 2, 2));
	v.push_back(Edge(3, 4, 4));

	int parent[VERTEX_N]; //makeset
	int rank[VERTEX_N]; //랭크
	for (int i = 0; i < VERTEX_N; i++) { //초기화
		parent[i] = i; //makeset역할을 해준다(ex)parent[0]=0)
		makeset(rank, i); //makeset
	}

	sort(v.begin(), v.end()); //weight에 따라 배열을 오름차순으로 정렬

	for (int i = 0; i < v.size(); i++) //생성된 edge의 갯수만큼 반복
	{
		if (find(parent, v[i].node[0]) != find(parent, v[i].node[1])) { //edge가 tree에 추가되지 않았으면
			sum += v[i].weight; //weight를 sum에 더해준다
			tree.push_back(Edge(v[i].node[0], v[i].node[1], v[i].weight)); //tree에 edge추가
			unionset(rank, parent, v[i].node[0], v[i].node[1]); //union
		}
	}
	for (int i = 0; i < tree.size(); i++) //tree의 edge갯수만큼 반복
		cout << "Edge : (" << tree[i].node[0] << ", " << tree[i].node[1] 
		<< ") " << "weight : " << tree[i].weight << endl; //tree에 연결된 edge 출력
	for (int i = 0; i < VERTEX_N; i++)
		cout<<"parent["<<i<<"] : "<<parent[i]<<endl; //parent출력
	for (int i = 0; i < VERTEX_N; i++)
		cout << "rank[" << i << "] : " << rank[i] << endl; //rank출력
	cout << "\nweight sum : "<<sum<<endl; //weight의 합 출력
}
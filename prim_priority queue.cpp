#include <iostream> //표준입출력
#include <vector> //vector 클래스를 사용하기 위함
#include <queue> //큐 사용
#include <limits> //무한대 표현
using namespace std;

#define VERTEX_N 5 //vertex 갯수
#define EDGE_M 6 //edge 갯수

struct Edge { //edge 구조체
	int start, end; //start, end vertex
	int weight; //weight
	Edge():start(0),end(0), weight(0){} //생성자
	Edge(int start, int end, int weight):start(start),end(end),weight(weight){} //생성자
	bool operator<(const Edge& edge) const { //연산자 오버로딩 : 자신의 엣지 < 새로 들어온 엣지
		return weight > edge.weight; //자신의 weight가 새로운 엣지의 weight보다 크면 true
	} //새로운 엣지를 위로 올려준다 즉, 우선순위를 높인다.
};

vector<pair<int, int>> a[VERTEX_N];
bool Visited[VERTEX_N] = { false };
int Prev[VERTEX_N];

void main() {
	int cost[VERTEX_N];
	
	a[0].push_back(make_pair(1, 6)); //정적으로 edge넣어줌
	a[0].push_back(make_pair(4, 7));
	a[1].push_back(make_pair(0, 6));
	a[1].push_back(make_pair(2, 2));
	a[1].push_back(make_pair(4, 5));
	a[2].push_back(make_pair(1, 2));
	a[2].push_back(make_pair(3, 3));
	a[3].push_back(make_pair(2, 3));
	a[3].push_back(make_pair(4, 4));
	a[4].push_back(make_pair(0, 7));
	a[4].push_back(make_pair(1, 5));
	a[4].push_back(make_pair(3, 4));

	//for (int i = 0; i < EDGE_M; i++) //edge 직접 입력 받기
	//{
	//	int start, end, weight;
	//	cin >> start >> end >> weight;
	//	a[start].push_back(make_pair(end, weight));
	//	a[end].push_back(make_pair(start, weight));
	//}

	for (int i = 0; i < VERTEX_N; i++) { //각 vertex의 cost, prev를 무한대, null로 초기화
		cost[i] = numeric_limits<int>::max();
		Prev[i] = NULL;
	}

	cost[0] = 0; //cost 0은 0
	Visited[0] = true; //0 vertex는 방문
	vector<Edge> tree; //vector타입의 tree선언
	Edge v; //edge v 선언
	priority_queue<Edge>e; //우선큐 e선언

	for (int i = 0; i < a[0].size(); i++) { //0 vertex과 인접한 edge의 갯수만큼 반복
		e.push(Edge(0, a[0][i].first, a[0][i].second)); //0 vertex와 인접한 edge를 큐에 넣는다
		Prev[a[0][i].first] = 0; //0 vertex와 인접한 edge의 prev=0
		cost[a[0][i].first] = a[0][i].second; ////0 vertex와 인접한 edge의 cost= 해당 edge의 weight
	}
	while (!e.empty()) {
		v = e.top(); //v에 큐의 top을 넣는다
		e.pop(); //큐를 pop한다
		if (Prev[v.end] == v.start){ //prev[v]==u이면
		//if (!(Visited[v.start] == true && Visited[v.end] == true)) { //vertex의 start와 end 둘 중 하나라도 방문하지 않았으면
			tree.push_back(Edge(v.start, v.end, v.weight)); //tree에 추가
			Visited[v.end] = true; //v를 방문체크
			for (int i = 0; i < a[v.end].size(); i++) { //v와 인접한 edge찾기
				if (Visited[a[v.end][i].first] == false) { //v와 인접한 z를 방문하지 않았으면
					e.push(Edge(v.end, a[v.end][i].first, a[v.end][i].second)); //큐에 추가
					if (cost[a[v.end][i].first] > a[v.end][i].second) { //cost[z]>weight[v,z]
						cost[a[v.end][i].first] = a[v.end][i].second; //cost[z]에 weight[v,z]대입
						Prev[a[v.end][i].first] = v.end; //prev[z]=v
					}
				}
			}
		}
	}
	for(int i=0; i<tree.size();i++) //tree에 추가한 edge출력
		cout << "Edge(" << tree[i].start << ", " << tree[i].end << ")"
			<< "weight : " << tree[i].weight << endl;
	cout << "\n";
	for (int i = 0; i < VERTEX_N; i++) //vertex들의 cost출력
		cout << "Cost(" << i << ") : " << cost[i] << endl;
	cout << "\n";
	for (int i = 0; i < VERTEX_N; i++) //vertex들의 prev출력
		cout << "Prev(" << i  << ") : " << Prev[i] << endl;
	cout << "\n";
}

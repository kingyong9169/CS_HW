#include <iostream> //ǥ�������
#include <vector> //vector Ŭ������ ����ϱ� ����
#include <queue> //ť ���
#include <limits> //���Ѵ� ǥ��
using namespace std;

#define VERTEX_N 5 //vertex ����
#define EDGE_M 6 //edge ����

struct Edge { //edge ����ü
	int start, end; //start, end vertex
	int weight; //weight
	Edge():start(0),end(0), weight(0){} //������
	Edge(int start, int end, int weight):start(start),end(end),weight(weight){} //������
	bool operator<(const Edge& edge) const { //������ �����ε� : �ڽ��� ���� < ���� ���� ����
		return weight > edge.weight; //�ڽ��� weight�� ���ο� ������ weight���� ũ�� true
	} //���ο� ������ ���� �÷��ش� ��, �켱������ ���δ�.
};

vector<pair<int, int>> a[VERTEX_N];
bool Visited[VERTEX_N] = { false };
int Prev[VERTEX_N];

void main() {
	int cost[VERTEX_N];
	
	a[0].push_back(make_pair(1, 6)); //�������� edge�־���
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

	//for (int i = 0; i < EDGE_M; i++) //edge ���� �Է� �ޱ�
	//{
	//	int start, end, weight;
	//	cin >> start >> end >> weight;
	//	a[start].push_back(make_pair(end, weight));
	//	a[end].push_back(make_pair(start, weight));
	//}

	for (int i = 0; i < VERTEX_N; i++) { //�� vertex�� cost, prev�� ���Ѵ�, null�� �ʱ�ȭ
		cost[i] = numeric_limits<int>::max();
		Prev[i] = NULL;
	}

	cost[0] = 0; //cost 0�� 0
	Visited[0] = true; //0 vertex�� �湮
	vector<Edge> tree; //vectorŸ���� tree����
	Edge v; //edge v ����
	priority_queue<Edge>e; //�켱ť e����

	for (int i = 0; i < a[0].size(); i++) { //0 vertex�� ������ edge�� ������ŭ �ݺ�
		e.push(Edge(0, a[0][i].first, a[0][i].second)); //0 vertex�� ������ edge�� ť�� �ִ´�
		Prev[a[0][i].first] = 0; //0 vertex�� ������ edge�� prev=0
		cost[a[0][i].first] = a[0][i].second; ////0 vertex�� ������ edge�� cost= �ش� edge�� weight
	}
	while (!e.empty()) {
		v = e.top(); //v�� ť�� top�� �ִ´�
		e.pop(); //ť�� pop�Ѵ�
		if (Prev[v.end] == v.start){ //prev[v]==u�̸�
		//if (!(Visited[v.start] == true && Visited[v.end] == true)) { //vertex�� start�� end �� �� �ϳ��� �湮���� �ʾ�����
			tree.push_back(Edge(v.start, v.end, v.weight)); //tree�� �߰�
			Visited[v.end] = true; //v�� �湮üũ
			for (int i = 0; i < a[v.end].size(); i++) { //v�� ������ edgeã��
				if (Visited[a[v.end][i].first] == false) { //v�� ������ z�� �湮���� �ʾ�����
					e.push(Edge(v.end, a[v.end][i].first, a[v.end][i].second)); //ť�� �߰�
					if (cost[a[v.end][i].first] > a[v.end][i].second) { //cost[z]>weight[v,z]
						cost[a[v.end][i].first] = a[v.end][i].second; //cost[z]�� weight[v,z]����
						Prev[a[v.end][i].first] = v.end; //prev[z]=v
					}
				}
			}
		}
	}
	for(int i=0; i<tree.size();i++) //tree�� �߰��� edge���
		cout << "Edge(" << tree[i].start << ", " << tree[i].end << ")"
			<< "weight : " << tree[i].weight << endl;
	cout << "\n";
	for (int i = 0; i < VERTEX_N; i++) //vertex���� cost���
		cout << "Cost(" << i << ") : " << cost[i] << endl;
	cout << "\n";
	for (int i = 0; i < VERTEX_N; i++) //vertex���� prev���
		cout << "Prev(" << i  << ") : " << Prev[i] << endl;
	cout << "\n";
}

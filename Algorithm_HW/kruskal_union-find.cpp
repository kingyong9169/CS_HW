#include <iostream> //ǥ�������
#include <vector> //vector Ŭ������ ����ϱ� ����
#include <algorithm> //sort�� ����ϱ� ����
using namespace std;

#define VERTEX_N 5 //vertex ����
#define EDGE_M 6 //edge ����
class Edge { //edge Ŭ����
public:
	int node[2]; //��� 2�� ����
	int weight; //weight ����
	Edge(int x, int y, int weight) { //edge ������
		this->node[0] = x; //x�� �ʱ�ȭ
		this->node[1] = y; //y�� �ʱ�ȭ
		this->weight = weight; //weight�� �ʱ�ȭ
	} 
	bool operator<(Edge& edge) {
		return this->weight < edge.weight;
	}
};
 
void makeset(int rank[], int x) //makeset�Լ�
{
	rank[x] = 0; //��ũ�� 0���� �����ش�
}

int find(int parent[], int x) //����� ��ġ�� ã�� ������ �ϴ� find�Լ�
{
	while (x != parent[x]) { //x!=parent[x]�̸� �ݺ�
		x=parent[x]; //x=parent[x]
	}
	return x; //x����
}

void unionset(int rank[], int parent[], int x, int y) //vertex 2���� union
{
	x = find(parent, x); 
	y = find(parent, y);
	if (x == y)
		return; //������ union�� ���� �ʴ´�
	if (x > y)
		parent[y] = x;
	else if(x < y){ //y�� x���� ũ��
		parent[x] = y;
		if (rank[x] == rank[y]) //x�� ��ũ�� y�� ��ũ�� ������
			rank[y] = rank[y] + 1; //y�� ��ũ�� 1����
	}
}

void main()
{
	vector<Edge> v; //edge vector����
	vector<Edge> tree; //tree vector����
	int sum = 0; //weight�� ��

	v.push_back(Edge(1, 0, 6));
	v.push_back(Edge(4, 0, 7));
	v.push_back(Edge(4, 1, 5));
	v.push_back(Edge(2, 3, 3));
	v.push_back(Edge(1, 2, 2));
	v.push_back(Edge(3, 4, 4));

	int parent[VERTEX_N]; //makeset
	int rank[VERTEX_N]; //��ũ
	for (int i = 0; i < VERTEX_N; i++) { //�ʱ�ȭ
		parent[i] = i; //makeset������ ���ش�(ex)parent[0]=0)
		makeset(rank, i); //makeset
	}

	sort(v.begin(), v.end()); //weight�� ���� �迭�� ������������ ����

	for (int i = 0; i < v.size(); i++) //������ edge�� ������ŭ �ݺ�
	{
		if (find(parent, v[i].node[0]) != find(parent, v[i].node[1])) { //edge�� tree�� �߰����� �ʾ�����
			sum += v[i].weight; //weight�� sum�� �����ش�
			tree.push_back(Edge(v[i].node[0], v[i].node[1], v[i].weight)); //tree�� edge�߰�
			unionset(rank, parent, v[i].node[0], v[i].node[1]); //union
		}
	}
	for (int i = 0; i < tree.size(); i++) //tree�� edge������ŭ �ݺ�
		cout << "Edge : (" << tree[i].node[0] << ", " << tree[i].node[1] 
		<< ") " << "weight : " << tree[i].weight << endl; //tree�� ����� edge ���
	for (int i = 0; i < VERTEX_N; i++)
		cout<<"parent["<<i<<"] : "<<parent[i]<<endl; //parent���
	for (int i = 0; i < VERTEX_N; i++)
		cout << "rank[" << i << "] : " << rank[i] << endl; //rank���
	cout << "\nweight sum : "<<sum<<endl; //weight�� �� ���
}
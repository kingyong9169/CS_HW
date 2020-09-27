/*#define N 5
#include <iostream>
using namespace std;

int count_vertex = 0;
int count_edge = 0;
int count_adj = 0;
int count_uvertex;
class Node{
public:
	int vertex;
	Node* next;
	Node(int num=0, Node* link=NULL) :vertex(num), next(link)
	{
	}
	friend class adjlist;
	friend class LinkdedGraph;
};

class adjlist
{
public:
	Node* first;
	friend class LinkdedGraph;
};

class LinkedGraph
{
public:
	adjlist* list;
	int n;
	
public:
	LinkedGraph(int number):n(number)
	{
        list = new adjlist[n];
		for (int i = 0; i < n; i++) {
			list[i].first = NULL;
			count_vertex++;
		}
	}
	void AddEdge(int num1, int num2)
	{
		Node* newNode1 = new Node(num2);
		newNode1->vertex = num2;
		newNode1->next = list[num1].first;
		list[num1].first = newNode1;

		Node* newNode2 = new Node(num1);
		newNode2->vertex = num1;
		newNode2->next = list[num2].first;
		list[num2].first = newNode2;
		count_edge++;
	}
	friend ostream& operator<<(ostream& os, LinkedGraph& lg);
};

ostream& operator<<(ostream& os, LinkedGraph& lg)
{
	os << "�� �������� ����Ǿ� �ִ� �������� ���" << endl;
	for (int i = 0; i < lg.n; i++)
	{
		Node* temp = lg.list[i].first;
		os << i << ": ";
		while (temp)
		{
			os << temp->vertex<<" ";
			temp = temp->next;
		}
		os << endl;
	}
	return os;
}

int main(void)
{
	int u,v;
	LinkedGraph lg(N);
	for (int i = 0; i < N; i++)
	{
		if (i + 1 < N) {
			lg.AddEdge(i, i + 1);
		}
	}
	cout << lg;
	cout << "��������Ʈ�� �����ϴ� ����(count_vertex + count_edge) : " << count_vertex + count_edge<<endl;
	cout << "Vertex u�� v�� adjacent���� üũ�Ϸ��� u,v�� �Է��Ͻÿ�.";
	cin >> u>>v;
	Node* temp1 = lg.list[u].first;
	while (temp1)
	{
		temp1 = temp1->next;
		count_adj++;
	}
	cout << "time complexity : "<<count_adj<<endl;

	cout << "Vertex u�� adjacent�� ��� vertexŽ���� ���� u�� �Է��Ͻÿ�.";
	cin >> u;
	Node* temp3 = lg.list[u].first;
	while (temp3)
	{
		cout << "������ vertex : "<<temp3->vertex << " ";
		temp3 = temp3->next;
		count_uvertex++;
	}
	cout << endl;
	cout << "time complexity : "<<count_uvertex<<endl;
	cout << "deg(u) : "<<count_uvertex;
	return 0;
}*/
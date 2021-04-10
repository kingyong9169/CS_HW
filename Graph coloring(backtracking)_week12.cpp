#include<iostream>
#include<vector>
using namespace std;
int n; //노드의 수
int m; //색깔의 수
int *vcolor; //노드에 할당된 색
bool **W;
int count_node = 0;

bool promising(int i)
{
	int j = 0;
	bool switcha = true;
	if (i < n) {
		while (j < i && switcha) {
			if (W[i][j] && vcolor[i] == vcolor[j])
				switcha = false;
			j++;
		}
	}
	if (i > n)
		switcha = false;
	return switcha;
}

void m_coloring(int i)
{
	int color;
	
	if (promising(i)) {
		if (i == n) {
			cout << "\n";
			for (int j = 0; j < n; j++)
				cout << vcolor[j] << " ";
		}
		else
			for (color = 1; color <= m; color++) {
				if (i + 1 < n) {
					vcolor[i + 1] = color;
					count_node++;
					m_coloring(i + 1);
				}
				if(i+1==n&&color==1)
					m_coloring(i + 1);
			}
	}
}

int main()
{
	int e; //edge의 갯수
	cout << "노드의 갯수를 입력하시오 : ";
	cin >> n;
	cout << "Edge의 갯수를 입력하시오 : ";
	cin >> e;
	cout << "색깔의 갯수를 입력하시오 : ";
	cin >> m;
	vcolor = new int[n];
	W = new bool *[n];
	for (int i = 0; i < n; i++)
		W[i] = new bool[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			W[i][j] = false;

	int u, v; //edge
	cout << "Edge를 입력하시오 : \n";
	for (int i = 0; i < e; i++) {
		cin >> u >> v;
		W[u][v] = true;
		W[v][u] = true;
	}

	m_coloring(-1);
	cout << "\n생성되는 노드의 갯수 : ";
	cout << count_node;
	//동적할당 해제
	for (int i = 0; i < n; i++)
		delete W[i];
	delete W;
	delete vcolor;

	return 0;
}
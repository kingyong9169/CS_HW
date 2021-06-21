#include <iostream>
using namespace std;

int n; //노드의 수
int m; //Edge의 수
int* vindex; //경로상에서 노드의 인덱스
bool** W;
int count_node = 0;

bool promising(int i)
{
	int j = 0;
	bool switcha = true;

	if (i == n - 1 && !W[vindex[n - 1]][vindex[0]])
		switcha = false;
	else if (i > 0 && !W[vindex[i - 1]][vindex[i]])
		switcha = false;
	else {
		while (j < i && switcha) {
			if (vindex[i] == vindex[j])
				switcha = false;
			j++;
		}
	}
	return switcha;
}

void hamiltonian(int i)
{
	int j;

	if (promising(i)) {
		if (i == n - 1) {
			cout << "\n";
			for (int i = 0; i < n; i++)
				cout << vindex[i] << " ";
		}
		else
			for (j = 1; j < n; j++) {
				vindex[i + 1] = j;
				count_node++;
				hamiltonian(i + 1);
			}
	}
} 

int main()
{
	cout << "노드의 갯수를 입력하시오 : ";
	cin >> n;
	cout << "Edge의 갯수를 입력하시오 : ";
	cin >> m;
	vindex = new int[n];
	W = new bool* [n];
	for (int i = 0; i < n; i++)
		W[i] = new bool[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			W[i][j] = false;

	int u, v; //edge
	cout << "Edge를 입력하시오 : \n";
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		W[u][v] = true;
		W[v][u] = true;
	}

	vindex[0] = 0;
	hamiltonian(0);

	cout << "\n생성되는 노드의 갯수 : ";
	cout << count_node;
	//동적할당 해제
	for (int i = 0; i < n; i++)
		delete W[i];
	delete W;
	delete vindex;

	return 0;
}
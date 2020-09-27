/*#include <iostream>

using namespace std;

int n, m;
int u, v;
int count_space, count_adjacent, count_adj;
int main() {
	cout << "정점의 수와 간선의 수를 입력하시오.";
	cin >> n >> m;
	int** matrix;
	matrix = new int*[n];
	for (int i = 0; i < n; i++)
		matrix[i] = new int[n];
	for(int i=0;i<n;i++)
		for (int j = 0; j < n; j++) {
			matrix[i][j] = 0;
			count_space++;
		}
	for (int i = 0; i < m; i++)
	{
		cout << "간선을 입력하시오.";
		int s, e;
		cin >> s >> e;
		matrix[s][e] = 1;
		matrix[e][s] = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << "인접리스트가 차지하는 공간(n*n) : " << count_space << endl;
	cout << "Vertex u와 v가 adjacent한지 체크하려면 u,v를 입력하시오.";
	cin >> u >> v;
	if (matrix[u][v] == 1|| matrix[u][v] == 0)
		count_adjacent++;
	cout << "time complexity : " << count_adjacent << endl;
	cout << "Vertex u와 adjacent한 모든 vertex탐색을 위해 u를 입력하시오.";
	cin >> u;
	for (int j = 0; j < n; j++)
		count_adj++;
	cout << "time complexity : " << count_adj << endl;
	cout << "deg(u) : " << count_adj;
}*/
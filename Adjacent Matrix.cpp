/*#include <iostream>

using namespace std;

int n, m;
int u, v;
int count_space, count_adjacent, count_adj;
int main() {
	cout << "������ ���� ������ ���� �Է��Ͻÿ�.";
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
		cout << "������ �Է��Ͻÿ�.";
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
	cout << "��������Ʈ�� �����ϴ� ����(n*n) : " << count_space << endl;
	cout << "Vertex u�� v�� adjacent���� üũ�Ϸ��� u,v�� �Է��Ͻÿ�.";
	cin >> u >> v;
	if (matrix[u][v] == 1|| matrix[u][v] == 0)
		count_adjacent++;
	cout << "time complexity : " << count_adjacent << endl;
	cout << "Vertex u�� adjacent�� ��� vertexŽ���� ���� u�� �Է��Ͻÿ�.";
	cin >> u;
	for (int j = 0; j < n; j++)
		count_adj++;
	cout << "time complexity : " << count_adj << endl;
	cout << "deg(u) : " << count_adj;
}*/
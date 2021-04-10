#include <iostream>
using namespace std;

int n; //����� ��
int m; //Edge�� ��
int* vindex; //��λ󿡼� ����� �ε���
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
	cout << "����� ������ �Է��Ͻÿ� : ";
	cin >> n;
	cout << "Edge�� ������ �Է��Ͻÿ� : ";
	cin >> m;
	vindex = new int[n];
	W = new bool* [n];
	for (int i = 0; i < n; i++)
		W[i] = new bool[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			W[i][j] = false;

	int u, v; //edge
	cout << "Edge�� �Է��Ͻÿ� : \n";
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		W[u][v] = true;
		W[v][u] = true;
	}

	vindex[0] = 0;
	hamiltonian(0);

	cout << "\n�����Ǵ� ����� ���� : ";
	cout << count_node;
	//�����Ҵ� ����
	for (int i = 0; i < n; i++)
		delete W[i];
	delete W;
	delete vindex;

	return 0;
}
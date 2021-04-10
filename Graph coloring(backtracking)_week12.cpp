#include<iostream>
#include<vector>
using namespace std;
int n; //����� ��
int m; //������ ��
int *vcolor; //��忡 �Ҵ�� ��
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
	int e; //edge�� ����
	cout << "����� ������ �Է��Ͻÿ� : ";
	cin >> n;
	cout << "Edge�� ������ �Է��Ͻÿ� : ";
	cin >> e;
	cout << "������ ������ �Է��Ͻÿ� : ";
	cin >> m;
	vcolor = new int[n];
	W = new bool *[n];
	for (int i = 0; i < n; i++)
		W[i] = new bool[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			W[i][j] = false;

	int u, v; //edge
	cout << "Edge�� �Է��Ͻÿ� : \n";
	for (int i = 0; i < e; i++) {
		cin >> u >> v;
		W[u][v] = true;
		W[v][u] = true;
	}

	m_coloring(-1);
	cout << "\n�����Ǵ� ����� ���� : ";
	cout << count_node;
	//�����Ҵ� ����
	for (int i = 0; i < n; i++)
		delete W[i];
	delete W;
	delete vcolor;

	return 0;
}
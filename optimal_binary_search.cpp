#include<iostream>
#include<vector>
#include<utility>
using namespace std;

int main() {

	vector<pair<int, int>>node;

	int n;  //����� ����
	cin >> n;

	for (int i = 0; i < n; i++) {  //���⼭ �Է¹޴´�
		int num;
		int bindo;
		cin >> num >> bindo;
		node.push_back(make_pair(num, bindo));
	}

	vector<vector<int>>C(n, vector<int>(n));  //2���� �迭 C����


	//C �迭���� 0�� �Ǵ� �Ͱ� i==j�� �Ǵ� ���� ���� �۾��Ѵ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i > j) C[i][j] = 0;
			else if (i == j) C[i][j] = node[i].second;
		}
	}

	int index = 1;
	int i = 0;
	int j;
	cout << "\n";
	while (index < n) {
		for (i = 0; i + index < n; i++) {
			j = i + index;
			int min, k = i;
			int bindo = 0;
			for (int a = i; a <= j; a++) bindo += node[a].second;	//int bindo = node[i].second + node[j].second;
			if (k == 0) min = 0 + C[k + 1][j] + bindo;
			else min = C[i][k - 1] + C[k + 1][j] + bindo;
			for (k = i + 1; k <= j; k++) {
				int value;
				if (k >= n - 1) value = C[i][k - 1] + 0 + bindo;
				else value = C[i][k - 1] + C[k + 1][j] + bindo;
				if (min > value) min = value;  //min���� �ֽ�ȭ
			}
			C[i][j] = min;
		}
		index++;
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << " " << C[i][j];
		}
		cout << "\n";
	}

}

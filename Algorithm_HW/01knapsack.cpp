#include<iostream>
#include<vector>
#include<utility>
using namespace std;

vector<pair<int, int>>E;

void print(vector<vector<int>>& M, int i, int j) {
	if (i == 0 && j == 0) return;
	if (M[i][j] == 1) {
		cout << " " << i << " ";
		print(M, i - 1, j - E[i - 1].first);
	}
	else print(M, i - 1, j);
}

int main() {

	int item, w;  //n: 전체 item 개수 , w : 전체 가방의 weight
	cin >> item >> w;


	for (int i = 0; i < item; i++) {  //각각의 item들에 대한 weight와 value 입력, weight = (1 ~ weight)
		int weight, value;
		cin >> weight >> value;
		E.push_back(make_pair(weight, value));
	}


	vector<vector<int>>B(item + 1, vector<int>(w + 1));
	vector<vector<int>>M(item + 1, vector<int>(w + 1, 0));

	for (int j = 0; j <= w; j++) B[0][j] = 0;
	for (int i = 1; i <= item; i++) {
		B[i][0] = 0;
		for (int j = 1; j <= w; j++) {
			if (E[i - 1].first <= j) {
				if (B[i - 1][j - E[i - 1].first] + E[i - 1].second > B[i - 1][j]) {
					B[i][j] = B[i - 1][j - E[i - 1].first] + E[i - 1].second;
					M[i][j] = 1;
				}
				else {
					B[i][j] = B[i - 1][j];
					M[i][j] = 0;
				}
			}
			else {
				B[i][j] = B[i - 1][j];
				M[i][j] = 0;
			}
		}
	}

	for (int i = 0; i <= item; i++) {
		for (int j = 0; j <= w; j++) {
			cout << " " << B[i][j];
		}
		cout << "\n";
	}

	cout << "\n";
	for (int i = 0; i <= item; i++) {
		for (int j = 0; j <= w; j++) {
			cout << " " << M[i][j];
		}
		cout << "\n";
	}

	cout << "\n";
	//print(M, item, w);

}
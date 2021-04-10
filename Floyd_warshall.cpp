#include<iostream>
#include<algorithm>
using namespace std;
const int INF = 987654321;//¹«ÇÑ´ë

int main() {
	int N = 4, M = 6;
	int dist[4][4];
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (i == j)dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	dist[0][1] = 3; 
	dist[1][0] = 2; 
	dist[2][1] = 1;
	dist[3][2] = 2; 
	dist[0][3] = 5; 
	dist[1][3] = 4;

	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);

	cout << "i/j [1] [2] [3] [4]\n";
	for (int i = 0; i < N; i++) {
		cout << "["<<i+1<<"]"<<"  ";
		for (int j = 0; j < N; j++) {
			if (dist[i][j] == INF)
				cout <<INF<<" ";
			else
				cout << dist[i][j] << "   ";
		}
		cout << "\n";
	}
	return 0;
}
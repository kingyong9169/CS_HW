#include <iostream>
#include <vector>
#include <tuple>

const long long INF = 1e18;//¹«ÇÑ´ë
using namespace std;

int main() {
	int N=8, M=11;
	long long dist[8];
	int prev[8];
	vector<tuple<int, int, int>>edge;

	edge.push_back(tuple<int, int, int>(0, 1, 10));
	edge.push_back(tuple<int, int, int>(0, 7, 8));
	edge.push_back(tuple<int, int, int>(2, 1, 1));
	edge.push_back(tuple<int, int, int>(2, 3, 1));
	edge.push_back(tuple<int, int, int>(3, 4, 3));
	edge.push_back(tuple<int, int, int>(4, 5, -1));
	edge.push_back(tuple<int, int, int>(6, 5, -1));
	edge.push_back(tuple<int, int, int>(7, 6, 1));
	edge.push_back(tuple<int, int, int>(6, 1, -4));
	edge.push_back(tuple<int, int, int>(1, 5, 2));
	edge.push_back(tuple<int, int, int>(5, 2, -2));

	for (int i = 0; i < N; i++) {
		dist[i] = INF;
		prev[i] = INF;
	}

	dist[0] = 0;
	prev[0] = 0;
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < M; j++) {
			int U = get<0>(edge[j]);
			int V = get<1>(edge[j]);
			int weight = get<2>(edge[j]);
			if (dist[U] == INF) continue;
			if (dist[V] > dist[U] + weight){
				dist[V] = dist[U] + weight;
				prev[V] = U;
			}
		}
	cout << "dist [0] [1] [2] [3] [4] [5] [6] [7]\n";
	cout << "     ";
	for (int i = 0; i < N; i++) {
		cout <<" "<<dist[i] << "  ";
	}
	cout << "\n";
	cout << "prev [0] [1] [2] [3] [4] [5] [6] [7]\n";
	cout << "     ";
	for (int i = 0; i < N; i++) {
		cout <<" " << prev[i] << "  ";
	}
	return 0;
}
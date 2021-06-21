#include<iostream>
using namespace std;

int W; //배낭의 총 부피
int n; //item의 갯수
int* w; //i번째 아이템의 가치
int* p; //i번째 아이템의 무게
bool* bestset;
bool* include;

int maxprofit=0; //지금까지 찾은 최선의 해답이 주는 가치
int count_node=0; //노드의 갯수

bool promising(int i, int profit, int weight) {
	int j, k;
	int totweight; float bound;
	if (weight >= W) return false;
	else {
		j = i + 1;
		bound = profit;
		totweight = weight;
		while ((j <= n) && (totweight + w[j] <= W)) {
			totweight = totweight + w[j];
			bound = bound + p[j];
			j++;
		}
		k = j;
		if (k <= n)
			bound = bound + (W - totweight) * (p[k] / w[k]);
	}
		return (bound > maxprofit);
}

void knapsack(int i, int profit, int weight) {
	if (weight <= W && profit > maxprofit) {
		maxprofit = profit;
		for(int j=1;j<=n;j++)
			bestset[j] = include[j];
	}
	if (promising(i, profit, weight)) {
		include[i + 1] = true;
		count_node++;
		knapsack(i + 1, profit + p[i + 1], weight + w[i + 1]);
		include[i + 1] = false;
		count_node++;
		knapsack(i + 1, profit, weight);
	}
}

void main()
{
	cout << "배낭의 총 부피를 입력하시오 : ";
	cin >> W;
	cout << "item의 갯수를 입력하시오 : ";
	cin >> n;
	w = new int[n+1];
	p = new int[n+1];
	bestset = new bool[n+1];
	include = new bool[n+1];

	for (int i = 1; i <= n; i++) {
		include[i]=false;
	}

	cout << "무게(p), 가치(w)를 입력하시오 : \n";
	for (int i = 1; i <=n; i++) {
		cin >>  p[i] >> w[i] ;
	}

	knapsack(0,0,0);

	for (int i = 1; i <= n; i++) {
		cout << bestset[i] << " ";
	}

	cout << "\n생성되는 노드의 갯수 : ";
	cout << count_node;
	//동적할당 해제
	delete w;
	delete p;
}
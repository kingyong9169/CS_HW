#include<iostream>
using namespace std;

int W; //�賶�� �� ����
int n; //item�� ����
int* w; //i��° �������� ��ġ
int* p; //i��° �������� ����
bool* bestset;
bool* include;

int maxprofit=0; //���ݱ��� ã�� �ּ��� �ش��� �ִ� ��ġ
int count_node=0; //����� ����

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
	cout << "�賶�� �� ���Ǹ� �Է��Ͻÿ� : ";
	cin >> W;
	cout << "item�� ������ �Է��Ͻÿ� : ";
	cin >> n;
	w = new int[n+1];
	p = new int[n+1];
	bestset = new bool[n+1];
	include = new bool[n+1];

	for (int i = 1; i <= n; i++) {
		include[i]=false;
	}

	cout << "����(p), ��ġ(w)�� �Է��Ͻÿ� : \n";
	for (int i = 1; i <=n; i++) {
		cin >>  p[i] >> w[i] ;
	}

	knapsack(0,0,0);

	for (int i = 1; i <= n; i++) {
		cout << bestset[i] << " ";
	}

	cout << "\n�����Ǵ� ����� ���� : ";
	cout << count_node;
	//�����Ҵ� ����
	delete w;
	delete p;
}
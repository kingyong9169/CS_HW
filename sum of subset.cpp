#include <iostream>
using namespace std;

int w[5] = { 5,6,10,11,16 };
int W;
int include[5] = { 0 };


bool promising(int i, int weight, int total) {
	if (weight + total >= W && (weight == W || weight + w[i + 1] <= W))
		return true;
	return false;
}

void print() {
	for (int i = 0; i < 5; i++)
		if (include[i] != 0)
			cout << include[i]<<" ";
	cout << "\n";
}

void sum_of_subset(int i, int weight, int total) {
	if (promising(i, weight, total)) {
		if (W == weight)
			print();
		else {
			include[i + 1] = w[i + 1];
			sum_of_subset(i + 1, weight + w[i + 1], total - w[i + 1]);
			include[i + 1] = 0;
			sum_of_subset(i + 1, weight, total - w[i + 1]);
		}
	}
}

void main() {
	int num;
	int total = 0;
	cout << "검사할 숫자 입력 : ";
	cin >> W;
	cout << "\n";
	for (int i = 0; i < 5; i++)
		total += w[i];
	sum_of_subset(-1, 0, total);
}
#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main(void) {
	int n = 8;
	int input[] = {91, 46, 85, 15, 92, 35, 31, 22};
	vector<queue<int>> data(10);
	vector<int> temp;
	for (int num : input) {
		data[num % 10].push(num);
	}
	for (int i = 0; i < 10; i++) {
		while (!data[i].empty()) {
			temp.push_back(data[i].front());
			data[i].pop();
		}
	}
	for (int num : temp) {
		data[(int)(num / 10)].push(num);
	}
	for (int i = 0; i < 10; i++) {
		while (!data[i].empty()) {
			cout << data[i].front() << " ";
			data[i].pop();
		}
	}
	return 0;
}
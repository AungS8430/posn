#include <bits/stdc++.h>
#include <deque>
#include <vector>
using namespace std;

int main(void) {
	int classes, students;
	cin >> classes >> students;
	vector<int> c_students[classes];
	int a, b;
	for (int i = 0; i < students; i++) {
		cin >> a >> b;
		c_students[a-1].push_back(b);
	}
	char arg1;
	int arg2;
	int cur;
	deque<int> line_q;
	vector<int> output;
	int cls_pos[classes];
	for (int i = 0; i < classes; i++) {cls_pos[i] = -1;}
	while (true) {
		cin >> arg1;
		if (arg1 == 'E') {
			cin >> arg2;
			for (int i = 0; i < classes; i++) {
				if (find(c_students[i].begin(), c_students[i].end(), arg2) != c_students[i].end()) {
					cur = i;
					break;
				}
			}
			if (cls_pos[cur] == -1) {
				cls_pos[cur] = line_q.size();
				line_q.push_back(arg2);
			} else {
				for (int i = 0; i < classes; i++) {
					if (cls_pos[i] >= cls_pos[cur] && cls_pos[i] != -1) cls_pos[i]++;
				}
				line_q.insert(line_q.begin() + cls_pos[cur] , arg2);
			}
		} else if (arg1 == 'D') {
			output.push_back(line_q[0]);
			line_q.pop_front();
			for (int i = 0; i < classes; i++) {
				if (cls_pos[i] > -1) cls_pos[i]--;
			}
		} else if (arg1 == 'X') {
			for (int out : output) {
				cout << out << endl;
			}
			cout << 0 << endl;
			return 0;
		}
	}
	return 1;
}
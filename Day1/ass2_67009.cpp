#include <bits/stdc++.h>
using namespace std;

void assign(int ***arr, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			*((*(*arr+i))+j) = i * (col * 10) + (j + 1) * 10;
		}
	}
	return;
}

void output(int ***arr, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << *((*(*arr+i))+j) << " ";
		}
		cout << endl;
	}
	return;
}

int main(void) {
	int row, col;
	cout << "Enter rows: ";
	cin >> row;
	cout << "Enter columns: ";
	cin >> col;
	int **arr = new int * [row];
	for (int i = 0; i < row; i++) {
		*(arr+i) = new int[col];
	}
	assign(&arr, row, col);
	output(&arr, row, col);
	for (int i = 0; i < row; i++) {
		delete[] *(arr+i);
	}
	delete[] arr;
	return 0;
}

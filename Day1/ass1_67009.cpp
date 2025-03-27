#include <bits/stdc++.h>
using namespace std;

void extend_ptr(int** ptr, int &size) {
	int* temp = new int[8];
	for (int i = 0; i < 4; i++) {
		temp[i] = (*ptr)[i];
	}
	delete[] *ptr;
	*ptr = temp;
	size *= 2;
	return;
}

int main(void) {
	int size = 4;
	int* arr = new int[size];
	arr[0] = 1, arr[1] = 2, arr[2] = 3; arr[3] = 4;
	extend_ptr(&arr, size);
	for (int i = 0; i < 8; i++) {
		cout << arr[i] << " ";
	}
	cout << endl << size << endl;
	delete[] arr;
	return 0;
}

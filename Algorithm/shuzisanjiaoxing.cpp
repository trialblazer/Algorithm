#include <iostream>

using namespace std;

#define Max 15

int f(int b[][5], int size, int i, int j) {
	if (i+1 >= size)
		return b[i][j];
	int m = f(b, size, i+1, j);
	int n = f(b, size, i+1, j+1);
	return ((m>n? m:n)+b[i][j]);
}

int main() {
	int a[Max] = {9,12,15,10,6,8,2,18,9,5,19,7,10,4,16};
	int b[5][5], p = Max;
	int i;
	for (i=4; i>=0; i--) 
		for (int j=i; j>=0; j--)
			b[i][j] = a[--p];

	
	cout << f(b, 5, 0, 0) << endl;
	return 0;
}
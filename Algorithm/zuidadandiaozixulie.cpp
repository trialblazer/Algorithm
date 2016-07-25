#include <iostream>

using namespace std;

#define Max 8

int a[Max] = {65,158,170,155,239,300,207,389};
int b[Max] = {0};

int f() {
	int i, j, max;
	for (i=Max-1; i >= 0; i--) {
		max = b[i] = 1;
		for (j=i; j<Max-1; j++) {
			//if (a[j] < a[j+1]) {
			if (a[i] < a[j+1]) {
				if (b[j+1]) {
					//b[j] += b[j+1];
					b[i] += b[j+1];
                    if (max < b[i])
                        max = b[i];
					break;
				} //else {
					//b[j] += 1; 
				//}	
			}
		}
	}
	return max;
}

int main() {
	cout << f() << endl;
	return 0;
}

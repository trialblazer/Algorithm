#include<iostream>

using namespace std;

void sort(char *name[], int n);
void prin(char *name[], int n);

int main() {
	char *name[] = {"FELF SF", "DFKASDJ", "FELFD SDF", "RJIFGI", "EOREO", "OIOEJ"};
	int n = 6;
	prin(name, n);
	sort(name, n);
	prin(name, n);
	return 0;
}

void sort(char *name[], int n) {
	char *tmpt;
	int i, j, k;
	for (i=0; i<n-1; i++) {
		k = i;
		for (j=i+1; j<n; j++) 
			if (strcmp(name[k], name[j])>0)
				k = j;
		if (k != i) {
			tmpt = name[i];
			name[i] = name[k];
			name[k] = tmpt;
		}
	}
}

void prin(char *name[], int n) {
	for (int i=0; i<n; i++) 
		cout << name[i] << "  ";
	cout << endl;
}


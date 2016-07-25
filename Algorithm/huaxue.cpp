
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int f(int *a, int *ra, int c, int r,  int i);

int main() {
    int R, C, *h, *rh, i=0, Max=0;;
    do {
        cin >> R;
    }while (R<1 || R>100);
    do {
        cin >> C;
    } while (C <1 || C>100);
	h = new int[R*C];
	rh = new int [R*C];
    for (i=0; i<R*C; i++) {
		rh[i] = 0;
        do {
			cin >> h[i];
        } while (h[i]<0 || h[i]>10000);
    }

    for (i=0; i<R; i++)
		if (rh[i] == 0) {
		    rh[i] = f(h, rh, R, C, i);
			Max = Max < rh[i]? rh[i]:Max;
		}
    cout << Max << endl;
	return 0;
}

int f(int *a, int *ra, int c, int r, int i) {
    int up=0, down=0, right=0, left=0;
	if (i-c>=0 && a[i]<a[i-c])
        up = ra[i-c] != 0? ra[i-c]:f(a, ra, r, c, i-c);
	if (i+c>=0 && a[i]<a[i+c])
        down = ra[i+c] != 0? ra[i+c]:f(a, ra, r, c, i+c);
	if (i%r == 0 && i/r ==0) {
		if (a[i]<a[i+1])
			right = ra[i+1] != 0? ra[i+1]:f(a, ra, r, c, i+1);
	}
	if (i%r == 0 && i/r != 0) {
		if (a[i]<a[i-1])
			left = ra[i-1] != 0? ra[i-1]:f(a, ra, r,  c, i-1);
	} 
	else {
		if (a[i]<a[i-1])
			left = ra[i-1] != 0? ra[i-1]:f(a, ra, r,  c, i-1);
		if (a[i]<a[i+1])
			right = ra[i+1] != 0? ra[i+1]:f(a, ra, r, c, i+1);
	}
    int m = up>down?  up:down;
    int n = left>right? left:right;
    return m>n? (m+1):(n+1);
}

/*

int f(int *a, int *ra, int r, int c, int i) {
    int up=0, down=0, right=0, left=0;
    if ((i-c)>=0 && (i-c)<(r*c) && a[i]<a[i-c])
        up = ra[i-c] != 0? ra[i-c]:f(a, ra, r, c, i-c);
    if ((i+c)>=0 && (i+c)<(r*c) && a[i]<a[i+c])
        down = ra[i+c] != 0? ra[i+c]:f(a, ra, r, c, i+c);
    if ((i-1)>=0 && (i-1)<(r*c) && a[i]<a[i-1])
        left = ra[i-1] != 0? ra[i-1]:f(a, ra, r, c, i-1);
    if ((i+1)>=0 && (i+1)<(r*c) && a[i]<a[i+1]+1)
        right = ra[i+1] != 0? ra[i+1]:f(a, ra, r, c, i+1);
    int m = up>down?  up:down;
    int n = left>right? left:right;
    return m>n? (m+1):(n+1);
}
*/
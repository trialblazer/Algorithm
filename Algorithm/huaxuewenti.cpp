#include<iostream>

using namespace std;

#define Maxsize 5

#define max(a, b) ((a)>(b)?(a):(b))

/// int offset[4][2] = {{-1, 0,}, {1, 0}, {0, 1}, {0, -1}};

int h_size, l_size;

int f(int i, int j, int a[][100], int b[][100]);
bool walk_shang(int i, int j, int a[][100]);
bool walk_xia(int i, int j, int a[][100]);
bool walk_zuo(int i, int j, int a[][100]);
bool walk_you(int i, int j, int a[][100]);

int main() {
    int R, C;
    cout << "输出最长区域的长度。\n";
    do {
        cin >> R >> C;
    } while(R < 0 || R > 100 || C < 0 ||C > 100);

    int a[100][100];
    h_size = R;
    l_size = C;
    int b[100][100];
    for (int i=0; i<h_size; i++)
        for(int j=0; j<l_size; j++)
           b[i][j] = -1;

    for (int i=0; i<h_size; i++) {
        for(int j=0; j<l_size; j++) {
            do {
               cin >> a[i][j];
            } while(a[i][j] < 0 || a[i][j] > 10000);
        }
    }
    int Max = 0;
    for(int i=0; i<h_size; i++) {
        for(int j=0; j<l_size; j++) {
            int tmp = f(i, j, a, b);
            Max = Max<tmp ? tmp : Max;
        }
    }
    cout << endl << Max << endl;
    return 0;
}

bool walk_shang(int i, int j, int a[][100]) {
    if ((i-1) < 0)
        return true;
    if (a[i][j]<a[i-1][j])
        return true;
    return false;
}

bool walk_xia(int i, int j, int a[][100]) {
    if ((i+1) >= l_size)
        return true;
    if (a[i+1][j]>a[i][j])
        return true;
    return false;
}

bool walk_zuo(int i, int j, int a[][100]) {
    if ((j-1) < 0)
        return true;
    if (a[i][j]<a[i][j-1])
        return true;
    return false;
}

bool walk_you(int i, int j, int a[][100]) {
    if ((j+1) >= l_size)
        return true;
    if (a[i][j]<a[i][j+1])
        return true;
    return false;
}


int f(int i, int j, int a[][100], int b[][100]) {
    if (walk_shang(i, j, a) && walk_xia(i, j, a) && walk_you(i, j, a) && walk_zuo(i, j, a)) {
        b[i][j] =1;
        return b[i][j];
    }

    int temp = 0, s = 0, x = 0, z = 0, y = 0;

    if (!walk_shang(i, j, a))
        s = b[i-1][j] == -1 ? f(i-1, j, a, b) : b[i-1][j];
    if (!walk_xia(i, j, a))
        x = b[i+1][j] == -1 ? f(i+1, j, a, b) : b[i+1][j];
    if (!walk_zuo(i, j, a))
        z = b[i][j-1] == -1 ? f(i, j-1, a, b) : b[i][j-1];
    if (!walk_you(i, j, a))
        y = b[i][j+1] == -1 ?f(i, j+1, a, b) : b[i][j+1];

    if (b[i][j] == -1)
        b[i][j] = max(max(s, x), max(z, y))+1;
    return b[i][j];
}

/*
int f(int i, int j, int a[][100]) {
    if (walk_shang(i, j, a) && walk_xia(i, j, a) && walk_you(i, j, a) && walk_zuo(i, j, a))
        return 1;

    int temp = 0;
    int s = 0;
    int x = 0;
    int z = 0;
    int y = 0;
    if (!walk_shang(i, j, a))
        s = f(i-1, j, a);
    if (!walk_xia(i, j, a))
        x = f(i+1, j, a);
    if (!walk_zuo(i, j, a))
        z = f(i, j-1, a);
    if (!walk_you(i, j, a))
        y = f(i, j+1, a);

    return max(max(s, x), max(z, y))+1;
}





int f(int i, int j, int a[][100]) {
     if (walk_shang(i, j, a) && walk_xia(i, j, a) && walk_you(i, j, a) && walk_zuo(i, j, a))
        return 1;

    return max(max(f(i-1, j, a), f(i+1, j, a)), max(f(i, j-1, a), f(i, j+1, a)))+1;
}



int f(int i, int j, int a[][100]) {
     if (i<0 || i>h_size || j<0 || j>l_size || (a[i][j]<a[i-1][j] && a[i+1][j]>a[i][j] && a[i][j]<a[i][j-1] && a[i][j]<a[i][j+1]))
        return 0;
    return max(max(f(i-1, j, a), f(i+1, j, a)), max(f(i, j-1, a), f(i, j+1, a)))+1;
}*/


#include <iostream>
#include <string>

using std::cout;
using std::cin;

bool check(int i, int j, int r, int c);
int f(int a[][100], int ra[][100], int r, int c,  int i, int j);

int main() {
    int R, C,  h[100][100], rh[100][100], i=0, j=0, Max=0;;
    do {
        cin >> R;
    }while (R<1 || R>100);
    do {
        cin >> C;
    } while (C <1 || C>100);
    for (i=0; i<R; i++) {
        for (j=0; j<C; j++) {
            rh[i][j] = 0;
            do {
                cin >> h[i][j];
            } while (h[i][j]<0 || h[i][j]>10000);
        }
    }
    for (i=0; i<R; i++)
        for (j=0; j<C; j++)
            if (rh[i][j] == 0) {
                rh[i][j] = f(h, rh, R, C, i, j);
                Max = Max < rh[i][j]? rh[i][j]:Max;
            }
    cout << Max;
	return 0;
}

bool check(int i, int j, int r, int c) {
    if (i>=0 && i<r && j>=0 && j<c)
        return true;
    return false;
}

int f(int a[][100], int ra[][100], int r, int c, int i, int j) {
    int up=0, down=0, right=0, left=0;
    if (check(i-1, j, r, c) && a[i][j]<a[i-1][j])
        up = ra[i-1][j] != 0? ra[i-1][j]:f(a, ra, r, c, i-1, j);
    if (check(i+1, j, r, c) && a[i][j]<a[i+1][j])
        down = ra[i+1][j] != 0? ra[i+1][j]:f(a, ra, r, c, i+1, j);
    if (check(i, j-1, r, c) && a[i][j]<a[i][j-1])
        left = ra[i][j-1] != 0? ra[i][j-1]:f(a, ra, r, c, i, j-1);
    if (check(i, j+1, r, c) && a[i][j]<a[i][j+1])
        right = ra[i][j+1] != 0? ra[i][j+1]:f(a, ra, r, c, i, j+1);
    int m = up>down?  up:down;
    int n = left>right? left:right;
    return m>n? (m+1):(n+1);
}


#include <iostream>
using namespace std;

#define Max 8

int demo[Max][Max] = {0};
int t = 1;

void prin() {
    for (int i=0; i<Max; i++) {
        for (int j=0; j<Max; j++)
            cout << demo[i][j]  << "\t";
        cout << endl << endl;
    }
    cout << endl << endl;
}

void f(int ra, int rb, int rc, int rd, int size) {
    if (size == 2) {
        for (int i=ra; i<ra+2; i++) {
            for (int j=rb; j<rb+2; j++)
                if (demo[i][j] == 0)
                    demo[i][j] = t;
        }
        t++;
        return;
    }
    int s = size/2, sign = 1;
    if (ra+s > rc && rb+s > rd) {
        demo[ra+s-1][rb+s] = t;
        demo[ra+s][rb+s-1] = t;
        demo[ra+s][rb+s] = t++;
    }

    if (ra+s > rc && rb+s <= rd) {
        demo[ra+s-1][rb+s-1] = t;
        demo[ra+s][rb+s-1] = t;
        demo[ra+s][rb+s] = t++;
        sign = 2;
    }

    if (ra+s <= rc && rb+s > rd) {
        demo[ra+s-1][rb+s-1] = t;
        demo[ra+s-1][rb+s] = t;
        demo[ra+s][rb+s] = t++;
        sign = 3;
    }

    if (ra+s <= rc && rb+s <= rd) {
        demo[ra+s-1][rb+s-1] = t;
        demo[ra+s-1][rb+s] = t;
        demo[ra+s][rb+s-1] = t++;
        sign = 4;
    }

    if (sign == 1) { f(ra, rb, rc, rd, s);    }
    else           { f(ra, rb, s-1, s-1, s);  }
    if (sign == 2) { f(ra, rb+s, rc, rd, s);  }
    else           { f(ra, rb+s, s-1, s, s);  }
    if (sign == 3) { f(ra+s, rb, rc, rd, s);  }
    else           { f(ra+s, rb, s, s-1, s);  }
    if (sign == 4) { f(ra+s, rb+s, rc, rd, s);}
    else           { f(ra+s, rb+s, s, s, s);  }

}

int main() {
    int x, y;
    cout << "请输入特殊点横坐标(不大于8)：";
    do {
        cin >> x;
    }while (x < 0 || x >= 8);
    cout << "请输入特殊点纵坐标(不大于8)：";
    do {
        cin >> y;
    }while (y < 0 || y >= 8);
    demo[x][y] = -1;
    f(0, 0, x, y, Max);
    for (int i=0; i<Max; i++) {
        for (int j=0; j<Max; j++) {
            if (i == x && j == y) {
                cout << 0 << "\t";
            } else
            cout << demo[i][j]  << "\t";
        }
        cout << endl << endl;
    }
    return 0;
}

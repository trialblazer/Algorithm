#include<iostream>
#include<ctime>
#include<algorithm>
#include<cstdlib>

using namespace std;

bool walk_n(int x, int y); //上
bool walk_s(int x, int y); //下
bool walk_w(int x, int y); //左
bool walk_e(int x, int y); //右
bool walk_se(int x, int y); //右下
bool walk_sw(int x, int y); //左下
bool walk_nw(int x, int y); //左上
bool walk_ne(int x, int y); //右上
bool w(int x, int y, int key1, int key2);
void prin();

#define Max 5
#define Key 2

int b[Max][Max];
int graph[Max][Max];

int main() {
    srand(time(NULL));
    for (int i=0; i<Max; i++) {
        for(int j=0; j<Max; j++) {
            graph[i][j] = rand()%2;
            graph[0][0] = 1;
            graph[Max-1][Max-1] = 1;
            cout << graph[i][j] << "  ";
            b[i][j] = 0;
        }
        cout << endl;
    }

    cout << endl << endl;
    prin();
    return 0;
}

bool walk_n(int x, int y) {
    if (b[x][y] == 3 || b[x][y] == 2)
        return false;
    if (x<0)
        return false;
    if (graph[x][y] == 0 || graph[x][y] == Key)
        return false;
    return true;
}
bool walk_s(int x, int y) {
    if (b[x][y] == 3 || b[x][y] == 2)
        return false;
    if (x>=Max)
        return false;
    if (graph[x][y] == 0 || graph[x][y] == Key)
        return false;
    return true;
}
bool walk_w(int x, int y) {
    if (b[x][y] == 3 || b[x][y] == 2)
        return false;
    if (y<0)
        return false;
    if (graph[x][y] == 0 || graph[x][y] == Key)
        return false;
    return true;
}
bool walk_e(int x, int y) {
    if (b[x][y] == 3 || b[x][y] == 2)
        return false;
    if (y>=Max)
        return false;
    if (graph[x][y] == 0 || graph[x][y] == Key)
        return false;
    return true;
}
bool walk_se(int x, int y) {
    if (b[x][y] == 3 || b[x][y] == 2)
        return false;
    if (x>=Max || y>=Max)
        return false;
    if (graph[x][y] == 0 || graph[x][y] == Key)
        return false;
    return true;
}
bool walk_sw(int x, int y) {
    if (b[x][y] == 3 || b[x][y] == 2)
        return false;
    if (x+1>=Max || y-1<0)
        return false;
    if (graph[x][y] == 0 || graph[x][y] == Key)
        return false;
    return true;
}

bool walk_nw(int x, int y) {
    if (b[x][y] == 3 || b[x][y] == 2)
        return false;
    if (x<0 || y<0)
        return false;
    if (graph[x][y] == 0 || graph[x][y] == Key)
        return false;
    return true;
}
bool walk_ne(int x, int y) {
    if (b[x][y] == 3 || b[x][y] == 2)
        return false;
    if (y>=Max || x-1<0)
        return false;
    if (graph[x][y] == 0 || graph[x][y] == Key)
        return false;
    return true;
}

bool w(int x, int y, int key1, int key2) {
    b[x][y] = Key;
    if (x == key1 && y == key2) {
        b[x][y] = Key;
        return true;
    }
    if (walk_n(x-1, y)) {
        b[x-1][y] = Key;
        return w(x-1, y, key1, key2);
        b[x-1][y] = 3;
    } else {
        if (x-1 == key1 && y == key2) {
            b[x-1][y] = Key;
            return true;
        }
    }
    if (walk_s(x+1, y)) {
        b[x+1][y] = Key;
        return w(x+1,  y, key1, key2);
        b[x+1][y] = 3;
    }else {
        if (x+1 == key1 && y == key2) {
            b[x+1][y] = Key;
            return true;
        }
    }
    if (walk_w(x, y-1)) {
        b[x][y-1] = Key;
        return w(x, y-1, key1, key2);
        b[x][y-1] = 3;
    }else {
        if (x == key1 && y-1 == key2) {
            b[x][y-1] = Key;
            return true;
        }
    }
    if (walk_e(x, y+1)) {
        b[x][y+1] = Key;
        return w(x, y+1, key1, key2);
        b[x][y+1] = 3;
    }else {
        if (x == key1 && y+1 == key2) {
            b[x][y+1] = Key;
            return true;
        }
    }
    if (walk_nw(x-1, y-1)) {
        b[x-1][y-1] = Key;
        return w(x-1, y-1, key1, key2);
        b[x-1][y-1] = 3;
    }else {
        if (x-1 == key1 && y-1 == key2) {
            b[x-1][y-1] = Key;
            return true;
        }
    }
    if (walk_ne(x-1, y+1)) {
        b[x-1][y+1] = Key;
        return w(x-1, y+1, key1, key2);
        b[x-1][y+1] = 0;
    }else {
        if (x-1 == key1 && y+1 == key2) {
            b[x-1][y+1] = Key;
            return true;
        }
    }
    if (walk_sw(x+1, y-1)) {
        b[x+1][y-1] = Key;
        return w(x+1, y-1, key1, key2);
        b[x+1][y-1] = 0;
    }else {
        if (x+1 == key1 && y-1 == key2) {
            b[x+1][y-1] = Key;
            return true;
        }
    }
    if (walk_se(x+1, y+1)) {
        b[x+1][y+1] = Key;
        return w(x+1, y+1, key1, key2);
        b[x+1][y+1] = 0;
    }else {
        if (x+1 == key1 && y+1 == key2) {
            b[x+1][y+1] = Key;
            return true;
        } else
            return false;
    }

}

void prin() {
    if (w(0,0,Max-1, Max-1)) {
        for (int i=0; i<Max; i++) {
            for(int j=0; j<Max; j++) {
                if (b[i][j] == 3)
                    b[i][j] = 0;
                cout << b[i][j] << "  ";
            }
            cout << endl;
        }
    } else
        cout << "error!!\n";
}

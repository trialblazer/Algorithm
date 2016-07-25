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
void w(int x, int y, int key1, int key2);   //走迷宫
void prin();  //以二维数组表现线路
void creat();

#define Max 4			//迷宫的大小
#define Key 2			//解中线路标记数字
#define Exit1 Max-1    //出口横坐标
#define Exit2 Max-1		//出口纵坐标

int b[Max][Max];
int graph[Max][Max];

int main() {
    creat();
    w(0, 0, Exit1, Exit2);
    return 0;
}

void w(int x, int y, int key1, int key2) {
    b[x][y] = Key;
    if (x == key1 && y == key2) {
        b[x][y] = Key;
        prin();
    }

    if (walk_n(x-1, y)) {
        b[x-1][y] = Key;
        w(x-1, y, key1, key2);
        b[x-1][y] = 3;
    } 
    if (walk_s(x+1, y)) {
        b[x+1][y] = Key;
        w(x+1,  y, key1, key2);
        b[x+1][y] = 3;
    }
    if (walk_w(x, y-1)) {
        b[x][y-1] = Key;
        w(x, y-1, key1, key2);
        b[x][y-1] = 3;
    }
    if (walk_e(x, y+1)) {
        b[x][y+1] = Key;
        w(x, y+1, key1, key2);
        b[x][y+1] = 3;
    }
    if (walk_nw(x-1, y-1)) {
        b[x-1][y-1] = Key;
        w(x-1, y-1, key1, key2);
        b[x-1][y-1] = 3;
    }
    if (walk_ne(x-1, y+1)) {
        b[x-1][y+1] = Key;
        w(x-1, y+1, key1, key2);
        b[x-1][y+1] = 0;
    }
    if (walk_sw(x+1, y-1)) {
        b[x+1][y-1] = Key;
        w(x+1, y-1, key1, key2);
        b[x+1][y-1] = 0;
    }
    if (walk_se(x+1, y+1)) {
        b[x+1][y+1] = Key;
        w(x+1, y+1, key1, key2);
        b[x+1][y+1] = 0;
    } 
}

void prin() {
	for (int i=0; i<Max; i++) {
		for(int j=0; j<Max; j++) {
			if (b[i][j] == 3)
				b[i][j] = 0;
			cout << b[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl << endl;
}



void creat() {
    srand(time(NULL));
    for (int m=0; m<Max*3; m++)
        cout << "_";
    cout << endl;
    for (int i=0; i<Max; i++) {
        cout << "|";
        for(int j=0; j<Max; j++) {
            graph[i][j] = rand()%2;
            graph[0][0] = 1;
            graph[Exit1][Exit2] = 1;
            if (graph[i][j] == 0) 
                cout << "|*|";
            else {
                if (j == Max-1)
                    cout << "  |";
                else
                    cout << "   ";
            }
            b[i][j] = 0;
        }
        cout << endl;
    }
    for (int g=0; g<Max*3; g++)
        cout << "-";
	cout << endl << endl;
}


bool walk_n(int x, int y) {
	if (x<0)
        return false;
    if (b[x][y] == 3 || b[x][y] == Key || graph[x][y] == 0)
        return false;
    return true;
}

bool walk_s(int x, int y) {
	if (x>=Max)
        return false;
    if (b[x][y] == 3 || b[x][y] == 2 || graph[x][y] == 0)
        return false;
    return true;
}

bool walk_w(int x, int y) {
	if (y<0)
        return false;
    if (b[x][y] == 3 || b[x][y] == 2 || graph[x][y] == 0)
        return false;
    return true;
}

bool walk_e(int x, int y) {
	if (y>=Max)
        return false;
    if (b[x][y] == 3 || b[x][y] == 2 || graph[x][y] == 0)
        return false;
    return true;
}

bool walk_se(int x, int y) {
	if (x>=Max || y>=Max)
        return false;
    if (b[x][y] == 3 || b[x][y] == 2 || graph[x][y] == 0)
        return false;
    return true;
}
bool walk_sw(int x, int y) {
	if (x>=Max || y<0)
        return false;
    if (b[x][y] == 3 || b[x][y] == 2 || graph[x][y] == 0)
        return false;
    return true;
}

bool walk_nw(int x, int y) {
	if (x<0 || y<0)
        return false;
    if (b[x][y] == 3 || b[x][y] == 2 || graph[x][y] == 0)
        return false;
    return true;
}

bool walk_ne(int x, int y) {
	if (y>=Max || x<0)
        return false;
    if (b[x][y] == 3 || b[x][y] == 2 || graph[x][y] == 0)
        return false;
    return true;
}

#include<iostream>
#include<ctime>
#include<algorithm>
#include<cstdlib>

using namespace std;

bool walk_n(int x, int y); //��
bool walk_s(int x, int y); //��
bool walk_w(int x, int y); //��
bool walk_e(int x, int y); //��
bool walk_se(int x, int y); //����
bool walk_sw(int x, int y); //����
bool walk_nw(int x, int y); //����
bool walk_ne(int x, int y); //����
bool w(int x, int y, int key1, int key2);   //���Թ�
void prin();  //�Զ�ά���������·
void creat();

#define Max 4			//�Թ��Ĵ�С
#define Key 2			//������·�������
#define Exit1 Max-1    //���ں�����
#define Exit2 Max-1		//����������

int b[Max][Max];
int graph[Max][Max];

int main() {
    creat();
    prin();
    return 0;
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
    } 
    if (walk_s(x+1, y)) {
        b[x+1][y] = Key;
        return w(x+1,  y, key1, key2);
        b[x+1][y] = 3;
    }
    if (walk_w(x, y-1)) {
        b[x][y-1] = Key;
        return w(x, y-1, key1, key2);
        b[x][y-1] = 3;
    }
    if (walk_e(x, y+1)) {
        b[x][y+1] = Key;
        return w(x, y+1, key1, key2);
        b[x][y+1] = 3;
    }
    if (walk_nw(x-1, y-1)) {
        b[x-1][y-1] = Key;
        return w(x-1, y-1, key1, key2);
        b[x-1][y-1] = 3;
    }
    if (walk_ne(x-1, y+1)) {
        b[x-1][y+1] = Key;
        return w(x-1, y+1, key1, key2);
        b[x-1][y+1] = 0;
    }
    if (walk_sw(x+1, y-1)) {
        b[x+1][y-1] = Key;
        return w(x+1, y-1, key1, key2);
        b[x+1][y-1] = 0;
    }
    if (walk_se(x+1, y+1)) {
        b[x+1][y+1] = Key;
        return w(x+1, y+1, key1, key2);
        b[x+1][y+1] = 0;
    } else
		return false;
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

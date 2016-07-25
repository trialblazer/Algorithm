#include<iostream>
#include<ctime>
#include<cstdlib>
#include<conio.h>

using namespace std;

#define Max 7		   //迷宫的大小
#define Key 2		   //解中线路标记数字
#define Exit1 Max-1    //出口横坐标
#define Exit2 Max-1	   //出口纵坐标
#define Entrance1 0    //入口横坐标
#define Entrance2 0    //入口纵坐标
int tmpt1 = 0;         //标记看生成的迷宫是否走得通，通则为1，否则为0

int b[Max][Max];
int graph[Max][Max];

void menu();                  //菜单
void maprand();               //生成迷宫
void prmap(int x, int y);     //显示迷宫
bool walk(int x, int y);      //是否可走
bool walk_n(int x, int y);    //上
bool walk_s(int x, int y);    //下
bool walk_w(int x, int y);    //左
bool walk_e(int x, int y);    //右
bool walk_se(int x, int y);   //右下
bool walk_sw(int x, int y);   //左下
bool walk_nw(int x, int y);   //左上
bool walk_ne(int x, int y);   //右上
int findway(int x, int y);   //自动探索
void peoplefind();            //人工探索


int main() {
	while (1) {
        menu();
		char choice = getch();
loop:maprand();
		switch(choice) {
		case '1':
			tmpt1 = 0;
			findway(Entrance1, Entrance2);
			if (tmpt1 == 0) {
				choice = '1';
				goto loop;
			}
			peoplefind();
			break;
		case '2':
			system("cls");
			break;
		case '3':
			return 0;
		default: break;
		}
	}
}


void menu() {
    cout << "1:人工探索模式(如果无解则按‘0’返回上一级)。" << endl;
    cout << "2:清屏。" << endl;
    cout << "3:退出。" << endl;
}

void maprand() {
	srand(time(NULL));
    for (int i=0; i<Max; i++)
        for(int j=0; j<Max; j++) {
            graph[i][j] = rand()%2;
            graph[0][0] = 1;
            graph[Exit1][Exit2] = 1;
            b[i][j] = 0;
        }
}

void prmap(int x, int y ) {
	for (int j=0; j<Max; j++)
		cout << "__";
	cout << endl;
	for (int i=0; i<Max; i++) {
		cout << "|";
		for (int j=0; j<Max; j++) {
			graph[0][0] = 1;
			graph[Max-1][Max-1] = 1;
			if (i == x && j == y) {
				if (y == Max-1)
					cout << "!";
				else
					cout << "! ";
				continue;
			}
			if (graph[i][j] == 0) {
				if (j == Max-1)
					cout << "X";
				else
					cout << "X ";
			} else
				if (j == Max-1)
					cout << " ";
				else
					cout << "  ";
		}
		cout << "|" << endl;
	}
	for (int p=0; p<Max; p++)
		cout << "--";
	cout << endl;
}

void peoplefind() {
	int x=Entrance1, y=Entrance2;
	prmap(x, y);
	char a;
	while (1) {
		a = getch();
		switch(a) {
		case 'a':
			if (walk(x, y-1)) {
				system("cls");
				menu();
				prmap(x, y-1);
				x = x;
				y = y-1;
				if (x == Exit1 && y == Exit2) {
					cout << "you are great!!\n\n\n";
					return;
				}
			}
			break;
		case 'd':
			if (walk(x, y+1)) {
				system("cls");
				menu();
				prmap(x, y+1);
				x = x;
				y = y+1;
				if (x == Exit1 && y == Exit2) {
					cout << "you are great!!\n\n\n";
					return;
				}
			}
			break;
		case 'w':
			if (walk(x-1, y)) {
				system("cls");
				menu();
				prmap(x-1, y);
				x = x-1;
				y = y;
				if (x == Exit1 && y == Exit2) {
					cout << "you are great!!\n\n\n";
					return;
				}
			}
			break;
		case 'x':
			if (walk(x+1, y)) {
				system("cls");
				menu();
				prmap(x+1, y);
				x = x+1;
				y = y;
				if (x == Exit1 && y == Exit2) {
					cout << "you are great!!\n\n\n";
					return;
				}
			}
			break;
		case 'q':
			if (walk(x-1, y-1)) {
				system("cls");
				menu();
				prmap(x-1, y-1);
				x = x-1;
				y = y-1;
				if (x == Exit1 && y == Exit2) {
					cout << "you are great!!\n\n\n";
					return;
				}
			}
			break;
		case 'e':
			if (walk(x-1, y+1)) {
				system("cls");
				menu();
				prmap(x-1, y+1);
				x = x-1;
				y = y+1;
				if (x == Exit1 && y == Exit2) {
					cout << "you are great!!\n\n\n";
					return;
				}
			}
			break;
		case 'z':
			if (walk(x+1, y-1)) {
				system("cls");
				menu();
				prmap(x+1, y-1);
				x = x+1;
				y = y-1;
				if (x == Exit1 && y == Exit2) {
					cout << "you are great!!\n\n\n";
					return;
				}
			}
			break;
		case 'c':
			if (walk(x+1, y+1)) {
				system("cls");
				menu();
				prmap(x+1, y+1);
				x = x+1;
				y = y+1;
				if (x == Exit1 && y == Exit2) {
					cout << "you are great!!\n\n\n";
					return;
				}
			}
			break;
		case '0':
			return;
		default:
			break;
		}
	}
}

void findway(int x, int y) {
    b[x][y] = Key;
    if (x == Exit1 && y == Exit2) {
        b[x][y] = Key;
		tmpt1 = 1;
    }

    if (walk_n(x-1, y)) {
        b[x-1][y] = Key;
        findway(x-1, y);
        b[x-1][y] = 3;
    }
    if (walk_s(x+1, y)) {
        b[x+1][y] = Key;
        findway(x+1,  y);
        b[x+1][y] = 3;
    }
    if (walk_w(x, y-1)) {
        b[x][y-1] = Key;
        findway(x, y-1);
        b[x][y-1] = 3;
    }
    if (walk_e(x, y+1)) {
        b[x][y+1] = Key;
        findway(x, y+1);
        b[x][y+1] = 3;
    }
    if (walk_nw(x-1, y-1)) {
        b[x-1][y-1] = Key;
        findway(x-1, y-1);
        b[x-1][y-1] = 3;
    }
    if (walk_ne(x-1, y+1)) {
        b[x-1][y+1] = Key;
        findway(x-1, y+1);
        b[x-1][y+1] = 0;
    }
    if (walk_sw(x+1, y-1)) {
        b[x+1][y-1] = Key;
        findway(x+1, y-1);
        b[x+1][y-1] = 0;
    }
    if (walk_se(x+1, y+1)) {
        b[x+1][y+1] = Key;
        findway(x+1, y+1);
        b[x+1][y+1] = 0;
    }
}


bool walk(int x, int y) {
	if (x<0 || x>=Max || y<0 || y>=Max)
		return false;
	if (graph[x][y] == 0)
		return false;
	return true;
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

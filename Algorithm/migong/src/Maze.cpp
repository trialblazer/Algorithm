#include "Maze.h"
#include<ctime>
#include<cstdlib>

using namespace std;

#define Max 7
#define Key 2		   //解中线路标记数字
#define Exit1 Max-1    //出口横坐标
#define Exit2 Max-1	   //出口纵坐标
#define Entrance1 0    //入口横坐标
#define Entrance2 0    //入口纵坐标

Maze::Maze() {
    tmpt1 = 0;
    tmpt2 = 0;
}

void Maze::maprand() {
	srand(time(NULL));
    for (int i=0; i<Max; i++)
        for(int j=0; j<Max; j++) {
            graph[i][j] = rand()%2;
            graph[0][0] = 1;
            graph[Exit1][Exit2] = 1;
            b[i][j] = 0;
        }
}

void Maze::prmap(int x, int y ) {
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



void Maze::prmap_() {
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

void Maze::peoplefind() {
	int x=Entrance1, y=Entrance2;
	prmap(x, y);
	char a;
	while (1) {
		a = getch();
		switch(a) {
		case 'a':
			if (walk(x, y-1)) {
				system("cls");
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

void Maze::findway(int x, int y) {
    b[x][y] = Key;
    if (x == Exit1 && y == Exit2) {
        b[x][y] = Key;
        if (tmpt2 == 0)
            prmap_();
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
	if (tmpt1 == 0 && x == Entrance1 && y == Entrance2 && tmpt2 == 0) {
		cout << "error!!" << endl << endl << endl;
	}
}

void Maze::menu() {
    std::cout << "1:人工探索模式(如果无解则按‘0’返回上一级)。\n";
		std::cout << "2:自动探索模式。\n";
		std::cout << "3:清屏。\n";
		std::cout << "4:退出。\n";
}

bool Maze::walk(int x, int y) {
	if (x<0 || x>=Max || y<0 || y>=Max)
		return false;
	if (graph[x][y] == 0)
		return false;
	return true;
}


bool Maze::walk_n(int x, int y) {
	if (x<0)
        return false;
    if (b[x][y] == 3 || b[x][y] == Key || graph[x][y] == 0)
        return false;
    return true;
}

bool Maze::walk_s(int x, int y) {
	if (x>=Max)
        return false;
    if (b[x][y] == 3 || b[x][y] == 2 || graph[x][y] == 0)
        return false;
    return true;
}

bool Maze::walk_w(int x, int y) {
	if (y<0)
        return false;
    if (b[x][y] == 3 || b[x][y] == 2 || graph[x][y] == 0)
        return false;
    return true;
}

bool Maze::walk_e(int x, int y) {
	if (y>=Max)
        return false;
    if (b[x][y] == 3 || b[x][y] == 2 || graph[x][y] == 0)
        return false;
    return true;
}

bool Maze::walk_se(int x, int y) {
	if (x>=Max || y>=Max)
        return false;
    if (b[x][y] == 3 || b[x][y] == 2 || graph[x][y] == 0)
        return false;
    return true;
}
bool Maze::walk_sw(int x, int y) {
	if (x>=Max || y<0)
        return false;
    if (b[x][y] == 3 || b[x][y] == 2 || graph[x][y] == 0)
        return false;
    return true;
}

bool Maze::walk_nw(int x, int y) {
	if (x<0 || y<0)
        return false;
    if (b[x][y] == 3 || b[x][y] == 2 || graph[x][y] == 0)
        return false;
    return true;
}

bool Maze::walk_ne(int x, int y) {
	if (y>=Max || x<0)
        return false;
    if (b[x][y] == 3 || b[x][y] == 2 || graph[x][y] == 0)
        return false;
    return true;
}


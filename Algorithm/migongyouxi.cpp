#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<cstdlib>
#include<conio.h>

using namespace std;

#define Max 12

int g[Max][Max];

void maprand();  //生成迷宫
void prmap(int x, int y);  //显示迷宫
bool walk(int x, int y); 
void peoplefind(); //人工探索

int main() {
	maprand();
	peoplefind();
	return 0;
}

void maprand() {
	srand(time(NULL));
	for (int i=0; i<Max; i++) {
		for (int j=0; j<Max; j++) {
			g[i][j] = rand()%2;
		}
	}
}

void prmap(int x, int y ) {
	for (int j=0; j<Max; j++)
		cout << "__";
	cout << endl;
	for (int i=0; i<Max; i++) {
		cout << "|";
		for (int j=0; j<Max; j++) {
			g[0][0] = 1;
			g[Max-1][Max-1] = 1;
			if (i == x && j == y) {
				if (y == Max-1)
					cout << "!";
				else
					cout << "! ";
				continue;
			}
			if (g[i][j] == 0) {
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

bool walk(int x, int y) {
	if (x<0 || x>=Max || y<0 || y>=Max)
		return false;
	if (g[x][y] == 0)
		return false;
	return true;
}

void peoplefind() {
	int x=0, y=0;
	prmap(0, 0);
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
				if (x == Max-1 && y == Max-1) {
					cout << "you are great!!\n";
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
				if (x == Max-1 && y == Max-1) {
					cout << "you are great!!\n";
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
				if (x == Max-1 && y == Max-1) {
					cout << "you are great!!\n";
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
				if (x == Max-1 && y == Max-1) {
					cout << "you are great!!\n";
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
				if (x == Max-1 && y == Max-1) {
					cout << "you are great!!\n";
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
				if (x == Max-1 && y == Max-1) {
					cout << "you are great!!\n";
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
				if (x == Max-1 && y == Max-1) {
					cout << "you are great!!\n";
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
				if (x == Max-1 && y == Max-1) {
					cout << "you are great!!\n";
					return;
				}
			}
			break;
		default: 
			break;
		}
	}
}

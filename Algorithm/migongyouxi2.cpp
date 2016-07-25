#include<iostream>
#include<ctime>
#include<cstdlib>
#include<conio.h>

using namespace std;

#define Max 7		   //�Թ��Ĵ�С
#define Key 2		   //������·�������
#define Exit1 Max-1    //���ں�����
#define Exit2 Max-1	   //����������
#define Entrance1 0    //��ں�����
#define Entrance2 0    //���������
int tmpt1 = 0;         //��ǿ����ɵ��Թ��Ƿ��ߵ�ͨ��ͨ��Ϊ1������Ϊ0
int tmpt2 = 0;         //���Ϊ0ʱ�Զ�̽�����ӡ����b�����򲻴�ӡ   

int b[Max][Max];
int graph[Max][Max];


void maprand();               //�����Թ�
void prmap(int x, int y);     //��ʾ�Թ�
void prmap_();                //��������ʽ��ʾ�Թ���
bool walk(int x, int y);      //�Ƿ����
bool walk_n(int x, int y);    //��
bool walk_s(int x, int y);    //��
bool walk_w(int x, int y);    //��
bool walk_e(int x, int y);    //��
bool walk_se(int x, int y);   //����
bool walk_sw(int x, int y);   //����
bool walk_nw(int x, int y);   //����
bool walk_ne(int x, int y);   //����
void findway(int x, int y);   //�Զ�̽��
void peoplefind();            //�˹�̽��


int main() {
	while (1) {
		cout << "1:�˹�̽��ģʽ(����޽��򰴡�0��������һ��)��" << endl;
		cout << "2:�Զ�̽��ģʽ��" << endl;
		cout << "3:������" << endl;
		cout << "4:�˳���" << endl;
		char choice = getch();
loop:maprand();
		switch(choice) {
		case '1':
			tmpt2 = 1;
			tmpt1 = 0;
			findway(Entrance1, Entrance2);
			if (tmpt1 == 0) {
				choice = '1';
				goto loop;
			}
			peoplefind();
			tmpt2 = 0;
			break;
		case '2':
			tmpt1 = 0;
			prmap(Entrance1,Entrance2);
			findway(Entrance1, Entrance2);
			break;
		case '3':
			system("cls");
			break;
		case '4':
			return 0;
		default: break;
		}
	}
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

void prmap_() {
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

void findway(int x, int y) {
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

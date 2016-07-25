#ifndef MAZE_H
#define MAZE_H

#include<iostream>
#include<conio.h>
#include<stdlib.h>

#define Max 7		   //�Թ��Ĵ�С
#define Entrance1 0    //��ں�����
#define Entrance2 0    //���������

class Maze {
public:
    Maze();
    void prmap(int x, int y);     //��ʾ�Թ�
    void prmap_();                //��������ʽ��ʾ�Թ���
    void findway(int x, int y);   //�Զ�̽��
    void peoplefind();            //�˹�̽��
    void maprand();               //�����Թ�
    int getmpt1() {return tmpt1;} //��ȡtmpt1��ֵ
    void setmpt1(int value) {tmpt1 = value;}//�ı�tmpt1��ֵ
    int getmap2() {return tmpt2;} //��ȡtmpt2��ֵ
    void setmpt2(int value) {tmpt2 = value;}//�ı�tmpt2��ֵ
    void menu();

protected:
    bool walk(int x, int y);      //�Ƿ����
    bool walk_n(int x, int y);    //��
    bool walk_s(int x, int y);    //��
    bool walk_w(int x, int y);    //��
    bool walk_e(int x, int y);    //��
    bool walk_se(int x, int y);   //����
    bool walk_sw(int x, int y);   //����
    bool walk_nw(int x, int y);   //����
    bool walk_ne(int x, int y);   //����

private:
    int tmpt1;
    int tmpt2;          //��¼�Թ��Ƿ���ߣ�����Ϊ1������Ϊ2
    int b[Max][Max];
    int graph[Max][Max];
};

#endif // MAZE_H


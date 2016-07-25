#ifndef MAZE_H
#define MAZE_H

#include<iostream>
#include<conio.h>
#include<stdlib.h>

#define Max 7		   //迷宫的大小
#define Entrance1 0    //入口横坐标
#define Entrance2 0    //入口纵坐标

class Maze {
public:
    Maze();
    void prmap(int x, int y);     //显示迷宫
    void prmap_();                //以数组形式显示迷宫解
    void findway(int x, int y);   //自动探索
    void peoplefind();            //人工探索
    void maprand();               //生成迷宫
    int getmpt1() {return tmpt1;} //获取tmpt1的值
    void setmpt1(int value) {tmpt1 = value;}//改变tmpt1的值
    int getmap2() {return tmpt2;} //获取tmpt2的值
    void setmpt2(int value) {tmpt2 = value;}//改变tmpt2的值
    void menu();

protected:
    bool walk(int x, int y);      //是否可走
    bool walk_n(int x, int y);    //上
    bool walk_s(int x, int y);    //下
    bool walk_w(int x, int y);    //左
    bool walk_e(int x, int y);    //右
    bool walk_se(int x, int y);   //右下
    bool walk_sw(int x, int y);   //左下
    bool walk_nw(int x, int y);   //左上
    bool walk_ne(int x, int y);   //右上

private:
    int tmpt1;
    int tmpt2;          //记录迷宫是否可走，可以为1，否则为2
    int b[Max][Max];
    int graph[Max][Max];
};

#endif // MAZE_H


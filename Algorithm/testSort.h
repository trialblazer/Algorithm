#ifndef TESTSORT_H

#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::cerr;
using std::sort;

/*********************************************************************************************************/
/// date  ：     2016/2/24
/// author；     zpt
/// object：     sort
/// description: 1.该类为排序算法测试类，对特定的排序算法进行多次(默认10次)测试.测试数组大小默认(默认200)
///                排序算法要求为：参数<1>为Test&,参数<2>位bool(表示是否递增排序<默认>)返回值为void，
///               如Test t; void sort(t); 或 void sort(t, false);
///              2.getArray();可获取测试数组指针
///                getSize(); 可获取测试数组大小
///              3.如果要指定测试数组大小和测试次数可通过构造函数传递，如  Test t(20, 2); 表示数组大小20，测试2次
///              4.如果要指定测试数组（大小设定为USERSIZE）,可以通过：int a[USERSIZE]; Test t(a);
///
/// useMethod：  1.测试方法为 test函数;接受两个参数，第一个为测试算法函数指针，
///              第二个为排序规则（默认递增，如果递减，可指定第二个参数为false）
///              用法如： t.test(sort);  或  t.test(sort, false);
///              2.如果要查看排序结果可以将第三个注释宏取消注释
/**********************************************************************************************************/
class Test {
private:
    #define SIZE 200     //测试数组大小,默认
    #define NUM 10        //测试次数，默认
    #define USERSIZE 6   //用户自定义测试数组大小
    //#define PRINT         //测试宏，如果不打印结果将其注销

private:
    int* _array;   //测试数组
    int _size;     //测试数组大小
    int _num;      //循环测试次数
    bool _rand;    //测试数组是否为随机数组

public:
    Test():_size(SIZE), _num(NUM), _rand(true) {   //初始化测试数组,并调用排序函数对比对数组进行排序
        init();
    }
    Test(int s, int n):_size(s), _num(n), _rand(true) {
        init();
    }
    Test(int *initA): _num(1), _size(USERSIZE) {  //用户自定义测试数组，大小为USERSIZE
        if (initA == NULL) {
            exit(1);
        }
        _rand = false;
        init();
        for (int i=0; i<_size; i++) {
            _array[i] = initA[i];
        }
    }
    ~Test() {
        if (_array != NULL)
            delete _array;
    }
    void test(void (*_sort)(Test&, bool b), bool increase = true) {  //启动整个测试过程，默认为递增排序(increase为true)
        for (int i=0; i<_num; i++) {   // 循环测试
            if (_rand)
                rebegin();                 //重置数组，准备下一次测试
            #ifdef PRINT
            cout << "测试第" << i+1 << "次：" << endl;
            #endif

            Sort(_sort, increase);              //使用测试程序对该对象内数组进行排序

            #ifdef PRINT
            print();                   //测试打印程序
            cout << endl << endl;
            #endif
            if (check(increase) == false) {    // 检测排序是否正确
                return ;
            }
        }
        if (increase)
            cout << "递增排序";
        else
            cout << "递减排序";
        cout << "测试" << _num << "次，测试数组大小为" << _size << ",排序均正确，排序算法正确！" << endl;
    }
    int *getArray() {
        if (_array == NULL)
            exit(1);
        return _array;
    }
    int getSize() { return _size; }

private:
    void init() {  //初始化数据
        _array = new int[_size];
        if (_array == NULL) {
            cerr << "Memory allocate failure!" << endl;
            exit(1);
        }
        srand(time(NULL));
    }
    void initArray() {   //初始化测试数组
        if (_array == NULL)
            exit(1);
        for (int i=0; i<_size; i++) {
            _array[i] = rand()*12%(_size*100);  //随机生成测试数组
        }
    }
    void rebegin() {  //重置数组，准备下一次测试
        initArray();
    }
    bool check(bool incress) {  //检测测试函数运行结果,increase为true表示递增排序，否则为递减排序
        vector<int> check;
        for (int i=0; i<_size; i++) {
            check.push_back(_array[i]);
        }
        if (incress) //递增排序
            std::sort(check.begin(), check.end(), std::less<int>());  //对测试数组内的数进行排序，作为标准答案
        else  //递减排序
            std::sort(check.begin(), check.end(), std::greater<int>());  //对测试数组内的数进行排序，作为标准答案
        for (int i=0; i<_size; i++) {
            if (check[i] != _array[i]) {
                cout << "错误, i: " << i << endl;
                cout << "_array[i] = " << _array[i] << "    check[i] = " << check[i] << endl;
                return false;
            }
        }
        return true;
    }
    void Sort(void (*_sort)(Test&, bool), bool increase) {  //对测试数组进行排序
        _sort(*this, increase);
    }

private:
    void print() {  //测试函数，打印每次排序好的结果
        for (int i=0; i<_size; i++) {
            cout << _array[i] << "  ";
        }
        cout << endl;
    }
};



#endif // TESTSORT_H

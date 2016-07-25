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
/// date  ��     2016/2/24
/// author��     zpt
/// object��     sort
/// description: 1.����Ϊ�����㷨�����࣬���ض��������㷨���ж��(Ĭ��10��)����.���������СĬ��(Ĭ��200)
///                �����㷨Ҫ��Ϊ������<1>ΪTest&,����<2>λbool(��ʾ�Ƿ��������<Ĭ��>)����ֵΪvoid��
///               ��Test t; void sort(t); �� void sort(t, false);
///              2.getArray();�ɻ�ȡ��������ָ��
///                getSize(); �ɻ�ȡ���������С
///              3.���Ҫָ�����������С�Ͳ��Դ�����ͨ�����캯�����ݣ���  Test t(20, 2); ��ʾ�����С20������2��
///              4.���Ҫָ���������飨��С�趨ΪUSERSIZE��,����ͨ����int a[USERSIZE]; Test t(a);
///
/// useMethod��  1.���Է���Ϊ test����;����������������һ��Ϊ�����㷨����ָ�룬
///              �ڶ���Ϊ�������Ĭ�ϵ���������ݼ�����ָ���ڶ�������Ϊfalse��
///              �÷��磺 t.test(sort);  ��  t.test(sort, false);
///              2.���Ҫ�鿴���������Խ�������ע�ͺ�ȡ��ע��
/**********************************************************************************************************/
class Test {
private:
    #define SIZE 200     //���������С,Ĭ��
    #define NUM 10        //���Դ�����Ĭ��
    #define USERSIZE 6   //�û��Զ�����������С
    //#define PRINT         //���Ժ꣬�������ӡ�������ע��

private:
    int* _array;   //��������
    int _size;     //���������С
    int _num;      //ѭ�����Դ���
    bool _rand;    //���������Ƿ�Ϊ�������

public:
    Test():_size(SIZE), _num(NUM), _rand(true) {   //��ʼ����������,�������������Աȶ������������
        init();
    }
    Test(int s, int n):_size(s), _num(n), _rand(true) {
        init();
    }
    Test(int *initA): _num(1), _size(USERSIZE) {  //�û��Զ���������飬��СΪUSERSIZE
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
    void test(void (*_sort)(Test&, bool b), bool increase = true) {  //�����������Թ��̣�Ĭ��Ϊ��������(increaseΪtrue)
        for (int i=0; i<_num; i++) {   // ѭ������
            if (_rand)
                rebegin();                 //�������飬׼����һ�β���
            #ifdef PRINT
            cout << "���Ե�" << i+1 << "�Σ�" << endl;
            #endif

            Sort(_sort, increase);              //ʹ�ò��Գ���Ըö����������������

            #ifdef PRINT
            print();                   //���Դ�ӡ����
            cout << endl << endl;
            #endif
            if (check(increase) == false) {    // ��������Ƿ���ȷ
                return ;
            }
        }
        if (increase)
            cout << "��������";
        else
            cout << "�ݼ�����";
        cout << "����" << _num << "�Σ����������СΪ" << _size << ",�������ȷ�������㷨��ȷ��" << endl;
    }
    int *getArray() {
        if (_array == NULL)
            exit(1);
        return _array;
    }
    int getSize() { return _size; }

private:
    void init() {  //��ʼ������
        _array = new int[_size];
        if (_array == NULL) {
            cerr << "Memory allocate failure!" << endl;
            exit(1);
        }
        srand(time(NULL));
    }
    void initArray() {   //��ʼ����������
        if (_array == NULL)
            exit(1);
        for (int i=0; i<_size; i++) {
            _array[i] = rand()*12%(_size*100);  //������ɲ�������
        }
    }
    void rebegin() {  //�������飬׼����һ�β���
        initArray();
    }
    bool check(bool incress) {  //�����Ժ������н��,increaseΪtrue��ʾ�������򣬷���Ϊ�ݼ�����
        vector<int> check;
        for (int i=0; i<_size; i++) {
            check.push_back(_array[i]);
        }
        if (incress) //��������
            std::sort(check.begin(), check.end(), std::less<int>());  //�Բ��������ڵ�������������Ϊ��׼��
        else  //�ݼ�����
            std::sort(check.begin(), check.end(), std::greater<int>());  //�Բ��������ڵ�������������Ϊ��׼��
        for (int i=0; i<_size; i++) {
            if (check[i] != _array[i]) {
                cout << "����, i: " << i << endl;
                cout << "_array[i] = " << _array[i] << "    check[i] = " << check[i] << endl;
                return false;
            }
        }
        return true;
    }
    void Sort(void (*_sort)(Test&, bool), bool increase) {  //�Բ��������������
        _sort(*this, increase);
    }

private:
    void print() {  //���Ժ�������ӡÿ������õĽ��
        for (int i=0; i<_size; i++) {
            cout << _array[i] << "  ";
        }
        cout << endl;
    }
};



#endif // TESTSORT_H

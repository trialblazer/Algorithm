
/*

void print(list<char>& s) {
    list<char>::iterator t = s.begin();
    for (; t!=s.end(); t++)
        cout << *t << " ";
    cout << endl << endl;
}

int hanno(int size) {
    int sum = 0;
    list<char> s1, s2, s3;
    cout << "初始化。。" << endl;
    for (int i=0; i<size; i++)
        s1.push_front('a'+i);
    cout << "盘s1:";
    print(s1);



    cout << "结束。。" << endl;
    cout << "盘s3:";
    print(s3);
    return sum;
}

*/


/*
char pop(list<char>& l) {
    char tmpt = l.front();
    l.pop_front();
    return tmpt;
}

typedef struct Node {
    char a, b, c;
    int n;
}node;

void set(list<char>& a, list<char>& b, list<char>& c, int size) {
    int a_cur_size = size, b_cur_size = 0, c_cur_size = 0; /// 表示柱子上实际的数目
    int a_vir_size = 0, b_vir_size, c_vir_size;  ///表示柱子上应该虚拟的盘子的数目
    int a_tmp_size = 1, b_tmp_size = 0, c_tmp_size = 0;  ///表示柱子上实际虚拟的盘子数目

    int cur_vir_size = 1; ///表示总共虚拟盘子的数目
    int tmp_size = size; ///表示未放好盘子的数目

    if (size%2 == 0) {
        while (cur_vir_size != tmp_size) {
            b_vir_size = (cur_vir_size%2 == 1? cur_vir_size:0);
            c_vir_size = cur_vir_size-b_vir_size;
            while (a_tmpt_size != a_vir_size || b_vir_size != b_tmp_size || c_vir_size != c_tmp_size) {
                cur_vir_size%2 == 0? s2.push_front(pop(s1)):s3.push_front(pop(s1));
                a_tmp_size--;
                cur_vir_size%2 == 0? c_tmp_size++:b_tmp_size++;

            }
        }
    } else {

    }
}

void hanoi(int size) {
    int a_cur_size = size, b_cur_size = 0, c_cur_size = 0; /// 表示柱子上实际的数目
    int a_vir_size = 0, b_vir_size, c_vir_size;  ///表示柱子上应该虚拟的盘子的数目
    int a_tmp_size = 1, b_tmp_size = 0, c_tmp_size = 0;  ///表示柱子上实际虚拟的盘子数目

    int cur_vir_size = 1; ///表示总共虚拟盘子的数目
    int tmp_size = size; ///表示未放好盘子的数目

    list<int> s1, s2, s3;
    list<node> l;

    for (int i=0; i<size; i++)
        s1.push_front('a'+i);

    if (size%2 == 0) {
        while (cur_vir_size != tmp_size) {
            b_vir_size = (cur_vir_size%2 == 1? cur_vir_size:0);
            c_vir_size = cur_vir_size-b_vir_size;
            while (a_tmpt_size != a_vir_size || b_vir_size != b_tmp_size || c_vir_size != c_tmp_size) {
                cur_vir_size%2 == 0? s2.push_front(pop(s1)):s3.push_front(pop(s1));
                a_tmp_size--;
                cur_vir_size%2 == 0? c_tmp_size++:b_tmp_size++;

            }
        }
    } else {

    }
}

*/
#include <iostream>
#include <list>
#include <vector>
#include <stack>

using namespace std;

int hanoi(char a, char b, char c, int size);
int hanoi(int size);
int hano(int n,char a='a',char b='b',char c='c');

///sum = 2^size-1;

int main() {
    unsigned int size, sum;
    cin >> size;
    sum = hanoi('a', 'b', 'c', size);
    cout << "sum: " << sum << endl << endl;
    sum = hanoi(size);
    cout << "sum: " << sum << endl << endl;
    sum = hano(size);
    cout << "sum: " << sum << endl;
    return 0;
}


int hanoi(char a, char b, char c, int size) {
    if (size == 1) {
        cout << a << "-->" << c << endl;
        return 1;
    }
    unsigned int sum = 0;
    sum += hanoi(a, c, b, size-1);
    cout << a << "-->" << c << endl;
    sum++;
    sum += hanoi(b, a, c, size-1);
    return sum;
}

int hanoi(int size) {
    vector<list<int>* >v;
    for (int i=0; i<size; i++) {
        list<int>* l = new list<int>;
        if (i == 0) {
            l->push_back(2);
        } else {
            list<int>* p = v[i-1];
            list<int>::iterator t = v[i-1]->begin();
            //for (int j=0; j<v[i-1]->size(); j++) {
                for (; t!=v[i-1]->end(); t++) {
                    switch(*t) {
                    case 1: l->push_back(2); break;
                    case 2: l->push_back(1); break;
                    case 3: l->push_back(5); break;
                    case 4: l->push_back(6); break;
                    case 5: l->push_back(3); break;
                    case 6: l->push_back(4); break;
                    }
                }
                l->push_back(2);
                t = v[i-1]->begin();
                for (; t!=v[i-1]->end(); t++) {
                    switch(*t) {
                    case 1: l->push_back(3); break;
                    case 2: l->push_back(4); break;
                    case 3: l->push_back(1); break;
                    case 4: l->push_back(2); break;
                    case 5: l->push_back(6); break;
                    case 6: l->push_back(5); break;
                    }
                }
            //}
        }
        v.push_back(l);

    }
    int sum = 0;
    list<int>::iterator i=v[size-1]->begin();
    for (; i!=v[size-1]->end(); i++) {
        switch(*i) {
            case 1: cout << 'a' << "-->" << 'b' << endl; break;
            case 2: cout << 'a' << "-->" << 'c' << endl; break;
            case 3: cout << 'b' << "-->" << 'a' << endl; break;
            case 4: cout << 'b' << "-->" << 'c' << endl; break;
            case 5: cout << 'c' << "-->" << 'a' << endl; break;
            case 6: cout << 'c' << "-->" << 'b' << endl; break;
        }
        sum++;
    }
    for (int i=0; i<v.size(); i++)
        delete v[i];
    return sum;
}


int hano(int n,char a,char b,char c)
{
    stack<int> st;
    st.push(n);
    st.push(a);
    st.push(b);
    st.push(c);

    int sum=0;

    while (false==st.empty())
    {
        char _c=st.top();
        st.pop();
        char _b=st.top();
        st.pop();
        char _a=st.top();
        st.pop();
        char _n=st.top();
        st.pop();

        if(_n==1)
        {
            cout<<_a<<" --> "<<_c<<endl;
            sum++;
            continue;
        }
        //栈为先进后出的数据，因而
        //先将n-1个盘子由b通过a挪到c
        st.push(_n-1);
        st.push(_b);
        st.push(_a);
        st.push(_c);

        //将最底下的盘子由a挪到c
        st.push(1);
        st.push(_a);
        st.push(_b);
        st.push(_c);

        //将n-1个盘子由a通过c挪到b
        st.push(_n-1);
        st.push(_a);
        st.push(_c);
        st.push(_b);
    }
    return sum;
}




















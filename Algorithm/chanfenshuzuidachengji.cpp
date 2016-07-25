#include <iostream>
#include <string>
#include <sstream>
#include <limits.h>
#include <deque>
#include <algorithm>

using namespace std;

class BigNum {  //大整数加法，乘法
    deque<int> v;

public:
    BigNum() {}
    BigNum(string str) {
        copy(str.begin(), str.end(), back_inserter(v));
        transform(v.begin(), v.end(), v.begin(), bind2nd(minus<int>(), '0')); //字符‘1’变成整数要减去‘0’
    }
    deque<int>::iterator begin()    { return v.begin(); }
    deque<int>::iterator end()      { return v.end(); }
    int size()                      { return v.size(); }
    back_insert_iterator< deque<int> > Back_Inserter() { return back_inserter(v); }
    void push_front(int n) { v.push_front(n); }
    void push_back(int n) { v.push_back(n); }
    void adjust() {  //调整容器每位整型元素值都小于10
        int nSize = v.size();
        for (int i=nSize-1; i>0; i--) {
            int value = v[i];
            if (value < 10)
                continue;
            v[i] = value%10;
            v[i-1] += value/10;
        }
        //处理最高位
        int value = v[0];
        if (value >= 10) {
            v[0] = value%10;
            value = value/10;
            while (value > 0) {
                v.push_front(value%10);
                value /= 10;
            }
        }
        nSize = v.size();
    }

public:
    BigNum operator+(BigNum& m) {
        BigNum result;
        int n = size()-m.size();
        if (n >= 0) {
            transform(begin()+n, end(), m.begin(), result.Back_Inserter(), plus<int>());
            for (int i=n-1; i>=0; i--) {
                result.push_front(*(begin()+i));
            }
        } else {
            transform(begin(), end(), m.begin()-n, result.Back_Inserter(), plus<int>());
            for (int i=-n-1; i>=0; i--)
                result.push_front(*(m.begin()+i));
        }
        result.adjust();
        return result;
    }
    BigNum operator*(BigNum& m) {
        BigNum result("0");
        BigNum mid;
        for (int i=0; i<m.size(); i++) {
            mid = *this;
            for (int j=0; j<i; j++)
                mid.push_back(0);
            transform(mid.begin(), mid.end(), mid.begin(), bind2nd(multiplies<int>(), *(m.end()-i-1)));
            result = mid+result;
        }
        result.adjust();
        return result;
    }
    bool operator == (BigNum& m) { return v == m.v; }
    bool operator != (BigNum& m) { return v != m.v; }
    bool operator > (BigNum& m) {
        int len1 = v.size(), len2 = m.size();
        if (len1 > len2)
            return true;
        if (len1 < len2)
            return false;
        deque<int>::iterator t1, t2;
        for (t1=v.begin(), t2=m.begin(); t1!=v.end(); t1++, t2++) {
            if (*t1 > *t2)
                return true;
            if (*t1 < *t2)
                return false;
        }
        return false;  //相等
    }
    friend ostream& operator << (ostream& os, BigNum& bn) {
        copy(bn.v.begin(), bn.v.end(), ostream_iterator<int>(os, ""));
        return os;
    }
};

class MaxProduct {
//目的： 求一个数的拆分成多个数的最大乘积
//思路： 最大乘积 = 该数的前一部分数组成的子数 * 剩余部分拆分后的最大乘积
//算法： 动态规划
    BigNum key[50][50];   //中间结果保存数组,保存一个数从第i位开始到第j位的最大乘积
    string value;
    int maxSize;

private:
    class Check {  //检查一个string类型是否可以正确转换为数字型数据
    public:
        bool operator () (string v) {
            bool result = true;
            int index = v.find_first_not_of(" ");
            for (int i=index; i<v.length(); i++) {
                if (v[i] == '-')
                    continue;
                if (v[i]<'0' || v[i] > '9')  {
                    cerr << "输入不能含有非数字符" << endl;
                    result = false;
                    break;
                }
            }
            if (result) {
                index = v.find_first_not_of(' ');
                if (v[index] == '-') {
                    cerr << "输入不能为负数!" << endl;
                    result = false;;
                }
            }
            return result;
        }
    };


private:
    BigNum maxValue(int begin, int end, int size) { //求value拆分的最大乘积
        if (begin+1 == end || 1 == size)            //如果剩余部分只有一个数或者拆分已经达到上限
            return BigNum(value.substr(begin, end-begin));  //转换成数字型数据

        BigNum a("0");
        if (key[begin][end-1] > a)          //数据以前已经计算过了，直接返回
            return key[begin][end-1];

        BigNum maxV("0");                   //保存最大值
        for (int i=begin+1; i<end; i++) {               //前半部分数为从第begin位开始到第i位结束的数
            if (end-i+1 < size)             //划分次数限制
                break;
            BigNum first(value.substr(begin, i-begin)); //前半部分数据转换
            BigNum second = maxValue(i, end, size-1);   //计算后半部分的最大乘积


            BigNum tmpt = first*second;         //计算当前该划分的最终结果
            maxV = maxV>tmpt? maxV:tmpt;        //如果是最大的，保存到maxV
        }
        key[begin][end-1] = maxV;  //将最终结果保存到key数组
        return maxV;               //返回结果
    }

public:
    void operator() (string v, int size) {  //重载（）
        value = v;
        if (Check()(v) == false) {
            return ;
        }
        if (BigNum(v).size() < size) {
            cerr << "无法拆分,太短" << endl;
            return ;
        }
        maxSize = size;
        cout << "    key : " << value << endl;
        BigNum tmpt =  maxValue(0, value.length(), maxSize);
        cout << "maxValue: " << tmpt << endl;
    }
};



int main() {
    cout << endl << "求拆分乘积最大值：" << endl;
    string key;
    while (1) {
        cin >> key;
        MaxProduct()(key, 3);
    }
	return 0;
}

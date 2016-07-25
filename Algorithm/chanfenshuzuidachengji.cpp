#include <iostream>
#include <string>
#include <sstream>
#include <limits.h>
#include <deque>
#include <algorithm>

using namespace std;

class BigNum {  //�������ӷ����˷�
    deque<int> v;

public:
    BigNum() {}
    BigNum(string str) {
        copy(str.begin(), str.end(), back_inserter(v));
        transform(v.begin(), v.end(), v.begin(), bind2nd(minus<int>(), '0')); //�ַ���1���������Ҫ��ȥ��0��
    }
    deque<int>::iterator begin()    { return v.begin(); }
    deque<int>::iterator end()      { return v.end(); }
    int size()                      { return v.size(); }
    back_insert_iterator< deque<int> > Back_Inserter() { return back_inserter(v); }
    void push_front(int n) { v.push_front(n); }
    void push_back(int n) { v.push_back(n); }
    void adjust() {  //��������ÿλ����Ԫ��ֵ��С��10
        int nSize = v.size();
        for (int i=nSize-1; i>0; i--) {
            int value = v[i];
            if (value < 10)
                continue;
            v[i] = value%10;
            v[i-1] += value/10;
        }
        //�������λ
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
        return false;  //���
    }
    friend ostream& operator << (ostream& os, BigNum& bn) {
        copy(bn.v.begin(), bn.v.end(), ostream_iterator<int>(os, ""));
        return os;
    }
};

class MaxProduct {
//Ŀ�ģ� ��һ�����Ĳ�ֳɶ���������˻�
//˼·�� ���˻� = ������ǰһ��������ɵ����� * ʣ�ಿ�ֲ�ֺ�����˻�
//�㷨�� ��̬�滮
    BigNum key[50][50];   //�м�����������,����һ�����ӵ�iλ��ʼ����jλ�����˻�
    string value;
    int maxSize;

private:
    class Check {  //���һ��string�����Ƿ������ȷת��Ϊ����������
    public:
        bool operator () (string v) {
            bool result = true;
            int index = v.find_first_not_of(" ");
            for (int i=index; i<v.length(); i++) {
                if (v[i] == '-')
                    continue;
                if (v[i]<'0' || v[i] > '9')  {
                    cerr << "���벻�ܺ��з����ַ�" << endl;
                    result = false;
                    break;
                }
            }
            if (result) {
                index = v.find_first_not_of(' ');
                if (v[index] == '-') {
                    cerr << "���벻��Ϊ����!" << endl;
                    result = false;;
                }
            }
            return result;
        }
    };


private:
    BigNum maxValue(int begin, int end, int size) { //��value��ֵ����˻�
        if (begin+1 == end || 1 == size)            //���ʣ�ಿ��ֻ��һ�������߲���Ѿ��ﵽ����
            return BigNum(value.substr(begin, end-begin));  //ת��������������

        BigNum a("0");
        if (key[begin][end-1] > a)          //������ǰ�Ѿ�������ˣ�ֱ�ӷ���
            return key[begin][end-1];

        BigNum maxV("0");                   //�������ֵ
        for (int i=begin+1; i<end; i++) {               //ǰ�벿����Ϊ�ӵ�beginλ��ʼ����iλ��������
            if (end-i+1 < size)             //���ִ�������
                break;
            BigNum first(value.substr(begin, i-begin)); //ǰ�벿������ת��
            BigNum second = maxValue(i, end, size-1);   //�����벿�ֵ����˻�


            BigNum tmpt = first*second;         //���㵱ǰ�û��ֵ����ս��
            maxV = maxV>tmpt? maxV:tmpt;        //��������ģ����浽maxV
        }
        key[begin][end-1] = maxV;  //�����ս�����浽key����
        return maxV;               //���ؽ��
    }

public:
    void operator() (string v, int size) {  //���أ���
        value = v;
        if (Check()(v) == false) {
            return ;
        }
        if (BigNum(v).size() < size) {
            cerr << "�޷����,̫��" << endl;
            return ;
        }
        maxSize = size;
        cout << "    key : " << value << endl;
        BigNum tmpt =  maxValue(0, value.length(), maxSize);
        cout << "maxValue: " << tmpt << endl;
    }
};



int main() {
    cout << endl << "���ֳ˻����ֵ��" << endl;
    string key;
    while (1) {
        cin >> key;
        MaxProduct()(key, 3);
    }
	return 0;
}

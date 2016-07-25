#include<iostream>
using namespace std;

struct People
{
    int height;
    int weight;
    People(int h, int w)
    {
        height = h;
        weight = w;
    }
};

struct Stack
{
    int size;
    int * a;
    int p;

    Stack(int s)
    {
        p = 0;

        cout<< "Stack construct function called"<<endl;
        size = s;
        a = new int[s];
    }

    int length()
    {
        return size;
    }

    //ÍËÕ»
    void pop()
    {
        if(p>0)
            p--;
    }

    void push(int s)
    {
        if(p<size)
        {
            a[p] = s;
            p++;
        }
    }

    int top()
    {
        return a[p-1];
    }

    bool isEmpty()
    {
        return p==0;
    }

    ~Stack()
    {
        cout<<"Stack deconstruct function called"<<endl;
        delete []a;
    }
};

int main()
{
    //People zpb(170, 50);
    //cout<<zpb.height<<endl;
    //cout<<zpb.weight<<endl;

    int * a;
    int n;
    cin>>n;
    a = new int[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    Stack s(n);
    for(int i=0; i<n; i++)
        s.push(a[i]);
    for(int i=0; i<n; i++)
    {
        a[i] = s.top();
        s.pop();
    }

    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}


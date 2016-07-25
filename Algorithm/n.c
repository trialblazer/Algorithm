#include <ctime>
#include <cstdlib>
// ����Ϊ�����������Ҫ��ͷ�ļ�
#include <iostream>
using namespace std;

#include "bs_tree.h"

// ����������ĸ��������Ըı����ִ�С���ı����ڵ�ĸ���
// �Ӷ��ı�������ݵĹ�ģ
#define M 100

int main()
{
	int a[M];
	// ���������
	cout << "random digit" << endl;
	srand(time(NULL));
	for (int i=0; i<M; i++)
    {
		a[i] = rand()%100000;
		cout << a[i] << " ";
	}
	cout << endl;


    BS_Tree tree;
	cout << "test insert function" << endl;
	cout << "start insert" << endl;
	for (int j=0; j<M; j++)
		tree.Insert(a[j]);
	cout << "after insert" << endl;
	cout << "in order travel " << endl;
	tree.InOrderTravel();
	cout << "pre order travel" << endl;
	tree.PreOrderTravel();
	cout << "post order travel" << endl;
	tree.PostOrderTravel();
	cout << "layer travel" << endl;
	tree.LayerTravel();


	cout << "test depth function" << endl;
	cout << "depth :  " << tree.Depth() << endl;

	// ���Ҵ���ɾ��
	for (int s=0; s<M; s++)
		swap(a[s], a[(a[s]%M)]);

	// ����ɾ��
	cout << "test remove function" << endl;
	cout << "start remove" << endl;
	for (int k=0; k<M; k++)
		tree.Remove(a[k]);
	cout << "after remove" << endl;
	tree.InOrderTravel();

    return 0;
}

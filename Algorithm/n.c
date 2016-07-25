#include <ctime>
#include <cstdlib>
// 以上为生成随机数需要的头文件
#include <iostream>
using namespace std;

#include "bs_tree.h"

// 生成随机数的个数，可以改变数字大小而改变插入节点的个数
// 从而改变测试数据的规模
#define M 100

int main()
{
	int a[M];
	// 生成随机数
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

	// 打乱次序删除
	for (int s=0; s<M; s++)
		swap(a[s], a[(a[s]%M)]);

	// 测试删除
	cout << "test remove function" << endl;
	cout << "start remove" << endl;
	for (int k=0; k<M; k++)
		tree.Remove(a[k]);
	cout << "after remove" << endl;
	tree.InOrderTravel();

    return 0;
}

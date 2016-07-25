#include "bs_tree.h"

#include <iostream>
#include <queue>

BS_Tree::BS_Tree():root(NULL) {
}

BS_Tree::~BS_Tree() {
    Destory();
}

void BS_Tree::Destory() { 
    _destory(root);
    // 此处需要将root设为NULL，因为root是否为NULL代表树是否为空（影响insert的动作）
    // 删除后root的值并没有改变（此处按值传递），因此需要将root
    // 设为NULL来表明树已经为空
    root = NULL;
}

void BS_Tree::_destory(BS_Node *node) {
    if (node != NULL) {
        _destory(node->lchild);
        _destory(node->rchild);
        delete node;
        node = NULL;
    }
}

bool BS_Tree::Insert(int v) {
    return _insert(v, &root);
}

/// 此处必须传递指针的指针或者指针的引用
/// 因为需要改变节点的值，因此不能按值传递
bool BS_Tree::_insert(int v, BS_Node **node) {
    if ((*node) == NULL) {
        *node = new BS_Node(v);
        if (*node == NULL)
            return false;
        return true;
    }
    if ((*node)->value > v)
        return _insert(v, &(*node)->lchild);
    return _insert(v, &(*node)->rchild);
}

void BS_Tree::Remove(int v) {
    _remove(v, &root);
}

/// 此处必须传递指针的指针或者指针的引用
/// 因为需要改变节点的值，因此不能按值传递
void BS_Tree::_remove(int v, BS_Node **node) {
    // 没有找到待删除节点
    if ((*node) == NULL)
        return;
    if ((*node)->value == v) {
        if ((*node)->lchild == NULL && (*node)->rchild == NULL) {
            // 待删除节点是叶节点
            delete *node;
            *node = NULL;
        } else {
            // 待删除节点非叶节点
            // 用当前节点的右子树的最左节点替换当前节点
            BS_Node *pp = (*node);
            BS_Node *p = (*node)->rchild;
            if (p == NULL) {
                // 当前节点没有右子树
                // 直接将当前节点删除
                p = (*node);
                *node = p->lchild;
                delete p;
                p = NULL;
            } else {
                // 当前节点有右子树
                // 找右子树最左边的节点
                while (p->lchild != NULL) {
                    pp = p;
                    p = pp->lchild;
                }
                // 替换当前节点
                (*node)->value = p->value;

				// 待删除右子树没有左子树
				if ((*node) == pp)
					pp->rchild = p->rchild;
				else 
					// p节点可能含有右子树
					pp->lchild = p->rchild;

                // 删除p节点
                delete p;
                p = NULL;
            }
        }
    } else if ((*node)->value > v){
        // 从左子树删除
        _remove(v, &(*node)->lchild);
    } else {
        // 从右子树删除
        _remove(v, &(*node)->rchild);
    }
}


// 中序遍历
void BS_Tree::InOrderTravel() {
	_inordertravel(root);
	std::cout << std::endl;
}

void BS_Tree::_inordertravel(BS_Node *node) {
	if (node != NULL) {
		_inordertravel(node->lchild);
		std::cout << node->value << " ";
		_inordertravel(node->rchild);
	}
}

// 前序遍历
void BS_Tree::PreOrderTravel() {
	_preordertravel(root);
	std::cout << std::endl;
}

void BS_Tree::_preordertravel(BS_Node *node) {
	if (node != NULL) {
		std::cout << node->value << " ";
		_preordertravel(node->lchild);
		_preordertravel(node->rchild);
	}
}

// 后序遍历
void BS_Tree::PostOrderTravel() {
	_postordertravel(root);
	std::cout << std::endl;
}

void BS_Tree::_postordertravel(BS_Node *node) {
	if (node != NULL) {
		_postordertravel(node->lchild);
		_postordertravel(node->rchild);
		std::cout << node->value << " ";
	}
}

void BS_Tree::LayerTravel() {
	// 用于存放每一层节点的队列
	std::queue<BS_Node*> q1;
	// 用于存放q1队列中节点的下一层节点
	std::queue<BS_Node*> q2;

	q1.push(root);
	while (q1.empty() == false) {
		// 将各个节点从q1中弹出，并访问每一个节点
		while(q1.empty() == false) {
			// 弹出节点
			BS_Node *p = q1.front();
			// 将已弹出的几点从队列删除
			q1.pop();
			
			// 访问当前节点
			std::cout << p->value << " ";

			//若当前节点左右子树不为空，则将其保存至q2，等待下一次访问
			if (p->lchild != NULL)
				q2.push(p->lchild);
			if (p->rchild != NULL)
				q2.push(p->rchild);
		}
		// 交换q1和q2
		std::swap(q1, q2);
	}
}

int BS_Tree::Depth() {
	return _depth(root);
}

int BS_Tree::_depth(BS_Node *node) {
	if (node == NULL)
		return 0;
	int l = _depth(node->lchild);
	int r = _depth(node->rchild);
	return (l > r ? l : r) + 1;
}
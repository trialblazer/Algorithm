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
    // �˴���Ҫ��root��ΪNULL����Ϊroot�Ƿ�ΪNULL�������Ƿ�Ϊ�գ�Ӱ��insert�Ķ�����
    // ɾ����root��ֵ��û�иı䣨�˴���ֵ���ݣ��������Ҫ��root
    // ��ΪNULL���������Ѿ�Ϊ��
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

/// �˴����봫��ָ���ָ�����ָ�������
/// ��Ϊ��Ҫ�ı�ڵ��ֵ����˲��ܰ�ֵ����
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

/// �˴����봫��ָ���ָ�����ָ�������
/// ��Ϊ��Ҫ�ı�ڵ��ֵ����˲��ܰ�ֵ����
void BS_Tree::_remove(int v, BS_Node **node) {
    // û���ҵ���ɾ���ڵ�
    if ((*node) == NULL)
        return;
    if ((*node)->value == v) {
        if ((*node)->lchild == NULL && (*node)->rchild == NULL) {
            // ��ɾ���ڵ���Ҷ�ڵ�
            delete *node;
            *node = NULL;
        } else {
            // ��ɾ���ڵ��Ҷ�ڵ�
            // �õ�ǰ�ڵ��������������ڵ��滻��ǰ�ڵ�
            BS_Node *pp = (*node);
            BS_Node *p = (*node)->rchild;
            if (p == NULL) {
                // ��ǰ�ڵ�û��������
                // ֱ�ӽ���ǰ�ڵ�ɾ��
                p = (*node);
                *node = p->lchild;
                delete p;
                p = NULL;
            } else {
                // ��ǰ�ڵ���������
                // ������������ߵĽڵ�
                while (p->lchild != NULL) {
                    pp = p;
                    p = pp->lchild;
                }
                // �滻��ǰ�ڵ�
                (*node)->value = p->value;

				// ��ɾ��������û��������
				if ((*node) == pp)
					pp->rchild = p->rchild;
				else 
					// p�ڵ���ܺ���������
					pp->lchild = p->rchild;

                // ɾ��p�ڵ�
                delete p;
                p = NULL;
            }
        }
    } else if ((*node)->value > v){
        // ��������ɾ��
        _remove(v, &(*node)->lchild);
    } else {
        // ��������ɾ��
        _remove(v, &(*node)->rchild);
    }
}


// �������
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

// ǰ�����
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

// �������
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
	// ���ڴ��ÿһ��ڵ�Ķ���
	std::queue<BS_Node*> q1;
	// ���ڴ��q1�����нڵ����һ��ڵ�
	std::queue<BS_Node*> q2;

	q1.push(root);
	while (q1.empty() == false) {
		// �������ڵ��q1�е�����������ÿһ���ڵ�
		while(q1.empty() == false) {
			// �����ڵ�
			BS_Node *p = q1.front();
			// ���ѵ����ļ���Ӷ���ɾ��
			q1.pop();
			
			// ���ʵ�ǰ�ڵ�
			std::cout << p->value << " ";

			//����ǰ�ڵ�����������Ϊ�գ����䱣����q2���ȴ���һ�η���
			if (p->lchild != NULL)
				q2.push(p->lchild);
			if (p->rchild != NULL)
				q2.push(p->rchild);
		}
		// ����q1��q2
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
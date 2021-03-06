#include "pch.h"
#include <iostream>
using namespace std;

class BinaryTreeNode
{
	class Node {
	public:
		int data;
		Node *left;
		Node *right;
	};
	Node *tree;
	//创建二叉树
	Node *createBinaryTreeNode()
	{
		Node *p;
		int data;
		cin >> data;
		if (data == -1)
		{
			return NULL;
		}
		else
		{
			p = new Node;
			p->data = data;
			p->left = createBinaryTreeNode();
			p->right = createBinaryTreeNode();
		}
		return p;
	}

	//前序遍历
	void preTraversal(Node *p)
	{
		if (p)
		{
			cout << p->data << ' ';
			preTraversal(p->left);
			preTraversal(p->right);
		}
	}

	//中序遍历
	void cenTraversal(Node *p)
	{
		if (p)
		{
			preTraversal(p->left);
			cout << p->data << ' ';
			preTraversal(p->right);
		}
	}

	//后序遍历
	void lastTraversal(Node *p)
	{
		if (p)
		{
			preTraversal(p->left);
			preTraversal(p->right);
			cout << p->data << ' ';
		}
	}

	//释放
	Node *del(Node *p)
	{
		if (p)
		{
			del(p->left);
			del(p->right);
			delete p;
		}
	}
public:
	void createBinaryTree()
	{
		tree = createBinaryTreeNode();
	}
	void preOut()
	{
		cout << "前序遍历：";
		preTraversal(tree);
		cout << endl;
	}
	void cenOut()
	{
		cout << "中序遍历：";
		cenTraversal(tree);
		cout << endl;
	}
	void lastOut()
	{
		cout << "后序遍历：";
		lastTraversal(tree);
		cout << endl;
	}
	
	~BinaryTreeNode()
	{
		del(tree);
	}
};


int main()
{
	BinaryTreeNode *tree = new BinaryTreeNode;
	tree->createBinaryTree();
	tree->preOut();
	tree->cenOut();
	tree->lastOut();
}
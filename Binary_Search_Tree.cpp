#include <iostream>
#include "Binary_Search_Tree.h"

using std::cout;
using std::cin;
using std::endl;

Node* Tree::Push(Node* next, char x)
{
	if (next == 0)
	{
		next = new Node(x);
	}
	else if (next->Data > x)
	{
		next->leftNode = Push(next->leftNode, x);
	}
	else
	{
		next->rightNode = Push(next->rightNode, x);
	}
	return next;
}

void Tree::Push(char x)
{
	root = Push(root, x);
}

void Tree::Inorder(Node* node)
{
	if (node == 0) { return; };

	Inorder(node->leftNode);
	printf("%c ", node->Data);
	Inorder(node->rightNode);
}

void Tree::Preorder(Node* node)
{
	if (node == 0) { return; };

	printf("%c ", node->Data);
	Preorder(node->leftNode);
	Preorder(node->rightNode);
}

void Tree::Postorder(Node* node)
{
	if (node == 0) { return; };

	Postorder(node->leftNode);
	Postorder(node->rightNode);
	printf("%c ", node->Data);
}

void Tree::Find(Node* node, char x)
{
	if (node == 0) { return; };
	if (node->Data == x)
	{
		printf("%c %s ", x, "is in the tree");
	}
	Find(node->leftNode, x);
	Find(node->rightNode, x);
}

Node* Tree::Max(Node *node)
{
	if (node->rightNode == 0)
	{
		return node;
	}
	node = Max(node->rightNode);
}

Node* Tree::Mini(Node *node)
{
	if (node->leftNode == 0)
	{
		return node;
	}
	node = Mini(node->leftNode);
}

Node* Tree::Delete(Node* node, char x)
{
	if (node == 0) return NULL;
	if (node->Data > x)
	{
		node->leftNode = Delete(node->leftNode, x);
	}
	else if (node->Data < x)
	{
		node->rightNode = Delete(node->rightNode, x);
	}
	else
	{
		if (node->leftNode == 0 && node->rightNode == 0)
		{
			delete node;
			node = 0;
		}
		else if (node->leftNode == 0)
		{
			Node *tmp = node;
			node = node->rightNode;
			delete tmp;
		}
		else if (node->rightNode == 0)
		{
			Node *tmp = node;
			node = node->leftNode;
			delete tmp;
		}
		else
		{
			Node *tmp = Max(node->leftNode);
			node->Data = tmp->Data;
			delete tmp;
		}
	}
	return node;
}

void Tree::InorderPrint()
{
	cout << "Inorder-> ";
	Inorder(root);
	cout << endl;
}

void Tree::PreorderPrint()
{
	cout << "Preorder-> ";
	Preorder(root);
	cout << endl;
}

void Tree::PostorderPrint()
{
	cout << "Postorder-> ";
	Postorder(root);
	cout << endl;
}

void Tree::PrintFind(char x)
{
	Find(root, x);
	cout << endl;
}

void Tree::GetMax()
{
	cout << "The max value is " << Max(root)->Data << endl;
}

void Tree::GetMini()
{
	cout << "The mini value is " << Mini(root)->Data << endl;
}

void Tree::Delete(char x)
{
	Delete(root, x)->Data;
}
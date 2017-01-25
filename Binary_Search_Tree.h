#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

class Tree;
class Node
{
	friend class Tree;
private:
	char Data;
	Node *leftNode;
	Node *rightNode;
public:
	Node() :Data(0), leftNode(0), rightNode(0) {};
	Node(char x) :Data(x), leftNode(0), rightNode(0) {};
};

class Tree
{
public:
	Tree() :root(0) {};
	Node* Push(Node*, char);
	void Push(char);
	void InorderPrint();
	void PreorderPrint();
	void PostorderPrint();
	void PrintFind(char);
	void GetMax();
	void GetMini();
	void Delete(char);
private:
	void Inorder(Node*);
	void Preorder(Node*);
	void Postorder(Node*);
	void Find(Node*, char);
	Node* Max(Node*);
	Node* Mini(Node*);
	Node* Delete(Node*, char);
	Node *root;
};

#endif


#include <iostream>
#include "Binary_Search_Tree.h"

int main()
{
	/*
				D
			  /	  \		
			 B	   E
			/ \		\
		   A   C	 E
					  \
					   G
					    \
						 H
	*/
	Tree tree;
	tree.Push('D');
	tree.Push('B');
	tree.Push('A');
	tree.Push('E');
	tree.Push('G');
	tree.Push('H');
	tree.Push('C');
	tree.InorderPrint();
	tree.PreorderPrint();
	tree.PostorderPrint();
	tree.PrintFind('D');
	tree.GetMax();
	tree.GetMini();
	tree.Delete('D');

	system("pause");
	return 0;
}
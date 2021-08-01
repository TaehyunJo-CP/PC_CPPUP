#include <cassert>
#include "TreeNode.h"
#include "BinarySearchTree.h"
#include <iostream>

using namespace assignment4;

int main()
{
	BinarySearchTree<int> tree;

	bool bSearched1 = tree.Search(15);
	assert(!bSearched1);

	tree.Insert(std::make_unique<int>(10));
	tree.Insert(std::make_unique<int>(15));
	tree.Insert(std::make_unique<int>(5));
	tree.Insert(std::make_unique<int>(4));
	tree.Insert(std::make_unique<int>(19));
	tree.Insert(std::make_unique<int>(20));
	tree.Insert(std::make_unique<int>(17));
	tree.Insert(std::make_unique<int>(12));

	std::vector<int> v = tree.TraverseInOrder(tree.GetRootNode().lock());

	assert(v.size() == 8);
	assert(v[0] == 4);
	assert(v[1] == 5);
	assert(v[2] == 10);
	assert(v[3] == 12);
	assert(v[4] == 15);
	assert(v[5] == 17);
	assert(v[6] == 19);
	assert(v[7] == 20);

	bool bSearched2 = tree.Search(20);
	assert(bSearched2);

	bool bSearched3 = tree.Search(1);
	assert(!bSearched3);

	bool bSearched4 = tree.Search(15);
	assert(bSearched4);

	bool bDeleted = tree.Delete(6);
	assert(!bDeleted);

	bDeleted = tree.Delete(100);
	assert(!bDeleted);

	bDeleted = tree.Delete(17);
	assert(bDeleted);

	v = tree.TraverseInOrder(tree.GetRootNode().lock());

	assert(v.size() == 7);
	assert(v[0] == 4);
	assert(v[1] == 5);
	assert(v[2] == 10);
	assert(v[3] == 12);
	assert(v[4] == 15);
	assert(v[5] == 19);
	assert(v[6] == 20);

	bDeleted = tree.Delete(5);
	assert(bDeleted);

	v = tree.TraverseInOrder(tree.GetRootNode().lock());

	assert(v.size() == 6);
	assert(v[0] == 4);
	assert(v[1] == 10);
	assert(v[2] == 12);
	assert(v[3] == 15);
	assert(v[4] == 19);
	assert(v[5] == 20);


	bDeleted = tree.Delete(15);
	assert(bDeleted);

	v = tree.TraverseInOrder(tree.GetRootNode().lock());

	assert(v.size() == 5);
	assert(v[0] == 4);
	assert(v[1] == 10);
	assert(v[2] == 12);
	assert(v[3] == 19);
	assert(v[4] == 20);

	bool bSearched = tree.Search(15);
	assert(!bSearched);

	std::cout << "Done" << std::endl;

	return 0;
}
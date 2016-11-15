#include "TreeNode.h"
#include <vector>
#include "iostream"

using namespace std;

int main(int argc, char const *argv[])
{
	int a[] = {87,93,0,13,34,80,82,0,47,88,0,79};
	vector<int> v(a, a + sizeof(a) / sizeof(int));

	cout << "---------------BFS method---------------" << endl;
	TreeNode *root1 = createTree(v);
	printTree(root1);
	cout << "---------------recursion method---------------" << endl;
	TreeNode *root2 = createTree_rec(v, 0);
	printTree(root2);
	return 0;
}
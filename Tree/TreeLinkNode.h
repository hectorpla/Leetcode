#ifndef TREELINKNODE_H
#define TREELINKNODE_H struct 

#include <vector>
#include <queue>
#include <iostream>

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void printRoot(TreeLinkNode* root);

TreeLinkNode *createTree(std::vector<int>& vec) {
	int len = vec.size();
	int pos = 0;
	TreeLinkNode *root = NULL;
	std::queue<TreeLinkNode*> q;

	if ( len && vec[0] > 0 ) root = new TreeLinkNode(vec[pos++]);
	// q.push(root);
	int left_right = 0; // 0 for left, 1 for right, 2 for next node
	TreeLinkNode* cur = root;

	while ( pos < len && cur ) {
		TreeLinkNode* newNode;
		if ( vec[pos] > 0 )
			newNode = new TreeLinkNode(vec[pos]);
		else newNode = NULL;
		pos++;

		if ( left_right == 0 )  cur->left = newNode;
		else if ( left_right == 1 ) cur->right = newNode;
		if (newNode) q.push(newNode);

		left_right++;
		if ( left_right == 2 ) {
			left_right = 0;
			if ( q.empty() ) break;
			cur = q.front();
			q.pop();
		}
	}
	return root;
 }

void printTree(TreeLinkNode* root) {
	printRoot(root);
	std::cout << std::endl;
}

void printRoot(TreeLinkNode* root) {
 	if ( !root ) return;
 	std::cout << "[";
 	printRoot(root->left);
 	std::cout << " " << root->val << " ";
 	printRoot(root->right);
 	std::cout << "]";
 }

#endif

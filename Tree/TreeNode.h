#ifndef TREENODE_H
#define TREENODE_H

#include <vector>
#include <queue>
#include <iostream>

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* find(TreeNode* root, int target);
void printTree(TreeNode* root);
void printRoot(TreeNode* root);
TreeNode *createTree(std::vector<int>& vec);


/* creating Leetcode style BT, 
 * value of each nodes should be 
 * positive 
 */

/* Using BFS */
TreeNode *createTree(std::vector<int>& vec) {
	int len = vec.size();
	int pos = 0;
	TreeNode *root = NULL;
	std::queue<TreeNode*> q;

	if ( len && vec[0] > 0 ) root = new TreeNode(vec[pos++]);
	// q.push(root);
	int left_right = 0; // 0 for left, 1 for right, 2 for next node
	TreeNode* cur = root;

	while ( pos < len && cur ) {
		TreeNode* newNode;
		if ( vec[pos] > 0 )
			newNode = new TreeNode(vec[pos]);
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

 /* Using recursion (wrong !!! the tree might not be complete) */
 TreeNode *createTree_rec(std::vector<int>& vec, int pos) {
 	if ( pos >= vec.size() || vec[pos] <= 0 ) return NULL;

 	TreeNode *root = new TreeNode(vec[pos]);
 	root->left = createTree_rec(vec, pos * 2 + 1);
 	root->right = createTree_rec(vec, pos * 2 + 2);
 	return root;
 }

TreeNode* find(TreeNode* root, int target) {
	while ( root ) {
		if ( root->val == target ) return root;
		else if ( root->val > target ) root = root->left;
		else root = root->right;
	}
	return root;
}

void printTree(TreeNode* root) {
	printRoot(root);
	std::cout << std::endl;
}

void printRoot(TreeNode* root) {
 	if ( !root ) return;
 	std::cout << "[";
 	printRoot(root->left);
 	std::cout << " " << root->val << " ";
 	printRoot(root->right);
 	std::cout << "]";
 }

#endif

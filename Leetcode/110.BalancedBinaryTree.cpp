/*
easy challenge
110. Balanced Binary Tree
link to the problem:
https://leetcode.com/problems/balanced-binary-tree
*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/

class Solution {
private:
	int heightTree(TreeNode* root)
	{
		if (!root) return (0);

		int hl = heightTree(root->left);
		int hr = heightTree(root->right);

		if (hl == -1 || hr == -1)
			return (-1);

		if (abs(hl - hr) > 1)
			return (-1);

		return (1 + max(hl , hr));
	}

public:
	bool isBalanced(TreeNode* root) {
		return (heightTree(root) != -1);
	}
};
/*
235. Lowest Common Ancestor of a Binary Search Tree
link to the problem:
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {

private:
	TreeNode *ans;
	bool has_p;
	bool has_q;

	void containPQ(TreeNode *root, int p, int q)
	{
		if (!root) return ;

		if (root->val == p)
			has_p = true;

		if (root->val == q)
			has_q = true;

		containPQ(root->left, p, q);
		containPQ(root->right, p, q);
	}

public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

		if (!root) return (ans);

		has_p = has_q = false;

		containPQ(root, p->val, q->val);

		if (has_p && has_q)
			ans = root;
		else
			return (ans);

		lowestCommonAncestor(root->left, p, q);
		lowestCommonAncestor(root->right, p, q);

		return (ans);
	}
};
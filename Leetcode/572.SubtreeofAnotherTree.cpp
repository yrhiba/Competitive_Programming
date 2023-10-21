/*
572. Subtree of Another Tree

link to the problem:
https://leetcode.com/problems/subtree-of-another-tree/
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
	bool isSameTree(TreeNode* p, TreeNode* q) {

		if (!p && !q) return (true);
		if (!p || !q) return (false);

		if (p->val != q->val) return (false);

		return (
			
			isSameTree(p->left, q->left) && isSameTree(p->right, q->right)

		);
	}
public:
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {

		if (!root) return (false);

		if (isSameTree(root, subRoot))
			return (true);

		return ( 
				isSubtree(root->left, subRoot) ||
				isSubtree(root->right, subRoot)
		);
	}
};
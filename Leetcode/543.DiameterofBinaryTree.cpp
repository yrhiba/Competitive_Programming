/*
link to the problem:
https://leetcode.com/problems/diameter-of-binary-tree
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

	int ans = 0;

	int maxDepth(TreeNode *root)
	{
		if (!root) return (0);

		int ldepth = maxDepth(root->left);
		int rdepth = maxDepth(root->right);

		ans = max(ans, ldepth + rdepth);

		return (1 + max(ldepth, rdepth));
	}
public:
	int diameterOfBinaryTree(TreeNode* root) {

		// function calculate the max depth
		// but also calculate the diameter wich store in
		// ans member
		maxDepth(root);

		return (ans);
	}
};
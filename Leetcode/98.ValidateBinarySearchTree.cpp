/*

link to the problem:
https://leetcode.com/problems/validate-binary-search-tree/
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
public:
	bool isValidBST(TreeNode* root, long long minm = 1e18, long long maxm = -1e18)
	{
		if (!root)
			return (true);
		
		if ((root->val >= minm) || (root->val <= maxm))
			return (false);

		return (isValidBST(root->left, min(minm, (long long)root->val), maxm)
			&& isValidBST(root->right, minm, max(maxm, (long long)root->val)));
	}
};

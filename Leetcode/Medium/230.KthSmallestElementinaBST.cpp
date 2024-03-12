/*

230. Kth Smallest Element in a BST

Medium

link to the problem:
https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
class Solution
{
private:

	int ans = -1, lp = 0;

	void dfs(TreeNode *it, int &k)
	{
		if (!it || ans != -1)
			return ;

		dfs(it->left, k);
		
		lp += 1;

		if (lp == k && ans == -1)
			ans = it->val;

		dfs(it->right, k);
	}

public:

	int kthSmallest(TreeNode* root, int k)
	{
		dfs(root, k);

		return (ans);
	}
};

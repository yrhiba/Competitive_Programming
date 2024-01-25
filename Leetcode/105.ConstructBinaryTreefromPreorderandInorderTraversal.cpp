/*
105. Construct Binary Tree from Preorder and Inorder Traversal

Medium

link to the problem:
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
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
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
	{
		return _buildTree(preorder, inorder, 0, preorder.size() - 1, 0);
	}

private:
	TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder,
		int left, int right, int s)
	{
		if (left == right)
			return new TreeNode(inorder[left]);

		if (left > right)
			return nullptr;

		int i = left;

		while (inorder[i] != preorder[s])
			i += 1;

		TreeNode *ans = new TreeNode(preorder[s]);

		ans->right = _buildTree(
			preorder,
			inorder,
			i + 1,
			right,
			s + (i - left + 1)
		);

		ans->left = _buildTree(
			preorder,
			inorder,
			left,
			i - 1,
			s + 1
		);

		return ans;
	}
};

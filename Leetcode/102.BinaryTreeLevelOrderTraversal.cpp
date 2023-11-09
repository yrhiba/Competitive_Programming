/*

102. Binary Tree Level Order Traversal

Medium Leetcode Problem.

link to the problem:
https://leetcode.com/problems/binary-tree-level-order-traversal

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
	vector<vector<int>> levelOrder(TreeNode* root) {

		vector< vector<int> > ans;

		if (!root)
			return ans;

		ans.reserve(2e3 + 1);

		queue< vector< TreeNode* > > q; q.push(vector<TreeNode *>(1, root));

		while (q.size())
		{
			vector< TreeNode* > t = q.back();

			vector<int> values; values.reserve(t.size() + 1);

			vector< TreeNode* > adj; adj.reserve(t.size() * 2 + 1);

			for (int i = 0; i < t.size(); i++)
			{
				values.push_back(t[i]->val);

				if (t[i]->left)		adj.push_back(t[i]->left);
				if (t[i]->right)	adj.push_back(t[i]->right);
			}

			if (adj.size())		q.push(adj);
			if (values.size())	ans.push_back(values);

			q.pop();
		}

		return (ans);
	}
};
/*
Medium Leetcode problem

link to the problem:
https://leetcode.com/problems/permutations/
*/
class Solution {

	vector< vector<int> > ans;
	vector< int > t;

	void dfs(vector<int> &nums, int x = 0)
	{
		if (x == nums.size())
		{
			ans.push_back(t);
			return ;
		}

		for (int i = x; i < nums.size(); i++)
		{
			t.push_back(nums[i]);
			swap(nums[i], nums[x]);
			dfs(nums, x + 1);
			swap(nums[i], nums[x]);
			t.pop_back();
		}
	}

public:

	vector<vector<int>> permute(vector<int>& nums) {

		dfs(nums);

		return ans;
	}
};
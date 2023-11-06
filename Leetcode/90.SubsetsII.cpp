/*
link to the problem:
https://leetcode.com/problems/subsets-ii/
*/
class Solution {

	vector<vector<int>> ans;

	vector<int> t;

	void dfs(vector<int> &nums, int i = 0)
	{
		ans.push_back(t);

		if (i >= nums.size())
			return ;

		for (int x = i; x < nums.size(); x++)
		{
			if (x < nums.size() && x > i && nums[x] == nums[x - 1])
				continue ;


			t.push_back(nums[x]);
			dfs(nums, x + 1);
			t.pop_back();
		}
	}


public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {

		sort(nums.begin(), nums.end());
		dfs(nums);
		return ans;
	}
};
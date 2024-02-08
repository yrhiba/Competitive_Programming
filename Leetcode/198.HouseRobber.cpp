/*
198. House Robber

Medium

link to the problem:
https://leetcode.com/problems/house-robber
*/
class Solution
{
private:
	int dfs(vector<int> &nums, vector<int> &dp, int i = 0)
	{
		if (i >= nums.size()) return (0);
		if (dp[i] != -1) return (dp[i]);
		return dp[i] = max(
				dfs(nums, dp, i+2) + nums[i],
			dfs(nums, dp, i+1)
		);
	}

public:
	int rob(vector<int>& nums) {
		vector<int> dp(nums.size(), -1);
		return (dfs(nums, dp));
	}
};

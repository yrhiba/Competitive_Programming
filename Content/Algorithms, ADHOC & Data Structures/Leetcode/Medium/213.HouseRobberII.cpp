/*
213. House Robber II

Medium

link to the problem:
https://leetcode.com/problems/house-robber-ii
*/
class Solution
{
private:
	int dfs(vector<int> &nums, vector<int> &dp, int i, int n)
	{
		if (i >= n) return (0);
		if (dp[i] != -1) return (dp[i]);
		return dp[i] = max(nums[i] + dfs(nums, dp, i+2, n),
			dfs(nums, dp, i+1, n));
	}

public:
	int rob(vector<int>& nums)
	{
		if (nums.size() <= 1) return nums.front();
		int n = nums.size();
		vector<int> dp1(n, -1), dp2(n, -1);
		return max(dfs(nums, dp1, 0, n-1), dfs(nums, dp2, 1, n));
	}
};

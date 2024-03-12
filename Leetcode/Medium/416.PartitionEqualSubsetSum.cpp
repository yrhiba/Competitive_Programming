/*
416. Partition Equal Subset Sum

Medium

link to the problem:
https://leetcode.com/problems/partition-equal-subset-sum/
*/
class Solution
{
private:
	map< pair<int, int> , bool >  dp;

	bool rec(vector<int> &nums, int X, int cur = 0)
	{
		if (X < 0) return false;
		if (X == 0) return true;
		if (cur >= nums.size()) return false;
		if (dp.count({X, cur})) return dp[{X, cur}];

		return dp[{X, cur}] =
			rec(nums, X - nums[cur], cur+1) 
				|| rec(nums, X, cur+1);
	}

public:
	bool canPartition(vector<int>& nums)
	{
		int totalSum = 0;

		for (int n : nums) totalSum += n;

		if (totalSum % 2) return (false);

		return rec(nums, totalSum/2, 0);
	}
};

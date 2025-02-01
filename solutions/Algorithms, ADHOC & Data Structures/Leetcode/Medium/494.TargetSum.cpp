/*
494. Target Sum

Medium

link to the problem;
https://leetcode.com/problems/target-sum
*/
class Solution
{
private:
	int n;

	map< pair<int, int>, int > dp;

	int rec(vector<int> &nums, int target, int i)
	{
		if (i >= n) return (target == 0);

		if (dp.count({target, i})) return dp[{target, i}];

		return dp[{target, i}] = (rec(nums, target - nums[i], i + 1)
			+ rec(nums, target + nums[i], i + 1));
	}

public:
	int findTargetSumWays(vector<int>& nums, int target)
	{
		n = nums.size();
		return rec(nums, target, 0);
	}
};

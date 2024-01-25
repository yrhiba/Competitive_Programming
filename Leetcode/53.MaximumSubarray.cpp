/*
53. Maximum Subarray

Medium

link to the problem:
https://leetcode.com/problems/maximum-subarray/
*/
class Solution {
public:
	int maxSubArray(vector<int>& nums)
	{
		int n = nums.size();

		int cur = nums.front();
		int ans = cur;

		for (int i = 1; i < n; i++)
		{
			cur = max(cur + nums[i], nums[i]);
			ans = max(ans, cur);
		}

		return (ans);
	}
};

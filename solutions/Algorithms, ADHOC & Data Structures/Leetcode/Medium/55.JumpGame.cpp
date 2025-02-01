/*
55. Jump Game

Medium

link to the problem:
https://leetcode.com/problems/jump-game/
*/
class Solution
{
public:
	bool canJump(vector<int>& nums)
	{
		int n = nums.size();
		int maxJ = nums[0];
		for (int i = 1; i < n; i++)
		{
			if (maxJ == 0) return (false);
			maxJ = max(maxJ-1, nums[i]);
		}
		return (true);
	}
};

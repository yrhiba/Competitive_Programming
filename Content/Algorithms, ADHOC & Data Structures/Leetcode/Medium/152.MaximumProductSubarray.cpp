/*
152. Maximum Product Subarray

Medium

link to the problem:
https://leetcode.com/problems/maximum-product-subarray/
*/
class Solution
{
private:
	int ans = 0;
	int cur = 1;
	int pfx = 1;
	int firstNeg = -1;
	bool haveAns = false;

public:
	int maxProduct(vector<int>& nums)
	{
		vector<int> p(nums.size());
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
			{
				cur = pfx = 1;
				firstNeg = -1;
				ans = max(ans, 0);
				continue;
			}
			if (nums[i] < 0) firstNeg = (firstNeg != -1) ? firstNeg : i;
			pfx *= nums[i];
			p[i] = pfx;
			cur *= nums[i];
			if (cur < 0 && (i != firstNeg)) cur /= p[firstNeg];
			if (pfx > 0) cur = pfx;
			ans = haveAns ? max(ans, cur) : cur;
			haveAns = true;
		}
		return ans;
	}
};

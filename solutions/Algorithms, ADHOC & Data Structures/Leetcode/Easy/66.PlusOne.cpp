/*
66. Plus One

Easy

link to the problem:
https://leetcode.com/problems/plus-one
*/
class Solution {
public:
	vector<int> plusOne(vector<int>& digits)
	{
		vector<int> ans; ans.reserve(digits.size()+2);
		int n = digits.size() - 1, r = 1;
		for (int i = n; i >= 0; i--)
		{
			digits[i] += r;
			ans.push_back(digits[i] % 10);
			r = digits[i]/10;
		}
		if (r) ans.push_back(r);
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

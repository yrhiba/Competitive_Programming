/*
56. Merge Intervals

Medium

link to the problem:
https://leetcode.com/problems/merge-intervals
*/
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals)
	{
		vector<vector<int>> &a = intervals;

		sort(a.begin(), a.end());

		int n = a.size();

		vector<vector<int>> ans; ans.reserve(n+1);

		ans.push_back(a[0]);

		for (int i = 1; i < n; i++)
		{
			if (a[i][0] <= ans.back()[1]) ans.back()[1] = max(ans.back()[1], a[i][1]);
			else ans.push_back(a[i]);
		}

		return (ans);
	}
};

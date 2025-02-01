/*
57. Insert Interval

Medium

link to the problem:
https://leetcode.com/problems/insert-interval
*/
class Solution {
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
	{
		int n = intervals.size();

		bool newAdd = false;

		int l = newInterval[0], r = newInterval[1];

		vector< vector<int> > ans; ans.reserve(n+2);

		for (int i = 0; i < n; i++)
		{
			if (!newAdd)
			{
				if (l > intervals[i][1])
				{
					ans.push_back(intervals[i]);
					continue;
				}

				if (intervals[i][0] > r)
					ans.push_back({l, r}), ans.push_back(intervals[i]), newAdd = true;
				else
				{
					ans.push_back({min(l, intervals[i][0]), max(r, intervals[i][1])});
					newAdd = true;
				}
			}
			else
			{
				if (intervals[i][0] <= ans.back()[1])
					ans.back()[1] = max(ans.back()[1], intervals[i][1]);
				else  ans.push_back(intervals[i]);
			}
		}

		if (!newAdd) ans.push_back({l, r});

		return ans;
	}
};

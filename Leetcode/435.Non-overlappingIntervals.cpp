/*
435. Non-overlapping Intervals

Medium

link to the problem:
https://leetcode.com/problems/non-overlapping-intervals
*/
class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals)
	{
		sort(intervals.begin(), intervals.end());

		int r = intervals[0][1], n = intervals.size();

		int ans = 0;

		for (int i = 1; i < n; i++)
		{
			if (intervals[i][0] < r)
			{
				r = min(r, intervals[i][1]);
				ans += 1;
			}
			else r = intervals[i][1];
		}

		return (ans);
	}
};

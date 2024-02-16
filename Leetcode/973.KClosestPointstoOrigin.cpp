/*
973. K Closest Points to Origin

Medium

link to the problem:
https://leetcode.com/problems/k-closest-points-to-origin/
*/
class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
	{
		int n = points.size();
		vector< pair<int, int> > dis(n);

		for (int i = 0; i < n; i++)
		{
			dis[i] = {points[i][0]*points[i][0]
						+ points[i][1]*points[i][1], i};
		}

		sort(dis.begin(), dis.end());

		vector< vector<int> > ans(k);

		for (int i = 0; i < k; i++) ans[i] = points[dis[i].second];

		return (ans);
	}
};

/*
1514. Path with Maximum Probability

Medium

link to the problem:
https://leetcode.com/problems/path-with-maximum-probability
*/
class Solution {
public:
	double
	maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node)
	{
		vector< vector< pair<double, int> > > g(n);
		int m = edges.size();

		for (int i = 0; i < m; i++)
		{
			g[edges[i][0]].push_back(make_pair(succProb[i], edges[i][1]));
			g[edges[i][1]].push_back(make_pair(succProb[i], edges[i][0]));
		}

		vector<double> ans(n, -1e12);
		ans[start_node] = 1;

		priority_queue< pair<double, int> > pq;

		for (auto &[rate, node]: g[start_node])
		{
			ans[node] = rate;
			pq.push({rate, node});
		}

		while (pq.size())
		{
			pair<double, int> cur = pq.top(); pq.pop();
			if (cur.second == end_node) continue;
			for (auto &[rate, node]: g[cur.second])
				if (cur.first*rate > ans[node])
				{
					ans[node] = cur.first*rate;
					pq.push({ans[node], node});
				}
		}

		if (ans[end_node] < 0) return 0.0;
		return (ans[end_node]);
	}
};

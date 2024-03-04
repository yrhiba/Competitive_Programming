/*
743. Network Delay Time

Medium

link to the problem:
https://leetcode.com/problems/network-delay-time
*/
class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k)
	{
		vector< vector< pair<int, int> > > g(n);
		for (auto &v : times)
		{
			v[0] -= 1;
			v[1] -= 1;
			g[v[0]].push_back({v[1], v[2]});
		}
		k -= 1;
		vector<int> cost(n, 2e9);
		vector<int> vis(n, false);
		priority_queue< vector<int> > pr;
		cost[k] = 0;
		pr.push({0, k});
		int ans = 0, reached = 0;
		while (!pr.empty())
		{
			vector<int> cur = pr.top();
			pr.pop();
			if (!vis[cur[1]])
			{
				reached += 1;
				vis[cur[1]] = true;
			}
			for (auto &[node, cst] : g[cur[1]])
			{
				if (cur[0]+cst < cost[node])
				{
					cost[node] = cur[0]+cst;
					pr.push({cost[node], node});
				}
			}
		}
		for (int i : cost) ans = max(ans, i);
		return (reached == n ? ans : -1);
	}
};

/*
839. Similar String Groups

Hard

link to the problem:
https://leetcode.com/problems/similar-string-groups/
*/
class Solution {
public:
	int numSimilarGroups(vector<string>& strs)
	{
		int n = strs.size();
		map<string, vector<string>> g;
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
			{
				if (strs[i].size() != strs[j].size()) continue;
				vector< int > differ;
				for (int x = 0; x < strs[i].size(); x++)
					if (strs[i][x] != strs[j][x]) differ.push_back(x);
				if (differ.empty()) g[strs[i]].push_back(strs[j]), g[strs[j]].push_back(strs[i]);
				if (differ.size() != 2) continue;
				if ((strs[i][differ[0]] == strs[j][differ[1]]) && (strs[i][differ[1]] == strs[j][differ[0]]))
				{
					g[strs[i]].push_back(strs[j]);
					g[strs[j]].push_back(strs[i]);
				}
			}
		//
		int ans = 0;
		map<string, bool> vis;
		for (string &s : strs)
		{
			if (vis.count(s)) continue;
			ans += 1;
			dfs(g, vis, s);
		}
		return (ans);
	}
private:
	void dfs(map<string, vector<string>> &g, map<string, bool> &vis, string &s)
	{
		vis[s] = true;
		for (string &i : g[s])
		{
			if (vis.count(i)) continue;
			dfs(g, vis, i);
		}
	}
};

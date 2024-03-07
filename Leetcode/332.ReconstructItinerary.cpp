/*
332. Reconstruct Itinerary

Hard

link to the problem:
https://leetcode.com/problems/reconstruct-itinerary/
*/
class Solution
{
private:
	int n;
	string depart = "JFK";
	//
	map<string, multiset<string>> g;
	//
	vector<string> ans;
	//
	void dfs(string &cur)
	{
		while (!g[cur].empty())
		{
			string to = *g[cur].begin();
			g[cur].erase(g[cur].begin());
			dfs(to);
		}
		ans.push_back(cur);
	}

public:
	vector<string> findItinerary(vector<vector<string>>& tickets)
	{
		for (auto &v : tickets) g[v[0]].insert(v[1]);
		//
		dfs(this->depart);
		//
		reverse(ans.begin(), ans.end());
		//
		return (ans);
	}
};

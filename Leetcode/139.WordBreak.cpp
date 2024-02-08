/*
139. Word Break

Medium

link to the problem:
https://leetcode.com/problems/word-break/
*/
class Solution
{
private:
	map<string, bool> mp;
	bool rec(string &s, vector<int> &dp, int cur)
	{
		if (cur == s.size()) return (true);
		if (dp[cur] != -1) return dp[cur];
		string x = "";
		for (int i = cur; i < s.size(); i++)
		{
			x += s[i];
			if (mp.count(x) && rec(s, dp, i+1)) return dp[cur] = true;
		}
		return dp[cur] = false;
	}

public:
	bool wordBreak(string s, vector<string>& wordDict)
	{
		for (string &x : wordDict) mp[x] = true;
		vector<int> dp(s.size(), -1);
		return rec(s, dp, 0);
	}
};

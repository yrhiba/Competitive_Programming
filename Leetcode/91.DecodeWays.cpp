/*
91. Decode Ways

link to the problem:
https://leetcode.com/problems/decode-ways
*/
class Solution
{
private:
	int rec(string &s, vector<int> &dp,  int cur, pair<int, int> last)
	{
		if (last.first < 1 || last.first > 26) return (0);
		if (last.second == 2 && last.first < 10) return (0);
		if (cur == s.size()) return (1);
		if (dp[cur] != -1) return dp[cur];
		return dp[cur] = (rec(s, dp, cur + 1, {stoi(s.substr(cur, 1)), 1})
			+ rec(s, dp, cur + 2,  {stoi(s.substr(cur, 2)), 2}));
	}

public:
	int numDecodings(string s)
	{
		vector<int> dp(s.size(), -1);
		return rec(s, dp,  0, {1, 1});
	}
};

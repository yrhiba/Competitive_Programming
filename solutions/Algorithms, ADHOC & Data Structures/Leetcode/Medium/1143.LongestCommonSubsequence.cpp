/*
1143. Longest Common Subsequence

Medium

link to the problem:
https://leetcode.com/problems/longest-common-subsequence
*/
class Solution {
private:
	vector< vector<int> > dp;

	int rec(string &s1, string &s2, int i, int j)
	{
		if (i >= s1.size() || j >= s2.size()) return (0);

		if (dp[i][j] != -1) return dp[i][j];

		if (s1[i] == s2[j]) return dp[i][j] = (1 + rec(s1, s2, i+1, j+1));
		return dp[i][j] = (max(rec(s1, s2, i+1, j), rec(s1, s2, i, j+1)));
	}

public:
	int longestCommonSubsequence(string text1, string text2)
	{
		dp = vector<vector<int>>(text1.size(), vector<int>(text2.size(), -1));
		return rec(text1, text2, 0, 0);
	}
};

/*
iterative solution O(n*m)

class Solution
{
public:
	int longestCommonSubsequence(string text1, string text2)
	{
		int n = text1.size();
		int m = text2.size();
		//
		vector< vector<int> > dp(n+1, vector<int>(m+1, -1));
		//
		for (int i = n; i >= 0; i--)
			for (int j = m; j >= 0; j--)
			{
				if (i == n || j == m) dp[i][j] = 0;
				else
				{
					if (text1[i] == text2[j]) dp[i][j] = 1 + dp[i+1][j+1];
					else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
				}
			}
		//
		return dp[0][0];
	}
};

*/
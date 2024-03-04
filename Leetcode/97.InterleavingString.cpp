/*
97. Interleaving String

Medium

link to the problem:
https://leetcode.com/problems/interleaving-string
*/
class Solution
{
private:
	bool ans = false;

	vector< vector<bool> > dp;

	void rec(string &s1, string &s2, string &s3, int i, int j, int k)
	{
		if (ans) return ;

		if (i >= s1.size() && j >= s2.size() && k >= s3.size())
		{
			ans = true;
			return ;
		}

		if (k >= s3.size())
		{
			return ;
		}

		if (dp[i][j]) return ;

		dp[i][j] = true;

		if ((i < s1.size() && s1[i] == s3[k]) && (j < s2.size() && s2[j] == s3[k]))
		{
			rec(s1, s2, s3, i+1, j, k+1);
			rec(s1, s2, s3, i, j+1, k+1);
		}
		else if (i < s1.size() && s1[i] == s3[k])
		{
			rec(s1, s2, s3, i+1, j, k+1);
		}
		else if (j < s2.size() && s2[j] == s3[k])
		{
			rec(s1, s2, s3, i, j+1, k+1);
		}
		else return ;
	}

public:
	bool isInterleave(string s1, string s2, string s3)
	{
		dp = vector<vector<bool>>(s1.size()+1, vector<bool>(s2.size()+1, false));
		rec(s1, s2, s3, 0, 0, 0);
		return ans;
	}
};

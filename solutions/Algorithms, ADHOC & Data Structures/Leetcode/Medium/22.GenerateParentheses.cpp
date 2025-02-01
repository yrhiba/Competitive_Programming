/*
medium problem
link to it:
https://leetcode.com/problems/generate-parentheses/
*/
class Solution {
private:
	void dfs(vector<string> &ans, int n, int m = 0, string gen = "")
	{
		if (n == 0 && m == 0)
		{
			ans.push_back(gen);
			return ;
		}

		if (n)
			dfs(ans, n - 1, m + 1, gen + '(');

		if (m)
			dfs(ans, n, m - 1, gen + ')');
	}
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		dfs(ans, n);
		return (ans);
	}
};
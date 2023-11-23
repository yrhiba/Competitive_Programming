/*

51. N-Queens

Hard Leetcode Problem.

link to the problem:
https://leetcode.com/problems/n-queens

*/
class Solution {

	vector< vector<string> > ans;

	vector< bool > col;
	vector< bool > diam;
	vector< bool > rdiam;

	void dfs(vector<string> &g, const int &n, int i = 0)
	{
		if (i == n)
		{
			ans.push_back(g);
			return ;
		}

		for (int j = 0; j < n; j++)
		{
			if (col[j] || diam[j - i + n] || rdiam[j + i]) continue;
			
			g[i][j] = 'Q';

			col[j] = true;
			diam[j - i + n] = true;
			rdiam[j + i] = true;

			dfs(g, n, i + 1);

			col[j] = false;
			diam[j - i + n] = false;
			rdiam[j + i] = false;

			g[i][j] = '.';
		}
	}

public:
	vector< vector<string> > solveNQueens(int n) {

		vector<string> g(n, string(n, '.'));

		col = vector<bool>(n, false);
		diam = vector<bool>(2*n, false);
		rdiam = vector<bool>(2*n, false);

		dfs(g, n);

		return ans;
	}
};
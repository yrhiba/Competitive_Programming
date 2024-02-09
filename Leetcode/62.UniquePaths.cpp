/*
62. Unique Paths

Medium

link to the problem:
https://leetcode.com/problems/unique-paths
*/
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector< vector<int> > g(m, vector<int>(n, 0));
		g[0][0] = 1;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
			{
				if (!i && !j) continue;
				if (j-1>=0) g[i][j] += g[i][j-1];
				if (i-1>=0) g[i][j] += g[i-1][j];
			}
		return (g.back().back());
	}
};

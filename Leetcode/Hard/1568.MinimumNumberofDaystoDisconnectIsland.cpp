/*

Problem Name: Minimum Number of Days to Disconnect Island (Hard).

link to the problem:
https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/

*/

int dr[] = {+1, 0, -1, 0};
int dc[] = {0, +1, 0, -1};

class Solution
{
private:
	int n, m;
	vector<vector<bool>> vis;
	vector<pair<int, int>> ones;

	int rec(vector<vector<int>> &g, int i, int j)
	{
		int count = 1;
		vis[i][j] = true;
		for (int d = 0; d < 4; d++)
		{
			int ni = i + dr[d];
			int nj = j + dc[d];
			if (ni < 0 || nj < 0 
				|| ni >= n || nj >= m
				|| !g[ni][nj]
				|| vis[ni][nj]) continue;
			count += rec(g, ni, nj);
		}
		return (count);
	}

public:
	int minDays(vector<vector<int>>& grid)
	{
		n = grid.size(), m = grid[0].size();
		vis = vector<vector<bool>>(n, vector<bool>(m, false));

		int cc = 0, count;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j])
				{
					ones.push_back({i, j});
					if (!vis[i][j])
					{
						cc += 1;
						count = rec(grid, i, j);
					}
				}
			}

		if (cc != 1) return (0);
		if (count <= 2) return (count);

		for (auto [r, c] : ones)
		{
			cc = 0;
			vis = vector<vector<bool>>(n, vector<bool>(m, false));
			grid[r][c] = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < m; j++)
					if (grid[i][j] && !vis[i][j])
					{
						if (cc) return (1);
						cc += 1;
						rec(grid, i, j);
					}
			grid[r][c] = 1;
		}

		return (2);
	}
};

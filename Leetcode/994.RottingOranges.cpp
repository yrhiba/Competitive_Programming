/*
994. Rotting Oranges

Solved

Medium

link to the problem:
https://leetcode.com/problems/rotting-oranges/
*/

class Solution
{
public:
	int orangesRotting(vector<vector<int>> &grid)
	{
		int n = grid.size();
		int m = grid[0].size();
		int dr[] = {1, -1, 0, 0};
		int dc[] = {0, 0, 1, -1};

		vector<vector<int>> time(n, vector<int>(m, -1));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (grid[i][j] == 2)
				{
					vector<vector<bool>> vis(n, vector<bool>(m, false));

					queue<int> qr, qc, qt;

					qr.push(i);
					qc.push(j);
					qt.push(0);

					vis[i][j] = true;

					while (!qr.empty() && !qc.empty() && !qt.empty())
					{
						int cr = qr.front();
						int cc = qc.front();
						int ct = qt.front();

						time[cr][cc] = (time[cr][cc] != -1) ? min(time[cr][cc], ct) : ct;

						for (int d = 0; d < 4; d++)
						{
							int nr = cr + dr[d];
							int nc = cc + dc[d];

							if (nr < 0 || nc < 0
								|| nr >= n || nc >= m)
								continue;

							if (vis[nr][nc] || !grid[nr][nc])
								continue;

							vis[nr][nc] = true;

							qr.push(nr); qc.push(nc); qt.push(ct + 1);
						}

						qr.pop(); qc.pop(); qt.pop();
					}
				}

		bool remaining_oranges; int ans = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				remaining_oranges = ((grid[i][j] == 1) && (time[i][j] == -1));
				if (remaining_oranges) break;
				ans = (time[i][j] != -1) ? max(ans, time[i][j]) : ans;
			}
			if (remaining_oranges) break;
		}
		
		if (remaining_oranges) return (-1);
		return (ans);
	}
};

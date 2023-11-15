/*

Medium

200. Number of Islands

link to the problem:
https://leetcode.com/problems/number-of-islands

*/

int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

class Solution {

private:
	void dfs(vector< vector<char> > &grid, int i, int j)
	{
		if (i < 0 || i >= grid.size()) return ;  
		if (j < 0 || j >= grid[0].size()) return ;  

		if (grid[i][j] == '0') return ;

		grid[i][j] = '0';

		for (int d = 0; d < 4; d++)
			dfs(grid, i + dr[d], j + dc[d]);
	}

public:
	int numIslands(vector<vector<char>>& grid) {
		
		int n = grid.size();
		int m = grid[0].size();

		int ans = 0;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (grid[i][j] == '0') continue;

				dfs(grid, i, j);
				ans += 1;
			}
		}
		
		return ans;
	}
};
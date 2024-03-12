/*
417. Pacific Atlantic Water Flow

Medium

link to the problem:
https://leetcode.com/problems/pacific-atlantic-water-flow/
*/

class Solution
{
private:
	int n, m;

	void dfs(vector< vector< bool > > &ans, vector<vector<int>> &h, int i, int j)
	{
		if (ans[i][j]) return ;

		ans[i][j] = true; 

		int dr[] = {1, -1, 0, 0};
		int dc[] = {0, 0, 1, -1};

		for (int d = 0; d < 4; d++)
		{
			int ni = i + dr[d];
			int nj = j + dc[d];

			if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue ;
			if (h[ni][nj] < h[i][j]) continue;
			dfs(ans, h, ni, nj);
		}
	}

public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
	{
		n = heights.size();
		m = heights[0].size();

		vector< vector< bool > > ans1(n, vector<bool>(m, false));;    
		vector< vector< bool > > ans2(n, vector<bool>(m, false));;

		// pacific ocean
		for (int i = 0; i < n; i++) dfs(ans1, heights, i, 0);
		for (int i = 0; i < m; i++) dfs(ans1, heights, 0, i);
		// atlantic ocean
		for (int i = 0; i < n; i++) dfs(ans2, heights, i, m-1);
		for (int i = 0; i < m; i++) dfs(ans2, heights, n-1, i);

		vector<vector<int>> ans;

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (ans1[i][j] && ans2[i][j]) ans.push_back({i, j});

		return ans;
	}
};

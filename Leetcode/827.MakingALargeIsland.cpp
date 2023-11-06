/*
Hard Leetcode Problem.

link to the problem:
https://leetcode.com/problems/making-a-large-island
*/

int di[] = {0, 0, -1, 1};
int dj[] = {-1, 1, 0, 0};

class Solution {

	map< pair<int, int>, set<int> > mp;
	/*
		key: points have zero 
		value: set of adjasent componets colors
	*/

	int n;

	void dfs(int i, int j, int c, vector<vector<int>> &grid,
		vector< vector<int> >   &color,
		vector< int >           &colors_size)
	{
		if (i < 0 || i >= n) return;
		if (j < 0 || j >= n) return;

		if (grid[i][j] == 0)
		{
			mp[{i, j}].insert(c);
			return ;
		}

		if (color[i][j] != -1) return; 

		color[i][j] = c;
		colors_size[c] += 1;
		for (int d = 0; d < 4; d++)
			dfs(i+di[d], j+dj[d], c, grid, color, colors_size);
	}

public:
	int largestIsland(vector<vector<int>>& grid) {

		n = grid.size();
		
		int c = 0;

		vector< vector<int> >   color(n, vector<int>(n, -1));
		vector< int >           colors_size(n*n, 0);

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 0) continue;
				if (color[i][j] != -1) continue;

				dfs(i, j, c++, grid, color, colors_size);
			}
		}

		int ans =
				*max_element(colors_size.begin(), colors_size.end());

		ans = max(ans, 1);

		for (auto &[p, st] : mp)
		{
			int t = 1;
			for (auto &i : st)
				t += colors_size[i];
			ans = max(ans, t);
		}
		return ans;
	}
};
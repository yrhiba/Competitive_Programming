/*
Problem Name: Regions Cut By Slashes (Medium Level)

problem link:
https://leetcode.com/problems/regions-cut-by-slashes/
*/
int dr[] = {+1, 0, -1, 0};
int dc[] = {0, -1, 0, +1};
char dn[] = {'d', 'l', 'u', 'r'};

class Solution
{
private:
	int n, ans = 0;
	vector<vector<vector<bool>>> vis;

	bool bad(int i, int j)
	{
		return (i < 0 || i >= n || j < 0 || j >= n);
	}

	void go(vector<string>& grid, int i, int j, int dir)
	{
		int f = 0;
		if ((grid[i][j] == ' ') && !vis[i][j][0])
			rec(grid, i, j, 0), f += 1;
		else if (grid[i][j] == '\\')
		{
			if ((dir < 0 || dn[dir] == 'u' || dn[dir] == 'r') && !vis[i][j][1])
				rec(grid, i, j, 1), f += 1;
			if ((dir < 0 || dn[dir] == 'd' || dn[dir] == 'l') && !vis[i][j][2])
				rec(grid, i, j, 2), f += 1;
		}
		else if (grid[i][j] == '/')
		{
			if ((dir < 0 || dn[dir] == 'd' || dn[dir] == 'r') && !vis[i][j][3])
				rec(grid, i, j, 3), f += 1;
			if ((dir < 0 || dn[dir] == 'u' || dn[dir] == 'l') && !vis[i][j][4])
				rec(grid, i, j, 4), f += 1;
		}
		if (dir < 0) ans += f;
	}

	void rec(vector<string>& grid, int i, int j, int k)
	{
		vis[i][j][k] = true;
		vector<int> pd;
		if (k == 0) pd = {0, 1, 2, 3};
		else if (k == 1) pd = {1, 0};
		else if (k == 2) pd = {2, 3};
		else if (k == 3) pd = {2, 1};
		else if (k == 4) pd = {0, 3};
		for (int d : pd)
		{
			int ni = i + dr[d];
			int nj = j + dc[d];
			if (bad(ni, nj)) continue;
			go(grid, ni, nj, d);
		}
	}

public:
	int regionsBySlashes(vector<string>& grid)
	{
		n = grid.size();

		vis = vector<vector<vector<bool>>>
				(n, vector<vector<bool>>(n, vector<bool>(5, false)));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) go(grid, i, j, -1);
		
		return (ans);
	}
};

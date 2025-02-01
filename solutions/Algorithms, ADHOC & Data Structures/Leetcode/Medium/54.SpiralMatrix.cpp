/*
Topics: dfs math
link to the problem:
https://leetcode.com/problems/spiral-matrix
*/

int dc[] = {+1, 0, -1, 0};
int dr[] = {0, +1, 0, -1};

class Solution
{
private:
	int n, m, visited = 101;
	vector<int> ans;

	void dfs(vector<vector<int>>& matrix, int i, int j, int dir)
	{
		ans.push_back(matrix[i][j]);
		matrix[i][j] = visited;
		//
		for (int d = 0; d < 4; d++, dir = (dir + 1)%4)
		{
			int ni = i + dr[dir];
			int nj = j + dc[dir];
			//
			if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue ;
			if (matrix[ni][nj] == visited) continue ;
			//
			dfs(matrix, ni, nj, dir);
		}
	}

public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		n = matrix.size();
		m = matrix[0].size();
		dfs(matrix, 0, 0, 0);
		return (ans);
	}
};

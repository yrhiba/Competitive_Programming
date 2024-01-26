/*
48. Rotate Image

Medium

link to the problem:
https://leetcode.com/problems/rotate-image/
*/
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {

		int n = matrix.size();

		for (int i = 0; i < (n+1)/2; i++)
		{
			int m = (n - i) - i;

			int d[4][2] = {
				{i, i},
				{i, i + m - 1},
				{i + m - 1, i + m - 1},
				{i + m - 1, i}
			};

			int dx[4][2] = {
				{0, +1},
				{+1, 0},
				{0, -1},
				{-1, 0},
			};

			for (int j = 0; j < m - 1; j++)
			{
				int t = matrix[d[3][0] + j * dx[3][0]][d[3][1] + j * dx[3][1]];

				for (int x = 0; x < 4; x++)
				{
					swap(matrix[d[x][0] + j * dx[x][0]][d[x][1] + j * dx[x][1]], t);
				}
			}
		}
	}
};

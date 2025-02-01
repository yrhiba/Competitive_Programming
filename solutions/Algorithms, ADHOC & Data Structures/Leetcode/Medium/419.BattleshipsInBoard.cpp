/*
419. Battleships in a Board

link to the problem:
https://leetcode.com/problems/battleships-in-a-board/
*/

class Solution {
public:
	int countBattleships(vector<vector<char>>& board)
	{
		int n = board.size(), m = board[0].size();
		int ans = 0;

		int dr[] = {-1, 0};
		int dc[] = {0, -1};

		for (int i = 0; i < n; i++)
			for (int j = 0, flag = 1; j < m; j++, flag = 1)
				if (board[i][j] == 'X')
				{
					for (int d = 0; d < 2; d++)
					{
						int ni = i + dr[d], nj = j + dc[d];
						//
						if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;

						if (board[ni][nj] == 'X')
						{
							flag = 0;
							break ;
						}
					}

					ans += flag;
				}


		return (ans);
	}
};

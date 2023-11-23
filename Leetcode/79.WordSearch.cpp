/*

Leetcode

79. Word Search

link to the problem:
https://leetcode.com/problems/word-search/

*/

int di[] = {0, 0, -1, 1};
int dj[] = {1, -1, 0, 0};

class Solution {

int n;
int m;

bool
dfs(const vector< vector<char> > &board, const string &word, vector< vector<bool> > &visited,  int i, int j, int cur_word_index = 0)
{
	if (cur_word_index+1 >= word.size())
		return (true);

	for (int d = 0; d < 4; d++)
	{
		int ni = i + di[d];
		int nj = j + dj[d];

		if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

		if (visited[ni][nj]) continue;

		if (board[ni][nj] == word[cur_word_index + 1])
		{
			visited[i][j] = true;
			if (dfs(board, word, visited, ni, nj, cur_word_index + 1))
				return (true);
			visited[i][j] = false;
		}
	}

	return (false);
}

public:
	bool exist(vector<vector<char>>& board, string word) {
		
		n = board.size();
		m = board[0].size();

		vector< vector<bool> > visited(n, vector<bool>(m, false));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (board[i][j] == word[0])
				{
					visited[i][j] = true;
					if (dfs(board, word, visited, i, j))
						return (true);
					visited[i][j] = false;
				}
			}

		return (false);
	}
};
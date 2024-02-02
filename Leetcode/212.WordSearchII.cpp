/*
212. Word Search II

link to the problem:
https://leetcode.com/problems/word-search-ii/
*/

/* optimized-Solution - ~610 ms */
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

struct Node {
	Node *links[26];
	bool endOfWord;
	Node()
	{
		for (int i = 0; i < 26; i++)
			links[i] = nullptr;
		endOfWord = false;
	}
};

class Solution {
private:
	vector<string> ans;
	string cur = "";
	Node *root = new Node();
	int n, m;

	void insert(string &word)
	{
		Node *it = root;
		for (char c : word)
		{
			if (it->links[c - 'a'] == nullptr)
				it->links[c - 'a'] = new Node();
			it = it->links[c - 'a'];
		}
		it->endOfWord = true;
	}

	void dfs(vector<vector<char>>& board, vector< vector<bool> > &vis, int i, int j, Node *it)
	{
		cur.push_back(board[i][j]);

		vis[i][j] = true;

		if (it->endOfWord)
		{
			it->endOfWord = false;
			ans.push_back(cur);
		}

		for (int d = 0; d < 4; d++)
		{
			int ni = i + dr[d];
			int nj = j + dc[d];

			if (ni < 0 || nj < 0 || ni >= n || nj >= m)
				continue;

			if (vis[ni][nj])
				continue;

			if (it->links[board[ni][nj] - 'a'])
				dfs(board, vis, ni, nj, it->links[board[ni][nj] - 'a']);
		}

		vis[i][j] = false;
		cur.pop_back();
	}

public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
	{
		for (string &w : words)
			insert(w);

		n = board.size();
		m = board[0].size();

		vector< vector<bool> > vis(n, vector<bool>(m, false));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
			{
				if (root->links[board[i][j] - 'a'])
					dfs(board, vis, i, j, root->links[board[i][j] - 'a']);
			}

		return (ans);
	}
};


/* First Solution - ~2100 ms */
/*
int dr[] = {1, -1, 0, 0};
int dc[] = {0, 0, 1, -1};

struct Node
{
	Node *links[26];
	Node()
	{
		for (int i = 0; i < 26; i++)
			links[i] = nullptr;
	}
};

class Solution {
private:
	int n, m;
	Node *root = new Node();
	string cur = "";

	bool search(string &word)
	{
		Node *it = root;
		for (char c : word)
		{
			if (!(it->links[c - 'a']))
				return false;
			it = it->links[c - 'a'];
		}
		return (true);
	}

	void insert(string &word)
	{
		Node *it = root;
		for (char c : word)
		{
			if (!it->links[c - 'a'])
				it->links[c - 'a'] = new Node();
			it = it->links[c - 'a'];
		}
	}

	void dfs(vector<vector<char>>& board, vector< vector<bool> > &vis, int i, int j)
	{
		if (cur.size() >= 10)
		{
			insert(cur);
			return ;
		}

		vis[i][j] = true;

		cur += board[i][j];

		bool f = false;

		for (int d = 0; d < 4; d++)
		{
			int ni = i + dr[d];
			int nj = j + dc[d];

			if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
			if (vis[ni][nj]) continue;
		
			bool f = true;

			dfs(board, vis, ni, nj);
		}

		if (f == false)
			insert(cur);

		vis[i][j] = false;
		cur.pop_back();
	}

public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
	{
		n = board.size();
		m = board[0].size();

		vector< vector<bool> > vis(n, vector<bool>(m, false));

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				dfs(board, vis, i, j);

		vector<string> ans;

		for (string &word : words)
		{
			if (search(word))
				ans.push_back(word);
		}

		return ans;
	}
};
*/

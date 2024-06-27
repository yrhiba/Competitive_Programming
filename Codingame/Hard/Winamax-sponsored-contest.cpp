/*
Hard;

link to the problem:
https://www.codingame.com/training/hard/winamax-sponsored-contest
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

char dir[] = {'>', '<', 'v', '^'};
int dr[] = {0, 0, +1, -1};
int dc[] = {+1, -1, 0, 0};
int n;
int m;

vector<string> g;
vector<string> ans;
vector<pair<int, int>> balls;

/*
(-1) can't apply this direction
(+0) allowed direction
(+1) reach a hole
(+2) for future!!!
*/
int isValid(int r, int c, int d, int dis)
{
	for (int i = 0; i < dis; i++)
	{
		r += dr[d], c += dc[d];
		if (r < 0 || r >= n || c < 0 || c >= m) return (-1);
		if (ans[r][c] != '.' || g[r][c] == 'h' 
			|| (g[r][c] != 'X' && g[r][c] != 'H' && g[r][c] != '.')) return (-1);
	}
	return ((g[r][c] == 'X' || g[r][c] == 'h') ? -1 : g[r][c] == 'H');
}

pair<int, int> updateRoad(int r, int c, int d, int dis, bool remove = false) 
{
	for (int i = 0; i < dis; i++)
	{
		ans[r][c] = remove ? '.' : dir[d];
		r += dr[d], c += dc[d];
		if ((remove && g[r][c] == 'h') || (!remove && g[r][c] == 'H'))
		{
			g[r][c] = remove ? 'H' : 'h';
			return {r, c};
		}
	}
	return {r, c};
}

void rec(int i, pair<int, int> curPos, int dis, int depth = 0)
{
	if (i >= balls.size())
	{
		for (auto &row : ans)
			cout << row << '\n';
		//
		exit(0);
	}


	int r = curPos.first;
	int c = curPos.second;

	for (int d = 0; d < 4; d++)
	{
		int dirStatus = isValid(r, c, d, dis);

		if (dirStatus == 1)
		{
			updateRoad(r, c, d, dis);

			rec(i + 1, (i+1 < balls.size() ? balls[i+1] : make_pair(0, 0)), 
			(i+1 < balls.size() ? g[balls[i+1].first][balls[i+1].second] - '0' : 0), depth + 1);
			updateRoad(r, c, d, dis, true);
		}
		else if (dirStatus == 0 && dis > 1)
		{
			rec(i, updateRoad(r, c, d, dis), dis - 1, depth + 1);
			updateRoad(r, c, d, dis, true);
		}
	}
}

int main()
{
	cin >> m >> n; cin.ignore();

	for (int i = 0; i < n; i++) {
		string row;
		cin >> row; cin.ignore();
		g.push_back(row);
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
				if (isdigit(g[i][j]))
					balls.push_back({i, j});

	ans = vector<string>(n, string(m, '.'));

	rec(0, !balls.empty() ? balls[0] : make_pair(0, 0), !balls.empty() ? g[balls[0].first][balls[0].second] - '0' : 0);
}

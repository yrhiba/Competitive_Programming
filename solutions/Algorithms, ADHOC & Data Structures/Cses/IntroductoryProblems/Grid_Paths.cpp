/*
CSES Problem Set

Grid Paths

link to the problem:
https://cses.fi/problemset/task/1625/
*/
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <fstream>
# define ull unsigned long long
# define ll long long
ll mod = 1e9 + 7;
using namespace std;

ll n = 7;

char	dch[]	= {'U', 'D', 'R', 'L'};
ll		dr[]		= {-1, +1, 0, 0};
ll		dc[]		= {0, 0, +1, -1};

bool isVisited(vector<vector<bool>> &vis, ll i, ll j)
{
	if (i < 0 || j < 0 || i >= n || j >= n) return (true);
	return (vis[i][j]);
}

ll dfs(vector<vector<bool>> &vis, string &mask, ll i, ll j, ll curIdx = 0)
{
	//
	if (curIdx == mask.size()) return ((i == n - 1) && (j == 0));
	if ((i == n - 1) && (j == 0)) return (0);
	//
	if (isVisited(vis,i+1,j) == isVisited(vis,i-1,j)
	&& isVisited(vis,i,j+1) == isVisited(vis,i,j-1)
	&& isVisited(vis,i+1,j) != isVisited(vis,i,j+1)) return (0);
	//
	if (isVisited(vis,i-1,j+1) && !isVisited(vis,i-1,j)
	&& isVisited(vis,i-1,j) == isVisited(vis,i,j+1)) return (0);
	//
	if (isVisited(vis,i+1,j+1) && !isVisited(vis,i+1,j)
	&& isVisited(vis,i+1,j) == isVisited(vis,i,j+1)) return (0);
	//
	if (isVisited(vis,i+1,j-1) && !isVisited(vis,i+1,j)
	&& isVisited(vis,i+1,j) == isVisited(vis,i,j-1)) return (0);
	//
	if (isVisited(vis,i-1,j-1) && !isVisited(vis,i-1,j)
	&& isVisited(vis,i-1,j) == isVisited(vis,i,j-1)) return (0);
	//
	ll curResult = 0;
	//
	vis[i][j] = true;
	//
	for (ll d = 0; d < 4; d++)
	{
		if (mask[curIdx] != '?' && dch[d] != mask[curIdx]) continue;
		ll ni = i + dr[d];
		ll nj = j + dc[d];
		if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
		if (vis[ni][nj]) continue;
		//
		curResult += dfs(vis, mask, ni, nj, curIdx + 1);
	}
	//
	vis[i][j] = false;
	//
	return (curResult);
}

void solve()
{
	string mask; cin >> mask;
	//
	vector<vector<bool>> vis(n, vector<bool>(n, false));
	//
	cout << dfs(vis, mask, 0, 0) << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

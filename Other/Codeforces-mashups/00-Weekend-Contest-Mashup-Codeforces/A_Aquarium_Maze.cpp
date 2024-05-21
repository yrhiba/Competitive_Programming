/*
Weekend Contest

A. Aquarium Maze

link to the problem:
find problems.pdf
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
#include <numeric>
# define ull unsigned long long
# define ll long long
const ll mod = 1e9 + 7;
using namespace std;

ll dr[] = {1, 0, 0};
ll dc[] = {0, -1, 1};

ll n, m;

ll dfs(vector<string> &g, ll i, ll j)
{
	if (i < 0 || j < 0 || i >= n || j >= m)
		return (0);

	if (g[i][j] != '.')
		return (0);

	g[i][j] = 'v';

	ll cur = 1;
	for (ll d = 0; d < 3; d++)
		cur += dfs(g, i + dr[d], j + dc[d]);

	return cur;
}

void solve()
{
	cin >> n >> m;

	vector<string> g(n);
	for (auto &s : g)
		cin >> s;

	ll ans = 0;
	for (ll i = 0; i < m; i++)
	{
		if (g[0][i] != '.') continue;
		ans += dfs(g, 0, i);
	}

	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
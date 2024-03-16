/*
link to the problem:
https://codeforces.com/contest/1948/problem/C
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

ll dr[] = {1, -1, 0, 0};
ll dc[] = {0, 0, 1, -1};

ll		n;
bool	ans;

void dfs(vector<string> &g, ll i, ll j)
{
	if (ans) return ;
	if (i < 0 || j < 0 || i >= 2 || j >= n) return ;
	if (g[i][j] == 'x') return ;
	char &c = g[i][j];
	//
	ans |= ((i == 1) && (j == (n-1)));
	j += ((g[i][j] == '>') ? +1 : -1);
	//
	c = 'x';
	//
	ans |= ((i == 1) && (j == (n-1)));
	if (ans) return ;
	//
	for (ll d = 0; d < 4; d++) dfs(g, i+dr[d], j+dc[d]);
}

void solve()
{
	ans = false;
	cin >> n;
	vector<string> g(2);
	for (auto &i : g) cin >> i;
	for (ll d = 0; d < 4; d++) dfs(g, dr[d], dc[d]);
	if (ans) cout << "YES\n";
	else cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--) solve();
}

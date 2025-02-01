/*
link to the problem:
https://cses.fi/problemset/task/1674/
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

ll dfs(vector< vector<ll> > &g, vector<ll> &ans, ll cur)
{
	if (ans[cur] != -1) return ans[cur];
	//
	ans[cur] = 0;
	//
	for (ll subOr : g[cur]) ans[cur] += dfs(g, ans, subOr);
	//
	return (1 + ans[cur]);
}

void solve()
{
	ll n; cin >> n;
	vector< vector<ll> > g(n);
	for (ll i = 1; i < n; i++)
	{
		ll t; cin >> t; t -= 1;
		g[t].push_back(i);
	}
	//
	vector<ll> ans(n, -1);
	//
	for (ll i = 0; i < n; i++)
	{
		if (ans[i] == -1) dfs(g, ans, i);
		//
		cout << ans[i] << " \n"[i+1 == n];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

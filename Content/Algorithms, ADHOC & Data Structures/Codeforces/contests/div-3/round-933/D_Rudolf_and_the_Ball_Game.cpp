/*
link to the problem:
https://codeforces.com/contest/1941/problem/D
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

ll n, m;

void rec(set<pair<ll, ll>> &dp, vector< pair<ll, char> > &a, set<ll> &ans, ll i, ll player)
{
	if (i >= m)
	{
		ans.insert(player);
		return ;
	}
	//
	if (dp.count({i, player})) return ;
	//
	dp.insert({i, player});
	//
	if (a[i].second == '?')
	{
		rec(dp, a, ans, i+1, (player + a[i].first) % n);
		rec(dp, a, ans, i+1, (player - a[i].first + n) % n);
	}
	else if (a[i].second == '0')
	{
		rec(dp, a, ans, i+1, (player + a[i].first) % n);
	}
	else if (a[i].second == '1')
	{
		rec(dp, a, ans, i+1, (player - a[i].first + n) % n);
	}
}

void solve()
{
	ll x;
	cin >> n >> m >> x;
	vector< pair<ll, char> > a(m);
	//
	for (ll i = 0; i < m; i++) 
		cin >> a[i].first >> a[i].second;
	//
	set<ll> ans;
	set<pair<ll, ll>> dp;
	//
	rec(dp, a, ans, 0, x-1);
	//
	cout << ans.size() << "\n";
	for (auto i : ans) cout << i + 1 << ' ';
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--)
		solve();
}

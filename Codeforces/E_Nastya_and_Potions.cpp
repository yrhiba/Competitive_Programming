/*

Codeforces Round 888 (Div. 3)

E. Nastya and Potions

link to the problem:
https://codeforces.com/contest/1851/problem/E

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

void calc(map<ll, ll> &dp, vector<ll> &costs, vector<bool> &haved, vector< vector<ll> > &formix, ll idx)
{
	if (dp.find(idx) != dp.end())
		return ;

	ll &ans = dp[idx];

	if (haved[idx])
	{
		ans = 0;
		return ;
	}

	if (formix[idx].empty())
	{
		ans = costs[idx];
		return ;
	}

	ll first_cost = costs[idx];
	ll second_cost = 0;
	for (auto &i : formix[idx])
	{
		calc(dp, costs, haved, formix, i);
		second_cost += dp[i];
	}
	ans = min(first_cost, second_cost);
	return ;
}

void solve()
{
	ll n, k; cin >> n >> k;
	vector<ll> costs(n);
	vector<bool> haved(n, false);
	for (ll &i : costs)
		cin >> i;
	for (ll i = 0; i < k; i++)
	{
		ll t; cin >> t; t -= 1;
		haved[t] = true;
	}
	vector< vector<ll> > formix(n);
	for (ll i = 0; i < n; i++)
	{
		ll m; cin >> m;
		if (m == 0) continue;
		vector<ll> &a = formix[i];
		a.resize(m);
		for (auto &x : a)
		{
			cin >> x;
			x -= 1;
		}
	}
	map<ll, ll> dp;
	vector<ll> ans(n, 0);
	for (ll i = 0; i < n; i++)
	{
		calc(dp, costs, haved, formix, i);
		ans[i] = dp[i];
	}
	for (ll i = 0; i < n; i++)
		cout << ans[i] << " \n"[i+1 == n];
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

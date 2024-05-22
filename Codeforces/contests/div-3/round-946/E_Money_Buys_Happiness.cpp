/*
E. Money Buys Happiness

time limit per test: 3 second
memory limit per test: 256 megabytes
input: standard input
output: standard output

link to the problem:
https://codeforces.com/contest/1974/problem/E
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

ll m, x, ans;

void rec(vector<vector<ll>> &dp, vector<pair<ll, ll>> &a, ll money, ll happines, ll i)
{
	if (money < 0) return ;

	ans = max(ans, happines);

	if ((dp[i][happines] == -1) || (dp[i][happines] < money))
	{
		dp[i][happines] = money;
	}
	else return ;

	if (i >= m) return ;

	if (i) money += x;

	rec(dp, a, money - a[i].first, happines + a[i].second, i+1);
	rec(dp, a, money, happines, i+1);
}


void solve()
{
	ans = 0;
	//
	cin >> m >> x;
	vector<pair<ll, ll>> a(m);
	ll sum = 0;
	for (auto &[c, h] : a) 
	{
		cin >> c >> h;
		sum += h;
	}
	//
	vector<vector<ll>> dp(m+1, vector<ll>(sum+1, -1));
	//
	rec(dp, a, 0, 0, 0);
	//
	cout << ans << '\n';
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

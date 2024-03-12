/*

Codeforces Round 344 (Div. 2)

B. Print Check

link to the problem:
https://codeforces.com/contest/631/problem/B

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
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
ll power(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = power(x, p/2);
	if (p%2)
		return ((res * res) * x);
	return (res * res);
}
ll gcd(ll a, ll b)
{
	if (b == 0) return (a);
	return (gcd(b, a%b));
}
ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a, b));
}

void solve()
{
	ll n, m, k; cin >> n >> m >> k;

	vector< vector<ll> > g(n, vector<ll>(m, 0));

	vector<ll> rows(max(n, m), 0);
	vector<ll> colomns(max(n, m), 0);


	vector< vector<ll> > querys(k, vector<ll>(3));
	for (ll i = 0; i < k; i++)
		for (ll j = 0; j < 3; j++)
		{
			cin >> querys[k - i - 1][j];

			if (j != 2)
				querys[k - i - 1][j] -= 1;
		}

	vector< vector<ll> > to_draw; to_draw.reserve(k);

	for (ll i = 0; i < k; i++)
	{
		if (querys[i].front())
		{
			if (rows[querys[i][1]]) continue;
			rows[querys[i][1]] = querys[i][2];
			to_draw.push_back(querys[i]);
		}
		else
		{
			if (colomns[querys[i][1]]) continue;
			colomns[querys[i][1]] = querys[i][2];
			to_draw.push_back(querys[i]);
		}
	}

	for (auto &v : to_draw)
	{
		if (v.front())
		{
			for (ll i = 0; i < n; i++)
			{
				if (g[i][v[1]]) continue;
				g[i][v[1]] = v[2];
			}
		}
		else
		{
			for (ll i = 0; i < m; i++)
			{
				if (g[v[1]][i]) continue;
				g[v[1]][i] = v[2];
			}
		}
	}

	for (auto &i : g)
	{
		for (auto &j : i)
			cout << j <<  " ";
		cout << "\n";
	}
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

/*
link to the problem:
https://codeforces.com/contest/1800/problem/E2
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


void dfs(vector<ll> &color, ll i, ll n, ll k, ll c, vector< map<char, ll> > &repo, string &s)
{
	if (i >= n || i < 0) return ;

	if (color[i] != -1) return ;

	color[i] = c;

	repo[c][s[i]] += 1;

	dfs(color, i+k, n, k, c, repo, s);
	dfs(color, i+k+1, n, k, c, repo, s);
	dfs(color, i-k, n, k, c, repo, s);
	dfs(color, i-k-1, n, k, c, repo, s);
}

void solve()
{
	ll n, k; cin >> n >> k;

	vector<ll> color(n, -1);

	string s; cin >> s;
	string x; cin >> x;

	vector< map<char, ll> > repo(n);

	ll c = 0;
	for (ll i = 0; i < n; i++)
	{
		if (color[i] == -1)
			dfs(color, i, n, k, c++, repo, s);

		if (repo[color[i]][x[i]] > 0)
		{
			repo[color[i]][x[i]] -= 1;
		}
		else
		{
			cout << "NO\n";
			return ;
		}
	}

	cout << "YES\n";
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

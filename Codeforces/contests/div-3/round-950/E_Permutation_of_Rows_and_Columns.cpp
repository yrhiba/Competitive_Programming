/*

Codeforces Round 950 (Div. 3)

E. Permutation of Rows and Columns

time limit per test: 3 second
memory limit per test: 256 megabytes
input: standard input
output: standard output

link to the problem:
https://codeforces.com/contest/1980/problem/E

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

# define ll long long

using namespace std;

void solve()
{
	ll n, m; cin >> n >> m;
	vector<vector<ll>> a(n, vector<ll>(m));
	vector<vector<ll>> b(n, vector<ll>(m));
	map<ll, pair<ll, ll>> mp;
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
		{
			cin >> a[i][j];
			mp[a[i][j]] = {i, j};
		}
	//
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++) cin >> b[i][j];
	//
	vector<ll> r(n), c(m);
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
		{
			ll x = mp[b[i][j]].first;
			ll y = mp[b[i][j]].second;
			//
			r[i] = x, c[j] = y;
		}
	//
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			if (a[r[i]][c[j]] != b[i][j])
			{
				cout << "NO\n";
				return ;
			}
	//
	cout << "YES\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--) solve();
}

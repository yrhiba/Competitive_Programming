/*
link to the problem:
https://codeforces.com/contest/1941/problem/A
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

void solve()
{
	ll n, m, k; cin >> n >> m >> k;
	vector<ll> a(n);
	vector<ll> b(m);
	for (ll &i : a) cin >> i;
	for (ll &i : b) cin >> i;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	ll ans = 0;
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			if (a[i] + b[j] <= k) ans += 1;
	//
	cout << ans << "\n";
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

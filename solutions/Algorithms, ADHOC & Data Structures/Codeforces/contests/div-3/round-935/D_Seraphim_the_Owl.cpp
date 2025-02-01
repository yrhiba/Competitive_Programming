/*
link to the problem:
https://codeforces.com/contest/1945/problem/D
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
	ll n, m; cin >> n >> m;
	vector<ll> a(n), b(n);
	for (ll &i : a) cin >> i;
	for (ll &i : b) cin >> i;
	vector<ll> p(n);
	for (ll i = 0; i < n; i++) p[i] = min(a[i], b[i]) + (((i-1)>=0)?p[i-1]:0);
	ll ans = 1e18;
	for (ll i = 0; i < m; i++)
		ans = min(ans, (p[n-1] - p[i]) + a[i]);
	//
	cout << ans << "\n";
}

int main()
{
	cin.tie()->sync_with_stdio(false);
	ll t; cin >> t;
	while (t--)
		solve();
}

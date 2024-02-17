/*
A. Maximise The Score

link to the problem:
https://codeforces.com/contest/1930/problem/A
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
# define ull unsigned long long
# define ll long long
const ll mod = 1e9 + 7;
using namespace std;

void solve()
{
	ll n; cin >> n; n*=2;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a.rbegin(), a.rend());
	ll ans = 0;
	for (ll i = 1; i < n; i+=2)
		ans += a[i];
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

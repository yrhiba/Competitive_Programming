/*
B. Chaya Calendar

link to the problem:
https://codeforces.com/contest/1932/problem/B
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
	ll n; cin >> n;
	vector<ll> a(n);
	for (ll &i : a) cin >> i;
	ll ans = a[0];
	for (ll i = 1; i < n; i++)
	{
		if (a[i] > ans) ans = a[i];
		else ans = a[i]*((ans+a[i])/a[i]);
	}
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

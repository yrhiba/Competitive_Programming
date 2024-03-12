/*
D. Divisible Pairs

link to the problem:
https://codeforces.com/contest/1931/problem/D
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
	ll n, x, y; cin >> n >> x >> y;
	vector<ll> a(n);
	map< pair<ll, ll>, ll > X;
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		ans += X.count({(x - (a[i]%x))%x, a[i]%y})
			? X[{(x - (a[i]%x))%x, a[i]%y}] : 0;
		X[{a[i]%x, a[i]%y}] += 1;
	}
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--) solve();
}

/*
D. Vlad and Division

link to the problem:
https://codeforces.com/contest/1926/problem/D
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
	map<ll, ll> mp;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		mp[a[i]] += 1;
	}
	ll ans = n;
	for (ll i = 0; i < n; i++)
	{
		if (!mp[a[i]]) continue;
		ll t = a[i], rt = 0;
		for (ll j = 0; j < 31; j++)
		{
			rt += ((t%2)?0:1) * (1<<j);
			t /= 2;
		}
		if (mp[rt])
		{
			ans -= 1;
			mp[rt] -= 1;
			mp[a[i]] -= 1;
		}
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

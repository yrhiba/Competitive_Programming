/*
link to the problem:
https://codeforces.com/contest/1946/problem/B
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
	ll n, k; cin >> n >> k;
	//
	ll ans = 0, cur = 0, sum = 0;
	for (ll i = 0; i < n; i++)
	{
		ll t; cin >> t;
		cur = max(cur+t, t);
		ans = max(ans, cur);
		sum += (t%mod);
		if (sum < 0) sum += (3 * mod);
		sum %= mod;
	}
	//
	for (ll i = 0; i < k; i++)
	{
		sum += ans%mod;
		if (sum < 0) sum += (3 * mod);
		sum %= mod;
		//
		ans += (ans%mod);
		ans %= mod;
	}
	//
	cout << sum << "\n";
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

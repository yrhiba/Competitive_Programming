/*
link to the problem:
https://codeforces.com/contest/1941/problem/B
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
	ll n; cin >> n;
	vector<ll> a(n);
	for (ll &i : a) cin >> i;
	//
	for (ll i = 1; i+1 < n; i++)
	{
		ll left = a[i-1];
		ll right = a[i+1];
		ll cur = a[i]/2;
		//
		a[i-1] -= min({left, right, cur});
		a[i] -= 2 * min({left, right, cur});
		a[i+1] -= min({left, right, cur});
	}
	for (ll &i : a)
		if (i)
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
	while (t--)
		solve();
}

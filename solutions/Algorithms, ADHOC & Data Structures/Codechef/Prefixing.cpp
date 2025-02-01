/*

Starters 111 (Rated till 6 Stars)

Prefixing

link to the problem:
https://www.codechef.com/problems/FIX

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
	map<ll, bool> mp;
	vector<ll> f(n, 0);

	ll maxe = -1;

	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];

		maxe = max(maxe, a[i]);

		if (mp.count(a[i]))
			f[i] = 1;

		mp[a[i]] = true;
	}

	for (ll i = 0; i < n; i++)
	{
		if (f[i])	a[i] = maxe;
	}

	for (ll i = 0; i < n; i++)
		cout << a[i] << " \n"[i + 1 == n];
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


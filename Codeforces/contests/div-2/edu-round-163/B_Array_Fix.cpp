/*
link to the problem:
https://codeforces.com/contest/1948/problem/B
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
	reverse(a.begin(), a.end());
	for (ll i = 1; i < n; i++)
	{
		if (a[i] <= a[i-1]) continue;
		else
		{
			ll x = a[i] / 10, y = a[i] % 10;
			//
			if ((a[i] < 10) || (y < x) || (y > a[i-1]))
			{
				cout << "NO\n";
				return ;
			}
			a[i] = x;
		}
	}
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

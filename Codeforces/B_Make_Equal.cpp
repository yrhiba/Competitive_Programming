/*
B. Make Equal

link to the problem:
https://codeforces.com/contest/1931/problem/B
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
	ll p = 0;
	vector<ll> a(n); for (ll &i : a) cin >> i, p += i;
	ll cur = 0, x = p/n;
	for (ll i = 0; i < n; i++)
	{
		if (a[i] > x) cur += a[i]-x;
		else if (a[i] < x) cur -= (x-a[i]);
		if (cur < 0)
		{
			cout << "NO\n";
			return ;
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

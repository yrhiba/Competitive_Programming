/*
link to the problem:
https://codeforces.com/contest/1829/problem/C
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
	ll a = 1e18, b = 1e18, c = 1e18;
	for (ll i = 0; i < n; i++)
	{
		ll t; cin >> t;
		string s; cin >> s;
		if (s == "00") continue;
		else if (s == "01")
		{
			if (t < a) a = t;
		}
		else if (s == "10")
		{
			if (t < b) b = t;
		}
		else if (s == "11")
		{
			if (t < c) c = t;
		}
	}
	if ((c == 1e18))
	{
		if (a == 1e18 || b == 1e18)
			cout << "-1\n";
		else
			cout << a + b << "\n";
	}
	else
	{
		if (a == 1e18 || b == 1e18)
			cout << c << "\n";
		else
			cout << min(a + b, c) << "\n";
	}
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

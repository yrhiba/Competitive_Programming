/*

Minimum XOR

Starters 109 Division 3

link to the problem:
https://www.codechef.com/problems/MINMXOR

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

# define ll long long

using namespace std;

void solve()
{
	ll n; cin >> n;

	vector<ll> a(n);
	vector<ll> p(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];

		if (i)
			p[i] = (a[i] ^ p[i - 1]);
		else
			p[i] = a[i];
	}

	if (n == 1)
	{
		cout << 0 << "\n";
		return ;
	}

	ll ans = p.back();

	for (ll i = 0; i < n; i++)
	{
		ll t = -1;

		if (i == 0)
		{
			t = p.back() ^ p.front();
		}
		else if (i == n - 1)
		{
			t = p[i-1];
		}
		else
		{
			t = p[i - 1] ^ p[n - 1] ^ p[i];
		}

		ans = min(ans, t);
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

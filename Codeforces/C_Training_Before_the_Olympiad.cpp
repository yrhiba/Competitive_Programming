/*

C. Training Before the Olympiad

Good Bye 2023

link to the problem:
https://codeforces.com/contest/1916/problem/C

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

ll calc(ll odds, ll evens)
{
	static map<pair<ll, ll>, ll> dp;

	if (dp.count({odds, evens})) return (dp[{odds, evens}]);

	ll &ans = dp[{odds, evens}];
	ll cost = 0;

	if (odds + evens == 1)
		return (ans = cost);

	// first player turn
	{
		if (odds >= 2)
		{
			odds -= 2;
			evens += 1;
		}
		else if (evens >= 2)
		{
			evens -= 1;
		}
		else
		{
			odds -= 1;
			cost += 1;
		}
	}

	if (odds + evens == 1)
		return (ans = cost);

	// second player turn
	{
		if (odds > 0 && evens > 0)
		{
			odds -= 1;
			cost += 1;
		}
		else if (evens >= 2)
		{
			evens -= 1;
		}
		else
		{
			odds -= 1;
		}
	}

	return (ans = (cost + calc(odds, (evens > 0))));
}

void solve()
{
	ll n; cin >> n;
	vector<ll> odds(n+1, 0);
	vector<ll> evens(n+1, 0);
	vector<ll> a(n+1, 0);
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		odds[i] = ((a[i]%2) + odds[i-1]);
		evens[i] = (!(a[i]%2) + evens[i-1]);
		a[i] += a[i-1];
		cout << a[i] - calc(odds[i], (evens[i] > 0)) << " \n"[i==n];
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

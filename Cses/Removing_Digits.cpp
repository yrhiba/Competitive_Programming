/*

CSES Problem Set

Removing Digits

link to the problem:
https://cses.fi/problemset/task/1637

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

	vector<ll> dp(n+1, 0);

	for (ll i = 0; i <= n; i++)
	{
		ll cur = i;

		while (cur)
		{
			if (cur%10)
			{
				if (!dp[i])
				{
					dp[i] = 1 + dp[i - cur%10];
				}
				else
				{
					dp[i] = min(dp[i], 1 + dp[i - cur%10]);
				}
			}
			cur /= 10;
		}
	}

	cout << dp[n] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

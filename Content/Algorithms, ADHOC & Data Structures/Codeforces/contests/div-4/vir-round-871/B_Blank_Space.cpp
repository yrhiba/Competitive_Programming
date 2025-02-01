/*
link to the problem:
https://codeforces.com/contest/1829/problem/B
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
	ll cur = 0, ans = 0;
	ll n; cin >> n;
	for (ll i = 0; i < n; i++)
	{
		ll t; cin >> t;
		if (t == 0)
		{
			cur += 1;
			ans = max(ans, cur);
		}
		else
		{
			cur = 0;
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

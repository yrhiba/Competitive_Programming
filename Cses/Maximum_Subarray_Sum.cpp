/*
CSES Problem Set

Maximum Subarray Sum

link to the problem:
https://cses.fi/problemset/task/1643
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
	ll cur; cin >> cur;
	ll ans = cur;
	n -= 1;
	for (ll i = 0; i < n; i++)
	{
		ll t; cin >> t;
		cur = max(cur + t, t);
		ans = max(ans, cur);
	}
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

/*

AtCoder Beginner Contest 332

A - Online Shopping

link to the problem:
https://atcoder.jp/contests/abc332/tasks/abc332_a

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
	ll n, s, k; cin >> n >> s >> k;

	ll ans = 0;

	for (ll i = 0; i < n; i++)
	{
		ll p, q; cin >> p >> q;
		ans += (p*q);
	}

	if (ans < s)
		ans += k;

	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

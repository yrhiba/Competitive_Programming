/*
CSES Problem Set

Range Xor Queries

link to the problem:
https://cses.fi/problemset/task/1650/
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
# define ll long long
const ll mod = 1e9 + 7;
using namespace std;

void solve()
{
	ll n, q; cin >> n >> q;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		if (i)
			a[i] ^= a[i - 1];
	}

	while (q--)
	{
		ll x, y; cin >> x >> y;	x--, y--;

		if (x)
			cout << (a[y] ^ a[x - 1]) << "\n";
		else
			cout << a[y] << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

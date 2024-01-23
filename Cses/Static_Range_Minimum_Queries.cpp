/*
CSES Problem Set

Static Range Minimum Queries

link to the problem:
https://cses.fi/problemset/task/1647/
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

ll log2(ll n)
{
	int lg2 = 0;
	while (n)
	{
		lg2 += 1;
		n /= 2;
	}
	return (lg2);
}

void solve()
{
	ll n, q; cin >> n >> q;

	vector<ll> a(n);

	ll lg2 = log2(n);
	ll sparce_table[lg2][n];

	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		sparce_table[0][i] = a[i];
	}

	for (ll j = 1; j < lg2; j++)
	{
		for (ll i = 0; (i + (1<<j) - 1) < n; i++)
		{
			sparce_table[j][i]
				= min(sparce_table[j - 1][i], sparce_table[j - 1][i + (1<<(j-1))]);
		}
	}

	while (q--)
	{
		ll l, r; cin >> l >> r;

		l -= 1;
		r -= 1;

		ll len = r - l + 1;
		ll x = 0;
		for (int i = 63; i >= 0; i--)
			if (((1l<<i) & len) > 0)
			{
				x = i;
				break;
			}

		cout << min(sparce_table[x][l], sparce_table[x][r - (1<<x) + 1]) << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

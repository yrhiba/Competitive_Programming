/*
CSES Problem Set

Sum of Two Values

link to the problem:
https://cses.fi/problemset/task/1640
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
	ll n, x; cin >> n >> x;

	map<ll, ll> mp;

	for (ll i = 1; i <= n; i++)
	{
		ll y; cin >> y;

		if (mp.count(x - y))
		{
			cout << mp[x - y] << " " << i << endl;
			return ;
		}

		mp[y] = i;
	}

	cout << "IMPOSSIBLE" << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

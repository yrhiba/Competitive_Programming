/*

CSES Problem Set

Grid Paths

link to the problem:
https://cses.fi/problemset/task/1638

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
	ll n; cin >> n;

	vector<string> g(n);
	for (auto &l : g)
		cin >> l;

	if (g[0][0] == '*')
	{
		cout << 0 << "\n";
		return ;
	}

	vector< vector<ll> > a(n, vector<ll>(n, 0));

	a[0][0] = 1;
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < n; j++)
		{
			if (g[i][j] == '*')
				continue;

			if (i - 1 >= 0)
				a[i][j] += a[i-1][j], a[i][j] %= mod;

			if (j - 1 >= 0)
				a[i][j] += a[i][j-1], a[i][j] %= mod;
		}

	cout << a[n-1][n-1] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

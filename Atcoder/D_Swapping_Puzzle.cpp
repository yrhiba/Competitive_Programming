/*

AtCoder Beginner Contest 332

D - Swapping Puzzle

link to the problem:
https://atcoder.jp/contests/abc332/tasks/abc332_d

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
	ll h, w; cin >> h >> w;

	vector< vector<ll> > g(h, vector<ll>(w));
	for (ll i = 0; i < h; i++)
		for (ll j = 0; j < w; j++)
			cin >> g[i][j];

	vector< vector<ll> > a(h, vector<ll>(w));
	for (ll i = 0; i < h; i++)
		for (ll j = 0; j < w; j++)
			cin >> a[i][j];


	vector<ll> rows(h);
	for (ll i = 0; i < h; i++)
		rows[i] = i;

	vector<ll> cols(w);

	ll ans = -1;

	do
	{
		for (ll i = 0; i < w; i++)
			cols[i] = i;

		do
		{
			bool f = true;
			for (ll i = 0; i < h; i++)
			{
				for (ll j = 0; j < w; j++)
					if (g[i][j] != a[rows[i]][cols[j]])
					{
						f = false;
						break;
					}
				if (!f)	break;
			}

			if (f)
			{
				vector<ll> ans_rows(rows.begin(), rows.end());
				vector<ll> ans_cols(cols.begin(), cols.end());

				ll cost = 0;

				for (ll r = 1; r < h; r++)
				{
					ll x = r;
					while (x-1 >= 0 && ans_rows[x] < ans_rows[x - 1])
					{
						swap(ans_rows[x], ans_rows[x - 1]);
						x -= 1;
						cost += 1;
					}
				}

				for (ll c = 1; c < w; c++)
				{
					ll x = c;
					while (x-1 >= 0 && ans_cols[x] < ans_cols[x - 1])
					{
						swap(ans_cols[x], ans_cols[x - 1]);
						x -= 1;
						cost += 1;
					}
				}

				if (ans == -1)
					ans = cost;
				else
					ans = min(ans, cost);
			}

		} while (next_permutation(cols.begin(), cols.end()));

	} while (next_permutation(rows.begin(), rows.end()));


	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

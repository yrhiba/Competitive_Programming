/*

Codeforces Round 914 (Div. 2)

C. Array Game

link to the problem:
https://codeforces.com/contest/1904/problem/C

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
	ll n, k; cin >> n >> k;

	vector<ll> a(n);
	ll mmin = 1e18;
	for (auto &i : a)
	{
		cin >> i;
		mmin = min(mmin, i);
	}

	ll ans = mmin;

	if (k == 1)
	{
		for (ll i = 0; i < n; i++)
			for (ll j = i + 1; j < n; j++)
				ans = min(ans, abs(a[j] - a[i]));
		cout << ans << endl;
	}
	else
	if (k == 2)
	{
		vector<ll> b(a.begin(), a.end());

		sort(b.begin(), b.end());

		for (ll i = 0; i < n; i++)
			for (ll j = i + 1; j < n; j++)
			{
				ll cur = abs(a[i] - a[j]);
	
				ll start = 0;
				ll end = n - 1, mid, r = -1, f = -1;
				while (start <= end)
				{
					mid = start + (end - start) / 2;

					if (b[mid] <= cur)
					{
						if (r = -1)
							r = b[mid];
						else
							r = min(r, b[mid]);

						start = mid + 1;
					}
					else
					{
						end = mid - 1;
					}
				}
				start = 0; end = n - 1;
				while (start <= end)
				{
					mid = start + (end - start) / 2;

					if (b[mid] >= cur)
					{
						if (f = -1)
							f = b[mid];
						else
							f = min(f, b[mid]);

						end = mid - 1;
					}
					else
					{
						start = mid + 1;
					}
				}

				ans = min(ans, cur);
				ans = min(ans, abs(cur - r));
				ans = min(ans, abs(cur - f));
			}

		cout << ans << "\n";
	}
	else
	{
		cout << 0 << "\n";
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

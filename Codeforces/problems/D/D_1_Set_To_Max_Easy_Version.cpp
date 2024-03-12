/*

Codeforces Round 914 (Div. 2)

D1. Set To Max (Easy Version)

link to the problem:
https://codeforces.com/contest/1904/problem/D1

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
	ll n; cin >> n;

	vector<ll> a(n);
	for (auto &i : a)
			cin >> i;
	vector<ll> b(n);
	for (auto &i : b)
		cin >> i;

	vector< pair< pair<ll, ll> , pair<ll, ll> > > sections;

	for (ll i = 0; i < n; )
	{
		ll j = i;
		ll maxe = a[j];
		while (j < n && b[i] == b[j])
		{
			maxe = max(maxe, a[j]);
			j++;
		}

		sections.push_back(make_pair(make_pair(b[i], maxe), make_pair(i, j - 1)));

		i = j;
	}

	sort(sections.begin(), sections.end());

	for (auto &[i, j] : sections)
	{
		ll target_value = i.first;
		ll max_value = i.second;

		if (max_value == target_value)
		{
			continue;
		}
		else
		if (max_value > target_value)
		{
			cout << "NO\n";
			return ;
		}
		else
		if (max_value < target_value)
		{
			ll		x;
			bool	f;

			x			= j.second+1;
			f			= false;

			while (x < n)
			{
				if (a[x] > target_value || b[x] < target_value)
					break;

				if (a[x] == target_value)
				{
					f = true;
					break;
				}

				a[x] = target_value;

				x += 1;
			}

			if (f) continue;

			x	= j.first-1;

			while (x >= 0)
			{
				if (a[x] > target_value || b[x] < target_value)
					break;

				if (a[x] == target_value)
				{
					f = true;
					break;
				}

				a[x] = target_value;

				x -= 1;
			}

			if (!f)
			{
				cout << "NO\n";
				return ;
			}
		}
	}

	cout << "YES\n";
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

/*

Codeforces Round 913 (Div. 3)

D. Jumping Through Segments

link to the problem:
https://codeforces.com/contest/1907/problem/D

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


bool good(vector< pair<ll, ll> > &seg, ll k)
{
	ll cur_pos = 0;
	if (cur_pos + k < seg[0].first)
		return false;

	ll min_pos = seg[0].first, max_pos = min(seg[0].second, cur_pos + k);

	for (ll i = 1; i < seg.size(); i++)
	{
		ll min_m = min_pos - k;
		ll max_m = max_pos + k;

		if (min_m > seg[i].second)
			return false;

		if (max_m < seg[i].first)
			return false;

		if (min_m <= seg[i].first)
			min_pos = seg[i].first;
		else
			min_pos = min_m;

		if (max_m >= seg[i].second)
			max_pos = seg[i].second;
		else
			max_pos = max_m;
	}
	return (true);
}

void solve()
{
	ll n;
	cin >> n;

	vector< pair<ll, ll> > seg(n);
	for (ll i = 0; i < n; i++)
		cin >> seg[i].first >> seg[i].second;

	ll start = 0;
	ll end = 1e9;
	ll mid, k = -1;

	while (start <= end)
	{
		mid = start + ((end - start) / 2);

		if (good(seg, mid))
		{
			end = mid - 1;
			k = mid;
		}
		else
		{
			start = mid + 1;
		}
	}

	cout << k << "\n";
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

/*
CSES Problem Set

Dynamic Range Minimum Queries

link to the problem:
https://cses.fi/problemset/task/1649/
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
using namespace std;

void setup(vector<ll> &s, vector<ll> &a, ll left, ll right, ll cur = 0)
{
	if (left == right)
	{
		s[cur] = a[left];
		return ;
	}
	ll mid = (left + right) / 2;
	setup(s, a, left, mid, cur * 2 + 1);
	setup(s, a, mid + 1, right, cur * 2 + 2);
	s[cur] = min(s[cur * 2 + 1], s[cur * 2 + 2]);
}

void update(vector<ll> &s, ll index, ll value, ll left, ll right, ll cur = 0)
{
	if (right == left)
	{
		s[cur] = value;
		return ;
	}
	ll mid = (left + right) / 2;
	if (index <= mid)
		update(s, index, value, left, mid, cur * 2 + 1);
	else
		update(s, index, value, mid + 1, right, cur * 2 + 2);
	s[cur] = min(s[cur * 2 + 1], s[cur * 2 + 2]);
}

ll query(vector<ll> &s, ll qleft, ll qright, ll left, ll right, ll cur = 0)
{
	if (qleft <= left && right <= qright)
	{
		return (s[cur]);
	}
	if (qleft > right || left > qright)
	{
		return 1e9;
	}
	ll mid = (left + right) / 2;
	return	min(
		query(s, qleft, qright, left, mid, cur * 2 + 1),
		query(s, qleft, qright, mid + 1, right, cur * 2 + 2)
	);
}

void solve()
{
	ll n, q; cin >> n >> q;
	vector<ll> a(n);
	for (auto &i : a)
		cin >> i;

	vector<ll> s(n*4);

	setup(s, a, 0, n - 1);

	while (q--)
	{
		ll t, x, y;
		cin >> t >> x >> y;

		if (t == 1) update(s, x - 1, y, 0, n - 1);
		else
		{
			cout << query(s, x - 1, y - 1, 0, n - 1) << "\n";
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

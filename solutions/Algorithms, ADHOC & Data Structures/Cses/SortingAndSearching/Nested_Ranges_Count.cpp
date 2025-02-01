/*
CSES Problem Set

Nested Ranges Count

link to the problem:
https://cses.fi/problemset/task/2169/
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

bool comp_one(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
	if (a.first != b.first) return a.first < b.first;
	return a.second > b.second;
}

bool comp_two(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
	if (a.second != b.second) return a.second < b.second;
	return a.first > b.first;
}

void update(vector<ll> &seg, ll idx, ll value, ll left, ll right, ll cur)
{
	if (left == right)
	{
		if (left == idx) seg[cur] += value;
		return ;
	}
	if (idx < left || idx > right) return ;
	ll mid = left + (right - left) / 2;
	update(seg, idx, value, left, mid, cur*2+1);
	update(seg, idx, value, mid+1, right, cur*2+2);
	seg[cur] = seg[cur*2+1] + seg[cur*2+2];
}

ll query(vector<ll> &seg, ll ql, ll qr, ll left, ll right, ll cur)
{
	if (ql <= left && right <= qr) return seg[cur];
	if (ql > right || qr < left) return (0);
	ll mid = left + (right - left) / 2;
	return (query(seg, ql, qr, left, mid, cur*2+1)
		+ query(seg, ql, qr, mid+1, right, cur*2+2));
}

void solve()
{
	ll n, idx = 0; cin >> n;
	vector<pair<ll, ll>> a(n);
	map<pair<ll, ll>, ll> mp;
	for (auto &[i, j] : a) cin >> i >> j;
	//
	vector<vector<ll>> af(n, vector<ll>(3)), as(n, vector<ll>(3));
	for (ll i = 0; i < n; i++)
	{
		af[i] = {a[i].first, i, a[i].first};
		as[i] = {a[i].second, i, a[i].second};
	}
	//
	sort(af.begin(), af.end());
	sort(as.begin(), as.end());
	for (ll i = 0; i < n; i++)
	{
		if (i && af[i][0] == af[i-1][2]) af[i][0] = af[i-1][1];
		else af[i][0] = i;
		//
		if (i && as[i][0] == as[i-1][2]) as[i][0] = as[i-1][1];
		else as[i][0] = i;
		//
		swap(af[i][0], af[i][1]);
		swap(as[i][0], as[i][1]);
	}
	//
	sort(af.begin(), af.end());
	sort(as.begin(), as.end());
	//
	for (ll i = 0; i < n; i++)
	{
		a[i] = {af[i][1], as[i][1]};
		mp[a[i]] = idx++;
	}
	//
	vector<ll> ans1(n, 0), ans2(n, 0), seg;
	sort(a.begin(), a.end(), comp_one);
	seg = vector<ll>((n+1) * 4, 0);
	for (auto &[i, j] : a)
	{
		ans1[mp[{i, j}]] = query(seg, j, n, 0, n, 0);
		update(seg, j, 1, 0, n, 0);
	}
	sort(a.begin(), a.end(), comp_two);
	seg = vector<ll>((n+1)*4, 0);
	for (auto &[i, j] : a)
	{
		ans2[mp[{i, j}]] = query(seg, i, n, 0, n, 0);
		update(seg, i, 1, 0, n, 0);
	}
	//
	for (ll i = 0; i < n; i++)
		cout << ans2[i] << " \n"[i+1 == n];
	//
	for (ll i = 0; i < n; i++)
		cout << ans1[i] << " \n"[i+1 == n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

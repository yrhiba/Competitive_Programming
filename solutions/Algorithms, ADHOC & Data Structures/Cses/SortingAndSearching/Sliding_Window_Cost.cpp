/*
CSES Problem Set

Sliding Window Cost

link to the problem:
https://cses.fi/problemset/task/1077
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

pair<ll, ll> operator+(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
	return make_pair(a.first + b.first, a.second + b.second);
}

void update(vector<pair<ll, ll>> &seg, ll idx, ll value, ll left, ll right, ll cur)
{
	if (left == right)
	{
		if (left == idx)
		{
			seg[cur].first += value;
			seg[cur].second = (seg[cur].first > 0);
		}
		return ;
	}
	if (idx < left || idx > right) return ;
	ll mid = left + (right - left) / 2;
	update(seg, idx, value, left, mid, cur*2+1);
	update(seg, idx, value, mid+1, right, cur*2+2);
	seg[cur] = seg[cur*2+1] + seg[cur*2+2];
}

pair<ll, ll> getIndex(vector<pair<ll, ll>> &seg, ll idx, ll left, ll right, ll cur)
{
	if (left == right) return make_pair(seg[cur].first, left);
	ll mid = left + (right - left) / 2;
	if (idx < seg[cur*2+1].second) return getIndex(seg, idx, left, mid, cur*2+1);
	return getIndex(seg, idx - seg[cur*2+1].second, mid+1, right, cur*2+2);
}

pair<ll, ll> query(vector<pair<ll, ll>> &seg, ll ql, ll qr, ll left, ll right, ll cur)
{
	if (left > right) return (make_pair(0, 0));
	if (ql <= left && right <= qr) return seg[cur];
	if (ql > right || qr < left) return (make_pair(0, 0));
	ll mid = left + (right - left) / 2;
	return query(seg, ql, qr, left, mid, cur*2+1)
		+ query(seg, ql, qr, mid+1, right, cur*2+2);
}

void solve()
{
	ll n, k;
	cin >> n >> k;
	vector<ll> o(n), a(n);
	vector<pair<ll, ll>> p(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> o[i];
		p[i].first = o[i];
		p[i].second = i;
	}
	sort(p.begin(), p.end());
	for (ll i = 0; i < n; i++) a[p[i].second] = i;
	vector<pair<ll, ll>> seg(n*4, {0, 0});
	ll i = 0;
	for (; i < k; i++) update(seg, a[i], o[i], 0, n-1, 0);
	vector<ll> targetIdx = {k/2 - (k%2 == 0), k/2};
	vector<ll> ans(n - k + 1, 1e18);
	//
	for (ll left = 0; i <= n; i++, left++)
	{
		for (ll idx : targetIdx)
		{
			auto mid = getIndex(seg, targetIdx[0], 0, n-1, 0);
			auto pl = query(seg, 0, mid.second - 1, 0, n-1, 0);
			auto pr = query(seg, mid.second + 1, n - 1, 0, n-1, 0);
			ll leftCount = pl.second, leftSum = pl.first, rightCount = pr.second, rightSum = pr.first;
			ans[left] = min(ans[left], (mid.first*leftCount - leftSum) + (rightSum - mid.first*rightCount));
			break;
		}
		if (i < n) update(seg, a[left], -o[left], 0, n-1, 0), update(seg, a[i], o[i], 0, n-1, 0);
	}
	//
	for (ll i = 0; i < (n - k + 1); i++)
		cout << ans[i] << " \n"[i+1 == n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

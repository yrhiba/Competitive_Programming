/*
CSES Problem Set

Josephus Problem II

link to the problem:
https://cses.fi/problemset/task/2163/
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
# define DEBUG 0
# define ull unsigned long long
# define ll long long
ll mod = 1e9 + 7;
using namespace std;

void setup(vector<ll> &seg, ll left, ll right, ll cur)
{
	if (left == right)
	{
		seg[cur] = 1;
		return ;
	}
	ll mid = left + (right - left) / 2;
	setup(seg, left, mid, cur*2 + 1);
	setup(seg, mid+1, right, cur*2 + 2);
	seg[cur] = seg[cur*2 + 1] + seg[cur*2 + 2];
}

void update(vector<ll> &seg, ll idx, ll value, ll left, ll right, ll cur)
{
	if (left == right)
	{
		if (left == idx) seg[cur] = value;
		return ;
	}
	if (idx < left || idx > right) return ;
	//
	ll mid = left + (right - left) / 2;
	update(seg, idx, value, left, mid, cur * 2 + 1);
	update(seg, idx, value, mid + 1, right, cur * 2 + 2);
	//
	seg[cur] = seg[cur * 2 + 1] + seg[cur * 2 + 2];
}

ll query(vector<ll> &seg, ll ql, ll qr, ll left, ll right, ll cur)
{
	if (ql <= left && right <= qr) return seg[cur];
	if (qr < left || ql > right) return (0);
	ll mid = left + (right - left) / 2;
	return query(seg, ql, qr, left, mid, cur * 2 + 1)
		+ query(seg, ql, qr, mid + 1, right, cur * 2 + 2);
}

ll queryOne(vector<ll> &seg, ll idx, ll left, ll right, ll cur)
{
	return query(seg, idx, idx, left, right, cur);
}

ll getIdx(vector<ll> &seg, ll idx, ll left, ll right, ll cur)
{
	if (idx >= seg[cur])	return (-1); // error
	if (left == right)		return (left);
	//
	ll mid = left + (right - left) / 2;
	if (idx < seg[cur * 2 + 1]) return getIdx(seg, idx, left, mid, cur * 2 + 1);
	return getIdx(seg, idx - seg[cur * 2 + 1], mid + 1, right, cur * 2 + 2);
}

void solve()
{
	ll n, k; cin >> n >> k;
	//
	vector<ll> seg(n*4 + 1);
	setup(seg, 0, n - 1, 0);
	//
	vector<ll> ans;
	//
	ans.push_back(k % n);
	update(seg, ans.back(), 0, 0, n - 1, 0);
	//
	while (seg.front() && ans.size() < n)
	{
		ll leftSize = query(seg, 0, ans.back() - 1, 0, n - 1, 0);
		ll rightSize = query(seg, ans.back(), n - 1, 0, n - 1, 0);
		//
		ll nextIdx = (leftSize + (k % seg.front())) % seg.front();
		//
		ll toAdd = getIdx(seg, nextIdx, 0, n - 1, 0);
		//
		ans.push_back(toAdd);
		update(seg, ans.back(), 0, 0, n - 1, 0);
	}
	//
	for (ll i = 0; i < n; i++)
		cout << ans[i] + 1 << " \n"[i+1 == n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

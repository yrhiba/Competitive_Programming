/*
CSES Problem Set

Nearest Smaller Values

link to the problem:
https://cses.fi/problemset/task/1645
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

ll query(vector<ll> &seg, ll ql, ll qr, ll left, ll right, ll cur)
{
	if (ql <= left && right <= qr) return seg[cur];
	if (ql > right || qr < left) return (0);
	ll mid = left + (right - left) / 2;
	return max(query(seg, ql, qr, left, mid, cur*2+1),
		query(seg, ql, qr, mid+1, right, cur*2+2));
}

void update(vector<ll> &seg, ll idx, ll value, ll left, ll right, ll cur)
{
	if (left == right)
	{
		if (left == idx) seg[cur] = value;
		return ;
	}
	if (idx < left || idx > right) return ;
	ll mid = left + (right - left) / 2;
	update(seg, idx, value, left, mid, cur*2+1);
	update(seg, idx, value, mid+1, right, cur*2+2);
	seg[cur] = max(seg[cur*2+1], seg[cur*2+2]);
}

void solve()
{
	ll n; cin >> n;
	vector<pair<ll, ll>> a(n);
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i-1].first;
		a[i-1].second = i;
	}
	//
	sort(a.begin(), a.end());
	for (ll i = 0, last_a = -1; i < n; i++)
	{
		if (a[i].first == last_a) a[i].first = a[i-1].second;
		else last_a = a[i].first, a[i].first = i;
		swap(a[i].first, a[i].second);
	}
	sort(a.begin(), a.end());
	//
	vector<ll> seg(n*4, 0);
	vector<ll> ans;
	//
	for (auto &[idx, t] : a)
	{
		ans.push_back(query(seg, 0, t-1, 0, n-1, 0));
		update(seg, t, idx, 0, n-1, 0);
	}
	//
	for (ll i = 0; i < n; i++)
		cout << ans[i] << " \n"[i+1 == n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}


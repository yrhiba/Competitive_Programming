/*
CSES Problem Set

Subarray Distinct Values

link to the problem:
https://cses.fi/problemset/result/9114030/
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

pair<ll, ll> fn(const pair<ll, ll> &a, const pair<ll, ll> &b)
{
	return (make_pair((a.first + b.first), (a.second + b.second)));
}

void update(vector<pair<ll, ll>> &seg, ll idx, ll value, ll left, ll right, ll cur)
{
	if (left == right)
	{
		if (left == idx)
		{
			seg[cur].second += value;
			seg[cur].first = (seg[cur].second > 0);
		}
		return ;
	}
	if (idx < left || idx > right) return ;
	ll mid = left + (right - left) / 2;
	update(seg, idx, value, left, mid, cur*2+1);
	update(seg, idx, value, mid+1, right, cur*2+2);
	seg[cur] = fn(seg[cur*2+1], seg[cur*2+2]);
}

pair<ll, ll> query(vector<pair<ll, ll>> &seg, ll ql, ll qr, ll left, ll right, ll cur)
{
	if (ql <= left && right <= qr) return (seg[cur]);
	if (ql > right || qr < left) return (make_pair(0, 0));
	ll mid = left + (right - left) / 2;
	return fn(query(seg, ql, qr, left, mid, cur*2+1),
		query(seg, ql, qr, mid+1, right, cur*2+2));
}

bool isValidToAdd(vector<pair<ll, ll>> &seg, ll toAdd, ll n, ll k)
{
	update(seg, toAdd, +1, 0, n-1, 0);
	bool ans = (seg.front().first <= k);
	update(seg, toAdd, -1, 0, n-1, 0);
	return ans;
}

void solve()
{
	ll n, k; cin >> n >> k;
	vector<pair<ll, ll>> p(n);
	for (ll i = 1; i <= n; i++)
	{
		cin >> p[i-1].first;
		p[i-1].second = i;
	}
	sort(p.begin(), p.end());
	for (ll i = 0, last_a = -1; i < n; i++)
	{
		if (last_a == p[i].first) p[i].first = p[i-1].second;
		else last_a = p[i].first, p[i].first = i;
		//
		swap(p[i].first, p[i].second);
	}
	sort(p.begin(), p.end());
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) a[i] = p[i].second;
	vector<pair<ll, ll>> seg(n*4, {0, 0});
	update(seg, a.front(), +1, 0, n-1, 0);
	ll left = 0, right = 0, ans = 0;
	vector<pair<ll, ll>> maxValidSubArrays;
	//
	while (right+1 < n)
	{
		//
		while (right+1 < n && isValidToAdd(seg, a[right+1], n, k))
			update(seg, a[right+1], +1, 0, n-1, 0), right += 1;
		//
		maxValidSubArrays.push_back({left, right});
		//
		if (right+1 < n)
			while (seg.front().first >= k) update(seg, a[left++], -1, 0, n-1, 0);
	}
	//
	for (ll i = 0; i < maxValidSubArrays.size(); i++)
	{
		ll left = maxValidSubArrays[i].first;
		ll right = maxValidSubArrays[i].second;
		ll prvRight = i ? maxValidSubArrays[i-1].second : -1;
		ans += (right - left + 1) * (right - left + 2) / 2;
		if (left <= prvRight)
			ans -= (prvRight - left + 1) * (prvRight - left + 2) / 2;
	}
	//
	cout << ans << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

/*
F. Greetings

link to the problem:
https://codeforces.com/contest/1915/problem/F
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
# define ull unsigned long long
# define ll long long
const ll mod = 1e9 + 7;
using namespace std;

ll query(vector<ll> &seg, ll ql, ll qr, ll left, ll right, ll cur)
{
	if (ql <= left && right <= qr) return seg[cur];
	if (ql > right || left > qr) return (0);
	ll mid = left+(right-left)/2;
	return (query(seg, ql, qr, left, mid, cur*2+1)
	+ query(seg, ql, qr, mid+1, right, cur*2+2));
}

void update(vector<ll> &seg, ll idx, ll left, ll right, ll cur)
{
	if (left == right)
	{
		if (idx == left) seg[cur] = 1;
		return;
	}
	if (idx < left || idx > right) return ;
	ll mid = left+(right-left)/2;
	update(seg, idx, left, mid, cur*2+1);
	update(seg, idx, mid+1, right, cur*2+2);
	seg[cur] = seg[cur*2+1]+seg[cur*2+2];
}

void solve()
{
	ll n; cin >> n;
	vector< pair<ll, ll> > a(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i].second;
		cin >> a[i].first;
	}
	sort(a.begin(), a.end());
	for (ll i = 0; i < n; i++)
	{
		swap(a[i].first, a[i].second);
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	for (ll i = 0; i < n; i++)
	{
		a[i].first = i;
		swap(a[i].first, a[i].second);
	}
	sort(a.begin(), a.end());
	vector<ll> seg(n*4, 0);
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		ll qr = query(seg, a[i].second, n-1, 0, n-1, 0);
		update(seg, a[i].second, 0, n-1, 0);
		ans += qr;
	}
	cout << ans << '\n';
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

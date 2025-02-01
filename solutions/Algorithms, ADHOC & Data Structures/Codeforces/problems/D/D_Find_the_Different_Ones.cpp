/*
D. Find the Different Ones!

link to the problem:
https://codeforces.com/contest/1927/problem/D
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

pair<ll, ll>	fn(vector<ll> &a, pair<ll, ll> x, pair<ll, ll> y)
{
	if (a[x.first] != a[x.second]) return x;
	if (a[y.first] != a[y.second]) return y;
	if (a[x.first] != a[y.first]) return {x.first, y.first};
	return x;
}

void	setup(vector< pair<ll, ll> > &seg, vector<ll> &a, ll left, ll right, ll cur)
{
	if (left == right)
	{
		seg[cur] = {left, left};
		return ;
	}
	ll mid = left + (right - left) / 2;
	setup(seg, a, left, mid, cur*2+1);
	setup(seg, a, mid+1, right, cur*2+2);
	seg[cur] = fn(a, seg[cur*2+1], seg[cur*2+2]);
}

pair<ll, ll> query(vector< pair<ll, ll> > &seg, const ll ql, const ll qr,
	ll left, ll right, ll cur, vector<ll> &a)
{
	if (ql <= left && right <= qr) return seg[cur];
	if (ql > right || left > qr) return (make_pair(-1, -1));
	ll mid = left + (right - left) / 2;
	pair<ll, ll> p1 = query(seg, ql, qr, left, mid, cur*2+1, a);
	pair<ll, ll> p2 = query(seg, ql, qr, mid+1, right, cur*2+2, a);
	if (p1.first == -1 && p2.first == -1) return p1;
	if (p1.first == -1) return p2;
	if (p2.first == -1) return p1;
	return fn(a, p1, p2);
}

void solve()
{
	ll n; cin >> n;
	vector<ll> a(n);
	for (ll &i : a) cin >> i;
	vector< pair<ll, ll> > seg(n*4, {-1, 0});
	setup(seg, a, 0, n-1, 0);
	ll q; cin >> q;
	while (q--)
	{
		ll l, r; cin >> l >> r;
		l--, r--;
		pair<ll, ll> ans = query(seg, l, r, 0, n-1, 0, a);
		if (ans.first != -1 && ans.first != ans.second)
			cout << ans.first+1 << " " << ans.second+1 << "\n";
		else
			cout << "-1 -1\n";
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

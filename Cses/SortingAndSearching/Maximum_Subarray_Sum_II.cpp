/*
CSES Problem Set

Maximum Subarray Sum II

link to the problem:
https://cses.fi/problemset/task/1644/
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

void setup(vector<ll> &seg, vector<ll> &pfx, ll left, ll right, ll cur)
{
	if (left == right)
	{
		seg[cur] = pfx[left];
		return ;
	}
	ll mid = left + (right - left) / 2;
	setup(seg, pfx, left, mid, cur*2+1);
	setup(seg, pfx, mid+1, right, cur*2+2);
	seg[cur] = max(seg[cur*2+1], seg[cur*2+2]);
}

ll query(vector<ll> &seg, ll ql, ll qr, ll left, ll right, ll cur, ll m = 0)
{
	if (ql <= left && right <= qr) return seg[cur] - m;
	if (ql > right || qr < left) return -1e18;
	ll mid = left + (right - left) / 2;
	return max(
		query(seg, ql, qr, left, mid, cur*2+1, m),
		query(seg, ql, qr, mid+1, right, cur*2+2, m)
	);
}

void solve()
{
	ll n, a, b, ans; cin >> n >> a >> b;
	vector<ll> pfx(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> pfx[i];
		if (i) pfx[i] += pfx[i-1];
	}
	ans = pfx[a-1];
	vector<ll> seg(n*4);
	setup(seg, pfx, 0, n-1, 0);
	for (ll i = (a - 1); i < n; i++)
		ans = max(ans, query(seg, i, i + (b-a), 0, n-1, 0) - ((i-a >= 0) ? pfx[i-a] : 0));
	//
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

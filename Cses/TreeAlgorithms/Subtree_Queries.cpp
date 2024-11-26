/*
yrhiba.github.io (c). 2022-2024
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
#include <cassert>
#include <random>
#include <sstream>
using namespace std;
# define all(x) begin(x), end(x)
# define rall(x) rbegin(x), rend(x)
typedef long long ll;

// solution
vector<pair<ll, ll>> eulerIdx;
vector<ll> v;

ll fn(ll a, ll b)
{
	return (a + b);
}
void segSetup(vector<ll> &seg, ll left, ll right, ll cur)
{
	if (left == right)
	{
		seg[cur] = v[left];
		return;
	}
	ll mid = left + (right - left) / 2;
	segSetup(seg, left, mid, cur*2+1);
	segSetup(seg, mid+1, right, cur*2+2);
	seg[cur] = fn(seg[cur*2+1], seg[cur*2+2]);
}
void segUpdate(vector<ll> &seg, ll idx, ll value, ll left, ll right, ll cur)
{
	if (left == right)
	{
		if (left == idx) seg[cur] = value;
		return ;
	}
	if (idx < left || idx > right) return ;
	ll mid = left + (right - left) / 2;
	segUpdate(seg, idx, value, left, mid, cur*2+1);
	segUpdate(seg, idx, value, mid+1, right, cur*2+2);
	seg[cur] = fn(seg[cur*2+1], seg[cur*2+2]);
}
ll segQuery(vector<ll> &seg, const ll &ql, const ll &qr, ll left, ll right, ll cur)
{
	if (ql <= left && right <= qr) return seg[cur];
	if (ql > right || left > qr) return (0);
	ll mid = left + (right - left) / 2;
	return fn(
		segQuery(seg, ql, qr, left, mid, cur*2+1),
		segQuery(seg, ql, qr, mid+1, right, cur*2+2)
	);
}

ll rec(
	vector<vector<ll>> &g,
	vector<ll> &a,
	vector<ll> &v,
	vector<pair<ll, ll>> &eulerIdx,
	ll node,
	ll parent,
	ll &idx
)
{
	v[idx] = a[node];
	eulerIdx[node] = {idx, idx};
	for (ll nx : g[node])
	{
		if (nx == parent) continue;
		idx += 1;
		ll t = rec(g, a, v, eulerIdx, nx, node, idx);
		eulerIdx[node].second = max(eulerIdx[node].second, t);
	}
	return eulerIdx[node].second;
}

void solve()
{
	ll n, q; cin >> n >> q;
	vector<ll> a(n);
	for (auto &i : a) cin >> i;
	vector<vector<ll>> g(n);
	for (ll i = 1; i < n; i++) {
		ll a, b; cin >> a >> b;
		a -= 1, b -= 1;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	v = vector<ll>(n);
	eulerIdx = vector<pair<ll, ll>>(n);
	ll idx = 0;
	rec(g, a, v, eulerIdx, 0, -1, idx);

	vector<ll> seg(n*4);
	segSetup(seg, 0, n-1, 0);

	while (q--)
	{
		ll t; cin >> t;

		if (t == 1) {
			ll s, x; cin >> s >> x;
			s -= 1;
			segUpdate(seg, eulerIdx[s].first, x, 0, n-1, 0);
		} else {
			ll s; cin >> s;
			s -= 1;
			cout << segQuery(seg, eulerIdx[s].first, eulerIdx[s].second, 0, n-1, 0) << '\n';
		}
	}
}

/* main funciton */
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	solve();
	return (0);
}

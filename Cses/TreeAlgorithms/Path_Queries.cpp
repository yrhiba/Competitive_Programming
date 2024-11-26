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
typedef long long ll;

/* solution */
void setup(vector<pair<ll, ll>> &seg, vector<ll> &a, ll left, ll right, ll cur)
{
	if (left == right) {
		seg[cur] = {a[left], 0};
		return;
	}
	ll mid = left + (right - left) / 2;
	setup(seg, a, left, mid, cur*2+1);
	setup(seg, a, mid+1, right, cur*2+2);
	seg[cur].first = seg[cur*2+1].first + seg[cur*2+2].first;
	seg[cur].second = 0;
}
 
void update(vector<pair<ll, ll>> &seg, ll ql, ll qr, ll u, ll left, ll right, ll cur)
{
	if (ql <= left && right <= qr) {
		seg[cur].second += u;
		return ;
	}
	if (ql > right || left > qr) return ;
	ll mid = left + (right - left) / 2;
	update(seg, ql, qr, u, left, mid, cur*2+1);
	update(seg, ql, qr, u, mid+1, right, cur*2+2);
	seg[cur].first = seg[cur*2+1].first + seg[cur*2+2].first;
	seg[cur].first += (right - left + 1) * seg[cur].second;
}
 
ll query(vector<pair<ll, ll>> &seg, ll idx, ll left, ll right, ll cur)
{
	if (left == right)
	{
		if (left == idx) {
			seg[cur].first += seg[cur].second;
			seg[cur].second = 0;
			return seg[cur].first;
		}
		return (0);
	}
	if (idx < left || idx > right) return (0);
	ll mid = left + (right - left) / 2;
	if (seg[cur].second)
	{
		seg[cur].first += seg[cur].second * (right - left + 1);
		seg[cur*2+1].second += seg[cur].second;
		seg[cur*2+2].second += seg[cur].second;
		seg[cur].second = 0;
	}
	return query(seg, idx, left, mid, cur*2+1)
		+ query(seg, idx, mid+1, right, cur*2+2);
}

ll rec(
vector<vector<ll>> &g,
vector<ll>	&v,
vector<ll>	&resultValues,
vector<pair<ll, ll>>	&nodesRange,
ll node, 
ll parent,
ll &idx
)
{
	resultValues[idx] += v[node];
	ll curRes = resultValues[idx];
	nodesRange[node] = {idx, idx};
	for (auto nx : g[node]) {
		if (nx != parent) {
			idx += 1;
			resultValues[idx] += curRes;
			nodesRange[node].second = max(
					nodesRange[node].second,
					rec(g, v, resultValues, nodesRange, nx, node, idx)
				);
		}
	}
	return nodesRange[node].second;
}

void solve()
{
	ll n, q; cin >> n >> q;

	vector<ll> v(n);
	for (auto &i : v) cin >> i;

	vector<vector<ll>> g(n);
	for (ll i = 0; i+1 < n; i++) {
		ll a, b; cin >> a >> b;
		a -= 1, b -= 1;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<ll> resultValues(n, 0);
	vector<pair<ll, ll>> nodesRange(n);

	ll idx = 0;
	rec(g, v, resultValues, nodesRange, 0, -1, idx);

	vector<pair<ll, ll>> seg(n*4);
	setup(seg, resultValues, 0, n-1, 0);

	while (q--)
	{
		ll t; cin >> t;

		if (t == 1) {
			ll s, x; cin >> s >> x; s -= 1;
			ll diff = x - v[s];
			v[s] = x;
			update(seg, nodesRange[s].first, nodesRange[s].second, diff, 0, n-1, 0);
		} else {
			ll s; cin >> s; s -= 1;
			cout << query(seg, nodesRange[s].first, 0, n-1, 0) << '\n';
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

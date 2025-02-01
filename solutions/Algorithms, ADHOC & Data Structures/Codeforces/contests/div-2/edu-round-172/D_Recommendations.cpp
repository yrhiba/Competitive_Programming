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
const int mod = int(1e9 + 7);
const double PI = 3.14159265359;
const string directions[8] {"D","R","U","L","DR","DL","TL","TR"};
const int dr[8] {1, 0, -1, 0, 1, 1, -1, -1};
const int dc[8] {0, 1, 0, -1, 1, -1, -1, 1};
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using o_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/* input - output */
void setIO(string s)
{
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
/* math */
ll gcd(ll a, ll b)
{
	if (b == 0) return (a);
	return (gcd(b, a%b));
}
ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a, b));
}
ll log2(ll x)
{
	ll r = ((x > 0) ? 0 : 1);
	while (x) x /= 2, r += 1;
	return (r);
}
ll log10(ll x)
{
	ll r = ((x > 0) ? 0 : 1);
	while (x) x /= 10, r += 1;
	return (r);
}
ll pow(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = pow(x, p/2);
	if (p%2) return ((res * res) * x);
	return (res * res);
}
ll powermod(ll x, ll p, ll m = mod)
{
	if (p == 0) return (1);
	ll res = powermod(x, p/2, m) % m;
	if (p%2)
		return ((((res * res) % m) * (x % m)) % m);
	return ((res * res) % m);
}
ll inverse(ll x, ll m = mod)
{
	return (powermod(x, m-2, m));
}
/* global varibles */
const int MAX_N = int(5e5);
/* precalculation/setup */
void preSetup()
{
}

/* solution */
vector<vector<pair<ll, ll>>> a;
vector<vector<pair<ll, ll>>> seg;
vector<vector<pair<ll, ll>>> info;

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
	if (a.first != b.first)
		return a.first < b.first;
	return a.second > b.second;
}

void evaluate(vector<pair<ll, ll>> &cur, vector<pair<ll, ll>> &a)
{
	sort(all(cur), cmp);
	a = cur;
	ll n = int(a.size());
	for (ll i = n - 2; i >= 0; i--) {
		a[i].first = min(a[i].first, a[i+1].first);
		a[i].second = max(a[i].second, a[i+1].second);
	}
}

void setup(ll left, ll right, ll cur)
{
	if (left == right)
	{
		seg[cur] = a[left & right];
		evaluate(seg[cur], info[cur]);
		return ;
	}
	ll mid = left + (right - left) / 2;
	setup(left, mid, cur*2+1);
	setup(mid+1, right, cur*2+2);
	merge(seg[cur*2+1].begin(), seg[cur*2+1].end(), seg[cur*2+2].begin(),
		seg[cur*2+2].end(), std::back_inserter(seg[cur]));
	evaluate(seg[cur], info[cur]);
}

pair<ll, ll> query(ll ql, ll qr, ll end, ll start, ll left, ll right, ll cur)
{
	if (ql <= left && right <= qr) {
		if (seg[cur].empty()) return make_pair(-1, -1);
		ll left = 0, right = int(seg[cur].size()) - 1, mid, res = -1;
		while (left <= right)
		{
			mid = left + (right - left) / 2;
			if (seg[cur][mid].first >= end) {
				res = mid;
				right = mid - 1;
			} else {
				left = mid + 1;
			}
		}
		if (res == -1) return (make_pair(-1, -1));
		if (info[cur][res] == make_pair(end, start)) res += 1;
		if (res >= int(info[cur].size())) return make_pair(-1, -1);
		return info[cur][res];
	}
	if (left > qr || ql > right) return (make_pair(-1, -1));
	ll mid = left + (right - left) / 2;
	auto r1 = query(ql, qr, end, start, left, mid, cur*2+1);
	auto r2 = query(ql, qr, end, start, mid+1, right, cur*2+2);
	if (r1.first == -1) return r2;
	if (r2.first == -1) return r1;
	r1.first = min(r1.first, r2.first);
	r1.second = max(r1.second, r2.second);
	return r1;
}

void solve()
{
	ll n; cin >> n;

	o_set<ll> st;
	vector<pair<ll, ll>> b(n);
	map<pair<ll, ll>, ll> mp;
	for (auto &[i, j] : b) {
		cin >> i >> j;
		st.insert(i);
		mp[{i, j}] += 1;
	}

	a = vector<vector<pair<ll, ll>>>(n);
	seg = vector<vector<pair<ll, ll>>>(n * 4);
	info = vector<vector<pair<ll, ll>>>(n * 4);

	for (auto &[i, j] : b) {
		a[st.order_of_key(i)].push_back({j, i});
	}

	setup(0, n - 1, 0);

	for (auto &[i, j] : b)
	{
		if (mp[{i, j}] > 1) {
			cout << "0\n";
			continue;
		}

		auto r = query(0, st.order_of_key(i), j, i, 0, n - 1, 0);
		if (r.first == -1) {
			cout << "0\n";
		} else {
			cout << (r.first - r.second + 1) - (j - i + 1) << '\n';
		}
	}
}
/* main funciton */
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	preSetup();
	ll t; cin >> t; cin.ignore();
	for (ll tc = 1; tc <= t; tc++)
	{
		// cerr << "test: " << tc << "\n";
		solve();
		// cerr << "#####" << "\n";
	}
	return (0);
}

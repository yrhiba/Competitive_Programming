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
# define int ll
const int mod = int(1e9 + 7);
const double PI = 3.14159265359;
const string directions[8] {"D","R","U","L","DR","DL","TL","TR"};
const int dr[8] {1, 0, -1, 0, 1, 1, -1, -1};
const int dc[8] {0, 1, 0, -1, 1, -1, -1, 1};
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
struct segTree{
	vector<int> all;
	int n;
	vector<int> s;
	vector<int> lazy;
 
	int fn(int a, int b){
		return a + b;
	}
	segTree(vector<int> &a){
		n = a.size();
		all = a;
		s.resize(4 * n);
		lazy.resize(4 * n);
		build(1, 0, n - 1);
	}
	void	build(int node, int start, int end){
		if (start == end){
			s[node] = all[start];
			return ;
		}
		int mid = (start + end) / 2;
		build(2 * node, start, mid);
		build(2 * node + 1, mid + 1, end);
		s[node] = fn(s[2*node], s[2*node + 1]);
	}
	
	void	push_down(int node, int start, int end) {
		s[node] += lazy[node] * (end - start + 1);
		if (start != end){
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
 
	void	update(int node, int start, int end, int l, int r, int val){
		push_down(node, start, end);
		if (start > r ||  end < l) return ;
		if (start >= l && end <= r){
			lazy[node] += val;
			push_down(node, start, end);
			return ;
		}
		int mid = (start + end) / 2;
		update(2 * node, start, mid, l, r, val);
		update(2 * node + 1, mid + 1, end, l, r, val);
		s[node] = fn(s[2 * node], s[2 * node + 1]);
	}
	void	update(int l, int r, int val){
		update(1, 0, n - 1, l, r, val);
	}
	
	int query(int node, int start, int end, const int l, const int r){
		push_down(node, start, end);
		if (start > r || end < l) return 0;
		if (start >= l && end <= r) return s[node];
		int mid = (start + end) / 2;
		int left = query(2 * node, start, mid, l, r);
		int right = query(2 * node + 1, mid + 1, end, l, r);
		return left + right;
	}
	int query(int l, int r){
		return query(1, 0, n - 1, l, r);
	}
};

void solve()
{
	ll n, m, k; cin >> n >> m >> k;
	string s; cin >> s;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++) {
		a[i] = s[i] - '0';
	}
	segTree seg(a);
	ll ans = 0;
	for (ll i = 0; i < n; i++)
		if (i+1 >= m) {
			
			ll curSum = seg.query(i - (m - 1), i);
			if (curSum) continue;
			ll nxSum = seg.query(i, min(n - 1, i + k - 1));
			seg.update(i, min(n - 1, i + k - 1), k - nxSum);
			ans += 1;
		}
	//
	cout << ans << '\n';
}
/* main funciton */
int32_t main()
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

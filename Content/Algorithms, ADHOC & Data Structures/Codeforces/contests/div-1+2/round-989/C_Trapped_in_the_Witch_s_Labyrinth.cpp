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

ll rec(
	vector<vector<int>> &g,
	vector<string> &a, 
	ll i,
	ll j
)
{
	if (i < 0 || j < 0 || i >= g.size() || j >= g[i].size()) return (0);
	if (g[i][j] == -2) return (1);
	//
	if (a[i][j] == '?') {
		g[i][j] = 1;
		return (1);
	}
	//
	if (g[i][j] != -1) return g[i][j];
	g[i][j] = -2;
	//
	if (a[i][j] == 'U') {
		g[i][j] = rec(g, a, i-1, j);
	} else if (a[i][j] == 'D') {
		g[i][j] = rec(g, a, i+1, j);
	} else if (a[i][j] == 'R') {
		g[i][j] = rec(g, a, i, j+1);
	} else {
		g[i][j] = rec(g, a, i, j-1);
	}

	return g[i][j];
}

void solve()
{
	ll n, m; cin >> n >> m;

	vector<vector<int>> g(n, vector<int>(m, -1));

	vector<string> a(n);
	for (auto &i : a) cin >> i;

	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			if (g[i][j] != -1) continue;
			if (a[i][j] == '?') continue;
			rec(g, a, i, j);
		}
	}

	ll ans = 0;
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < m; j++) {
			assert(g[i][j] != -2);
			if (g[i][j] == -1) {
				bool ok = false;
				for (ll d = 0; d < 4; d++) {
					ll ni = i + dr[d];
					ll nj = j + dc[d];
					if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
					ok |= (g[ni][nj] == 1 || a[ni][nj] == '?');
				}
				ans += ok;
			} else {
				ans += (g[i][j] == 1);
			}
		}
	}

	cout << ans << '\n';
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

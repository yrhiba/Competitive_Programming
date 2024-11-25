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
typedef long long ll;

/* solution */
ll n, q;
vector<vector<ll>> g;
vector<pair<ll, ll>> querys;
vector<vector<ll>> answers;
vector<ll> cur;

void rec(ll i = 0)
{
	for (auto &_ : answers[i]) {
		ll idx = cur.size() - 1 - _;
		if (idx < 0) {
			_ = -2;
		} else {
			_ = cur[idx];
		}
	}

	for (auto nx : g[i]) {
		cur.push_back(nx);
		rec(nx);
		cur.pop_back();
	}
}

void solve()
{
	cin >> n >> q;
	g = vector<vector<ll>>(n);
	answers = vector<vector<ll>>(n);
	for (ll i = 1; i < n; i++) {
		ll p; cin >> p; p -= 1;
		g[p].push_back(i);
	}
	for (ll i = 0; i < q; i++) {
		ll x, k; cin >> x >> k;
		x -= 1;
		answers[x].push_back(k);
		querys.push_back({x, answers[x].size() - 1});
	}
	cur.push_back(0), rec();
	for (auto &[x, k] : querys) {
		cout << (answers[x][k] + 1) << '\n';
	}
}
/* main funciton */
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	solve();
	return (0);
}

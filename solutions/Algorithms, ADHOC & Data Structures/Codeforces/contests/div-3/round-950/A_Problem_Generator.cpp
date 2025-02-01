/*

Codeforces Round 950 (Div. 3)

A. Problem Generator

time limit per test: 1 second
memory limit per test: 256 megabytes
input: standard input
output: standard output


link to the problem:
https://codeforces.com/contest/1980/problem/A

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

# define ll long long

using namespace std;

void solve()
{
	ll n, m; cin >> n >> m;
	vector<ll> t(256, 0);
	string s; cin >> s;
	for (char c : s) t[c] += 1;
	ll ans = 0;
	string p = "ABCDEFG";
	for (char c : p)
		if (t[c] < m) ans += m - t[c];
	cout << ans << "\n";
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

/*
C. Beautiful Triple Pairs

time limit per test: 4 second
memory limit per test: 256 megabytes
input: standard input
output: standard output

link to the problem:
https://codeforces.com/contest/1974/problem/C
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

void solve()
{
	ll n, ans = 0; cin >> n;
	vector<ll> a(n);
	for (ll &i : a) cin >> i;
	//
	map<pair<ll, ll>, pair<ll, map<ll, ll>>> p1, p2, p3;
	//
	for (ll i = 0; i+2 < n; i++)
	{
		ans += p1[{a[i], a[i+1]}].first;
		ans += p2[{a[i], a[i+2]}].first;
		ans += p3[{a[i+1], a[i+2]}].first;
		//
		ans -= p1[{a[i], a[i+1]}].second[a[i+2]];
		ans -= p2[{a[i], a[i+2]}].second[a[i+1]];
		ans -= p3[{a[i+1], a[i+2]}].second[a[i]];
		//
		p1[{a[i], a[i+1]}].first += 1;
		p2[{a[i], a[i+2]}].first += 1;
		p3[{a[i+1], a[i+2]}].first += 1;
		//
		p1[{a[i], a[i+1]}].second[a[i+2]] += 1;
		p2[{a[i], a[i+2]}].second[a[i+1]] += 1;
		p3[{a[i+1], a[i+2]}].second[a[i]] += 1;
	}
	//
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

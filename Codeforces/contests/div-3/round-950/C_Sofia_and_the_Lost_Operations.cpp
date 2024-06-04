/*

Codeforces Round 950 (Div. 3)

C. Sofia and the Lost Operations

time limit per test: 2 second
memory limit per test: 256 megabytes
input: standard input
output: standard output


link to the problem:
https://codeforces.com/contest/1980/problem/C

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
	ll n; cin >> n;
	vector<pair<ll, ll>> a(n);
	for (auto &i : a) cin >> i.first;
	for (auto &i : a) cin >> i.second;
	map<ll, ll> mp;
	set<ll> st;
	for (auto &[i, j] : a)
	{
		if (i != j) mp[j] += 1;
		st.insert(j);
	}
	//
	ll m; cin >> m;
	vector<ll> d(m);
	for (auto &i : d) cin >> i;
	reverse(d.begin(), d.end());
	ll validOp = 0;
	for (ll op : d)
	{
		if (st.count(op) == 0 && mp.count(op) == 0 && validOp == 0)
		{
			cout << "NO\n";
			return ;
		}
		if (mp.count(op))
		{
			mp[op] -= 1;
			if (mp[op] == 0) mp.erase(op);
		}
		validOp += 1;
	}
	if (mp.size() == 0) cout << "YES\n";
	else cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--) solve();
}

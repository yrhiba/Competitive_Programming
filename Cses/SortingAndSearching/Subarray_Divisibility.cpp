/*
CSES Problem Set

Subarray Divisibility

link to the problem:
https://cses.fi/problemset/task/1662/
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
	vector<ll> p(n);
	map<ll, ll> mp;
	mp[0] = 1;
	for (ll i = 0; i < n; i++)
	{
		cin >> p[i];
		p[i] = (p[i] + ((abs(p[i]) + n) / n) * n) % n;
		if (i) p[i] = (p[i] + p[i - 1]) % n;
		//
		if (mp.find(p[i]) != mp.end()) ans += mp[p[i]];
		//
		mp[p[i]] += 1;
	}
	//
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

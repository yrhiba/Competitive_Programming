/*
link to the problem:
https://codeforces.com/contest/1950/problem/D
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
# define ull unsigned long long
# define ll long long
const ll mod = 1e9 + 7;
using namespace std;

vector<ll> helper;

bool isIt(ll x)
{
	while (x)
	{
		if (!(x%10 == 0 || x%10 == 1)) return false;
		x /= 10;
	}
	return true;
}

bool rec(ll n)
{
	static map<ll, bool> mp;
	//
	if (mp.count(n)) return mp[n];
	//
	for (ll x : helper)
	{
		if (n == x) return mp[n] = true;
		if (n%x == 0) if (rec(n/x)) return mp[n] = true;
	}
	//
	return mp[n] = false;
}

void solve()
{
	ll n; cin >> n;
	//
	if ((n == 1) || rec(n))
	{
		cout << "YES\n";
		return ;
	}
	//
	cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (ll i = 2; i <= 1e5; i++)
		if (isIt(i)) helper.push_back(i);
	//
	ll t; cin >> t;
	while (t--) solve();
}

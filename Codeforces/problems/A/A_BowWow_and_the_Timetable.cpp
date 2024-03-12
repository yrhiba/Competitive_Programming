/*
link to the problem:
https://codeforces.com/contest/1204/problem/A
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
# define ull unsigned long long
# define ll long long
ll mod = 1000000007;
using namespace std;
ll powermod(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = powermod(x, p/2) % mod;
	if (p%2)
		return ((((res * res) % mod) * (x % mod)) % mod);
	return ((res * res) % mod);
}
ll power(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = power(x, p/2);
	if (p%2)
		return ((res * res) * x);
	return (res * res);
}

void solve()
{
	string s; cin >> s;

	bool f = false;
	for (ll i = 1; i < s.size(); i++)
	{
		if (s[i] == '1')
		{
			f = !f;
			break;
		}
	}

	if (s.size() % 2)
	{
		cout << ((s.size()) / 2) + f << endl;
	}
	else
	{
		cout << s.size() / 2 << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

/*
link to the problem:
https://codeforces.com/contest/1950/problem/E
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

bool good(ll &n, string &s, ll k)
{
	ll bad = 0;
	//
	for (ll i = 0; i < k; i++)
	{
		vector<ll> cnt(26, 0);
		for (ll j = i; j < n; j+=k) cnt[s[j]-'a'] += 1;
		ll t = 0, mine = 1e18;
		for (ll j : cnt)
			if (j)
			{
				t += 1;
				mine = min(mine, j);
			}
		//
		if (t > 2) return false;
		if (t == 2)
		{
			if (mine > 1) return false;
			bad += 1;
		}
	}
	//
	return (bad <= 1);
}

void solve(ll tc)
{
	ll n; cin >> n;
	string s; cin >> s;
	//
	set<ll> divs;
	for (ll i = 1; i*i <= n; i++)
		if (n%i==0)
		{
			divs.insert(i);
			divs.insert(n/i);
		}
	//
	for (ll k : divs)
	{
		if (good(n, s, k))
		{
			cout << k << "\n";
			return ;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll tc; cin >> tc;
	for (ll t = 1; t <= tc; t++)
		solve(t);
}

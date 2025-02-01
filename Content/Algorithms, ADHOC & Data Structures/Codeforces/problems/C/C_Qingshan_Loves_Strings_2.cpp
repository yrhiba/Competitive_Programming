/*
link to the problem:
https://codeforces.com/contest/1890/problem/C
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
ll powermod(ll x, ll p, ll m)
{
	if (p == 0) return (1);
	ll res = powermod(x, p/2, m) % m;
	if (p%2)
		return ((((res * res) % m) * (x % m)) % m);
	return ((res * res) % m);
}
ll power(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = power(x, p/2);
	if (p%2)
		return ((res * res) * x);
	return (res * res);
}
ll gcd(ll a, ll b)
{
	if (b == 0) return (a);
	return (gcd(b, a%b));
}
ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a,b));
}
ll inverse(ll x, ll m)
{
	return (powermod(x, m-2, m));
}


void solve()
{
	ll n; cin >> n;
	string s; cin >> s;

	if (s.size() % 2)
	{
		cout << -1 << "\n";
		return ;
	}

	vector<ll> ans; ans.reserve(301);

	ll o = 0;
	while (o < 300)
	{
		bool f = true;
		for (ll i = 0; i < s.size()/2; i++)
		{
			if (s[i] == s[s.size() - i - 1])
			{
				if (s[i] == '0')
				{
					ans.push_back(s.size() - i);
					s = s.substr(0, s.size() - i) + "01" 
							+ s.substr(s.size() - i, s.size());
				}
				else
				{
					ans.push_back(i);
					s = s.substr(0, i) + "01" 
							+ s.substr(i, s.size());
				}

				f = false;
				break;
			}
		}
		if (f)
		{
			cout << ans.size() << "\n";
			for (ll i = 0; i < ans.size(); i++)
			{
				cout << ans[i];
				if (i+1 < ans.size())
					cout << " ";
			}
			cout << "\n";
			return ;
		}
		o++;
	}
	cout << -1 << "\n";
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

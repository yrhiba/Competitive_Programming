/*
D. Colorful Stamp

link to the problem:
https://codeforces.com/contest/1669/problem/D
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
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
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
	return ((a*b)/gcd(a, b));
}

void solve()
{
	ll n; string s; cin >> n >> s;

	ll i = 0;
	while (i < s.size())
	{
		if (s[i] == 'B')
		{
			bool f = false;
			while (i < s.size())
			{
				if (s[i] == 'B')
				{
					i++;
					continue;
				}

				if (s[i] == 'R')
				{
					f = true;
					i++;
					break;
				}

				if (s[i] == 'W')
					break;
			}

			if (!f)
			{
				cout << "NO\n";
				return ;
			}

			while (s[i] == 'B' || s[i] == 'R')
				i++;
		}
		else if (s[i] == 'R')
		{
			bool f = false;
			while (i < s.size())
			{
				if (s[i] == 'R')
				{
					i++;
					continue;
				}

				if (s[i] == 'B')
				{
					f = true;
					i++;
					break;
				}

				if (s[i] == 'W')
					break;
			}

			if (!f)
			{
				cout << "NO\n";
				return ;
			}

			while (s[i] == 'B' || s[i] == 'R')
				i++;
		}
		else
			i++;
	}
	cout << "YES\n";
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

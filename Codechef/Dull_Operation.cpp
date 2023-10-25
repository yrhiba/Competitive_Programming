/*
Starters 105 Division 3 (Rated)

Dull Operation

link to the problem:
https://www.codechef.com/problems/DUPLET
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

string to_bin(ll x)
{
	string s(30, '0');

	ll i = s.size() - 1;
	while (x)
	{
		s[i--] = x%2 + '0';
		x/=2;
	}
	return s;
}

void print_ans(string &x, string &y)
{
	ll a = 0, b = 0;

	for (ll i = 0; i < x.size(); i++)
	{
		a = a*2 + (x[i] == '1');
		b = b*2 + (y[i] == '1');
	}

	cout << a << " " << b << "\n";
}


void solve()
{
	ll n; cin >> n;

	for (ll i = 1; i*i <= n; i+=2)
	{
		if (n%i == 0)
		{
			string a = to_bin(i);
			string b = to_bin(n/i);

			for (ll k = 0; k < 2; k++)
			{
				if (k) swap(a, b);

				string x (30, '0');
				string y (30, '0');

				bool good = true;

				for (ll i = 0; i < 30; i++)
				{
					if (a[i] == '0' && b[i] == '0')
					{
						x[i] = '0';
						y[i] = '0';
					}
					else if (a[i] == '1' && b[i] == '1')
					{
						x[i] = '0';
						y[i] = '1';
					}
					else if (a[i] == '1' && b[i] == '0')
					{
						x[i] = '1';
						y[i] = '1';
					}
					else if (a[i] == '0' && b[i] == '1')
					{
						good = false;
						break;
					}
				}

				if (good)
				{
					print_ans(x, y);
					return ;
				}
			}
		}
	}
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

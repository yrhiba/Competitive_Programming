/*
link to the problem:
https://codeforces.com/contest/1/problem/B
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


string to_normal(string &a, ll row)
{
	string ans;

	while (row)
	{
		ans = (char)(row%10 + '0') + ans;
		row /= 10;
	}

	ll num = 0;
	for (ll i = 0; i < a.size(); i++)
	{
		num = num*26 + (a[i] - 'A');
		num += 1;
	}

	string r;
	while (num)
	{
		r = (char)(num%10 + '0') + r;
		num /= 10;
	}

	ans = 'R' + ans + 'C' + r;

	return (ans);
}


string to_excel(ll row, ll colom)
{
	string r;
	while (row)
	{
		r = (char)(row%10 + '0') + r;
		row /= 10;
	}

	string c;
	while (colom > 0)
	{
		colom -= 1;
		c = (char)(colom%26 + 'A') + c;
		colom /= 26;
	}

	return (c + r);
}


void solve()
{
	string s; cin >> s;

	string a, b;

	ll x, y; x = 0, y = 0;

	ll i = 0;
	while (s[i] <= 'Z' && s[i] >= 'A')
		a += s[i++];

	while (s[i] <= '9' && s[i] >= '0')
		x = (x * 10) + (s[i++] - '0');

	while (s[i] <= 'Z' && s[i] >= 'A')
		b += s[i++];

	while (s[i] <= '9' && s[i] >= '0')
		y = (y * 10) + (s[i++] - '0');


	if (b.size() == 0)
	{
		cout << to_normal(a, x) << "\n";
	}
	else
	{
		cout << to_excel(x, y) << "\n";
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

/*
TOE2 - Tic-Tac-Toe ( II )

link to the problem:
https://www.spoj.com/problems/TOE2/
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

void solve(string s)
{
	vector<string> g(3);

	ll x, o; x = o = 0;

	for (ll i = 0; i < 3; i++)
	{
		g[i] = s.substr(i*3, 3);

		for (char &c : g[i])
		{
			x += (c == 'X');
			o += (c == 'O');
		}
	}

	vector<string> wins; wins.reserve(8 + 1);

	for (ll i = 0; i < 3; i++)
		wins.push_back(g[i]);

	for (ll c = 0; c < 3; c++)
	{
		string r;
		for (ll i = 0; i < 3; i++)
			r += g[i][c];
		wins.push_back(r);
	}

	string r, e;
	for (ll i = 0; i < 3; i++)
	{
		r += g[i][i];
		e += g[i][3 - i - 1];
	}
	wins.push_back(r);
	wins.push_back(e);

	ll x_wins = 0;
	ll o_wins = 0;

	for (ll i = 0; i < wins.size(); i++)
	{
		bool f = true;
		for (char &c : wins[i])
		{
			if (c != wins[i].front())
			{
				f = false;
				break;
			}
		}

		if (f)
		{
			x_wins += (wins[i].front() == 'X');
			o_wins += (wins[i].front() == 'O');
		}
	}

	if (x - o == 1 && 1 <= x_wins && x_wins <= 2 && o_wins == 0)
	{
		cout << "valid\n";
		return ;
	}

	if (x - o == 0 && o_wins == 1 && x_wins == 0)
	{
		cout << "valid\n";
		return ;
	}

	if (x - o == 1 && o_wins == 0 && x_wins == 0 && x + o == 9)
	{
		cout << "valid\n";
		return ;
	}

	cout << "invalid\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	while (cin >> s)
	{
		if (s == "end") break;
		solve(s);
	}
}

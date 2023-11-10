/*
476 - Points in Figures

link to the problem:
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=417

link to the problem (pdf version):
https://onlinejudge.org/external/4/476.pdf
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
	vector< vector<double> > rects; rects.reserve(10 + 1);

	char c;
	while (cin >> c)
	{
		if (c == '*') break;

		vector<double> i(4);

		cin >> i[0] >> i[2];
		cin >> i[1] >> i[3];

		if (i[0] > i[1])	swap(i[0], i[1]);
		if (i[2] > i[3])	swap(i[2], i[3]);

		rects.push_back(i);
	}

	ll point = 1;

	double x, y;

	while (cin >> x >> y)
	{
		if (abs(x - 9999.9) <= 1e-6 && abs(y - 9999.9) <= 1e-6)
			break;

		bool f = false;

		ll figure = 1;

		for (auto &rect : rects)
		{
			if (rect[0] < x && x < rect[1] && rect[2] < y && y < rect[3])
			{
				f = true;
				cout << "Point " << point << " is contained in figure " << figure << "\n";
			}

			figure += 1;
		}

		if (!f) cout << "Point " << point << " is not contained in any figure\n";

		point += 1;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

/*
Codeforces Round 272 (Div. 2)

B. Dreamoon and WiFi

link to the problem:
https://codeforces.com/contest/476/problem/B
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

ll correct_possibilitys = 0;
ll possiblitys = 0;

void dfs(ll origin_p, ll origin_n, ll rec_p, ll rec_n, ll missing)
{
	if (missing == 0)
	{
		correct_possibilitys += (origin_p == rec_p && origin_n == rec_n);
		possiblitys += 1;
		return ;
	}

	dfs(origin_p, origin_n, rec_p + 1, rec_n, missing - 1);
	dfs(origin_p, origin_n, rec_p, rec_n + 1, missing - 1);
}


void solve()
{
	ll p, n; p = n = 0;

	string s; cin >> s;

	for (char &c : s)
	{
		p += (c == '+');
		n += (c == '-');
	}

	string x; cin >> x;

	ll po, ne; po = ne = 0;

	ll pro = 0;

	for (char &c : x)
	{
		po += (c == '+');
		ne += (c == '-');
		pro += (c == '?');
	}

	dfs(p, n, po, ne, pro);

	double ans = (correct_possibilitys * 1.0) / (possiblitys * 1.0);

	cout << fixed << setprecision(12) << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

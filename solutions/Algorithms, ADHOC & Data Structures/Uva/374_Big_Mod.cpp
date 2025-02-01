/*
link to the problem:
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=310
link to the problem (pdf):
https://onlinejudge.org/external/3/374.pdf
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
ll gcd(ll a, ll b)
{
	if (b == 0) return (a);
	return (gcd(b, a%b));
}
ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a, b));
}

ll power(ll b, ll p, ll m)
{
	if (p == 0) return (1);

	ll res = power(b, p/2, m) % m;
	res *= res; res %= m;
	if (p%2) res *= b%m, res %=m;
	return (res);
}

void solve(ll b, ll p, ll m)
{
	cout << power(b, p, m) << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll b, p, m;
	while (cin >> b >> p >> m)
		solve(b, p, m);
}

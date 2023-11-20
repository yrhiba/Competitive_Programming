/*

1337 Competitive Programming Club - 1337 Global Round 2

E. (al3achra) in the MNPC

link to the problem:
find problems.pdf

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
	ll n, m; cin >> n >> m;


	// To calculate the Max
	ll	x = n - m;
		x = ((1+x) * x) / 2;

	// To calculate The min
	ll	y1 = (n / m) + ((n % m) ? 1 : 0);
		y1 = ((y1 * (y1 - 1)) / 2) * (n%m);

	ll	y2 = (((n / m) * ((n / m) - 1)) / 2) * (m - (n%m));

	// Log The Answer
	cout << y1 + y2 << " " << x << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

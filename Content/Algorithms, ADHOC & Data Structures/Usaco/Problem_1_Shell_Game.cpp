/*
Shell Game
Bronze - Easy

link to the problem:
http://www.usaco.org/index.php?page=viewproblem2&cpid=891
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
	ll n; cin >> n;

	int table[] =	{1, 2, 3};
	int ans[] =		{0, 0, 0};

	ll a, b, c;

	for (ll i = 0; i < n; i++)
	{
		cin >> a >> b >> c;
		swap(table[a-1], table[b-1]);

		ans[table[c-1] - 1] += 1;
	}

	cout << max(ans[0], max(ans[1], ans[2])) << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// Comment this line for local tests
	setIO("shell");
	solve();
}

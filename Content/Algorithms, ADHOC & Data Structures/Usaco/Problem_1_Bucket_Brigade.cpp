/*
Bronze
Bucket Brigade
Easy

link to the problem:
http://www.usaco.org/index.php?page=viewproblem2&cpid=939
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
	int Bx = 0, By = 0;
	int Lx = 0, Ly = 0;
	int Rx = 0, Ry = 0;

	for (ll i = 0; i < 10; i++)
	{
		string s; cin >> s;

		for (ll j = 0; j < 10; j++)
		{
			if (s[j] == 'B') Bx = i, By = j;
			else if (s[j] == 'L') Lx = i, Ly = j;
			else if (s[j] == 'R') Rx = i, Ry = j;
		}
	}

	int ans = abs(Bx - Lx) + abs(By - Ly) - 1;

	if ((Bx == Lx && Bx == Rx && ((Ly < Ry && Ry < By) || (By < Ry && Ry < Ly)))
		|| (By == Ly && By == Ry && ((Lx < Rx && Rx < Bx) || (Bx < Rx && Rx < Lx))))
			ans += 2;

	cout << ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// TO TEST LOCALY PLEASE COMMENT THIS LINE
	setIO("buckets");
	solve();
}

/*
Bronze
Block Game
Normal

link to the problem:
http://www.usaco.org/index.php?page=viewproblem2&cpid=664
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

	vector<ll> ans(26, 0);

	for (ll i = 0; i < n; i++)
	{
		string a, b; cin >> a >> b;

		vector<ll> la(26, 0);
		vector<ll> lb(26, 0);

		for (ll j = 0; j < a.size(); j++)
			la[a[j] - 'a']+= 1;

		for (ll j = 0; j < b.size(); j++)
			lb[b[j] - 'a']+= 1;

		for (ll j = 0; j < 26; j++)
			ans[j] += max(la[j], lb[j]);
	}

	for (ll i = 0; i < 26; i++)
		cout << ans[i] << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// comment this line for localy test
	setIO("blocks");
	solve();
}

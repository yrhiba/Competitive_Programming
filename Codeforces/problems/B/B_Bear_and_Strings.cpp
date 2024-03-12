/*

Codeforces Round 226 (Div. 2)

B. Bear and Strings

link to the problem:
https://codeforces.com/contest/385/problem/B

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
	string s; cin >> s;

	vector < pair<ll, ll> > bears_pairs;

	string bear = "bear";

	ll i = 0, j;
	while (i < s.size())
	{
		j = 0;
		while (j < bear.size() && i + j < s.size() && s[i+j] == bear[j])
			j++;

		if (j == bear.size())
		{
			bears_pairs.push_back({i, i + j - 1});
			i += j;
			continue;
		}
		i++;
	}

	ll ans = 0;

	for (ll i = 0; i < bears_pairs.size(); i++)
	{
		for (ll x = bears_pairs[i].first; x >= 0; x--)
		{
			if (i && x == bears_pairs[i - 1].first)
					break;
			for (ll y = bears_pairs[i].second; y < s.size(); y++)
				ans += 1;
		}
	}

	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}
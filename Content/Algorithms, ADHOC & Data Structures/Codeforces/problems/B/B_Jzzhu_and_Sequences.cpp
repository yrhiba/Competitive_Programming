/*

Codeforces Round 257 (Div. 2)

B. Jzzhu and Sequences

link to the problem:
https://codeforces.com/contest/450/problem/B

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
	ll x, y; cin >> x >> y;

	ll n; cin >> n;
	n--;

	vector<ll> ans;

	ans.push_back((x + mod) % mod);
	ans.push_back((y + mod) % mod);

	ll repeted_sequence = -1;

	for (ll i = 2; i <= n; i++)
	{
		if ((i - 2) > 1)
		{
			if (ans[i - 2] == ans[0] && ans[i - 1] == ans[1])
			{
				repeted_sequence = i - 2;
				break;
			}
		}

		ans.push_back((ans[i - 1] - ans[i - 2] + mod) % mod);
	}

	if (repeted_sequence == -1)
	{
		cout << ans[n] << endl;
		return ;
	}

	cout << ans[(n % repeted_sequence)] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

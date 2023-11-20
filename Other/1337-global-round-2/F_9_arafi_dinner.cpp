/*

1337 Global Round 2

F. 9arafi dinner

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

ll dfs(vector<ll> &ans, ll &k, ll len)
{
	if (len < 0) return (0);
	if (len == 0) return (1);

	if (ans[len]) return (ans[len]);

	ll choose_w = dfs(ans, k, len - k);
	ll choose_b = dfs(ans, k, len - 1);

	return (ans[len] = ((choose_b%mod) + (choose_w%mod)) % mod);
}

void solve()
{
	ll t, k; cin >> t >> k;

	vector<ll> ans(1e5+1, 0);

	dfs(ans, k, 1e5);

	for (ll i = 1; i <= 1e5; i++)
	{
		ans[i] += ans[i - 1];
		ans[i] %= mod;
	}

	while (t--)
	{
		ll a, b; cin >> a >> b;
		cout << (ans[b] - ans[a-1] + mod) % mod << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

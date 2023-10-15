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
# define ull unsigned long long
# define ll long long
ll mod = 1000000007;
using namespace std;
ll powermod(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = powermod(x, p/2) % mod;
	if (p%2)
		return ((((res * res) % mod) * (x % mod)) % mod);
	return ((res * res) % mod);
}
ll power(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = power(x, p/2);
	if (p%2)
		return ((res * res) * x);
	return (res * res);
}

void solve()
{
	vector<ll> ans(2); cin >> ans[0] >> ans[1];

	ll n; cin >> n; ans.resize(n+1);

	for (ll i = 2; i <= n; i++)
	{
		ans[i - 1] = (ans[i - 1]+mod)%mod;
		ans[i - 2] = (ans[i - 2]+mod)%mod;
		ans[i] = (ans[i - 1] - ans[i - 2] + mod)%mod;
	}
	cout << ans[n] << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

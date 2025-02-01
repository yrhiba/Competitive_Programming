/*

Codeforces Round 279 (Div. 2)

B. Queue

link to the problem:
https://codeforces.com/contest/490/problem/B

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

	ll first_student = 0;
	ll second_student = -1;

	map<ll, ll> mp;
	map<ll, ll> rmp;
	for (ll i = 0; i < n; i++)
	{
		ll a, b; cin >> a >> b;
		mp[a] = b;
		rmp[b] = a;
	}

	for (auto &[i, j] : mp)
	{
		if (rmp.count(i) == 0)
		{
			second_student = i;
			break;
		}
	}

	vector<ll> ans(n + 2);

	ll i = 0;
	while (i <= n)
	{
		ans[i] = first_student;
		ans[i + 1] = second_student;

		first_student = mp[first_student];
		second_student = mp[second_student];
		i += 2;
	}

	for (ll i = 1; i <= n; i++)
		cout << ans[i] << " ";
	cout << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

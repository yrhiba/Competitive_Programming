/*
link to the problem:
https://www.spoj.com/problems/PRIME1/
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
#include <unordered_map>
#include <unordered_set>
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

vector<bool> primes_numbers(1000000001, true);

void setprimesnumbers()
{
	// that's function for huge query but in the problem
	// we don't have a lot
	// so checking for each number if is prime
	// and remember their ansewr it's work fine.
	primes_numbers[0] = primes_numbers[1] = false;
	for (ll i = 2; i <= 1e9; i++)
	{
		if (primes_numbers[i] == false) continue;
		for (ll j = i*i; j <= 1e9; j+=i)
			primes_numbers[j] = false;
	}
}

bool isprime(ll x)
{
	static unordered_map<ll, bool> dp;

	if (x <= 1)	return (false);

	if (dp.find(x) != dp.end())
		return (dp[x]);

	for (ll i = 2; i*i <= x; i++)
	{
		if (x%i == 0)
			return (dp[x] = false);
	}
	return (dp[x] = true);
}

void solve()
{
	ll m, n; cin >> m >> n;

	for (ll i = m; i <= n; i++)
	{
		if (isprime(i))
			cout << i << "\n";
	}

	// to seperat output of test cases
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	// seting all prime numbers;
	// setprimesnumbers();
	ll t; cin >> t;
	while (t--)
		solve();
}

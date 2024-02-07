/*
A. Make it White

link to the problem:
https://codeforces.com/contest/1927/problem/A
*/
# define TESTCASES 1
# define N 1e5
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <set>
#include <string>
#include <fstream>
#include <numeric>
using namespace std;
# define ll long long
# define ull long long
# define all(x) (x.begin(), x.end());
# define rall(x) (x.rbegin(), x.rend());
ll gcd(ll a, ll b)
{
	if (!b) return (a);
	return (gcd(b, a%b));
}
ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a, b));
}
vector<bool> is_prime;
vector<ll> primes;
void setPrimes(void)
{
	primes.reserve(1e4);
	is_prime = vector<bool>(N, true);
	is_prime[0] = is_prime[1] = false;
	for (ll i = 2; i <= N; i++)
	{
		if (!is_prime[i]) continue;
		primes.push_back(i);
		for (ll j = i*i; j <= N; j+=i) is_prime[j] = false;
	}
}

void solve()
{
	ll n; cin >> n;
	string s; cin >> s;
	vector<ll> a;
	for (ll i = 0; i < s.size(); i++)
		if (s[i] == 'B')
			a.push_back(i);

	if (a.size())
		cout << a.back() - a.front() + 1 << "\n";
	else
		cout << 0 << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t = 1;
	#if TESTCASES
	cin >> t;
	#endif
	while (t--)
		solve();
}

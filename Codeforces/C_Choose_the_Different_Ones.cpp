/*
C. Choose the Different Ones!

link to the problem:
https://codeforces.com/contest/1927/problem/C
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
#include <algorithm>
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
	ll n, m, k; cin >> n >> m >> k;
	set<ll> sa, sb;
	vector<ll> a, b;
	for (ll i = 0; i < n; i++)
	{
		ll t; cin >> t;
		if (t > k) continue;
		a.push_back(t);
		sa.insert(a.back());
	}
	for (ll i = 0; i < m; i++)
	{
		ll t; cin >> t;
		if (t > k) continue;
		b.push_back(t);
		sb.insert(b.back());
	}
	if (!(sa.size() >= k/2 && sb.size() >= k/2))
	{
		cout << "NO\n";
		return ;
	}
	ll fixedA = 0, fixedB = 0, comman = 0;
	for (ll i = 1; i <= k; i++)
	{
		if (sa.count(i) && sb.count(i) == 0)
			fixedA += 1;
		else if (sa.count(i) == 0 && sb.count(i))
			fixedB += 1;
		else if (sa.count(i) && sb.count(i))
			comman += 1;
		else
		{
			cout << "NO\n";
			return ;
		}
	}
	if (fixedA + comman >= k/2 && fixedB + comman >= k/2)	cout << "YES\n";
	else cout << "NO\n";
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

/*
B. Colorful Field

link to the problem:
https://codeforces.com/contest/79/problem/B
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
# define ll int
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
	ll n, m, k, t; cin >> n >> m >> k >> t;

	string	outs[] = {"Carrots", "Kiwis", "Grapes"};

	vector<ll> value;

	while (k--)
	{
		ll a, b;

		cin >> a >> b; a--; b--;

		value.push_back(b + a * m);
	}

	sort(value.begin(), value.end());

	while (t--)
	{ 
		ll a, b;

		cin >> a >> b; a--; b--;

		ll idx = b + a * m;

		ll start = 0;
		ll end = value.size() - 1;
		ll ans = 0;
		ll mid;

		bool found = false;

		while (start <= end)
		{
			mid = start + ((end - start) / 2);

			if (value[mid] == idx)
			{
				found = true;
				break;
			}

			if (value[mid] < idx)
			{
				ans = mid + 1;
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}

		if (found)
		{
			cout << "Waste\n";
			continue;
		}

		cout << outs[(idx - ans) % 3] << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

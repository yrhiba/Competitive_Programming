/*

Codeforces Round 950 (Div. 3)

D. GCD-sequence

time limit per test: 2 second
memory limit per test: 256 megabytes
input: standard input
output: standard output

link to the problem:
https://codeforces.com/contest/1980/problem/D

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
#include <numeric>

# define ll long long

using namespace std;

ll gcd(ll a, ll b)
{
	if (b == 0) return (a);
	return (gcd(b, a%b));
}

void solve()
{
	ll n; cin >> n;
	vector<ll> a(n);
	for (ll &i : a )cin >> i;
	vector<ll> b(1, 0), isSorted(1, 0);
	for (ll i = 1; i < n; i++)
	{
		b.push_back(gcd(a[i-1], a[i]));
		isSorted.push_back(b[i] < b[i-1]);
		isSorted[i] += isSorted[i-1];
	}
	for (ll i = 0; i < 3; i++)
		b.push_back(1e18), isSorted.push_back(isSorted.back());
	//
	for (ll i = 0; i < n; i++)
	{
		bool left = ((i-1 >= 0) ? isSorted[i-1] : 0);
		bool right = isSorted.back() - isSorted[i+2];

		if (!left && !right)
		{
			if (i-1 >= 0 && i+1 < n)
			{
				ll nexX = gcd(a[i-1], a[i+1]);
				if (((i-1>=0) ? b[i-1] : 0) <= nexX && nexX <= b[i+2])
				{
					cout << "YES\n";
					return ;
				}
			}
			else
			{
				cout << "YES\n";
				return ;
			}
		}
	}
	cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--) solve();
}

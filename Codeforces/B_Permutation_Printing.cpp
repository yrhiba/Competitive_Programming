/*
B. Permutation Printing

link to the problem:
https://codeforces.com/contest/1930/problem/B
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
# define ull unsigned long long
# define ll long long
const ll mod = 1e9 + 7;
using namespace std;

void solve()
{
	ll n; cin >> n;

	vector<ll> a(n);

	for (ll i = 0, G = n, g = 1; i < n; i++)
	{
		if (i%2) a[i] = G--;
		else a[i] = g++;
	}

	for (ll i = 0; i < n; i++) cout << a[i] << " \n"[i+1==n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--)
		solve();
}

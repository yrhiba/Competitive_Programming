/*
A. Phone Desktop

time limit per test: 1 second
memory limit per test: 256 megabytes
input: standard input
output: standard output

link to the problem:
https://codeforces.com/contest/1974/problem/A
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

void solve()
{
	ll x, y; cin >> x >> y;

	ll ans = 0;

	ans = (y+1) / 2;

	ll ones_have = ans * 7 + (y%2 ? 4 : 0);

	ll rest_ones = x - ones_have;

	if (rest_ones < 0)
	{
		cout << ans << '\n';
	}
	else
	{
		cout << ans + ((rest_ones / 15) + ((rest_ones % 15) > 0)) << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	for (ll i = 1; i <= t; i++)
	{
		solve();
	}
}

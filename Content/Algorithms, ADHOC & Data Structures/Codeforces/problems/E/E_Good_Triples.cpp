/*
Codeforces Round 913 (Div. 3)

E. Good Triples

link to the problem:
https://codeforces.com/contest/1907/problem/E
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
	map<ll, ll> mp;
	for (ll i = 0; i <= 10; i++)
		for (ll j = 0; j <= 10; j++)
			for (ll k = 0; k <= 10; k++)
				mp[i+j+k] += 1;

	string s; cin >> s;

	ll ans = 1;

	for (char c : s)
		ans *= mp[c - '0'];

	cout << ans << "\n";
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

/*

Starters 111 (Rated till 6 Stars)

Beautiful Strings

link to the problem:
https://www.codechef.com/problems/BEAUTYSTR

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
	ll n; cin >> n;
	string s; cin >> s;

	map<char, ll> mp;

	for (char c : s)
	{
		if (!mp.count(c)) mp[c] += 1;
		mp[c] += 1;
	}

	ll ans = 1;
	for (auto &[i, j] : mp)
		ans = ((ans%mod) * (j%mod)) % mod;

	cout << ans - 1 << "\n";
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

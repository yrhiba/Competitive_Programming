/*
link to the problem:
https://codeforces.com/contest/1948/problem/D
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
//

void solve()
{
	string s;
	cin >> s;
	//
	ll n = s.size();
	//
	for (ll ans = n - n%2, p = 0; ans >= 2; ans -= 2, p = 0)
	{
		ll nx = ans/2;
		//
		for (ll i = 0; i+nx < n; i++)
		{
			if (s[i] == s[i+nx] || s[i] == '?' || s[i+nx] == '?') p++;
			else p = 0;
			//
			if (p == nx)
			{
				cout << ans << '\n';
				return ;
			}
		}
	}
	cout << 0 << "\n";
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

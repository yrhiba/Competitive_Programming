/*

Starters 112 Division 3 (Rated)

3 Logicians Walk into a Bar

link to the problem:
https://www.codechef.com/problems/LOGICIAN

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

	ll want = 0, does = 0;

	for (ll i = 0; i < n; i++)
	{
		does += (s[i] == '0');
		want += (s[i] == '1');

		if (does > 0)
		{
			cout << "NO\n";
		}
		else if (i+1 < n)
		{
			cout << "IDK\n";
		}
		else
		{
			cout << "YES\n";
		}
	}
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

/*

Codeforces Round 913 (Div. 3)

A. Rook

link to the problem:
https://codeforces.com/contest/1907/problem/A

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
	string s; cin >> s;
	map< pair<ll, ll> , bool > mp;

	char r = s[1];
	char c = s[0];

	for (char i = '1'; i <= '8'; i++)
	{
		for (char j = 'a'; j <= 'h'; j++)
		{
			if (i == r && j == c) continue;

			if (i == r || j == c)
				cout << j << i << "\n";
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

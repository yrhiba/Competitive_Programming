/*
A. Recovering a Small String

link to the problem:
https://codeforces.com/contest/1931/problem/A
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
	string ans = "zzz";
	for (char a = 'a'; a <= 'z'; a++)
	for (char b = 'a'; b <= 'z'; b++)
	for (char c = 'a'; c <= 'z'; c++)
	{
		if ((a-'a') + (b-'a') + (c-'a') + 3 == n)
		{
			string x = ""; x += a; x+=b, x+=c;
			if (ans > x) ans = x;
		}
	}
	cout << ans << '\n';
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

/*

AtCoder Beginner Contest 332

C - T-shirts

link to the problem:
https://atcoder.jp/contests/abc332/tasks/abc332_c

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
	ll n, m; cin >> n >> m;

	string s; cin >> s;

	ll ans = 0;

	ll plain = m, logo = 0;
	for (char c : s)
	{
		if (c == '0')
		{
			plain = m;
			logo = ans;
		}
		else
		if (c == '1')
		{
			if (plain > 0)
			{
				plain -= 1;
			}
			else
			if (logo > 0)
			{
				logo -= 1;
			}
			else
			{
				ans += 1;
			}
		}
		else
		if (c == '2')
		{
			if (logo > 0)
			{
				logo -= 1;
			}
			else
			{
				ans += 1;
			}
		}
	}

	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

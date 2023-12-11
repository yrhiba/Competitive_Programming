/*

AtCoder Beginner Contest 332

B - Glass and Mug

link to the problem:
https://atcoder.jp/contests/abc332/tasks/abc332_b

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
	ll k, x, y; cin >> k >> x >> y;

	ll a, b; a = b = 0;

	while (k--)
	{
		if (a == x)
		{
			a = 0;
		}
		else
		if (b == 0)
		{
			b = y;
		}
		else
		{
			ll max_can_field = x - a;

			if (max_can_field <= b)
			{
				a = x;
				b -= max_can_field;
			}
			else
			{
				a += b;
				b = 0;
			}
		}
	}

	cout << a << " " << b << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

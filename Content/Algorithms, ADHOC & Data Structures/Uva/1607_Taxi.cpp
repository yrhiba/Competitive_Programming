/*
link to the problem:
https://acm.timus.ru/problem.aspx?space=1&num=1607
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
	ll a, b, c, d; cin >> a >> b >> c >> d;
	if (a >= c)
	{
		cout << a << "\n";
		return ;
	}
	ll ans = -1;
	for (ll i = 1; ; i++)
	{
		if (i%2)
		{
			if (a+b >= c)
			{
				ans = c;
				break;
			}
			else a += b;
		}
		else
		{
			if (c-d <= a)
			{
				ans = a;
				break;
			}
			else c -= d;
		}
	}
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

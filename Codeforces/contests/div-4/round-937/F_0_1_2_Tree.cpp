/*
link to the problem:
https://codeforces.com/contest/1950/problem/F
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
	ll a, b, c; cin >> a >> b >> c;
	//
	queue<ll> q;
	q.push(0);
	//
	ll ans = 0;
	//
	while (!q.empty())
	{
		ll cur = q.front();
		q.pop();
		//
		ans = max(ans, cur);
		//
		if (a)
		{
			q.push(cur + 1);
			q.push(cur + 1);
			a -= 1;
		}
		else
		{
			if (b)
			{
				q.push(cur + 1);
				b -= 1;
			}
			else
			{
				if (c) c -= 1;
				else
				{
					cout << "-1\n";
					return ;
				}
			}
		}
	}
	//
	if (!a && !b && !c) cout << ans << "\n";
	else cout << "-1\n";
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

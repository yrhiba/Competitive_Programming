/*
C. Sasha and the Casino

link to the problem:
https://codeforces.com/contest/1929/problem/C
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
	ll k, x, a; cin >> k >> x >> a;
	ll lose = 1, bet = 1, have = a;
	for (ll i = 2; i <= (x+1); i++)
	{
		ll start = 1;
		ll end = have;
		ll mid, bet = -1;
		while (start <= end)
		{
			mid = start + (end - start) / 2;
			if (mid*(k-1)>lose)
			{
				bet = mid;
				end = mid - 1;
			}
			else start = mid + 1;
		}
		if (bet == -1)
		{
			cout << "NO\n";
			return ;
		}
		have -= bet;
		lose += bet;
	}
	if (have > 0) cout << "YES\n";
	else cout << "NO\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--)	solve();
}

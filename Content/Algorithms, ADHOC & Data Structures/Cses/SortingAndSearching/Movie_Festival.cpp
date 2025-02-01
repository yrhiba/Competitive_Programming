/*
CSES Problem Set

Movie Festival

link to the problem:
https://cses.fi/problemset/task/1629
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
# define ll long long
using namespace std;

void solve()
{
	ll n; cin >> n;
	vector< vector<ll> > a(n*2, vector<ll>(3));
	for (ll i = 0; i < (n*2); i+=2)
	{
		ll x, y; cin >> x >> y;
		a[i][0] = x;
		a[i][1] = 1;
		a[i][2] = i;
		a[i+1][0] = y;
		a[i+1][1] = -1;
		a[i+1][2] = i;
	}
	sort(a.begin(), a.end());
	map<ll, bool> mp;
	stack<ll> st;
	ll ans = 0;
	for (ll i = 0; i < (n*2); i++)
	{
		if (a[i][1] == 1)
		{
			st.push(a[i][2]);
		}
		else
		{
			if (mp.count(a[i][2])) continue;
			ans += 1;
			while (!st.empty())
			{
				mp[st.top()] = 1;
				st.pop();
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

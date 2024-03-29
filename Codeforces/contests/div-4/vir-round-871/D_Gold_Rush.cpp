/*
link to the problem:
https://codeforces.com/contest/1829/problem/D
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
	ll n, m; cin >> n >> m;
	queue<ll> q;
	set<ll> vis;
	q.push(n);
	while (!q.empty())
	{
		ll cur = q.front();
		q.pop();
		if (cur == m)
		{
			cout << "YES\n";
			return ;
		}
		if (cur%3) continue;
		ll a = (cur*2)/3, b = cur/3;
		if (!vis.count(a) || a < m)
		{
			q.push(a);
			vis.insert(a);
		}
		if (!vis.count(b) || b < m)
		{
			q.push(b);
			vis.insert(b);
		}
	}
	cout << "NO\n";
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	ll t; cin >> t;
	while (t--)
		solve();
}

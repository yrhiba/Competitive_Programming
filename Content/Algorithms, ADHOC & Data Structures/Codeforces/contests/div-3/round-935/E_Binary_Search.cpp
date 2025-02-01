/*
link to the problem:
https://codeforces.com/contest/1945/problem/E
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
#include <cassert>
# define ull unsigned long long
# define ll long long
ll mod = 1e9 + 7;
using namespace std;

void solve()
{
	ll n, x; cin >> n >> x;
	vector<ll> a(n+1);
	ll where_x = -1;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] == x) where_x = i;
	}
	//
	vector<ll> isIn(n+1, 0);
	ll l = 1, r = n+1, m;
	while (abs(l - r) > 1)
	{
		m = (r + l) / 2;
		if (a[m] <= x) 
		{
			l = m;
			isIn[m] = +1;
		}
		else
		{
			r = m;
			isIn[m] = -1;
		}
	}
	cout << 1 << "\n";
	cout << where_x << " " << l << "\n";
}

int main()
{
	cin.tie()->sync_with_stdio(false);
	ll t; cin >> t;
	while (t--) solve();
}

/*

Educational Codeforces Round 158 (Rated for Div. 2)

C. Add, Divide and Floor

link to the problem:
https://codeforces.com/contest/1901/problem/C

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
	ll n; cin >> n;
	ll a=1e9, b=0;
	for (ll i= 0; i < n; i++)
	{
		ll t; cin >> t;
		a = min(t, a);
		b = max(t, b);
	}
	vector<ll> ans;
	while (a != b)
	{
		if (a>b)
			swap(a, b);

		if (a%2 && b%2==0)
		{
			a = (a+1) / 2;
			b = (b+1) / 2;
			ans.push_back(1);
		}
		else
		{
			a/=2;
			b/=2;
			ans.push_back(0);
		}
	}
	cout << ans.size() << "\n";
	if (ans.size() && ans.size() <= n)
	{
		for (auto &i : ans)
			cout << i << ' ';
		cout << "\n";
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

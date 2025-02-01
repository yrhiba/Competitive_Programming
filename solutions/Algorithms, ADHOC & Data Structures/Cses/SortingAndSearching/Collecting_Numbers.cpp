/*
Sorting and Searching

link to the problem:
https://cses.fi/problemset/task/2216/
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
	vector<ll> a(n);
	for (ll &i : a)
		cin >> i;
	//
	vector<ll> ans(n+1, 0);
	ll cur = 0;
	ll res = 0;
	//
	for (ll i = 0; i < n; i++)
	{
		if (ans[a[i] - 1] != 0) ans[a[i]] = ans[a[i] - 1];
		else res = max(res, cur + 1), ans[a[i]] = cur + 1, cur += 1;
	}
	//
	cout << res << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

/*
C. Lexicographically Largest

link to the problem:
https://codeforces.com/contest/1930/problem/C
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
	ll n; cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		a[i] += (i+1);
	}
	sort(a.rbegin(), a.rend());
	vector<ll> ans; ans.push_back(a[0]);
	ll last = a[0];
	for (ll i = 1; i < n; i++)
	{
		if (a[i] < last) last = a[i];
		else a[i]=last=last-1;
		ans.push_back(a[i]);
	}
	sort(ans.rbegin(), ans.rend());
	for (ll i = 0; i < n; i++) cout << ans[i] << " \n"[i+1==n];
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

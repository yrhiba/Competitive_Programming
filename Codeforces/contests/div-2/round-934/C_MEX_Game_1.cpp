/*
link to the problem:
https://codeforces.com/contest/1944/problem/C
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
	multiset<ll> st;
	for (ll &i : a)
	{
		cin >> i;
		st.insert(i);
	}
	sort(a.begin(), a.end());
	//
	ll toPickFirst = -1;
	for (ll i = 0; i < n; i++)
		if (st.count(i) == 1)
		{
			toPickFirst = i;
			break;
		}
	//
	ll ans = 0;
	//
	for (ll i = 0; i < n; i++)
	{
		if (i == toPickFirst || st.count(i) >= 2) ans += 1;
		else break;
	}
	//
	cout << ans << "\n";
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

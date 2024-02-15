/*
B. Equalize

link to the problem:
https://codeforces.com/contest/1928/problem/B
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
	vector<ll> a; a.reserve(n+1);
	set<ll> st;
	for (ll i = 0; i < n; i++)
	{
		ll t; cin >> t;
		if (st.find(t) != st.end()) continue;
		a.push_back(t);
		st.insert(t);
	}
	if (a.size() == 1)
	{
		cout << 1 << "\n";
		return ;
	}
	sort(a.begin(), a.end());
	vector<ll> m(a.size()); m[0] = 0;
	for (ll i = 1; i < a.size(); i++) m[i] = (a[i] - a[i-1]) + m[i-1];
	ll ans = 1;
	for (ll i = 0; i+1 < a.size(); i++)
	{
		ll start = i+1;
		ll end = a.size()-1;
		ll mid;
		while (start <= end)
		{
			mid = start + (end-start)/2;
			if (m[mid]-m[i]<n)
			{
				ans = max(ans, mid-i+1);
				start = mid + 1;
			}
			else end = mid - 1;
		}
	}
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

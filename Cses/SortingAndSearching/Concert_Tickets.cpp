/*

CSES Problem Set

Concert Tickets

link to the problem:
https://cses.fi/problemset/task/1091/

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
	ll n, m; cin >> n >> m;
	multiset< ll, greater<ll> > st;
	for (ll i= 0; i < n; i++)
	{
		ll t; cin >> t;
		st.insert(t);
	}
	vector<ll> ans(m, -1);
	for (ll i = 0; i < m; i++)
	{
		ll t; cin >> t;
		auto a = st.lower_bound(t);
		if (a == st.end()) continue;
		ans[i] = *a;
		st.erase(a);
	}
	for (ll i = 0; i < m; i++)
		cout << ans[i] << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

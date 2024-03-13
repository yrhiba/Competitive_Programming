/*
link to the problem:
https://codeforces.com/contest/1941/problem/E
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

ll n, m, k, d;

ll calc_cost(vector<ll> &a)
{
	multiset<ll> st;
	vector<ll> dp(m, -1);
	//
	st.insert(1);
	dp[0] = 1;
	//
	for (ll i = 1, j = 0; i < m; i++)
	{
		while ((i - j) - 1 > d) st.erase(st.find(dp[j])), j++;
		//
		dp[i] = a[i] + 1 + *(st.begin());
		//
		st.insert(dp[i]);
	}
	//
	return (dp[m-1]);
}

void solve()
{
	cin >> n >> m >> k >> d;
	vector< vector<ll> > a(n, vector<ll>(m));
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
			cin >> a[i][j];
	//
	ll ans = 1e18;
	vector<ll> costs(n);
	//
	for (ll i = 0; i < n; i++)
	{
		costs[i] = calc_cost(a[i]);
		//
		if (i) costs[i] += costs[i - 1];
		//
		ll left = i - k, right = i;
		//
		if (i+1 >= k) ans = min(ans, costs[right] - ((left>=0)?costs[left]:0));
	}
	//
	cout << ans << '\n';
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	ll t; cin >> t;
	while (t--)
		solve();
}

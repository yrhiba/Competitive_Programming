/*
CSES Problem Set

Subarray Sums I

link to the problem:
https://cses.fi/problemset/task/1660/
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
	ll n, x; cin >> n >> x;
	vector<ll> a(n+1, 0);
	multiset<ll> st; st.insert(0);
	ll ans = 0;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] += a[i - 1];
		if (st.count(a[i] - x))
			ans += 1;
		st.insert(a[i]);
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

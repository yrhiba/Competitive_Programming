/*
C. Make Equal Again

link to the problem:
https://codeforces.com/contest/1931/problem/C
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
	for (ll &i : a) cin >> i;
	ll ans = n;
	ll i = 0, j = n, v = a[0];
	while (i+1 < n && a[i+1] == v) i++;
	while (j-1 >= 0 && a[j-1] == v) j--;
	ans = min(ans, (j<=i) ? 0 : j - i - 1);
	i = -1, j = n-1; v = a[n-1];
	while (i+1 < n && a[i+1] == v) i++;
	while (j-1 >= 0 && a[j-1] == v) j--;
	ans = min(ans, (j<=i) ? 0 : j - i - 1);
	cout << ans << endl;
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

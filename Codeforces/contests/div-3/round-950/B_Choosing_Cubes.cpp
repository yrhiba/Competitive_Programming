/*

Codeforces Round 950 (Div. 3)

B. Choosing Cubes

time limit per test: 1 second
memory limit per test: 256 megabytes
input: standard input
output: standard output

link to the problem:
https://codeforces.com/contest/1980/problem/B

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

# define ll long long

using namespace std;

void solve()
{
	ll n, f, k; cin >> n >> f >> k;
	f -= 1;
	vector<ll> a(n);
	for (ll &i : a) cin >> i;
	ll value = a[f];
	sort(a.rbegin(), a.rend());
	ll left, right; left = right = -1;
	for (ll i = 0; i < n; i++)
		if (a[i] == value)
		{
			left = i;
			while (i+1 < n && a[i+1] == a[left]) i += 1;
			right = i;
			break;
		}
	//
	if (left > k-1) cout << "NO\n";
	else if (right <= k-1) cout << "YES\n";
	else cout << "MAYBE\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--) solve();
}

/*

Starters 112 Division 3 (Rated)

Max Nutrition

link to the problem:
https://www.codechef.com/problems/NUTRITION

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
	vector<ll> a(n+1, 0);
	vector<ll> x(n);
	for (auto &i : x)
		cin >> i;
	vector<ll> y(n);
	for (auto &i : y)
		cin >> i;
	for (ll i = 0; i < n; i++)
		a[x[i]] = max(a[x[i]], y[i]);
	ll ans = 0;
	for (auto &i : a)
		ans += i;
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

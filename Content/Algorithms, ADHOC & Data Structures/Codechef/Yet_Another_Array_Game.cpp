/*

Starters 112 Division 3 (Rated)

Yet Another Array Game

link to the problem:
https://www.codechef.com/problems/ARRAYGAME

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

void solve1()
{
	ll n; cin >> n;

	vector<ll> a(n);
	for (auto &i : a)
		cin >> i;
	sort(a.begin(), a.end());
	ll ans = 0;
	if (n%2)
	{
		for (ll i = 0; i < (n+1)/2; i++)
			ans += a[i];
	}
	else
	{
		for (ll i = 1; i <= n/2; i++)
			ans += a[i];
	}
	cout << ans << '\n';
}

void solve2()
{
	ll n; cin >> n;
	vector<ll> a(n);
	for (ll &i : a)
		cin >> i;
	sort(a.rbegin(), a.rend());
	vector<ll> p(n+1, 0);
	for (ll i = 0; i < n; i++)
		p[i+1] = p[i] + a[i];
	ll maxe = (n+1)/2;
	ll ans = 0;
	for (ll i = 1; i <= maxe; i++)
		ans = max(ans, p[i+i-1] - p[i-1]);
	cout << ans << "\n";
}

void solve(ll s)
{
	if (s == 0)
		solve1();
	else
		solve2();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t, s; cin >> t >> s;
	while (t--)
		solve(s);
}

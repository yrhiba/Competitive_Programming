/*
link to the problem:
https://codeforces.com/contest/1945/problem/C
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
	string s; cin >> s;
	//
	double target = (n * 1.0f) / 2.0f;
	//
	vector<ll> ones(n+2, 0), zeros(n+2, 0);
	for (ll i = 1; i <= n; i++)
	{
		ones[i] = (s[i-1] == '1') + ones[i-1];
		zeros[i] = (s[i-1] == '0') + zeros[i-1];
	}
	//
	ll ans = -1;
	double dis = -1;
	//
	for (ll i = 0, r = n; i <= n; i++, r--)
	{
		//
		ll left_satisfied = zeros[i];
		ll right_satisfied = ones[n] - ones[i];
		//
		if (((i+1)/2) <= left_satisfied && ((r+1)/2) <= right_satisfied)
			if ((ans == -1) || (abs(target - i) < dis))
			{
				ans = i;
				dis = abs(target - i);
			}
	}
	//
	cout << ans << "\n";
}

int main()
{
	cin.tie()->sync_with_stdio(false);
	ll t; cin >> t;
	while (t--)
		solve();
}

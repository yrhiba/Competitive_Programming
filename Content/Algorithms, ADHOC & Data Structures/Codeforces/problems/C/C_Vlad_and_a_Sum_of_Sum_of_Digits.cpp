/*
C. Vlad and a Sum of Sum of Digits

link to the problem:
https://codeforces.com/contest/1926/problem/C
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
vector<ll> ans;

void solve()
{
	ll n; cin >> n;
	cout << ans[n] << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ans.resize(2e5+1);
	ans[0] = 0;
	for (ll i = 1; i <= 2e5; i++)
	{
		ans[i] = ans[i-1];
		ll x = i;
		while (x) ans[i]+=(x%10), x/=10;
	}
	ll t; cin >> t;
	while (t--)
		solve();
}

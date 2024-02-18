/*
E. Final Countdown

link to the problem:
https://codeforces.com/contest/1932/problem/E
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
	string s; cin >> s;
	vector<ll> ans;
	ll res = 0, r = 0;
	for (char c : s) res += (c-'0');
	ans.push_back(res%10);
	r = res/10;
	for (ll i = 1; i < n; i++)
	{
		res -= (s[n-i]-'0');
		ans.push_back((res+r)%10);
		r = (res+r)/10;
	}
	while (r) ans.push_back(r%10), r/=10;
	reverse(ans.begin(), ans.end());
	ll i = 0;
	while (!ans[i]) i++;
	for (; i < ans.size(); i++) cout << ans[i];
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--)	solve();
}

/*
D. Missing Subsequence Sum

link to the problem:
https://codeforces.com/contest/1966/problem/D
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
	ll n, k, j; cin >> n >> k;
	vector<ll> ans;
	for (ll i = 0; i < 20; i++)
	{
		if ((1<<i) <= k && k <= (1<<i) + (1<<i) - 1)
		{
			j = i;
			continue;
		}
		ans.push_back(1<<i);
	}

	ans.push_back(k - (1<<j));
	ans.push_back(k + 1);
	ans.push_back(k + 1 + (1<<j));

	cout << ans.size() << "\n";
	for (ll i = 0; i < ans.size(); i++)
		cout << ans[i] << " \n"[i+1 == ans.size()];
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

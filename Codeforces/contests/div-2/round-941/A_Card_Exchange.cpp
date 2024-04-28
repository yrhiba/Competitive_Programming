/*
A. Card Exchange

link to the problem:
https://codeforces.com/contest/1966/problem/A
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
	ll n, k; cin >> n >> k;
	map<ll, ll> mp;
	for (ll i = 0; i < n; i++)
	{
		ll t; cin >> t;
		mp[t] += 1;
	}
	priority_queue<ll> pr;
	for (auto &[num, cnt] : mp) pr.push(cnt);
	//
	while (!pr.empty())
	{
		ll b = pr.top();
		pr.pop();

		if (b > k)
		{
			pr.push(b - 1);
		}
		else if (b == k)
		{
			if (!pr.empty())
			{
				ll x = pr.top();
				pr.pop();
				pr.push(x + (k - 1));
			}
			else
			{
				cout << k - 1 << "\n";
				return ;
			}
		}
		else
		{
			pr.push(b);
			break;
		}
	}
	//
	ll ans = 0;
	while (!pr.empty())
	{
		ans += pr.top();
		pr.pop();
	}
	//
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

/*
CSES Problem Set

Sum of Three Values

link to the problem:
https://cses.fi/problemset/task/1641
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
	ll n, x; cin >> n >> x;
	vector<pair<ll, ll>> a(n);
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a.begin(), a.end());
	map<ll, ll> mp;
	for (ll i = 0; i < n; i++)
	{
		for (ll j = i+1; j < n; j++)
			if (mp.find(x - (a[i].first + a[j].first)) != mp.end())
			{
				cout << a[i].second << " " << a[j].second << " " << mp[x - (a[i].first + a[j].first)] << endl;
				return ;
			}
		//
		mp[a[i].first] = a[i].second;
	}
	//
	cout << "IMPOSSIBLE" << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

/*
CSES Problem Set

Sum of Four Values

link to the problem:
https://cses.fi/problemset/task/1642/
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
using namespace std;

void solve()
{
	int n, x; cin >> n >> x;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	//
	map<ll, set<pair<ll, ll>>> mp;
	//
	for (ll i = 0; i < n; i++)
		for (ll j = i+1; j < n; j++) mp[a[i] + a[j]].insert({i+1, j+1});
	//
	for (ll i = 0; i < n; i++)
		for (ll j = i+1; j < n; j++)
		{
			ll m = x - (a[i] + a[j]);
			//
			if (mp.find(m) != mp.end())
			{
				auto it = mp[m].lower_bound({j+2, 0});
				//
				if (it != mp[m].end())
				{
					cout << i+1 << " " << j+1 << " " << it->first << " " << it->second << endl;
					return ;
				}
			}
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

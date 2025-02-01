/*
CSES Problem Set

Playlist

link to the prbolem:
https://cses.fi/problemset/task/1141/
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
	vector<ll> a(n);
	map<ll, ll> ids;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		ids[a[i]] += 1;
	}
	//
	ll id = 0;
	for (auto &[song, toId] : ids) toId = id++;
	//
	for (ll i = 0; i < n; i++) a[i] = ids[a[i]];
	//
	vector<bool> vis(n, false);
	ll left = 0, toAdd = 0, ans = 0;
	while (toAdd < n)
	{
		while (vis[a[toAdd]]) vis[a[left++]] = false;
		//
		vis[a[toAdd++]] = true;
		ans = max(ans, toAdd - left);
	}
	//
	cout << ans << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

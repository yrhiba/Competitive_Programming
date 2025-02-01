/*

Codeforces Round 915 (Div. 2)

B. Begginer's Zelda

link to the problem:
https://codeforces.com/contest/1905/problem/B

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

	map<ll, vector<ll> > g;
	set<ll> st;
	for (ll i = 0; i < n-1; i++)
	{
		ll u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		st.insert(u);
		st.insert(v);
	}
	ll ans = 0;
	vector<bool> vis(1e5+1, false);
	queue<ll> q;
	q.push(*st.begin());
	vis[*st.begin()] = true;
	ll turn = 0;
	while(!q.empty())
	{
		ll cur = q.front();
		q.pop();
		ll go = 0;
		for (auto &i : g[cur])
		{
			if (vis[i]) continue;
			go += 1;
			vis[i] = true;
			q.push(i);
		}

		if (go == 0)
			ans += 1;
		else if (go == 1 && turn == 0)
			ans += 1;

		turn += 1;
	}

	cout << (ans+1)/2 << endl;
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
/*
link to the problem:
https://cses.fi/problemset/task/1667/
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
	ll n, m; cin >> n >> m;
	vector< vector<ll> > g(n);
	for (ll i = 0; i < m; i++)
	{
		ll a, b; cin >> a >> b;
		a -=  1;
		b -= 1;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	//
	ll end = n - 1;
	//
	queue<ll> q;
	queue<ll> steps;
	//
	q.push(0);
	steps.push(0);
	//
	vector<bool> vis(n, false);
	vis[0] = true;
	//
	map< ll, ll > parent;
	parent[0] = -1;
	//
	while (!(q.empty()))
	{
		ll cur_computer = q.front();
		ll cur_steps = steps.front();
		//
		q.pop();
		steps.pop();
		//
		if (cur_computer == end) break;
		//
		for (ll next_cp : g[cur_computer])
		{
			if (vis[next_cp]) continue;
			vis[next_cp] = true;
			q.push(next_cp);
			steps.push(cur_steps + 1);
			parent[next_cp] = cur_computer;
		}
	}
	//
	if (!vis[end])
	{
		cout << "IMPOSSIBLE\n";
		return ;
	}
	vector<ll> road;
	ll cur_cp = end;
	while (cur_cp != -1)
	{
		road.push_back(cur_cp);
		cur_cp = parent[cur_cp];
	}
	//
	reverse(road.begin(), road.end());
	cout << road.size() << "\n";
	for (ll i = 0; i < road.size(); i++)
		cout << road[i] + 1 << " \n"[i+1 == road.size()];
	//
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

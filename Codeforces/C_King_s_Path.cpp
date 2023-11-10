/*
C. King's Path

link to the problem:
https://codeforces.com/contest/242/problem/C
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
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}
ll power(ll x, ll p)
{
	if (p == 0) return (1);
	ll res = power(x, p/2);
	if (p%2)
		return ((res * res) * x);
	return (res * res);
}
ll gcd(ll a, ll b)
{
	if (b == 0) return (a);
	return (gcd(b, a%b));
}
ll lcm(ll a, ll b)
{
	return ((a*b)/gcd(a, b));
}

ll dr[] = {0, 0, 1, -1, 1, -1, 1, -1};
ll dc[] = {1, -1, 0, 0, -1, 1, 1, -1};

ll x, y;

void solve()
{
	ll start_x, start_y;

	cin >> start_x >> start_y;
	cin >> x >> y;

	map<ll, set< pair<ll, ll> > > mp;

	ll n; cin >> n;
	for (ll i = 0; i < n; i++)
	{
		ll r, ci, cj; cin >> r >> ci >> cj;
		mp[r].insert({cj, ci});
	}

	queue< pair<ll, ll> > q;	q.push({start_x, start_y});
	queue< ll > moves;			moves.push(0);

	map< pair<ll, ll> , bool > visited;	visited[{start_x, start_y}] = true;

	while (!q.empty() && !moves.empty())
	{

		pair <ll, ll>	&cur = q.front();
		ll				cur_moves = moves.front();

		if (cur.first == x && cur.second == y)
		{
			cout << cur_moves << endl;
			return ;
		}

		for (ll d = 0; d < 8; d++)
		{
			if (cur.first + dr[d] < 1 || cur.first + dr[d] > 1e9) continue;
			if (cur.second + dc[d] < 1 || cur.second + dc[d] > 1e9) continue;

			if (visited.count({cur.first + dr[d], cur.second + dc[d]})) continue;

			if (mp.find(cur.first + dr[d]) == mp.end()) continue;

			bool notvalid = true;

			for (auto &[ff, ss] : mp[cur.first + dr[d]])
			{
				if (ss <= cur.second + dc[d] && cur.second + dc[d] <= ff)
				{
					notvalid = false;
					break;
				}
			}

			if (notvalid) continue;

			visited[{cur.first + dr[d], cur.second + dc[d]}] = true;

			q.push({cur.first + dr[d], cur.second + dc[d]});
			moves.push(cur_moves + 1);
		}
		q.pop();
		moves.pop();
	}

	cout << -1 << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

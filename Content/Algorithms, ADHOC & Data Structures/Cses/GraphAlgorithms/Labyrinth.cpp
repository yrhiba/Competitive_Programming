/*
link to the problem:
https://cses.fi/problemset/task/1193/
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
	ll dr[] = {1, -1, 0, 0};
	ll dc[] = {0, 0, 1, -1};
	//
	map< pair<ll, ll> , char > dir;
	//
	dir[{1, 0}] = 'D';
	dir[{-1, 0}] = 'U';
	dir[{0, 1}] = 'R';
	dir[{0, -1}] = 'L';
	//
	pair<ll,ll> start, end;
	vector<string> g(n);
	for (string &l : g) cin >> l;
	//
	for (ll i = 0; i < n; i++)
		for (ll j = 0; j < m; j++)
		{
			if (g[i][j] == 'A') start = {i, j};
			else if (g[i][j] == 'B') end = {i, j};
		}
	//
	queue< pair<ll,ll> > qp;
	map<pair<ll, ll>, pair<ll,ll>> parent;
	//
	g[start.first][start.second] = '#';
	parent[start] = {-1, -1};
	//
	qp.push(start);
	//
	bool foundPath = false;
	//
	while (!qp.empty())
	{
		pair<ll, ll> cur = qp.front();
		qp.pop();
		//
		if (cur == end)
		{
			foundPath = true;
			break;
		}
		//
		for (int d = 0; d < 4; d++)
		{
			ll ni = cur.first + dr[d];
			ll nj = cur.second + dc[d];
			//
			if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
			if (g[ni][nj] == '#') continue;
			//
			g[ni][nj] = '#';
			qp.push({ni, nj});
			parent[{ni, nj}] = cur;
		}
	}
	//
	if (!foundPath)
	{
		cout << "NO" << endl;
		return ;
	}
	//
	vector< pair<ll, ll> > path;
	while (end != start)
	{
		path.push_back(end);
		end = parent[end];
	}
	cout << "YES\n";
	cout << path.size() << "\n";
	string directionGuid = "";
	reverse(path.begin(), path.end());
	//
	for (auto &[i, j] : path)
	{
		directionGuid += dir[{(i - start.first) , (j - start.second)}];
		start = {i, j};
	}
	cout << directionGuid << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

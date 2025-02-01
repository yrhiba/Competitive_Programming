/*
CSES Problem Set

Monsters

link to the problem:
https://cses.fi/problemset/task/1194
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
 
ll dr[] = {+1, -1, 0, 0};
ll dc[] = {0, 0, +1, -1};
 
bool isBoundry(ll i, ll j, ll n, ll m)
{
	return (i == 0 || j == 0 || i == n - 1 || j == m - 1);
}
 
void setDirectionChr(map<pair<ll, ll>, char> &directionChr)
{
	directionChr[{0, +1}] = 'R';
	directionChr[{0, -1}] = 'L';
	directionChr[{+1, 0}] = 'D';
	directionChr[{-1, 0}] = 'U';
}
 
void solve()
{
	//
	map<pair<ll, ll>, char> directionChr;
	setDirectionChr(directionChr);
	//
	ll n, m; cin >> n >> m;
	vector<string> g(n);
	pair<ll, ll> player;
	vector<pair<ll, ll>> monsters;
	//
	for (ll i = 0; i < n; i++)
	{
		cin >> g[i];
		//
		for (ll j = 0; j < m; j++)
		{
			if (g[i][j] == 'A') player = {i, j};
			else if (g[i][j] == 'M') monsters.push_back({i, j});
		}
	}
	//
	vector<vector<ll>> monstersMoves(n, vector<ll>(m, 1e18));
	//
	queue< pair<ll, ll> > q;
	queue< ll > qd;
	//
	for (auto monster : monsters)
	{
		q.push(monster), qd.push(0);
		monstersMoves[monster.first][monster.second] = 0;
	}
	//
	while (!q.empty() && !qd.empty())
	{
		pair<ll, ll> curPos = q.front();
		ll curDis = qd.front();
		q.pop(), qd.pop();
		//
		if (monstersMoves[curPos.first][curPos.second] > curDis) continue;
		//
		for (ll d = 0; d < 4; d++)
		{
			ll ni = curPos.first + dr[d];
			ll nj = curPos.second + dc[d];
			//
			if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
			if (g[ni][nj] == '#') continue;
			if (monstersMoves[ni][nj] <= curDis + 1) continue;
			//
			monstersMoves[ni][nj] = curDis + 1;
			//
			q.push({ni, nj});
			qd.push(monstersMoves[ni][nj]);
			//
		}
	}
	//
	vector<vector<bool>> vis(n, vector<bool>(m, false));
	//
	map<pair<ll, ll>, pair<ll, ll>> parent;
	//
	q.push(player);
	qd.push(0);
	//
	parent[player] = {-1, -1};
	//
	vis[player.first][player.second] = true;
	//
	while (!q.empty() && !qd.empty())
	{
		pair<ll, ll> curPos = q.front();
		ll curDis = qd.front();
		//
		q.pop(), qd.pop();
		//
		if (isBoundry(curPos.first, curPos.second, n, m)
			&& curDis < monstersMoves[curPos.first][curPos.second])
		{
			cout << "YES\n";
			cout << curDis << "\n";
			//
			string roadDirection;
			//
			pair<ll, ll> x = curPos;
			//
			while (parent[x].first != -1 && parent[x].second != -1)
			{
				pair<ll, ll> direction;
				//
				direction.first = x.first - parent[x].first;
				direction.second = x.second - parent[x].second;
				//
				x = parent[x];
				//
				roadDirection += directionChr[direction];
			}
			//
			reverse(roadDirection.begin(), roadDirection.end());
			cout << roadDirection << "\n";
			//
			return ;
		}
		//
		for (ll d = 0; d < 4; d++)
		{
			ll ni = curPos.first + dr[d];
			ll nj = curPos.second + dc[d];
			//
			if (ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
			if (vis[ni][nj] || g[ni][nj] == '#') continue;
			//
			vis[ni][nj] = true;
			//
			q.push({ni, nj});
			qd.push(curDis + 1);
			//
			parent[{ni, nj}] = curPos;
		}
	}
	//
	cout << "NO\n";
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

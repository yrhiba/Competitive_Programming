/*
A. Closest Restaurant

time limit per test: 6 seconds
memory limit per test: 256 megabytes
input: standard input
output: standard output

link to the problem:
https://codeforces.com/group/e5ZwbLkcA9/contest/523900/problem/A
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
#include <cassert>
# define ull unsigned long long
# define ll long long
ll mod = 1e9 + 7;
using namespace std;

# define SIZE 50
# define W int(SIZE + 1)
# define H int(SIZE + 1)

int dr[] = {0, 0, +1, -1, +1, -1, +1, -1};
int dc[] = {+1, -1, 0, 0, +1, -1, -1, +1};

struct Resto
{
	ll x, y;

	string name;

	Resto() : x(0), y(0), name(string()) {};
	Resto(ll _x, ll _y, string _name) : x(_x), y(_y), name(_name) {}

	static ll getAreaX(ll _x) {return ((_x * SIZE) / 1e9); }
	static ll getAreaY(ll _y) {return ((_y * SIZE) / 1e9); }
};

istream &operator>>(istream &is, Resto &resto)
{
	is >> resto.name >> resto.x >> resto.y;
	return (is);
}

struct Restos
{
	vector<Resto> container;

	void push_back(const Resto &resto) { this->container.push_back(resto); }

	Restos() {};

	pair<ll, string> getClosest(ll _x, ll _y)
	{
		if (this->container.empty()) return (make_pair(-1ll, ""));

		string ansName = "";
		ll ansDistance = -1;

		for (Resto &resto : this->container)
		{
			ll curDistance = (_x - resto.x) * (_x - resto.x) + (_y - resto.y) * (_y - resto.y);

			if ((ansDistance == -1) || (curDistance < ansDistance)
				|| ((curDistance == ansDistance) && ansName > resto.name))
			{
				ansName = resto.name;
				ansDistance = curDistance;
			}
		}
		return make_pair(ansDistance, ansName);
	}

	int size()
	{
		return container.size();
	}
};

void solve()
{
	vector<vector<Restos>> restos(SIZE + 5, vector<Restos>(SIZE + 5));
	Restos allRestos;

	int q; cin >> q;

	while (q--)
	{
		int type; cin >> type;

		if (type == 1)
		{
			Resto newResto; cin >> newResto;
			restos[newResto.getAreaX(newResto.x)][newResto.getAreaY(newResto.y)].push_back(newResto);
			allRestos.push_back(newResto);
		}
		else if (type == 2)
		{
			ll x, y; cin >> x >> y;
			if (allRestos.size() <= 1e3) cout << allRestos.getClosest(x, y).second << "\n";
			else
			{
				pair<ll, string>	ans = {-1, ""};
				int					foundAnsAtLevel = -1;
				//
				queue<vector<ll>> q; // v[0]:x, v[1]:y, v[2]:level
				q.push({Resto::getAreaX(x), Resto::getAreaY(y), 0});
				set<pair<ll, ll>> visited;
				visited.insert({Resto::getAreaX(x), Resto::getAreaY(y)});
				//
				while (!q.empty())
				{
					auto cur = q.front();
					q.pop();
					//
					if ((foundAnsAtLevel != -1) && (foundAnsAtLevel < (cur[2]-2))) continue;

					pair<ll, string> possibleAns = restos[cur[0]][cur[1]].getClosest(x, y);

					if ((possibleAns.first != -1)
						&& ((ans.first == -1 || foundAnsAtLevel == -1) || (ans.first > possibleAns.first)
							|| (ans.first == possibleAns.first && ans.second > possibleAns.second)))
					{
						ans.first = possibleAns.first;
						ans.second = possibleAns.second;
						foundAnsAtLevel = cur[2];
					}
					//
					for (int d = 0; d < 8; d++)
					{
						int ni = cur[0] + dr[d], nj = cur[1] + dc[d];
						if (ni < 0 || ni > (SIZE+1) || nj < 0 || nj > (SIZE+1)) continue;
						if (visited.count({ni, nj})) continue;
						visited.insert({ni, nj});
						q.push({ni, nj, cur[2] + 1});
					}
				}
				//
				cout << ans.second << "\n";
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

/*
CSES Problem Set

Gray Code

link to the problem:
https://cses.fi/problemset/task/2205/
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
	//
	ll h = (1<<n), w = n;
	//
	vector<vector<int>> g(h, vector<int>(w, 0));
	//
	for (ll i = 0, x = (1<<i), row = 0; i < w; i++, x = (1<<i), row = 0)
	{
		string chunk = string(x, '0') + string(x, '1');
		//
		for (ll j = 0; j < (h / (x*2)) && row < h; j++)
		{
			for (ll k = 0; k < (2*x); k++) g[row++][i] = (chunk[k] == '1');
			//
			reverse(chunk.begin(), chunk.end());
		}
	}
	//
	for (ll i = 0; i < h; i++)
	{
		reverse(g[i].begin(), g[i].end());
		for (ll j = 0; j < w; j++) cout << g[i][j];
		cout << endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

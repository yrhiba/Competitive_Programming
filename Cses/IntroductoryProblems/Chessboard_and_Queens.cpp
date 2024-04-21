/*
CSES Problem Set

Chessboard and Queens

link to the problem:
https://cses.fi/problemset/task/1624/
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

ll n = 8;

ll rec (
		map<ll, bool> *isValidDiagonal,
		vector<ll> &validColumn,
		vector<string> &g,
		ll row = 0,
		ll placed = 0
	)
{
	if (placed >= n) return (1);
	if (row >= n) return (0);

	ll ans = 0;
	//
	for (ll col = 0; col < n; col+=1)
	{
		if (!validColumn[col]) continue;
		if (isValidDiagonal[0][col - row]) continue;
		if (isValidDiagonal[1][col + row]) continue;
		if (g[row][col] == '*') continue;

		validColumn[col] = false;
		isValidDiagonal[0][col - row] = true;
		isValidDiagonal[1][col + row] = true;

		ans += rec(isValidDiagonal, validColumn, g, row + 1, placed + 1);

		validColumn[col] = true;
		isValidDiagonal[0][col - row] = false;
		isValidDiagonal[1][col + row] = false;
	}
	//
	return ans;
}

void solve()
{
	vector<string> g(n);
	for (string &i : g) cin >> i;
	//
	vector<ll> validColumn(n, true);
	//
	map<ll, bool> isValidDiagonal[2];
	//
	cout << rec(isValidDiagonal, validColumn, g, 0) << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

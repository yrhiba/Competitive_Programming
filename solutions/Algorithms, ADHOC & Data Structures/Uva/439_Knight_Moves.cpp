/*

439 Knight Moves

link to the problem:
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=380

link to the problem (pdf version):
https://onlinejudge.org/external/4/439.pdf

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

ll di[] = {1, 2, -1, -2, 1, 2, -1, -2};
ll dj[] = {2, 1, -2, -1, -2, -1, 2, 1};

void solve(string &a, string &b)
{
	ll x, y, start_x, start_y;

	x = b.front() - 'a' + 1;		y = b.back() - '1' + 1;
	start_x = a.front() - 'a' + 1;	start_y = a.back() - '1' + 1;

	queue< pair<ll, ll> > q;	q.push({start_x, start_y});
	queue< ll > moves;			moves.push(0);

	map< pair<ll, ll> , bool > visited; visited[{start_x, start_y}] = true;

	while (!q.empty() && !moves.empty())
	{
		pair<ll, ll>	&cur = q.front();
		ll				&cur_moves = moves.front();

		if (cur.first == x && cur.second == y)
		{
			cout << "To get from " << a << " to " << b << " takes " << cur_moves << " knight moves.\n";
			return ;
		}

		for (ll d = 0; d < 8; d++)
		{
			ll nx, ny;

			nx = cur.first + di[d];
			ny = cur.second + dj[d];

			if (nx < 1 || nx > 8 || ny < 1 || ny > 8) continue;
			if (visited.count({nx, ny})) continue;

			visited[{nx, ny}] = true;

			q.push({nx, ny});
			moves.push(cur_moves + 1);
		}

		q.pop();
		moves.pop();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a, b;
	while (cin >> a >> b)
		solve(a, b);
}

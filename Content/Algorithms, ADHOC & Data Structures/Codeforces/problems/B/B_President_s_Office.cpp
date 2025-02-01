/*
link to the problem:
https://codeforces.com/contest/6/problem/B
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

ll n, m;
char c;
ll pi, pj;
vector<string> g;
vector< vector<bool> > visited;
set<char> st;

ll di[] = {1, -1, 0, 0};
ll dj[] = {0, 0, 1, -1};

void calc(int i, int j)
{
	if (i < 0 || i >= n || j < 0 || j >= m)	return ;
	if (visited[i][j]) return;
	if (g[i][j] == '.') return ;

	visited[i][j] = true;

	if (g[i][j] != c)
	{
		st.insert(g[i][j]);
		return ;
	}


	for (ll k = 0; k < 4; k++)
		calc(i+di[k], j+dj[k]);
}

void solve()
{
	cin >> n >> m >> c;

	g.resize(n);
	visited.resize(n);

	pi = pj = -1;

	for (ll i = 0; i < n; i++)
	{
		cin >> g[i];

		visited[i] = vector<bool>(m, false);

		for (ll j = 0; j < m; j++)
		{
			if ((pi == -1) && (g[i][j] == c))
			{
				pi = i;
				pj = j;
			}
		}
	}

	// calulate
	calc(pi, pj);

	cout << st.size() << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

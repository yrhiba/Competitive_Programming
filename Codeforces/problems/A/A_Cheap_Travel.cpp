/*
A. Cheap Travel

link to the problem:
https://codeforces.com/contest/466/problem/A

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

# define ll long long

using namespace std;

ll n, m, a, b;

void calc(ll x = 0, ll cost = 0)
{
	if (x >= n)
	{
		cout << cost << endl;
		exit(0);
	}

	if (b < a * min(m, n - x))
	{
		calc(x+m, cost + b);
		return ;
	}

	calc(x + 1, cost + a);
}


void solve()
{
	cin >> n >> m >> a >> b;

	calc();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

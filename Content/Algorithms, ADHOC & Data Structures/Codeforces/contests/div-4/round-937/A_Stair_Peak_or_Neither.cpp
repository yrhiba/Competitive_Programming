/*
link to the problem:
https://codeforces.com/contest/1950/problem/A
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
#include <numeric>
# define ull unsigned long long
# define ll long long
const ll mod = 1e9 + 7;
using namespace std;

void solve()
{
	ll a, b, c; cin >> a >> b >> c;
	//
	if (a < b && b < c)
	{
		cout << "STAIR";
	}
	else if (a < b && b > c)
	{
		cout << "PEAK";
	}
	else
	{
		cout << "NONE";
	}
	//
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--)
		solve();
}

/*
B. Turtle Math: Fast Three Task

link to the problem:
https://codeforces.com/contest/1933/problem/B
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
	ll res = 0, is1 = false, is2 = false;
	for (ll i = 0; i < n; i++)
	{
		ll t; cin >> t;
		if (t%3 == 1) is1 = true;
		if (t%3 == 2) is2 = true;
		res += t%3;
		res %= 3;
	}
	if (res == 0) cout << "0\n";
	else if (res == 1)
	{
		if (is1) cout << "1\n";
		else cout << "2\n";
	}
	else
	{
		cout << "1\n";
	}
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

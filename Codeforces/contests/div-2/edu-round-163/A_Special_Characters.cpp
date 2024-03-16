/*
link to the problem:
https://codeforces.com/contest/1948/problem/A
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
	if (n%2)
	{
		cout << "NO\n";
		return ;
	}
	cout << "YES\n";
	for (ll i = 0; i < n/2; i++)
	{
		if (i%2) cout << "AA";
		else cout << "BB";
	}
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

/*
B. Vlad and Shapes

link to the problem:
https://codeforces.com/contest/1926/problem/B
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
# define ll int
const ll mod = 1e9 + 7;
using namespace std;

void solve()
{
	ll n; cin >> n;
	string s;
	ll prev = 0, cur = 0, ans = 0;
	for (ll i = 0; i < n; i++)
	{
		cin >> s;
		if (ans) continue;
		cur = 0;
		for (char x : s) cur += (x=='1');
		if (cur && prev)
		{
			if (cur == prev) ans = 1;
			else	ans = 2;
		}
		prev = cur;
	}
	if (ans == 1) cout << "SQUARE\n";
	else cout << "TRIANGLE\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--) solve();
}

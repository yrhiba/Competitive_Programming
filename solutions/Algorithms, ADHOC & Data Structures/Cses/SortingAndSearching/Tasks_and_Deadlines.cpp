/*
CSES Problem Set

Tasks and Deadlines

link to the prbolem:
https://cses.fi/problemset/task/1630
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
	vector<pair<ll, ll>> a(n);
	for (auto &[i, j] : a) cin >> i >> j;
	sort(a.begin(), a.end());
	//
	ll curTime = 0, ans = 0;
	for (auto &[duration, deadline] : a)
	{
		curTime += duration;
		ans += (deadline - curTime);
	}
	//
	cout << ans << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

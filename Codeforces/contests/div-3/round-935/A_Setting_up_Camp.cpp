/*
link to the problem:
https://codeforces.com/contest/1945/problem/A
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
	ll a, b , c;
	cin >>a >> b >> c;
	ll ans = a;
	ans += (b+c) / 3;
	//
	if ((b+c)%3 > c)
	{
		cout << -1 << "\n";
		return ;
	}
	ll r = (b+c)%3;
	ans += r/2;
	cout << ans + (r%2) << "\n";
}

int main()
{
	cin.tie()->sync_with_stdio(false);
	ll t; cin >> t;
	while (t--)
		solve();
}

/*
A. Rectangle Cutting

link to the problem:
https://codeforces.com/contest/1928/problem/A
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
	ll a, b; cin >> a >> b;
	if (a%2==0 && a/2 != b)
	{
		cout << "Yes\n";
		return ;
	}
	swap(a, b);
	if (a%2==0 && a/2 != b) cout << "Yes\n";
	else cout << "No\n";
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

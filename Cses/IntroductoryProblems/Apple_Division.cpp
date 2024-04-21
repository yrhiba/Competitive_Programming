/*
CSES Problem Set

Apple Division

link to the  problem:
https://cses.fi/problemset/task/1623/
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

ll rec(vector<ll> &a, ll &totalSum, ll i = 0, ll curSum = 0)
{
	if (i >= a.size()) return abs(curSum - (totalSum - curSum));
	//
	return min(rec(a, totalSum, i + 1, curSum), rec(a, totalSum, i + 1, curSum + a[i]));
}

void solve()
{
	ll n; cin >> n;
	vector<ll> a(n);
	ll totalSum = 0;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		totalSum += a[i];
	}
	//
	cout << rec(a, totalSum) << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

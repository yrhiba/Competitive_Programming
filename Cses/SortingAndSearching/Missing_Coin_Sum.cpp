/*
CSES Problem Set

Missing Coin Sum

link to the problem:
https://cses.fi/problemset/task/2183
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
	vector<ll> coins(n);
	for (ll &coin : coins) cin >> coin;
	//
	sort(coins.begin(), coins.end());
	//
	ll curMax = 0;
	for (ll &coin : coins)
	{
		if (coin > curMax + 1)
		{
			cout << curMax + 1 << endl;
			return ;
		}
		//
		curMax = coin + curMax;
	}
	//
	cout << curMax + 1 << endl;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

/*
G. Money Buys Less Happiness Now 

time limit per test: 2 second
memory limit per test: 256 megabytes
input: standard input
output: standard output

link to the problem:
https://codeforces.com/contest/1974/problem/G
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
	ll m, x; cin >> m >> x;
	vector<ll> c(m);
	for (ll &i : c) cin >> i;
	//
	priority_queue<ll> pr;
	ll myHappines = 0, money = 0;
	//
	for (ll i = 0; i < m; i++)
	{
		if (c[i] <= money)
		{
			myHappines += 1;
			money -= c[i];
			pr.push(c[i]);
		}
		else if (!pr.empty() && pr.top() > c[i])
		{
			money += pr.top();
			pr.pop();
			money -= c[i];
			pr.push(c[i]);
		}
		money += x;
	}
	//
	cout << myHappines << '\n';
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

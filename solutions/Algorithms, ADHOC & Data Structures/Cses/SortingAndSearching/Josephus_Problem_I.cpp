/*
CSES Problem Set

Josephus Problem I

link to the problem:
https://cses.fi/problemset/task/2162/
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

void rec(vector<ll> &ans, vector<ll> a)
{
	ll n = a.size();
	//
	if (n == 0) return ;
	if (n == 1)
	{
		ans.push_back(a.front());
		return ;
	}
	//
	for (ll i = 1; i < n; i += 2) ans.push_back(a[i]);
	vector<ll> nextA;
	//
	if (n % 2)
	{
		nextA.push_back(a.back());
		a.pop_back();
		n -= 1;
	}
	for (ll i = 0; i < n; i += 2) nextA.push_back(a[i]);
	rec(ans, nextA);
}

void solve()
{
	ll n; cin >> n;
	//
	vector<ll> childern(n);
	for (ll i = 1; i <= n; i++) childern[i-1] = i;
	//
	vector<ll> ans;
	//
	rec(ans, childern);
	//
	for (ll i = 0; i < n; i++)
		cout << ans[i] << " \n"[i+1 == n];
	//
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

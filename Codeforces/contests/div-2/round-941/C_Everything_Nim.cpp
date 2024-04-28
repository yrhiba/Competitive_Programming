/*
C. Everything Nim

link to the problem:
https://codeforces.com/contest/1966/problem/C
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
	vector<ll> a(n);
	for (ll &i : a) cin >> i;
	sort(a.begin(), a.end());
	ll m = 0;
	vector<ll>	choices;
	for (ll i = 0; i < n; i++)
	{
		if (m < a[i])
		{
			choices.push_back(a[i] - m);
			m += (a[i] - m);
		}
	}
	n = choices.size();
	vector<bool> state(n+1);
	state[n] = false;
	for (ll i = n-1; i >= 0; i--)
		if (!state[i+1])
		{
			state[i] = true;
		}
		else
		{
			if (choices[i] == 1) state[i] = false;
			else state[i] = true;
		}
	//
	if (state[0])
		cout << "Alice\n";
	else
		cout << "Bob\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--)
	{
		solve();
	}
}

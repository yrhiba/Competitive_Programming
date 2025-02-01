/*
link to the problem:
https://codeforces.com/contest/1950/problem/B
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
	ll n; cin >> n;
	vector<string> g;
	for (ll i = 0; i < n; i++)
	{
		string t = "";
		for (ll j = 0; j < n; j++)
		{
			if (i%2)
			{
				if (j%2) t += "##";
				else t += "..";
			}
			else
			{
				if (j%2) t += "..";
				else t += "##";
			}
		}
		g.push_back(t);
		g.push_back(t);
	}
	for (string s : g)
		cout << s << "\n";
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

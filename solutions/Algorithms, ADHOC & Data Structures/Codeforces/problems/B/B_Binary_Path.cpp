/*
B. Binary Path

link to the problem:
https://codeforces.com/contest/1937/problem/B
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
# define endl '\n'

void solve()
{
	ll n; cin >> n;
	string s, t, ans; cin >> s >> t; s.push_back('2');
	ll i, mark = -1;
	for (i = 0; i < n; i++)
	{
		ans += s[i];
		//
		if (s[i+1] != t[i])
		{
			if (s[i+1] == '0')
			{
				mark = -1;
				continue;
			}
			break;
		}
		else if (mark == -1) mark = i;
	}
	cout << ans;
	if (i < t.size()) cout << t.substr(i, t.size());
	cout << "\n";
	if (mark != -1) cout << i - mark + 1;
	else cout << 1;
	cout << "\n";
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

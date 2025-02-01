/*

Starters 111 (Rated till 6 Stars)

Reach Codetown

Problem Code:CODETOWN

link to the problem:
https://www.codechef.com/START111B/problems/CODETOWN

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

bool is(string s, char a)
{
	for (char c : s)
	{
		if (c == a)
			return true;
	}
	return false;
}

void solve()
{
	string s; cin >> s;

	string v = "AEIOU";

	string target = "CODETOWN";

	if (s.size() != target.size())
	{
		cout << "NO\n";
		return ;
	}

	for (int i = 0; i < s.size(); i++)
	{
		if (is(v, s[i]) != is(v, target[i]))
		{
			cout << "NO\n";
			return ;
		}
	}

	cout << "YES\n";
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

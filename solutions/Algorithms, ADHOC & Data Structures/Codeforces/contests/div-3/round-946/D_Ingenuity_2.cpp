/*
D. Ingenuity-2

time limit per test: 2 second
memory limit per test: 256 megabytes
input: standard input
output: standard output

link to the problem:
https://codeforces.com/contest/1974/problem/D
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
	string s; cin >> s;

	ll totalX = 0;
	ll totalY = 0;

	map<char, ll> mp, cnt;
	mp['N'] = mp['E'] = +1;
	mp['S'] = mp['W'] = -1;

	for (char c : s)
	{
		cnt[c] += 1;
		if (c == 'N' || c == 'S') totalX += mp[c];
		else totalY += mp[c];
	}

	if (abs(totalX) % 2 || abs(totalY) % 2)
	{
		cout << "NO\n";
		return ;
	}

	if (totalX == 0 && totalY == 0)
	{
		if (!(cnt['N'] >= 2 || cnt['E'] >= 2))
		{
			if (!(cnt['N'] + cnt['E'] >= 2))
			{
				cout << "NO\n";
				return ;
			}
		}

		if (cnt['N'] == 0)
		{
			for (ll i = 0, x = 0, y = 0; i < n; i++)
			{
				if (s[i] == 'E')
				{
					if (x < cnt['E']/2)
					{
						cout << 'R';
						x += 1;
					}
					else
					{
						cout << 'H';
					}
				}
				else
				{
					if (y < cnt['W']/2)
					{
						cout << 'R';
						y += 1;
					}
					else
					{
						cout << 'H';
					}
				}
			}
			cout << "\n";
			return ;
		}
		else if (cnt['E'] == 0)
		{
			for (ll i = 0, x = 0, y = 0; i < n; i++)
			{
				if (s[i] == 'N')
				{
					if (x < cnt['N']/2)
					{
						cout << 'R';
						x += 1;
					}
					else
					{
						cout << 'H';
					}
				}
				else
				{
					if (y < cnt['S']/2)
					{
						cout << 'R';
						y += 1;
					}
					else
					{
						cout << 'H';
					}
				}
			}
			cout << "\n";
			return ;
		}
	}

	ll x = 0, y = 0, t = 0, o = 0;

	string ans = "";

	for (ll i = 0; i < n; i++)
	{
		if (s[i] == 'N' || s[i] == 'S')
		{
			if (x != totalX/2)
			{
				ans += 'R';
				x += mp[s[i]];
			}
			else
			{
				ans += 'H';
			}
		}
		else
		{
			if (y != totalY/2)
			{
				ans += 'H';
				y += mp[s[i]];
			}
			else
			{
				ans += 'R';
			}
		}
	}

	cout << ans << "\n";
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

/*

Codeforces Round 913 (Div. 3)

C. Removal of Unattractive Pairs

link to the problem:
https://codeforces.com/contest/1907/problem/C

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

	vector<ll> letters(256, 0);
	for (char c : s)
		letters[c] += 1;

	ll max_frequent_char = *max_element(letters.begin(), letters.end());

	if (max_frequent_char <= n / 2)
	{
		cout << (n%2) << '\n';
	}
	else
	{
		cout << n - ((n - max_frequent_char) * 2) << "\n";
	}
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

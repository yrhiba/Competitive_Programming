/*
link to the problem:
https://codeforces.com/contest/1950/problem/C
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
//
void solve()
{
	string s; cin >> s;
	//
	ll h = (s[0] - '0') * 10 + (s[1] - '0');
	ll m = (s[3] - '0') * 10 + (s[4] - '0');
	//
	string t;
	//
	if (h * 60 + m < (24*60)/2) t = "AM";
	else t = "PM";
	//
	h %= 12; if (h == 0) h = 12;
	cout << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << ' ' << t << "\n";
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

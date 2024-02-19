/*
A. Vlad and the Best of Five

link to the problem:
https://codeforces.com/contest/1926/problem/A
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
	string s; cin >> s;
	ll a=0, b=0;
	for (char c : s)
	{
		a += c=='A';
		b += c=='B';
	}
	if (a >= b) cout << "A";
	else cout << "B";
	cout << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll t; cin >> t;
	while (t--)	solve();
}

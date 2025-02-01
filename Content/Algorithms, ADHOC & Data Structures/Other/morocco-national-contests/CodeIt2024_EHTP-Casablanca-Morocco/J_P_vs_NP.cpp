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
#include <sstream>
# define ull unsigned long long
# define ll long long
ll mod = 1e9 + 7;
using namespace std;

void solve(stringstream sin)
{
	string s;

	ll w = 0, v = 0;

	map<char, bool> mp;
	string T = "aeiouy";
	for (char c : T) mp[c] = true;

	while (sin >> s)
	{
		w += 1;
		for (char c : s) v += mp[c];
	}

	if (w * 2 == v) cout << "N";

	cout << "P\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	while (getline(cin, s))
		solve(stringstream(s));
}

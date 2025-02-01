/*
link to the problem:
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=654
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
	string a, b; cin >> a >> b;
	if (a.size() > b.size()) swap(a, b);
	if (a.size() != b.size()) a += string(b.size() - a.size(), '0');
	string ans = "";
	ll c, r = 0;
	for (ll i = 0; i < a.size(); i++)
	{
		c = (a[i] - '0') + (b[i] - '0') + r;
		ans += (char)((c%10) + '0');
		r = c/10;
	}
	if (r) ans += (r + '0');
	ll i = 0;
	while (ans[i] == '0') i++;
	cout << ans.substr(i, ans.size()) << "\n";
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

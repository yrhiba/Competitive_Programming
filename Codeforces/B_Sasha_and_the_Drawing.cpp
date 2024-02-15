/*
B. Sasha and the Drawing

link to the problem:
https://codeforces.com/contest/1929/problem/B
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
	ll n, k; cin >> n >> k;
	if (k <= ((n*2)-2)*2) cout << (k+1)/2 << "\n";
	else cout << n*2-2 + min(2ll, k-((n*2)-2)*2) << "\n";
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

/*
link to the problem:
https://cses.fi/problemset/task/2165/
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

vector<ll> stacks;
vector<pair<ll, ll>> ans;

void move(ll n)
{
	if (n == 0) return ;
	// step 1
	swap(stacks[1], stacks[2]);
	move(n - 1); // 1 -> 2
	swap(stacks[1], stacks[2]);
	// step 2
	ans.push_back({stacks.front(), stacks.back()});
	swap(stacks[0], stacks[1]);
	move(n - 1); // 2 -> 3
	swap(stacks[0], stacks[1]);
}

void solve()
{
	for (ll i = 1; i <= 3; i++) stacks.push_back(i);
	//
	ll n; cin >> n;
	//
	move(n);
	//
	cout << ans.size() << "\n";
	for (ll i = 0; i < ans.size(); i++)
		cout << ans[i].first << " " << ans[i].second << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

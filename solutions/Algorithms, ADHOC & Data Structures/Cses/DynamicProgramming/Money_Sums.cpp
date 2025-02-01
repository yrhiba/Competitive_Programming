/*
CSES Problem Set

Money Sums

link to the problem:
https://cses.fi/problemset/task/1745/
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
using namespace std;
 
void rec(set<int> &ans, vector<vector<bool>> &dp, vector<int> &coins, int i, int j)
{
	if (dp[i][j]) return ;

	dp[i][j] = true;

	ans.insert(i);

	if (j >= coins.size()) return ;

	rec(ans, dp, coins, i + coins[j], j+1);
	rec(ans, dp, coins, i, j+1);
}

void solve()
{
	int n, totalSum = 0; cin >> n;
	vector<int> coins(n);
	for (int &i : coins)
	{
		cin >> i;
		totalSum += i;
	}
	//
	vector<vector<bool>> dp(totalSum+1, vector<bool>(n+1, false));
	//
	set<int> ans;
	//
	rec(ans, dp, coins, 0, 0);
	//
	ans.erase(ans.begin());
	cout << ans.size() << "\n";
	for (int i : ans) cout << i << " ";
}
 
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}

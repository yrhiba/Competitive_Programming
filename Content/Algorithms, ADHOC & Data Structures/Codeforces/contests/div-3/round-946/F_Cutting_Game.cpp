/*
F. Cutting Game

time limit per test: 3 second
memory limit per test: 256 megabytes
input: standard input
output: standard output

link to the problem:
https://codeforces.com/contest/1974/problem/F
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
#include <cassert>
# define ull unsigned long long
# define ll long long
ll mod = 1e9 + 7;
using namespace std;

ll getIndexOf(vector<pair<ll, set<ll>>> &container, ll item)
{
	ll left = 0, right = container.size(), mid;
	while (left <= right)
	{
		mid = left + ((right - left) / 2);
		if (container[mid].first == item) return mid;
		if (container[mid].first < item) left = mid + 1;
		else right = mid - 1;
	}
	assert(false && "wtf");
	return (-1);
}

void solve()
{
	ll a, b; cin >> a >> b; // ([a]-rows * [b]-columns) grid size;
	ll n, m; cin >> n >> m; // n: number of chip | m: number of moves
	//
	map<ll, set<ll>> rows_chips; // [key: row, value: colums have chip]
	map<ll, set<ll>> columns_chips; // [key: column, value: rows have chip]
	//
	for (ll i = 0; i < n; i++)
	{
		ll x, y; cin >> x >> y;
		x -= 1, y -= 1;
		// [x, y] : 1 chip;
		rows_chips[x].insert(y);
		columns_chips[y].insert(x);
	}
	//
	vector<pair<ll, set<ll>>> rows;
	for (auto &item : rows_chips) rows.push_back(item);
	vector<pair<ll, set<ll>>> columns;
	for (auto &item : columns_chips) columns.push_back(item);
	//
	ll aliceScore, bobScore;
	aliceScore = bobScore = 0;
	//
	ll left_row = 0, right_row = a-1, lr_index = 0, rr_index = rows.size() - 1;
	ll left_column = 0, right_column = b-1, lc_index = 0, rc_index = columns.size() - 1;
	//
	for (ll j = 0; j < m; j++)
	{
		char c; ll k, curMoveScore = 0; cin >> c >> k;
		//
		if (c == 'U') // cut first k rows
		{
			left_row += k;
			while (lr_index < rows.size() && rows[lr_index].first < left_row)
			{
				while (!(rows[lr_index].second.empty()))
				{
					ll intersect_column = *rows[lr_index].second.begin();
					//
					curMoveScore += 1;
					//
					columns[getIndexOf(columns, intersect_column)].second.erase(rows[lr_index].first);
					rows[lr_index].second.erase(intersect_column);
				}
				lr_index += 1;
			}
		}
		else if (c == 'D') // cut last k rows
		{
			right_row -= k;
			while (rr_index >= 0 && rows[rr_index].first > right_row)
			{
				while (!(rows[rr_index].second.empty()))
				{
					ll intersect_column = *rows[rr_index].second.begin();
					//
					curMoveScore += 1;
					//
					columns[getIndexOf(columns, intersect_column)].second.erase(rows[rr_index].first);
					rows[rr_index].second.erase(intersect_column);
				}
				rr_index -= 1;
			}
		}
		else if (c == 'L') // cut first k columns
		{
			left_column += k;
			while (lc_index < columns.size() && columns[lc_index].first < left_column)
			{
				while (!(columns[lc_index].second.empty()))
				{
					ll intersect_row = *columns[lc_index].second.begin();
					//
					curMoveScore += 1;
					//
					rows[getIndexOf(rows, intersect_row)].second.erase(columns[lc_index].first);
					columns[lc_index].second.erase(intersect_row);
				}
				lc_index += 1;
			}
		}
		else if (c == 'R') // cut last k columns
		{
			right_column -= k;
			while (rc_index >= 0 && columns[rc_index].first > right_column)
			{
				while (!(columns[rc_index].second.empty()))
				{
					ll intersect_row = *columns[rc_index].second.begin();
					//
					curMoveScore += 1;
					//
					rows[getIndexOf(rows, intersect_row)].second.erase(columns[rc_index].first);
					columns[rc_index].second.erase(intersect_row);
				}
				rc_index -= 1;
			}
		}
		//
		if (j%2) bobScore += curMoveScore;
		else aliceScore += curMoveScore;
	}
	//
	cout << aliceScore << " " << bobScore << "\n";
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

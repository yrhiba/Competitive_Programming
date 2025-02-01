/*
yrhiba.github.io (c). 2022-2024
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
#include <random>
#include <sstream>
using namespace std;
typedef long long ll;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
# define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


/* SuffixArray from kctl */
struct SuffixArray {
	vi sa, lcp;
	SuffixArray(string& s, int lim=256) { // or basic_string<int>
		int n = sz(s) + 1, k = 0, a, b;
		vi x(all(s)), y(n), ws(max(n, lim));
		x.push_back(0), sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		for (int i = 0, j; i < n - 1; lcp[x[i++]] = k)
			for (k && k--, j = sa[x[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
};

/* sparce table from geeks for geeks */
int lookup[int(1e6+1)][30];
int sfxMap[int(1e6+1)];

// Fills lookup array lookup[][] in bottom up manner. 
void buildSparseTable(vector<int> &arr, int n)
{ 
	// Initialize M for the intervals with length 1 
	for (int i = 0; i < n; i++)
		lookup[i][0] = arr[i];
 
	// Compute values from smaller to bigger intervals 
	for (int j = 1; (1 << j) <= n; j++) { 
 
		// Compute minimum value for all intervals with 
		// size 2^j 
		for (int i = 0; (i + (1 << j) - 1) < n; i++) { 
 
			// For arr[2][10], we compare arr[lookup[0][7]]  
			// and arr[lookup[3][10]] 
			if (lookup[i][j - 1] <  
						lookup[i + (1 << (j - 1))][j - 1])
				lookup[i][j] = lookup[i][j - 1];
			else
				lookup[i][j] =
							lookup[i + (1 << (j - 1))][j - 1];
		}
	}
}
 
// Returns minimum of arr[L..R] 
int query(int L, int R) 
{ 
	// Find highest power of 2 that is smaller 
	// than or equal to count of elements in given 
	// range. For [2, 10], j = 3
	int j = (int)log2(R - L + 1);
 
	// Compute minimum of last 2^j elements with first 
	// 2^j elements in range. 
	// For [2, 10], we compare arr[lookup[0][3]] and 
	// arr[lookup[3][3]], 
	if (lookup[L][j] <= lookup[R - (1 << j) + 1][j]) 
		return lookup[L][j]; 
 
	else
		return lookup[R - (1 << j) + 1][j]; 
} 
 
int getLcp(SuffixArray &a, int i, int j)
{
	i = sfxMap[i];
	j = sfxMap[j];
	if (i > j) swap(i, j);
	return (query(i+1, j));
}
 
void solve()
{
	string s; cin >> s;
 
	int n = int(s.size());
 
	SuffixArray a(s);

	auto &sfxArr = a.sa;
	for (int i = 0; i < a.sa.size(); i++) {
		sfxMap[a.sa[i]] = i;
	}

	// build the sparce table for LCP querys
	buildSparseTable(a.lcp, a.lcp.size());
 
	vector<int> ans;
	ans.reserve(n);
 
	for (int i = 1; i < n; i++) {
		int r = getLcp(a, 0, i);
		if (r == n - i) {
			ans.push_back(r);
		}
	}
 
	sort(all(ans));
 
	for (ll i = 0; i < int(ans.size()); i++) {
		cout << ans[i] << " \n"[i+1 == int(ans.size())];
	}
}

/* main funciton */
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	solve();
	return (0);
}
/*
link to the problem:
https://cses.fi/problemset/task/1731/
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

struct Node
{
	Node *links[26];
	int		endWord;
	//
	Node()
	{
		for (int i = 0; i < 26; i++) this->links[i] = NULL;
		this->endWord = 0;
	}
};

struct Trie
{
	Node *root;
	//
	Trie()
	{
		root = new Node();
	}
	//
	void insert(string &s)
	{
		Node *it = this->root;
		for (char c : s)
		{
			if (!it->links[c - 'a']) it->links[c - 'a'] = new Node();
			it = it->links[c - 'a'];
		}
		it->endWord += 1;
	}
};

ll rec(Trie &trie, Node *it, vector<ll> &dp, string &s, ll i)
{
	ll n = s.size();
	//
	if (i >= n) return 1;
	//
	if (dp[i] != -1) return dp[i];
	//
	ll &ans = dp[i];
	//
	ans = 0;
	//
	for (; i < n; i++)
	{
		if (!(it->links[s[i] - 'a'])) return ans;
		//
		it = it->links[s[i] - 'a'];
		//
		if (it->endWord)
		{
			ans += (it->endWord % mod) * (rec(trie, trie.root, dp, s, i+1) % mod);
			ans %= mod;
		}
	}
	//
	return ans;
}

void solve()
{
	Trie trie;
	string s; cin >> s;
	ll n = s.size();
	ll k; cin >> k;
	while (k--)
	{
		string t; cin >> t;
		trie.insert(t);
	}
	//
	vector<ll> dp(n+1, -1);
	//
	cout << rec(trie, trie.root, dp, s, 0) << "\n";
}

int main()
{
	cin.tie(0)->sync_with_stdio(false);
	solve();
}

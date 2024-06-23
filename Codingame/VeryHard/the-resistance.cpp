/*

The Resistance

Difficulty : Very Hard

Community success rate: 40%


problem link: 
https://www.codingame.com/training/expert/the-resistance

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
# define int long long

vector<string> db = {
	".-", // a
	"-...", // b
	"-.-.", // c
	"-..", // d
	".", // e
	"..-.", // f
	"--.", // g
	"....", // h
	"..", // i
	".---",
	"-.-",
	".-..", // l
	"--",
	"-.",
	"---",
	".--.", // p
	"--.-",
	".-.",
	"...",
	"-", // t
	"..-",
	"...-",
	".--",
	"-..-",
	"-.--",
	"--..", // z
};

struct Node 
{
	map<char, Node*> links;
	int endOf;
	Node()
	{
		endOf = 0;
	}
};

struct Trie
{
	Node *root = new Node();
	void insert(const string &s)
	{
		Node *it = root;
		for (char c : s)
		{
			if (it->links.count(c) == 0)
				it->links[c] = new Node();
			it = it->links[c];
		}
		it->endOf += 1;
	}
};


int rec(vector<int> &dp, Trie &trie, Node *it, string &s, int i)
{
	if (i >= s.size()) return (1);
	if (dp[i] != -1) return (dp[i]);

	int &ans = dp[i];

	ans = 0;

	for (; i < (int)(s.size()); i++)
	{
		if (it->links.count(s[i]) == 0) return (ans);
		it = it->links[s[i]];

		if (it->endOf)
		{ 
			int r = rec(dp, trie, trie.root, s, i+1);
			ans += (r * it->endOf);
		}
	}

	return (ans);
}

int32_t main()
{
	Trie trie;
	string l;
	cin >> l; cin.ignore();
	int n;
	cin >> n; cin.ignore();
	for (int i = 0; i < n; i++) {
		string w;
		cin >> w; cin.ignore();
		string d;
		for (char c : w) d += db[c - 'A'];
		trie.insert(d);
	}
	vector<int> dp(l.size(), -1);
	cout << rec(dp, trie, trie.root, l, 0) << endl;
}

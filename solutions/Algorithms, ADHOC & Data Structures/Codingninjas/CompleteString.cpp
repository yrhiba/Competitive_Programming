/*
Complete String

Hard

120/120 

link to the problem:
https://www.codingninjas.com/studio/problems/complete-string_2687860
*/

#include <bits/stdc++.h> 

struct Node
{
	map<char, Node*> links;
	bool   endOfWord;

	Node()
	{
		endOfWord = false;
	}
};

struct Trie
{
	Node *root;

	Trie()
	{
		root = new Node();
	}

	bool insertAndCheck(string &w)
	{
		bool ans = true;
		Node *it = root;

		for (int i = 0; i < w.size(); i++)
		{
			char c = w[i];

			if (!(it->links.count(c)))
				it->links[c] = new Node();

			it = it->links[c];

			if ((i+1<w.size())
				&& it->endOfWord == false)
					ans = false;
		}

		it->endOfWord = true;

		return (ans);
	}
};

string completeString(int n, vector<string> &a)
{
	Trie *trie = new Trie();

	sort(a.begin(), a.end());

	string ans = "";

	for (string &w : a)
		if (trie->insertAndCheck(w) && w.size() > ans.size())
			ans = w;

	return ans.empty() ? "None" : ans;
}

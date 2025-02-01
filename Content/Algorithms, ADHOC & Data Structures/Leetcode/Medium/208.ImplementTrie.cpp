/*
208. Implement Trie (Prefix Tree)

Medium

link to the problem:
https://leetcode.com/problems/implement-trie-prefix-tree/
*/
struct Node
{
	Node	*next[26];
	bool	endOfWord;

	Node()
	{
		endOfWord = false;
		for (int i = 0; i < 26; i++)
			next[i] = nullptr;
	}
};

class Trie
{
private:
	Node *root;

public:
	Trie() {
		root = new Node();
	}

	void insert(string word) {
		Node *it = root;
		for (char c : word)
		{
			if (it->next[c - 'a'])
			{
				it = it->next[c - 'a'];
			}
			else
			{
				it->next[c - 'a'] = new Node();
				it = it->next[c - 'a'];
			}
		}
		it->endOfWord = true;
	}

	bool search(string word) {
		Node *it = root;
		for (char c : word)
		{
			if (it->next[c - 'a'])
			{
				it = it->next[c - 'a'];
			}
			else
				return false;
		}
		return it->endOfWord;
	}

	bool startsWith(string prefix) {
		Node *it = root;
		for (char c : prefix)
		{
			if (it->next[c - 'a'])
			{
				it = it->next[c - 'a'];
			}
			else
				return false;
		}
		return true;
	}
};

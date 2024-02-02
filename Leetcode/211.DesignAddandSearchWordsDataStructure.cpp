/*
211. Design Add and Search Words Data Structure

Medium

link to the problem:
https://leetcode.com/problems/design-add-and-search-words-data-structure/
*/
class TrieNode
{
public:
	map<char, TrieNode*>	links;
	bool					endOfWord;

	TrieNode()
	{
		endOfWord = false;
	}
};

class Trie
{
private:
	TrieNode *root;

public:
	Trie()
	{
		root = new TrieNode();
	}

	void insert(string &word)
	{
		TrieNode *it = root;

		for (char c : word)
		{
			if (!it->links.count(c)) it->links[c] = new TrieNode();
			it = it->links[c];
		}

		it->endOfWord = true;
	}

	bool search(string &word, TrieNode *it = nullptr, int i = 0) {

		if (!it) it = root;

		for (; i < word.size(); i++)
		{
			if (word[i] == '.')
			{
				for (auto &[ch, link] : it->links)
					if (search(word, link, i + 1))
						return true;
				return false;
			}
			
			if (!(it->links.count(word[i])))
				return false;

			it = it->links[word[i]];
		}

		return it->endOfWord;
	}
};

class WordDictionary {
private:
	Trie *trie;

public:
	WordDictionary() {
		trie = new Trie();
	}

	void addWord(string word) {
		trie->insert(word);
	}

	bool search(string word) {
		return trie->search(word);
	}
};

/**
* Your WordDictionary object will be instantiated and called as such:
* WordDictionary* obj = new WordDictionary();
* obj->addWord(word);
* bool param_2 = obj->search(word);
*/
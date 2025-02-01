/*
link to the problem:
https://leetcode.com/problems/shortest-uncommon-substring-in-an-array/
*/
struct Node
{
	map<char, Node*> links;
	int endWord;
	Node()
	{
		this->endWord = 0;
	}
};

struct Trie
{
	Node *root;
	//
	Trie()
	{ root = new Node(); }
};

class Solution {
public:
	vector<string> shortestSubstrings(vector<string>& arr)
	{
		Trie globalTrie;
		vector<Trie> localTrie(arr.size());
		//
		for (int i = 0; i < arr.size(); i++)
		{
			string &s = arr[i];
			//
			for (int j = 0; j < s.size(); j++)
			{
				Node *GlobalIt = globalTrie.root;
				Node *LocalIt = localTrie[i].root;
				//
				for (int k = j; k < s.size(); k++)
				{
					char &c = s[k];
					
					if (!(GlobalIt->links.count(c))) GlobalIt->links[c] = new Node();
					if (!(LocalIt->links.count(c))) LocalIt->links[c] = new Node();
					//
					GlobalIt = GlobalIt->links[c];
					GlobalIt->endWord += 1;
					LocalIt = LocalIt->links[c];
					LocalIt->endWord += 1;
				}
			}
		}
		//
		vector<string> ans(arr.size());
		//
		for (int i = 0; i < arr.size(); i++)
		{
			string &s = arr[i];
			string &res = ans[i];
			res = "";
			//
			for (int x = 0; x < s.size(); x++)
			{
				Node *it = globalTrie.root;
				Node *cIt = localTrie[i].root;
				//
				string cur = "";
				//
				for (int y = x; y < s.size(); y++)
				{
					it = it->links[s[y]];
					cIt = cIt->links[s[y]];
					//
					cur += s[y];
					//
					if ((it->endWord - cIt->endWord) < 1)
						if (  res.empty() 
							|| (cur.size() < res.size()) 
							|| (cur.size() == res.size() && cur < res) )
						{
							res = cur;
						}
				}
			}
		}
		//
		return (ans);
	}
};

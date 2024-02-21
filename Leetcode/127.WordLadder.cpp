/*
127. Word Ladder

Hard

link to the problem:
https://leetcode.com/problems/word-ladder
*/
class Solution
{
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList)
	{
		set<string> words;
		for (string &s : wordList) words.insert(s);

		if (words.count(beginWord)) words.erase(beginWord);

		queue< pair<string, int> > q;
		q.push({beginWord, 1});

		while (!q.empty())
		{
			string cur = q.front().first;
			int val = q.front().second;
			q.pop();

			if (cur == endWord) return val;

			for (int i = 0; i < cur.size(); i++)
			{
				char orign = cur[i];
				for (cur[i] = 'a'; cur[i] <= 'z'; cur[i]++)
					if (cur[i] != orign && words.count(cur))
					{
						q.push({cur, val + 1});
						words.erase(cur);
					}
				cur[i] = orign;
			}
		}

		return (0);
	}
};

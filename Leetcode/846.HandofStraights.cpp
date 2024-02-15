/*
846. Hand of Straights

Medium

link to the problem:
https://leetcode.com/problems/hand-of-straights/
*/
class Solution {
public:
	bool isNStraightHand(vector<int>& hand, int groupSize)
	{
		if (hand.size() % groupSize) return false;

		map<int, int> mp;
		
		for (auto &i : hand) mp[i] += 1;

		int groups = 0, n = hand.size()/groupSize;

		for (int i = 0; i < n; i++)
		{
			vector<int> toErase;

			int last, x = 0;

			for (auto &[i, j] : mp)
			{
				if (!x || (i - last == 1)) last = i, j -= 1, x += 1;
				else return (false);

				if (j < 0) return (false);
				if (j == 0) toErase.push_back(i);
				if (x == groupSize) break;
			}

			if (x < groupSize) return (false);

			for (auto &e : toErase) mp.erase(e);
		}

		return (true);
	}
};

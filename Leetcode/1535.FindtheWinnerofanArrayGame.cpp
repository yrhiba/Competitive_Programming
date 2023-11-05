/*
* Medium Leetcode problem.

link to the problem:
https://leetcode.com/problems/find-the-winner-of-an-array-game/
*/
class Solution {
public:
	int getWinner(vector<int>& arr, int k) {

		if (k >= arr.size())
			return (*max_element(arr.begin(), arr.end()));

		int i = 0, n = arr.size(), cur = 0;

		while (true)
		{
			if (cur == k)
				return (arr[i % n]);

			if (arr[i % n] > arr[(i + 1) % n])
			{
				cur += 1;
				swap(arr[i % n], arr[(i + 1) % n]);
			}
			else
			{
				cur = 1;
			}

			i += 1;
		}
		return (0); // dumy return
	}
};
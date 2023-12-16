/*

268. Missing Number

link to the problem:
https://leetcode.com/problems/missing-number/

*/
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int res = nums.size();
		for (int i = 0; i < nums.size(); i++)
			res = (res ^ nums[i] ^ i);
		return res;
	}
};
/*
link to the problem:
https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
*/
class Solution {
public:
	int findMin(vector<int>& nums) {
		
		int start = 0;
		int end = nums.size() - 1;
		int mid;
		int ans;

		while (start <= end)
		{
			mid = start + (end - start) / 2;
		
			if (nums[mid] <= nums[nums.size() - 1])
			{
				ans = nums[mid];
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
			}
		}

		return (ans);
	}
};
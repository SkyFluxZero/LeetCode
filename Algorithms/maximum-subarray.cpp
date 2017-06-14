// 53. Maximum Subarray
// https://leetcode.com/problems/maximum-subarray/

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int result = INT_MIN, sum = 0;
		for (const auto &i : nums) {
			sum = max(sum + i, i);
			result = max(result, sum);
		}
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums;
	int answer, result;

	nums = {-1};
	answer = -1;
	result = solution.maxSubArray(nums);
	assert(answer == result);

	nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	answer = 6;
	result = solution.maxSubArray(nums);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
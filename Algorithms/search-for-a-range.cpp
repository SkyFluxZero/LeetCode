// 34. Search for a Range
// https://leetcode.com/problems/search-for-a-range/

/*
Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		return {lowerBound(nums, target), upperBound(nums, target)};
	}
private:
	int lowerBound(vector<int>& nums, int target) {
		if (nums.empty()) {
			return -1;
		}
		int n = nums.size(), i = 0, j = n - 1;
		while (i + 1 < j) {
			int mid = i + (j - i) / 2;
			if (nums[mid] < target) {
				i = mid;
			}
			else {
				j = mid;
			}
		}
		if (nums[i] == target) {
			return i;
		}
		if (nums[j] == target) {
			return j;
		}
		return -1;
	}
	int upperBound(vector<int>& nums, int target) {
		if (nums.empty()) {
			return -1;
		}
		int n = nums.size(), i = 0, j = n - 1;
		while (i + 1 < j) {
			int mid = i + (j - i) / 2;
			if (nums[mid] > target) {
				j = mid;
			}
			else {
				i = mid;
			}
		}
		if (nums[j] == target) {
			return j;
		}
		if (nums[i] == target) {
			return i;
		}
		return -1;
	}
};

int main(void) {
	Solution solution;
	vector<int> nums, answer, result;
	int target;

	nums = {1};
	target = 1;
	answer = {0, 0};
	result = solution.searchRange(nums, target);
	assert(answer == result);

	nums = {};
	target = 0;
	answer = {-1, -1};
	result = solution.searchRange(nums, target);
	assert(answer == result);

	nums = {1};
	target = 0;
	answer = {-1, -1};
	result = solution.searchRange(nums, target);
	assert(answer == result);

	nums = {5, 7, 7, 8, 8, 10};
	target = 8;
	answer = {3, 4};
	result = solution.searchRange(nums, target);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
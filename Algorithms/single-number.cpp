// 136. Single Number
// https://leetcode.com/problems/single-number/

/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		return accumulate(begin(nums), end(nums), 0, bit_xor<int>());
	}
};
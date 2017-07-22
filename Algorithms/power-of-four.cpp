// 342. Power of Four
// https://leetcode.com/problems/power-of-four/

/*
Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

Example:
Given num = 16, return true. Given num = 5, return false.

Follow up: Could you solve it without loops/recursion?
*/

class Solution {
public:
	bool isPowerOfFour(int num) {
		return num > 0 and (num - 1) % 3 == 0 and (num & (num - 1)) == 0;
	}
};

class Solution {
public:
	bool isPowerOfFour(int num) {
		if (num <= 0) {
			return false;
		}
		while (num % 4 == 0) {
			num /= 4;
		}
		return num == 1;
	}
};
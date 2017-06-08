// 476. Number Complement
// https://leetcode.com/problems/number-complement/

/*
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findComplement(int num) {
		int mask = ~0;
		while (mask & num) {
			mask <<= 1;
		}
		return ~mask & ~num;
	}
};

int main(void) {
	Solution solution;
	int num, answer, result;

	num = 5;
	answer = 2;
	result = solution.findComplement(num);
	assert(answer == result);

	num = 1;
	answer = 0;
	result = solution.findComplement(num);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
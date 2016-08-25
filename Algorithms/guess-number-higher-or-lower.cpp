// 374. Guess Number Higher or Lower
// https://leetcode.com/problems/guess-number-higher-or-lower/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
	int guessNumber(int n) {
		int low = 1;
		int high = n;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			int result = guess(mid);
			if (result == 0) return mid;
			if (result < 0) high = mid - 1;
			else low = mid + 1;
		}
		return -1;
	}
};

class Solution {
public:
	int guessNumber(int n) {
		int low = 1;
		int high = n;
		while (low <= high) {
			int mid1 = low + (high - low) / 3;
			int mid2 = high - (high - low) / 3;
			int result1 = guess(mid1);
			int result2 = guess(mid2);
			if (result1 == 0) return mid1;
			if (result2 == 0) return mid2;
			if (result1 < 0) high = mid1 - 1;
			else if (result2 > 0) low = mid2 + 1;
			else {
				low = mid1 + 1;
				high = mid2 - 1;
			}
		}
		return -1;
	}
};
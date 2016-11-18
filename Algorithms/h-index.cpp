// 274. H-Index
// https://leetcode.com/problems/h-index/
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
// BEGIN: https://discuss.leetcode.com/topic/40765/java-bucket-sort-o-n-solution-with-detail-explanation
class Solution {
public:
	int hIndex(vector<int>& citations) {
		if (citations.empty()) return 0;
		const int n = citations.size();
		vector<int> buckets(n + 1, 0);
		for (const auto &i : citations) buckets[i >= n ? n : i]++;
		for (int i = n, cnt = 0; i >= 0; i--) {
			cnt += buckets[i];
			if (cnt >= i) return i;
		}
		return 0;
	}
};
// class Solution {
// public:
// 	int hIndex(vector<int>& citations) {
// 		if (citations.empty()) return 0;
// 		const int n = *max_element(begin(citations), end(citations));
// 		vector<int> buckets(n + 1, 0);
// 		for (const auto &i : citations) buckets[i]++;
// 		for (int i = n, cnt = 0; i >= 0; i--) {
// 			cnt += buckets[i];
// 			if (cnt >= i) return i;
// 		}
// 		return 0;
// 	}
// };
// END: https://discuss.leetcode.com/topic/40765/java-bucket-sort-o-n-solution-with-detail-explanation
int main(void) {
	Solution solution;
	vector<int> citations;
	cout << solution.hIndex(citations) << "\tPassed\n";
	citations = {3, 0, 6, 1, 5};
	cout << solution.hIndex(citations) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}
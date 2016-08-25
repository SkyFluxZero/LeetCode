// 339. Nested List Weight Sum
// https://leetcode.com/problems/nested-list-weight-sum/
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
	int depthSum(vector<NestedInteger>& nestedList) {
		return this->depthSum(nestedList, 1);
	}
private:
	int depthSum(vector<NestedInteger>& nestedList, int depth) {
		int result = 0;
		for (size_t i = 0; i < nestedList.size(); ++i) {
			if (nestedList[i].isInteger()) {
				result += depth * nestedList[i].getInteger();
				continue;
			}
			result += this->depthSum(nestedList[i].getList(), depth + 1);
		}
		return result;
	}
};
// 546. Remove Boxes
// https://leetcode.com/problems/remove-boxes/

/*
Given several boxes with different colors represented by different positive numbers. 
You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (composed of k boxes, k >= 1), remove them and get k*k points.
Find the maximum points you can get.

Example 1:
Input:

[1, 3, 2, 2, 2, 3, 4, 3, 1]
Output:
23
Explanation:
[1, 3, 2, 2, 2, 3, 4, 3, 1] 
----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
----> [1, 3, 3, 3, 1] (1*1=1 points) 
----> [1, 1] (3*3=9 points) 
----> [] (2*2=4 points)
Note: The number of boxes n would not exceed 100.
*/

#include <iostream> // std::cout; std::cin
#include <cstdlib> // rand
#include <cassert> // assert
#include <cctype> // isalnum; isalpha; isdigit; islower; isupper; isspace; tolower; toupper
#include <cmath> // pow; sqrt; round; fabs; abs; log
#include <climits> // INT_MIN; INT_MAX; LLONG_MIN; LLONG_MAX; ULLONG_MAX
#include <cfloat> // DBL_EPSILON; LDBL_EPSILON
#include <cstring> // std::memset
#include <algorithm> // std::swap; std::max; std::min; std::min_element; std::max_element; std::minmax_element; std::next_permutation; std::prev_permutation; std::nth_element; std::sort; std::lower_bound; std::upper_bound; std::reverse
#include <limits> // std::numeric_limits<int>::min; std::numeric_limits<int>::max; std::numeric_limits<double>::epsilon; std::numeric_limits<long double>::epsilon;
#include <numeric> // std::accumulate; std::iota
#include <string> // std::to_string; std::string::npos; std::stoul; std::stoull; std::stoi; std::stol; std::stoll; std::stof; std::stod; std::stold; 
#include <list> // std::list::merge; std::list::splice; std::list::merge; std::list::unique; std::list::sort
#include <bitset>
#include <vector>
#include <deque>
#include <stack> // std::stack::top; std::stack::pop; std::stack::push
#include <queue> // std::queue::front; std::queue::back; std::queue::pop; std::queue::push
#include <set> // std::set::count; std::set::find; std::set::equal_range; std::set::lower_bound; std::set::upper_bound
#include <map> // std::map::count; std::map::find; std::map::equal_range; std::map::lower_bound; std::map::upper_bound
#include <unordered_set>
#include <unordered_map>
#include <utility> // std::pair; std::make_pair
#include <iterator>
#include <functional> // std::less<int>; std::greater<int>
using namespace std;

class Solution {
public:
	int removeBoxes(vector<int>& boxes) {
		if (boxes.empty()) {
			return 0;
		}
		int result = 0;
		for (size_t i = 0, n = boxes.size(); i < n; i++) {
			if (i == 0 or boxes.at(i - 1) != boxes.at(i)) {
				result = max(result, removeBoxes(boxes, i));
			}
		}
		return result;
	}
private:
	int removeBoxes(vector<int>& boxes, size_t i) {
		if (boxes.empty()) {
			return 0;
		}
		size_t j = i;
		int result = 0, target = boxes.at(i);
		while (j < boxes.size() and boxes.at(j) == target) {
			j++;
		}
		boxes.erase(next(begin(boxes), i), next(begin(boxes), j));
		result = (j - i) * (j - i) + removeBoxes(boxes);
		boxes.insert(next(begin(boxes), i), j - i, target);
		return result;
	}
};

int main(void) {
	Solution solution;
	vector<int> boxes;
	int result = 0, answer = 0;

	boxes = {3, 8, 8, 5, 5, 3, 9, 2, 4, 4, 6, 5, 8, 4, 8, 6, 9, 6, 2, 8, 6, 4, 1, 9, 5, 3, 10, 5, 3, 3, 9, 8, 8, 6, 5, 3, 7, 4, 9, 6, 3, 9, 4, 3, 5, 10, 7, 6, 10, 7};
	answer = 136;
	result = solution.removeBoxes(boxes);
	assert(answer == result);

	boxes = {1, 3, 2, 2, 2, 3, 4, 3, 1};
	answer = 23;
	result = solution.removeBoxes(boxes);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
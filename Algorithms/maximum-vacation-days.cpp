// 568. Maximum Vacation Days
// https://leetcode.com/problems/maximum-vacation-days/

/*
LeetCode wants to give one of its best employees the option to travel among N cities to collect algorithm problems. But all work and no play makes Jack a dull boy, you could take vacations in some particular cities and weeks. Your job is to schedule the traveling to maximize the number of vacation days you could take, but there are certain rules and restrictions you need to follow.

Rules and restrictions:
You can only travel among N cities, represented by indexes from 0 to N-1. Initially, you are in the city indexed 0 on Monday.
The cities are connected by flights. The flights are represented as a N*N matrix (not necessary symmetrical), called flights representing the airline status from the city i to the city j. If there is no flight from the city i to the city j, flights[i][j] = 0; Otherwise, flights[i][j] = 1. Also, flights[i][i] = 0 for all i.
You totally have K weeks (each week has 7 days) to travel. You can only take flights at most once per day and can only take flights on each week's Monday morning. Since flight time is so short, we don't consider the impact of flight time.
For each city, you can only have restricted vacation days in different weeks, given an N*K matrix called days representing this relationship. For the value of days[i][j], it represents the maximum days you could take vacation in the city i in the week j.
You're given the flights matrix and days matrix, and you need to output the maximum vacation days you could take during K weeks.

Example 1:
Input:flights = [[0,1,1],[1,0,1],[1,1,0]], days = [[1,3,1],[6,0,3],[3,3,3]]
Output: 12
Explanation: 
Ans = 6 + 3 + 3 = 12. 

One of the best strategies is:
1st week : fly from city 0 to city 1 on Monday, and play 6 days and work 1 day. 
(Although you start at city 0, we could also fly to and start at other cities since it is Monday.) 
2nd week : fly from city 1 to city 2 on Monday, and play 3 days and work 4 days.
3rd week : stay at city 2, and play 3 days and work 4 days.
Example 2:
Input:flights = [[0,0,0],[0,0,0],[0,0,0]], days = [[1,1,1],[7,7,7],[7,7,7]]
Output: 3
Explanation: 
Ans = 1 + 1 + 1 = 3. 

Since there is no flights enable you to move to another city, you have to stay at city 0 for the whole 3 weeks. 
For each week, you only have one day to play and six days to work. 
So the maximum number of vacation days is 3.
Example 3:
Input:flights = [[0,1,1],[1,0,1],[1,1,0]], days = [[7,0,0],[0,7,0],[0,0,7]]
Output: 21
Explanation:
Ans = 7 + 7 + 7 = 21

One of the best strategies is:
1st week : stay at city 0, and play 7 days. 
2nd week : fly from city 0 to city 1 on Monday, and play 7 days.
3rd week : fly from city 1 to city 2 on Monday, and play 7 days.
Note:
N and K are positive integers, which are in the range of [1, 100].
In the matrix flights, all the values are integers in the range of [0, 1].
In the matrix days, all the values are integers in the range [0, 7].
You could stay at a city beyond the number of vacation days, but you should work on the extra days, which won't be counted as vacation days.
If you fly from the city A to the city B and take the vacation on that day, the deduction towards vacation days will count towards the vacation days of city B in that week.
We don't consider the impact of flight hours towards the calculation of vacation days.
*/

#include <iostream> // std::cout; std::cin
#include <fstream> // std::fstream::open; std::fstream::close; 
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
	int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
		unordered_map<size_t, unordered_map<size_t, unordered_map<bool, int>>> OPT;
		return helper(0, 0, true, flights, days, OPT);
	}
private:
	int helper(size_t city, size_t week, bool available, vector<vector<int>>& flights, vector<vector<int>>& days, unordered_map<size_t, unordered_map<size_t, unordered_map<bool, int>>>& OPT) {
		if (week >= days.front().size()) {
			return 0;
		}
		if (!OPT.empty() and OPT.count(city) and OPT.at(city).count(week) and OPT.at(city).at(week).count(available)) {
			return OPT.at(city).at(week).at(available);
		}
		int a = days.at(city).at(week) + helper(city, week + 1, true, flights, days, OPT);;
		if (!available) {
			return OPT[city][week][available] = a;
		}
		int b = 0;
		for (size_t i = 0, n = flights.size(); i < n; i++) {
			if (i != city and flights.at(city).at(i)) {
				b = max(b, helper(i, week, false, flights, days, OPT));
			}
		}
		return OPT[city][week][available] = max(a, b);
	}
};

int main(void) {
	Solution solution;
	vector<vector<int>> flights, days;
	int result = 0, answer = 0;

	flights = {{0, 1, 1}, {1, 0, 1}, {1, 1, 0}};
	days = {{1, 3, 1}, {6, 0, 3}, {3, 3, 3}};
	answer = 12;
	result = solution.maxVacationDays(flights, days);
	assert(answer == result);

	flights = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
	days = {{1, 1, 1}, {7, 7, 7}, {7, 7, 7}};
	answer = 3;
	result = solution.maxVacationDays(flights, days);
	assert(answer == result);

	flights = {{0, 1, 1}, {1, 0, 1}, {1, 1, 0}};
	days = {{7, 0, 0}, {0, 7, 0}, {0, 0, 7}};
	answer = 21;
	result = solution.maxVacationDays(flights, days);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
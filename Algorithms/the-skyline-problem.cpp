// 218. The Skyline Problem
// https://leetcode.com/problems/the-skyline-problem/

/*
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Now suppose you are given the locations and height of all the buildings as shown on a cityscape photo (Figure A), write a program to output the skyline formed by these buildings collectively (Figure B).

 Buildings  Skyline Contour
The geometric information of each building is represented by a triplet of integers [Li, Ri, Hi], where Li and Ri are the x coordinates of the left and right edge of the ith building, respectively, and Hi is its height. It is guaranteed that 0 ? Li, Ri ? INT_MAX, 0 < Hi ? INT_MAX, and Ri - Li > 0. You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

For instance, the dimensions of all buildings in Figure A are recorded as: [ [2 9 10], [3 7 15], [5 12 12], [15 20 10], [19 24 8] ] .

The output is a list of "key points" (red dots in Figure B) in the format of [ [x1,y1], [x2, y2], [x3, y3], ... ] that uniquely defines a skyline. A key point is the left endpoint of a horizontal line segment. Note that the last key point, where the rightmost building ends, is merely used to mark the termination of the skyline, and always has zero height. Also, the ground in between any two adjacent buildings should be considered part of the skyline contour.

For instance, the skyline in Figure B should be represented as:[ [2 10], [3 15], [7 12], [12 0], [15 10], [20 8], [24, 0] ].

Notes:

The number of buildings in any input list is guaranteed to be in the range [0, 10000].
The input list is already sorted in ascending order by the left x position Li.
The output list must be sorted by the x position.
There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...[2 3], [4 5], [7 5], [11 5], [12 7]...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...[2 3], [4 5], [12 7], ...]
*/

class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<Line> A;
		for (const auto & i : buildings) {
			A.push_back(Line(i[0], i[2], -1));
			A.push_back(Line(i[1], i[2], 1));
		}
		sort(begin(A), end(A));
		multiset<int, greater<int>> B;
		vector<pair<int, int>> result;
		for (const auto & i : A) {
			if (i.z < 0) {
				if (B.empty()) {
					result.push_back({i.x, i.y});
				}
				else if (*begin(B) < i.y) {
					result.push_back({i.x, i.y});
				}
				B.insert(i.y);
			}
			else {
				int h = *begin(B);
				B.erase(B.find(i.y));
				if (B.empty()) {
					result.push_back({i.x, 0});
				}
				else if (*begin(B) < h) {
					result.push_back({i.x, *begin(B)});
				}
			}
		}
		return result;
	}
private:
	struct Line {
		int x, y, z;
		Line(int x, int y, int z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}
		bool operator< (const Line & other) {
			if (this->x == other.x) {
				if (this->z == other.z) {
					if (this->z < 0) {
						return this->y > other.y;
					}
					return this->y < other.y;
				}
				return this->z < other.z;
			}
			return this->x < other.x;
		}
	};
};

class Solution {
public:
	vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
		vector<Line> A;
		for (const auto & i : buildings) {
			A.push_back(Line(i[0], i[2], -1));
			A.push_back(Line(i[1], i[2], 1));
		}
		sort(begin(A), end(A));
		multiset<int> B;
		vector<pair<int, int>> result;
		for (const auto & i : A) {
			if (i.z < 0) {
				if (B.empty()) {
					result.push_back({i.x, i.y});
				}
				else if (*prev(end(B)) < i.y) {
					result.push_back({i.x, i.y});
				}
				B.insert(i.y);
			}
			else {
				int h = *prev(end(B));
				B.erase(B.find(i.y));
				if (B.empty()) {
					result.push_back({i.x, 0});
				}
				else if (*prev(end(B)) < h) {
					result.push_back({i.x, *prev(end(B))});
				}
			}
		}
		return result;
	}
private:
	struct Line {
		int x, y, z;
		Line(int x, int y, int z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}
		bool operator< (const Line & other) {
			if (this->x == other.x) {
				if (this->z == other.z) {
					if (this->z < 0) {
						return this->y > other.y;
					}
					return this->y < other.y;
				}
				return this->z < other.z;
			}
			return this->x < other.x;
		}
	};
};
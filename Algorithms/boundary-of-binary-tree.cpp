// 545. Boundary of Binary Tree
// https://leetcode.com/problems/boundary-of-binary-tree/

/*
Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root. Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes.

Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.

The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.

The right-most node is also defined by the same way with left and right exchanged.

Example 1
Input:
  1
   \
    2
   / \
  3   4

Ouput:
[1, 3, 4, 2]

Explanation:
The root doesn't have left subtree, so the root itself is left boundary.
The leaves are node 3 and 4.
The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
So order them in anti-clockwise without duplicates and we have [1,3,4,2].
Example 2
Input:
    ____1_____
   /          \
  2            3
 / \          / 
4   5        6   
   / \      / \
  7   8    9  10  
       
Ouput:
[1,2,4,7,8,9,10,6,3]

Explanation:
The left boundary are node 1,2,4. (4 is the left-most node according to definition)
The leaves are node 4,7,8,9,10.
The right boundary are node 1,3,6,10. (10 is the right-most node).
So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].
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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void garbageCollection(TreeNode* root) {
	if (root) {
		garbageCollection(root->left);
		garbageCollection(root->right);
		delete root;
	}
}

// BEGIN: http://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/
// BEGIN: Time Complexity: Linear on size of tree, Space Complexity: Linear on size of tree
class Solution {
public:
	vector<int> boundaryOfBinaryTree(TreeNode* root) {
		if (!root) {
			return {};
		}
		vector<int> result;
		result.push_back(root->val);
		leftBoundary(root->left, result);
		leaves(root->left, result);
		leaves(root->right, result);
		rightBoundary(root->right, result);
		return result;
	}
private:
	void leftBoundary(TreeNode* root, vector<int>& result) {
		if (root) {
			if (root->left) {
				result.push_back(root->val);
				leftBoundary(root->left, result);
			}
			else if (root->right) {
				result.push_back(root->val);
				leftBoundary(root->right, result);
			}
		}
	}
	void leaves(TreeNode* root, vector<int>& result) {
		if (root) {
			leaves(root->left, result);
			if (!root->left and !root->right) {
				result.push_back(root->val);
			}
			leaves(root->right, result);
		}
	}
	void rightBoundary(TreeNode* root, vector<int>& result) {
		if (root) {
			if (root->right) {
				rightBoundary(root->right, result);
				result.push_back(root->val);
			}
			else if (root->left) {
				rightBoundary(root->left, result);
				result.push_back(root->val);
			}
		}
	}
};
// END: Time Complexity: Linear on size of tree, Space Complexity: Linear on size of tree
// END: http://www.geeksforgeeks.org/boundary-traversal-of-binary-tree/

int main(void) {
	Solution solution;
	TreeNode *root = NULL;
	vector<int> result, answer;

	root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	root->right->right = new TreeNode(4);
	answer = {1, 3, 4, 2};
	result = solution.boundaryOfBinaryTree(root);
	garbageCollection(root);
	assert(answer == result);

	root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right->left = new TreeNode(6);
	root->left->right->left = new TreeNode(7);
	root->left->right->right = new TreeNode(8);
	root->right->left->left = new TreeNode(9);
	root->right->left->right = new TreeNode(10);
	answer = {1, 2, 4, 7, 8, 9, 10, 6, 3};
	result = solution.boundaryOfBinaryTree(root);
	garbageCollection(root);
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
// 144. Binary Tree Preorder Traversal
// https://leetcode.com/problems/binary-tree-preorder-traversal/

/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
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

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void gc(TreeNode*& root) {
	if (root) {
		gc(root->left);
		gc(root->right);
		delete root;
		root = NULL;
	}
}

// BEGIN: Time Complexity O(n) Space Complexity O(1)
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> result;
		while (root) {
			if (!root->left) {
				result.push_back(root->val);
				root = root->right;
			}
			else {
				TreeNode *predecessor = root->left;
				while (predecessor->right and predecessor->right != root) {
					predecessor = predecessor->right;
				}
				if (!predecessor->right) {
					result.push_back(root->val);
					predecessor->right = root;
					root = root->left;
				}
				else {
					predecessor->right = NULL;
					root = root->right;
				}
			}
		}
		return result;
	}
};
// END: Time Complexity O(n) Space Complexity O(1)

// BEGIN: https://discuss.leetcode.com/topic/30632/preorder-inorder-and-postorder-iteratively-summarization
// BEGIN: Time Complexity O(n) Space Complexity O(n)
// class Solution {
// public:
// 	vector<int> preorderTraversal(TreeNode* root) {
// 		vector<int> result;
// 		list<TreeNode*> list;
// 		while (!list.empty() or root) {
// 			if (root) {
// 				result.push_back(root->val);
// 				list.push_back(root);
// 				root = root->left;
// 			}
// 			else {
// 				root = list.back()->right;
// 				list.pop_back();
// 			}
// 		}
// 		return result;
// 	}
// };
// END: Time Complexity O(n) Space Complexity O(n)
// END: https://discuss.leetcode.com/topic/30632/preorder-inorder-and-postorder-iteratively-summarization

// BEGIN: Time Complexity O(n) Space Complexity O(n)
// class Solution {
// public:
// 	vector<int> preorderTraversal(TreeNode* root) {
// 		vector<int> result;
// 		if (root) {
// 			vector<int> left = preorderTraversal(root->left), right = preorderTraversal(root->right);
// 			result.push_back(root->val);
// 			result.insert(end(result), begin(left), end(left));
// 			result.insert(end(result), begin(right), end(right));
// 		}
// 		return result;
// 	}
// };
// END: Time Complexity O(n) Space Complexity O(n)

int main(void) {
	Solution solution;
	TreeNode *root = NULL;
	vector<int> result, answer;

	root = NULL;
	result = solution.preorderTraversal(root);
	gc(root);
	answer = {};
	assert(answer == result);

	root = new TreeNode(1);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(3);
	result = solution.preorderTraversal(root);
	gc(root);
	answer = {1, 2, 3};
	assert(answer == result);

	cout << "\nPassed All\n";
	return 0;
}
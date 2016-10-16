// 422. Valid Word Square
// https://leetcode.com/problems/valid-word-square/
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
	bool validWordSquare(vector<string>& words) {
		for (size_t i = 0; i < words.size(); i++)
			for (size_t j = 0; j < words[i].size(); j++)
				if (j >= words.size() || i >= words[j].size() || words[i][j] != words[j][i])
					return false;
		return true;
	}
};
int main(void) {
	Solution solution;
	vector<string> words;
	cout << boolalpha << solution.validWordSquare(words) << "\tPassed\n";
	words = {"abcd", "bnrt", "crmy", "dtye"};
	cout << boolalpha << solution.validWordSquare(words) << "\tPassed\n";
	words = {"abcd", "bnrt", "crm", "dt"};
	cout << boolalpha << solution.validWordSquare(words) << "\tPassed\n";
	words = {"ball", "area", "read", "lady"};
	cout << boolalpha << solution.validWordSquare(words) << "\tPassed\n";
	cout << "\nPassed All\n";
	return 0;
}
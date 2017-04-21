// 5. Longest Palindromic Substring
// https://leetcode.com/problems/longest-palindromic-substring/

/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
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

// BEGIN: https://segmentfault.com/a/1190000003914228
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() <= 1) {
			return s;
		}
		string t;
		for (const auto &i : s) {
			t.push_back('#');
			t.push_back(i);
		}
		t.push_back('#');
		vector<int> OPT(t.size(), 1);
		int x = 0, y = 0;
		for (int i = 1, n = t.size(), a = 0, b = 0; i + 1 < n; i++) {
			if (i >= b) {
				int l = i, r = i;
				while (l >= 0 and r < n and t.at(l) == t.at(r)) {
					l--;
					r++;
				}
				x = i;
				y = r - 1;
				
				continue;
			}
		}
	}
};
// END: https://segmentfault.com/a/1190000003914228

// BEGIN: Time Complexity O(n ^ 2) Space Complexity O(n ^ 2)
// class Solution {
// public:
// 	string longestPalindrome(string s) {
// 		if (s.empty()) {
// 			return "";
// 		}
// 		string result;
// 		vector<vector<bool>> OPT(s.size(), vector<bool>(s.size(), false));
// 		for (int len = 1, n = s.size(); len <= n; len++) {
// 			for (int i = 0; i + len <= n; i++) {
// 				int j = i + len - 1;
// 				if (len == 1) {
// 					OPT.at(i).at(j) = true;
// 					result = s.substr(i, 1);
// 					continue;
// 				}
// 				if (len == 2) {
// 					if (s.at(i) == s.at(j)) {
// 						OPT.at(i).at(j) = true;
// 						result = s.substr(i, 2);
// 					}
// 					continue;
// 				}
// 				if (s.at(i) == s.at(j) and OPT.at(i + 1).at(j - 1)) {
// 					OPT.at(i).at(j) = true;
// 					result = s.substr(i, len);
// 					continue;
// 				}
// 			}
// 		}
// 		return result;
// 	}
// };
// END: Time Complexity O(n ^ 2) Space Complexity O(n ^ 2)

int main(void) {
	Solution solution;
	string s, result;
	unordered_set<string> answer;

	s = "lphbehiapswjudnbcossedgioawodnwdruaaxhbkwrxyzaxygmnjgwysafuqbmtzwdkihbwkrjefrsgjbrycembzzlwhxneiijgzidhngbmxwkhphoctpilgooitqbpjxhwrekiqupmlcvawaiposqttsdgzcsjqrmlgyvkkipfigttahljdhtksrozehkzgshekeaxezrswvtinyouomqybqsrtegwwqhqivgnyehpzrhgzckpnnpvajqevbzeksvbezoqygjtdouecnhpjibmsgmcqcgxwzlzztdneahixxhwwuehfsiqghgeunpxgvavqbqrelnvhnnyqnjqfysfltclzeoaletjfzskzvcdwhlbmwbdkxnyqappjzwlowslwcbbmcxoiqkjaqqwvkybimebapkorhfdzntodhpbhgmsspgkbetmgkqlolsltpulgsmyapgjeswazvhxedqsypejwuzlvegtusjcsoenrcmypexkjxyduohlvkhwbrtzjnarusbouwamazzejhnetfqbidalfomecehfmzqkhndpkxinzkpxvhwargbwvaeqbzdhxzmmeeozxxtzpylohvdwoqocvutcelgdsnmubyeeeufdaoznxpvdiwnkjliqtgcmvhilndcdelpnilszzerdcuokyhcxjuedjielvngarsgxkemvhlzuprywlypxeezaxoqfges";
	answer = {"pnnp"};
	result = solution.longestPalindrome(s);
	assert(answer.count(result));

	s = "ibvjkmpyzsifuxcabqqpahjdeuzaybqsrsmbfplxycsafogotliyvhxjtkrbzqxlyfwujzhkdafhebvsdhkkdbhlhmaoxmbkqiwiusngkbdhlvxdyvnjrzvxmukvdfobzlmvnbnilnsyrgoygfdzjlymhprcpxsnxpcafctikxxybcusgjwmfklkffehbvlhvxfiddznwumxosomfbgxoruoqrhezgsgidgcfzbtdftjxeahriirqgxbhicoxavquhbkaomrroghdnfkknyigsluqebaqrtcwgmlnvmxoagisdmsokeznjsnwpxygjjptvyjjkbmkxvlivinmpnpxgmmorkasebngirckqcawgevljplkkgextudqaodwqmfljljhrujoerycoojwwgtklypicgkyaboqjfivbeqdlonxeidgxsyzugkntoevwfuxovazcyayvwbcqswzhytlmtmrtwpikgacnpkbwgfmpavzyjoxughwhvlsxsgttbcyrlkaarngeoaldsdtjncivhcfsaohmdhgbwkuemcembmlwbwquxfaiukoqvzmgoeppieztdacvwngbkcxknbytvztodbfnjhbtwpjlzuajnlzfmmujhcggpdcwdquutdiubgcvnxvgspmfumeqrofewynizvynavjzkbpkuxxvkjujectdyfwygnfsukvzflcuxxzvxzravzznpxttduajhbsyiywpqunnarabcroljwcbdydagachbobkcvudkoddldaucwruobfylfhyvjuynjrosxczgjwudpxaqwnboxgxybnngxxhibesiaxkicinikzzmonftqkcudlzfzutplbycejmkpxcygsafzkgudy";
	answer = {"fklkf"};
	result = solution.longestPalindrome(s);
	assert(answer.count(result));

	s = "babad";
	answer = {"bab", "aba"};
	result = solution.longestPalindrome(s);
	assert(answer.count(result));

	s = "cbbd";
	answer = {"bb"};
	result = solution.longestPalindrome(s);
	assert(answer.count(result));

	cout << "\nPassed All\n";
	return 0;
}
// 271. Encode and Decode Strings
// https://leetcode.com/problems/encode-and-decode-strings/

/*
Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

Machine 1 (sender) has the function:

string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:

string encoded_string = encode(strs);
and Machine 2 does:

vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.

Implement the encode and decode methods.

Note:
The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.
*/

class Codec {
public:

	// Encodes a list of strings to a single string.
	string encode(vector<string>& strs) {
		string result;
		for (const auto & str : strs) {
			result.append(to_string(str.size()));
			result.push_back(' ');
			result.append(str);
		}
		return result;
	}

	// Decodes a single string to a list of strings.
	vector<string> decode(string s) {
		vector<string> result;
		for (int sz = s.size(), base = 10, i = 0; i < sz; ++i) {
			int j = 0;
			while (i < sz and isdigit(s[i])) {
				j = base * j + (s[i] - '0');
				++i;
			}
			result.push_back(s.substr(i + 1, j));
			i += j;
		}
		return result;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
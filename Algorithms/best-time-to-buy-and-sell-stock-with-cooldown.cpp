// 309. Best Time to Buy and Sell Stock with Cooldown
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int sz = prices.size();
		if (sz <= 1) {
			return 0;
		}
		array<int, 2> buy;
		array<int, 3> sell;
		buy[0] = -prices[0];
		sell[0] = 0;
		buy[1] = max(-prices[0], -prices[1]);
		sell[1] = max(0, prices[1] - prices[0]);
		for (int i = 2; i < sz; ++i) {
			int a = i % 2, b = (i - 1) % 2;
			int c = i % 3, d = (i - 1) % 3, e = (i - 2) % 3;
			buy[a] = max(buy[b], sell[e] - prices[i]);
			sell[c] = max(sell[d], buy[b] + prices[i]);
		}
		return sell[(sz - 1) % 3];
	}
};

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int sz = prices.size();
		if (sz <= 1) {
			return 0;
		}
		vector<int> buy(sz, 0), sell(sz, 0);
		buy[0] = -prices[0];
		sell[0] = 0;
		buy[1] = max(-prices[0], -prices[1]);
		sell[1] = max(0, prices[1] - prices[0]);
		for (int i = 2; i < sz; ++i) {
			buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]);
			sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
		}
		return sell[sz - 1];
	}
};
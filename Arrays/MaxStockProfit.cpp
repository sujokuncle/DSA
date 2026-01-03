// LeetCode 121 - Best Time to Buy and Sell Stock
/*
Problem:
You are given an array prices where prices[i] represents the stock price on day i.
You are allowed to complete only one transaction: buy once and sell once in the future.
Return the maximum profit you can achieve. If no profit is possible, return 0.

Example:
Input:  prices = [7,1,5,3,6,4]
Output: 5
Explanation:
Buy on day 2 at price 1 and sell on day 5 at price 6.
Profit = 6 - 1 = 5.

Approach:
We iterate through the array while keeping track of the minimum price seen so far.
For each day, we calculate the profit if we sell on that day and update the maximum profit.
This ensures that buying always happens before selling.

Algorithm:
1. Initialize minPrice as the first element of the array.
2. Initialize maxProfit = 0.
3. Traverse the array from left to right:
   - Update minPrice if a lower price is found.
   - Otherwise, calculate current profit and update maxProfit.
4. Return maxProfit.

Time Complexity:
O(n) — single traversal of the array.

Space Complexity:
O(1) — constant extra space used.

Pattern:
Greedy, Sliding Window
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++){
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minPrice);
        }
        return maxProfit;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;

        for (int index = 0; index < prices.size() - 1; index++) {
            if (prices[index] < prices[index + 1]) {
                max_profit += prices[index + 1] - prices[index];
            }
        }

        return max_profit;
    }
};

/* Work
1. No selling after dipping.
2. Buy lower day and sell higher day.
3. No buying on the last day (it can never increase).
4. We don't have to buy on first day.

1   5   7
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Variables:
        int maximum_profit = 0;

        for (int index = 0; index < prices.size() - 1; index++) {
            // Detect if there is a drop:
            if (prices[index] > prices[index + 1]) {
                continue;
            } else {
                maximum_profit += prices[index + 1] - prices[index];
            }
        }

        return maximum_profit;
    }
};

/* Work
1. Do not want to buy on a day where there is a drop.
2. We want to buy low and sell high.
3. We don't want to buy on last day (always a lost).
*/
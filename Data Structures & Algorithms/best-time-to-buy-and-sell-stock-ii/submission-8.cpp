class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Variables:
        int maximum_profit = 0;

        for (int index = 1; index < prices.size(); index++) {
            if (prices[index] > prices[index - 1]) {
                maximum_profit += prices[index] - prices[index - 1];
            }
        }

        return maximum_profit;
    }
};
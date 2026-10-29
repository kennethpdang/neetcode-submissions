class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maximum_profits = 0;

        for (int index = 0; index < prices.size() - 1; index++) {
            if (prices[index] > prices[index + 1]) {
                continue;
            }

            maximum_profits += prices[index + 1] - prices[index];
        }

        return maximum_profits;
    }
};
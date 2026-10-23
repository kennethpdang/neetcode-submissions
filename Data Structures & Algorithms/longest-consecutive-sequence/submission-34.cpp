class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Variables:
        unordered_set<int> consecutive(nums.begin(), nums.end());
        int length = 0;

        for (int index = 0; index < nums.size(); index++) {
            int count = 0;
            int current_value = nums[index];

            // Not beginning of a consecutive:
            if (consecutive.contains(current_value - 1)) {
                continue;
            }

            while (consecutive.contains(current_value)) {
                current_value++;
                count++;
            }

            length = max(length, count);
        }

        return length;
    }
};
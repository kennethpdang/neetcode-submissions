class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Variables:
        unordered_set<int> consecutive(nums.begin(), nums.end());
        int maximum_length = 0;

        for (int index = 0; index < nums.size(); index++) {
            int current_value = nums[index];
            int current_count = 0;

            if (consecutive.contains(current_value - 1)) {
                continue;
            }

            while (consecutive.contains(current_value)) {
                current_count++;
                current_value++;
            }

            maximum_length = max(maximum_length, current_count);
        }

        return maximum_length;
    }
};
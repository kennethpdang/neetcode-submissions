class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Variables:
        unordered_set<int> consecutive(nums.begin(), nums.end());
        int length = 0;

        for (int index = 0; index < nums.size(); index++) {
            int current_value = nums[index];
            int count = 0;

            // Not beginning of a consecutive:
            if (consecutive.contains(nums[index] - 1)) {
                continue;
            }

            while (consecutive.contains(current_value)) {
                current_value = current_value + 1;
                count++;
            }

            length = max(length, count);
        }

        return length;
    }
};
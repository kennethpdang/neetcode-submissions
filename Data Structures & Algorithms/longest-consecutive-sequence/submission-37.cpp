class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Variables:
        unordered_set<int> values(nums.begin(), nums.end());
        int maximum_length = 0;

        for (int index = 0; index < nums.size(); index++) {
            int count = 0;
            int current_value = nums[index];
            
            // Not the beginning:
            if (values.contains(current_value - 1)) {
                continue;
            }

            while (values.contains(current_value)) {
                current_value++;
                count++;
            }

            maximum_length = max(maximum_length, count);
        }

        return maximum_length;
    }
};
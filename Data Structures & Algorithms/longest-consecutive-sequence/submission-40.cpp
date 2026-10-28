class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Variables:
        unordered_set<int> consecutive(nums.begin(), nums.end());
        int maximum_length = 0;
        int count = 0;

        for (int index = 0; index < nums.size(); index++) {
            int current_value = nums[index];
            count = 0;

            // Check if not beginning of sequence:
            if (consecutive.contains(current_value - 1)) {
                continue;
            }

            // Walking count:
            while (consecutive.contains(current_value)) {
                current_value++;
                count++;
            }

            maximum_length = max(maximum_length, count);
        }

        return maximum_length;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // Make all negative values become zero:
        for (int index = 0; index < nums.size(); index++) {
            if (nums[index] < 0) {
                nums[index] = 0;
            }
        }

        for (int index = 0; index < nums.size(); index++) {
            int current_value = abs(nums[index]);
            if (current_value >= 1 && current_value <= nums.size()) {
                if (nums[current_value - 1] > 0) {
                    nums[current_value - 1] *= -1;
                } else if (nums[current_value - 1] == 0) {
                    nums[current_value - 1] = -1 * (nums.size() + 1);
                }
            }
        }

        for (int index = 1; index <= nums.size(); index++) {
            if (nums[index - 1] >= 0) {
                return index;
            }
        }

        return nums.size() + 1;
    }
};
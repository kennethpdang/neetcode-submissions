class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Variables:
        int next_zero_index = 0;
        int next_two_index = nums.size() - 1;

        for (int index = 0; index <= next_two_index; index++) {
            if (nums[index] == 0) {
                swap(nums[next_zero_index], nums[index]);
                next_zero_index++;
            } else if (nums[index] == 2) {
                swap(nums[next_two_index], nums[index]);
                next_two_index--;
                index--;
            }
        }
    }
};
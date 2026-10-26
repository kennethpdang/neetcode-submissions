class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Variables:
        int zero_flag = 0;
        int two_flag = nums.size() - 1;

        for (int current_index = 0; current_index <= two_flag; current_index++) {
            if (nums[current_index] == 0) {
                swap(nums[current_index], nums[zero_flag]);
                zero_flag++;
            }
            else if (nums[current_index] == 2) {
                swap(nums[current_index], nums[two_flag]);
                two_flag--;
                current_index--;
            }
        }
    }
};
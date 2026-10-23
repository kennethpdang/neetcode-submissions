class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Variables:
        int zero_index = 0;
        int two_index = nums.size() - 1;

        for (int current_index = 0; current_index <= two_index; current_index++) {
            if (nums[current_index] == 0) {
                swap(nums[current_index], nums[zero_index]);
                zero_index++;
            } else if (nums[current_index] == 2) {
                swap(nums[current_index], nums[two_index]);
                two_index--;
                current_index--;
            }
        }     
    }
};
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Variables:
        int zero_flag = 0;
        int two_flag = nums.size() - 1;

        for (int index = 0; index <= two_flag; index++) {
            if (nums[index] == 0) {
                swap(nums[index], nums[zero_flag]);
                zero_flag++;
            }
            else if (nums[index] == 2) {
                swap(nums[index], nums[two_flag]);
                two_flag--;
                index--;
            }
        }
    }
};

/* Work

0   0   0   1   1   2
            z
                t
                c

*/
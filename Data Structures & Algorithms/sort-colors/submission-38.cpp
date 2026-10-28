class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Variables:
        int next_red = 0;
        int next_blue = nums.size() - 1;

        for (int index = 0; index <= next_blue; index++) {
            if (nums[index] == 0) {
                swap(nums[index], nums[next_red]);
                next_red++;
            } else if (nums[index] == 2) {
                swap(nums[index], nums[next_blue]);
                next_blue--;
                index--;
            }
        }
    }
};
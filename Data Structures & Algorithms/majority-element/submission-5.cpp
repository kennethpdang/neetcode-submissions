class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Variables:
        int candidate = 0;
        int count = 0;
        int threshold = floor(nums.size() / 2);

        for (int index = 0; index < nums.size(); index++) {
            if (nums[index] == candidate) {
                count++;
            } else if (count == 0) {
                candidate = nums[index];
            } else {
                count--;
            }
        }

        return candidate;
    }
};
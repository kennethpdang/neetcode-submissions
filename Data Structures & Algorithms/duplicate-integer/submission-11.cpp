class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // Edge case:
        if (nums.size() == 0 || nums.size() == 1) {
            return false;
        }
        
        // Sort array:
        sort(nums.begin(), nums.end());

        for(int index = 1; index < nums.size(); index++) {
            if (nums[index] == nums[index - 1]) {
                return true;
            }
        }

        return false;
    }
};
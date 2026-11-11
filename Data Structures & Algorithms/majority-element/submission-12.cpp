class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Variables:
        int candidate;
        int candidate_count = 0;

        for (int index = 0; index < nums.size(); index++) {
            if (candidate_count == 0) {
                candidate = nums[index];
                candidate_count++;
            }
            else if (nums[index] == candidate) {
                candidate_count++;
            }
            else {
                candidate_count--;
            }
        }

        return candidate;
    }
};
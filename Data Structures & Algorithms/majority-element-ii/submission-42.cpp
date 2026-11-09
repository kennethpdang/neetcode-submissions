class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Variables:
        int candidate_one = 0;
        int candidate_two = 0;
        int count_candidate_one = 0;
        int count_candidate_two = 0;
        int threshold_value = floor(nums.size() / 3);
        vector<int> majority_elements;

        for (int index = 0; index < nums.size(); index++) {
            if (nums[index] == candidate_one) {
                count_candidate_one++;
            }
            else if (nums[index] == candidate_two) {
                count_candidate_two++;
            }
            else if (count_candidate_one == 0) {
                candidate_one = nums[index];
                count_candidate_one++;
            }
            else if (count_candidate_two == 0) {
                candidate_two = nums[index];
                count_candidate_two++;
            }
            else {
                count_candidate_one--;
                count_candidate_two--;
            }
        }

        // Verification:
        count_candidate_one = 0;
        count_candidate_two = 0;
        
        for (int index = 0; index < nums.size(); index++) {
            if (nums[index] == candidate_one) {
                count_candidate_one++;
            }
            if (nums[index] == candidate_two) {
                count_candidate_two++;
            }
        }
        
        if (count_candidate_one > threshold_value) {
            majority_elements.push_back(candidate_one);
        }

        if (count_candidate_two > threshold_value && candidate_two != candidate_one) {
            majority_elements.push_back(candidate_two);
        }

        return majority_elements;
    }
};
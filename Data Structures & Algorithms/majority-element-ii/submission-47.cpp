class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Variables:
        int candidate_one = 0;
        int candidate_two = 0;
        int candidate_one_count = 0;
        int candidate_two_count = 0;
        int threshold_value = floor(nums.size() / 3);
        vector<int> majority_elements;

        for (int index = 0; index < nums.size(); index++) {
            if (nums[index] == candidate_one) {
                candidate_one_count++;
            }
            else if (nums[index] == candidate_two) {
                candidate_two_count++;
            }
            else if (candidate_one_count == 0) {
                candidate_one = nums[index];
                candidate_one_count++;
            }
            else if (candidate_two_count == 0) {
                candidate_two = nums[index];
                candidate_two_count++;
            }
            else {
                candidate_one_count--;
                candidate_two_count--;
            }
        }

        // Verify:
        candidate_one_count = 0;
        candidate_two_count = 0;

        for (int index = 0; index < nums.size(); index++) {
            if (nums[index] == candidate_one) {
                candidate_one_count++;
            }
            else if (nums[index] == candidate_two) {
                candidate_two_count++;
            }
        }

        if (candidate_one_count > threshold_value) {
            majority_elements.push_back(candidate_one);
        }

        if (candidate_two_count > threshold_value) {
            majority_elements.push_back(candidate_two);
        }

        return majority_elements;
    }
};
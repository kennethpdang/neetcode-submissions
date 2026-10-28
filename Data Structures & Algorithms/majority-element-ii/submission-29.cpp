class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Variables:
        int threshold_value = floor(nums.size() / 3);
        int candidate_one = 0;
        int candidate_two = 0;
        int count_one = 0;
        int count_two = 0;
        vector<int> majority_elements;

        // Looping:
        for (int index = 0; index < nums.size(); index++) {
            if (nums[index] == candidate_one) {
                count_one++;
            } else if (nums[index] == candidate_two) {
                count_two++;
            } else if (count_one == 0) {
                candidate_one = nums[index];
                count_one++;
            } else if (count_two == 0) {
                candidate_two = nums[index];
                count_two++;
            } else {
                count_one--;
                count_two--;
            }
        }

        count_one = 0, count_two = 0;
        for (int index = 0; index < nums.size(); index++) {
            if (nums[index] == candidate_one) {
                count_one++;
            } else if (nums[index] == candidate_two) {
                count_two++;
            }
        }

        if (count_one > threshold_value) {
            majority_elements.push_back(candidate_one);
        }

        if (count_two > threshold_value) {
            majority_elements.push_back(candidate_two);
        }

        return majority_elements;
    }
};
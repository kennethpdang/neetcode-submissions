class Solution {
private:
    void insertionSortWithGap(vector<int>& nums, int gap_size) {
        for (int current_index = gap_size; current_index < nums.size(); current_index++) {
            int value_to_insert = nums[current_index];
            int replacement_index = current_index;

            // Keep replacing cards:
            while (replacement_index >= gap_size && value_to_insert < nums[replacement_index - gap_size]) {
                nums[replacement_index] = nums[replacement_index - gap_size];
                replacement_index -= gap_size;
            }

            nums[replacement_index] = value_to_insert;
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        int nums_size = nums.size();

        for (int gap_size = nums_size / 2; gap_size >= 1; gap_size /= 2) {
            insertionSortWithGap(nums, gap_size);
        }

        return nums;
    }
};
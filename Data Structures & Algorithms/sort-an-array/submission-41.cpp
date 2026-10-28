class Solution {
private:
    void insertionSortWithGap(vector<int>& nums, int gap_size) {
        int nums_size = nums.size();

        for (int index = gap_size; index < nums_size; index++) {
            int value_to_insert = nums[index];
            int insertion_index = index;

            while (insertion_index >= gap_size && value_to_insert < nums[insertion_index - gap_size]) {
                nums[insertion_index] = nums[insertion_index - gap_size];
                insertion_index -= gap_size;
            }

            nums[insertion_index] = value_to_insert;
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
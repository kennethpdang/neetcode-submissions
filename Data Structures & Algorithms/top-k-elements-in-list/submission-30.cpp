class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Variables:
        unordered_map<int, int> frequencies;
        vector<vector<int>> frequency_buckets(nums.size() + 1);
        int remaining = k;
        vector<int> top_k_elements;

        for (int index = 0; index < nums.size(); index++) {
            frequencies[nums[index]]++;
        }

        unordered_map<int, int>::iterator current_entry = frequencies.begin();
        while (current_entry != frequencies.end()) {
            frequency_buckets[current_entry -> second].push_back(current_entry -> first);
            current_entry++;
        }

        for (int index = frequency_buckets.size() - 1; index >= 0; index--) {
            if (remaining > 0) {
                int bucket_size = frequency_buckets[index].size();
                remaining -= bucket_size;

                for (int element_index = 0; element_index < bucket_size; element_index++) {
                    top_k_elements.push_back(frequency_buckets[index][element_index]);
                }
            }

            if (remaining == 0) {
                return top_k_elements;
            }
        }

        return top_k_elements;
    }
};

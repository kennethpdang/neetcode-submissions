class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Variables:
        unordered_map<int, int> frequencies;
        vector<vector<int>> frequency_bucket(nums.size() + 1);
        vector<int> top_k_elements;
        int size = 0;
        
        // Collect frequencies:
        for (int index = 0; index < nums.size(); index++) {
            frequencies[nums[index]]++;
        }

        // Sort into buckets:
        unordered_map<int, int>::iterator current_entry = frequencies.begin();
        while (current_entry != frequencies.end()) {
            frequency_bucket[current_entry -> second].push_back(current_entry -> first);
            current_entry++;
        }

        // Collect top k:
        for (int index = frequency_bucket.size() - 1; index >= 0; index--) {
            if (size < k) {
                int current_size = frequency_bucket[index].size();
                size += current_size;
                for (int element = 0; element < current_size; element++) {
                    top_k_elements.push_back(frequency_bucket[index][element]);
                }
            }

            if (size == k) {
                return top_k_elements;
            }
        }

        return top_k_elements;
    }
};

// NOTE TO SELF BEFORE DELETE:
// THINK OF BOUNDS OF ELEMENTS LIKE HERE IT"S BOUNDED BY N + 1 FOR FREQUENCIES.
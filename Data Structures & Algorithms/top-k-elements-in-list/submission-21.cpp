class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Variables:
        unordered_map<int, int> frequencies;
        vector<vector<int>> frequency_buckets(nums.size() + 1);
        vector<int> top_k_elements;
        int num_accumulated = 0;

        // Pick up frequencies:
        for (int index = 0; index < nums.size(); index++) {
            frequencies[nums[index]]++;
        }

        // Place in buckets:
        unordered_map<int, int>::iterator current_entry = frequencies.begin();
        while (current_entry != frequencies.end()) {
            frequency_buckets[current_entry -> second].push_back(current_entry -> first);
            current_entry++;
        }

        // Collect top k elements:
        for (int index = frequency_buckets.size() - 1; index >= 0; index--) {
            if (num_accumulated < k) {
                int bucket_size = frequency_buckets[index].size();
                num_accumulated += bucket_size;
                for (int element = 0; element < bucket_size; element++) {
                    top_k_elements.push_back(frequency_buckets[index][element]);
                }
            }      
        }

        return top_k_elements;
    }
};
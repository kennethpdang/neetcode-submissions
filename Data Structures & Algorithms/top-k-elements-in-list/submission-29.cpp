class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Variables
        unordered_map<int, int> frequency;
        vector<vector<int>> frequency_bucket(nums.size() + 1);
        vector<int> top_k_frequent;
        int current_count = 0;

        // Increase frequency hashmap:
        for (int index = 0; index < nums.size(); index++) {
            frequency[nums[index]]++;    
        }

        // Place in buckets:
        unordered_map<int, int>::iterator current_entry = frequency.begin();
        while (current_entry != frequency.end()) {
            frequency_bucket[current_entry -> second].push_back(current_entry -> first);
            current_entry++;
        }

        // Place into array:
        for (int index = frequency_bucket.size() - 1; index >= 0; index--) {
            if (current_count < k) {
                int bucket_size = frequency_bucket[index].size();
                current_count += bucket_size;

                for (int element = 0; element < bucket_size; element++) {
                    top_k_frequent.push_back(frequency_bucket[index][element]);
                }
            }

            if (current_count == k) {
                return top_k_frequent;
            }
        }

        return top_k_frequent;
    }
};
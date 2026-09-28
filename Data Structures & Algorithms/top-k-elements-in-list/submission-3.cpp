class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create a histogram (sorted by value) for nums
        // I want to use a map here, but you can't sort a map by value.
        // So, let's use a vector of pairs
        // but to sort a vector is O(nlogn), and we need O(n) time complexity.
        // I guess we can keep a live result and update it as we go
        // Wait, probably overthinking this.
        // I can just build the histo and then find the top k counts.
        // That's just two O(n) operations.
        unordered_map<int, int> histogram;
        for (int num : nums) {
            histogram[num]++;
        }

        // Create a vector of elems_at_count.
        // the outer vector tracks the number of occurences
        // the inner vector tracks which elements have occurred that number of times.
        vector<vector<int>> elems_at_count(nums.size() + 1);
        for (auto [elem, count] : histogram) {
            elems_at_count[count].push_back(elem);
        }

        // Slice the top k entries off of the elems_at_count.
        vector<int> result;
        for (auto it = elems_at_count.rbegin(); it != elems_at_count.rend() && k != 0; it++) {
            if (it->size() == 0) {
                continue;
            }
            if (it->size() < k) {
                for (auto elem : *it) {
                    result.push_back(elem);
                }
                k = k - it->size();
            } else {
                for (int i = 0; i < k; i++) {
                    result.push_back((*it)[i]);
                }
                break;
            }
        }

        return result;
        
    }
};

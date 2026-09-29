class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Count the occurrences of each entry in a unordered_map histogram
        typedef int elem;
        typedef int count;
        unordered_map<elem, count> histo;
        for (auto num : nums) {
            histo[num]++;
        } 
        // Then, map each entry into a bucket for bucket sort. 
        // The index of each bucket is the number of occurences
        // the value of each bucket is a vector containing the elements that have occurred that number of times.
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto entry : histo) {
            buckets[entry.second].push_back(entry.first);
        }
        // Then, iterate backwards through the buckets and return the top k results.
        vector<int> results;
        for (auto it = buckets.rbegin(); it < buckets.rend(); it++) {
            // if our iterator has less than k results
            if (it->size() < k) {
                // then push the results on the results vector, decrease k by the size
                for (auto result : *it) {
                    results.push_back(result);
                    k--;
                }
            } else {
                // else our iterator has greater than or equal to k results
                // then push the first k results onto the results vector, return
                for (int i = 0; i < k; i++) {
                    results.push_back((*it)[i]);
                }
                return results;
            }
        }
        return results;
    }

};

#include <unordered_map>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        // Build the histogram
        for (auto i : nums) {
            // std::cout << i << std::endl;
            counts[i]++;
        }
        // For debugging, print out counts
        std::cout << "printing counts" << std::endl;
        for (auto &pair : counts) {
            std::cout << pair.first << ", " << pair.second << std::endl;
        }
        // Create a new ordered map that flips the keys and values of the histogram.
        // This will have the effect of sorting by out values. We can then return
        // the top k elements, which would be the most occurring ints.
        // map<int, int> occurances;
        multimap<int, int> occurances;
        for (auto &pair : counts) {
            std::cout << "iterating this loop" << std::endl;
            // We have the same count for [1 2] here, so this approach will fail
            // because of duplicate keys.
            // Let's play around with a multimap and see what that solution looks
            // like.
            // occurances[pair.second] = pair.first;
            occurances.insert({pair.second, pair.first});
        }
        // For debugging, print out the inversion.
        std::cout << "Printing occurances" << std::endl;
        for (auto &pair : occurances) {
            std::cout << pair.first << ", " << pair.second << std::endl;
        }

        // grab the last k values from occurances.
        vector<int> result;
        int count = 0;
        for (auto it = occurances.rbegin(); it != occurances.rend() && count < k; it++) {
            result.push_back(it->second);
            count++;
        }
        return result;
    }
};

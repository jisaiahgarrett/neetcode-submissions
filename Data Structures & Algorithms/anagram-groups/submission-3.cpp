class Solution {
public:
    // O(m*n) time, so we are allowed to visit each character once.
    // O(m) space, so we only get a 1D store that scales with the number of strings
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> results;
        typedef int index_t;

        // Where index_t here is the index of the group matching this signature in results.
        map<map<char, int>, index_t> prev_signatures;
        for (int i = 0; i < strs.size(); i++) {
            map<char, int> signature;
            for (auto c : strs[i]) {
                signature[c]++;
            }
            auto matching_signature = prev_signatures.find(signature);
            if (matching_signature != prev_signatures.end()) {
                auto result_index = matching_signature->second;
                results[result_index].push_back(strs[i]);
            } else {
                prev_signatures[signature] = results.size();
                results.push_back({strs[i]});
            }
        }
        
        return results;
    }
};

// Brute force solution:
// 1. calculate the signature for each string O(n)
// 2. compare that signature to the existing list of signatures O(m)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // For each str in strs
        typedef map<char, int> signature_t;
        typedef int result_idx_t;
        map<signature_t, result_idx_t> seen;
        vector<vector<string>> results;
        for (int i = 0; i < strs.size(); i++) {
            auto str = strs[i];
            signature_t signature;
            for (auto c : str) {
                signature[c]++;
            }
            auto match = seen.find(signature);
            if (match != seen.end()) {
                auto result_idx = seen[signature];
                results[result_idx].push_back(str);
            } else {
                seen[signature] = results.size();
                results.push_back({str});
            }
        }
    return results;

        
    }
};

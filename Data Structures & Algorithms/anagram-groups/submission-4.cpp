class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // O(m*n) time, O(m) space, m := number of strings, n:= len(longest string)
        typedef map<char, int> signature_t;
        typedef int index_t;
        map<signature_t, index_t> seen_signatures;
        vector<vector<string>> results;

        // for each string
        for (auto str : strs) {
            // generate the signature with a map<char, int> 
            signature_t signature;
            for (auto c : str) {
                signature[c]++;
            }
            if (seen_signatures.contains(signature)) {
                results[seen_signatures[signature]].push_back(str);
            } else {
                seen_signatures[signature] = results.size();
                results.push_back({str});
        }
    }
    return results;

}
};

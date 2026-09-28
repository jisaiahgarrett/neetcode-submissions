class Solution {
public:
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> results;
    map<map<char, int>, int> group_to_result_index;
    for (auto& str : strs) {
        map<char, int> counts;
        for (char c : str) counts[c]++;
        auto it = group_to_result_index.find(counts);
        if (it != group_to_result_index.end()) {
            results[it->second].push_back(str);
        } else {
            group_to_result_index[counts] = results.size();
            results.push_back({str});
        }
    }
    return results;
}
};

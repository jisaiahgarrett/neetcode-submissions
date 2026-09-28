class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> has_appeared;
        for (auto i : nums) {
            if (has_appeared.contains(i)) {
                return true;
            }
            has_appeared.insert(i);
        }
        return false;
    }
};
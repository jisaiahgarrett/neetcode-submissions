class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> numSet;
        for (auto num : nums) {
            if (numSet.contains(num)) {
                return true;
            }
            numSet.insert(num);
        }
        return false;
        
    }
};
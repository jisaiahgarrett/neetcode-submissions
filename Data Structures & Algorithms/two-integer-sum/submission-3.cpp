class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        typedef int index_t;
        unordered_map<int, index_t> previous_entries;
        previous_entries[nums[0]] = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            auto num = nums[i];
            auto difference = target - num;
            if (previous_entries.contains(difference)) {
                result = {previous_entries[difference], i};
                return result;
            }
            previous_entries[num] = i;
        }
        return result;
    }
};

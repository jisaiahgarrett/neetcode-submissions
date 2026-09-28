class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        typedef int index_t;
        unordered_map<int, index_t> difference_to_index;
        for (int i = 0; i < nums.size(); i++) {
            auto difference = target - nums[i];
            auto match_found = difference_to_index.find(difference) != difference_to_index.end();
            if (match_found) {
                return {difference_to_index[difference], i};
            } else {
                difference_to_index[nums[i]] = i;
            }
        }
        return {}; // should never get here.
    }
};

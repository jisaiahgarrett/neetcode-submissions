class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        typedef int index_t;
        map<int, index_t> differences;
        // loop starts here.
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int difference = target - num;
            auto match = differences.find(difference);
            if (match != differences.end()) {
                return {match->second, i};
            } else {
                differences[num] = i;
            }
        }
        return {};
    }
};

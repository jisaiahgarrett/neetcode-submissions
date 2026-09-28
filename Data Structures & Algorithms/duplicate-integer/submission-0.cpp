#include <unordered_map>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int, int> counts;
        for (auto num : nums) {
            // std::cout << num << std::endl;
            // bool has_num = counts.contains(num);
            bool count = counts[num];
            // std::cout << count << std::endl;
            if (count > 0) {
                return true;
            }
            counts[num] = counts[num] + 1;
        }
        return false;
    }
};

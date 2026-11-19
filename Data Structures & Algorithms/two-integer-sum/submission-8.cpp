class Solution {
public:
    // We need a list of the values that we've seen and their indexes.
    // {value, idx}
    vector<int> twoSum(vector<int>& nums, int target) {
        typedef int value_t;
        typedef int index_t;
        std::map<value_t, index_t> seen;
        for (int i = 0; i < nums.size(); i++) {
            // calculate the addend value that we are looking for in nums
            value_t addend = target - nums[i];
            auto found = seen.find(addend);
            if (found != seen.end()) {
                cout << "typeid(found).name() " << typeid(found).name() << endl;
                cout << "typeid(*found).name() " << typeid(*found).name() << endl;
                cout << "found->first " << found->first << endl;
                cout << "found->second " << found->second << endl;
                return {seen[found->first], i};
            } else {
                seen[nums[i]] = i;
            }
        }
        return {};
    }
};

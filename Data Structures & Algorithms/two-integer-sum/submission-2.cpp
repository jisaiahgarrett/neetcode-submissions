class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // difference = target - nums[i]
        // if difference exists in the array, then we have foud our pair.
        // We use a hash map to keep track of the values that we have seen

        // Add the first value in nums to our hash map
        vector<int> result;
        typedef int index_t;
        unordered_map<int, index_t> previous_entries;
        previous_entries[nums[0]] = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            auto num = nums[i];
            auto difference = target - num;
            if (previous_entries.contains(difference)) {
                cout << "found it" << endl;
                result = {previous_entries[difference], i};
                return result;
            }
            cout << "adding " << num << ", with index " << i << endl;
            previous_entries[num] = i;
        }
        // if not, then add num to the hash map with it's index and keep going
        return result;
    }
};

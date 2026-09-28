class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // difference = target - nums[0]
        // See if difference already exists in your map.
        typedef int index_t;
        unordered_map<int, index_t> difference_to_index;
        // Initialize our map with the first entry in the array.
        difference_to_index[nums[0]] = 0;
        for (int i = 1; i < nums.size(); i++) {
            auto difference = target - nums[i];
            // Check if difference exists in our map,
            //auto match = find(difference_to_index.start(), difference);
            cout << "searching map for " << difference << endl;
            auto match = difference_to_index.find(difference);
            auto match_found = match != difference_to_index.end();
            // if so, then we have a match, return our results.
            if (match_found) {
                cout << "found!" << endl;
                return {difference_to_index[difference], i};
            } else {
            // if not, then add it to our map and keep iterating.
                cout << "adding " << nums[i] << " to map" << endl;
                difference_to_index[nums[i]] = i;
            }
        }
        return {0, 0}; // should never get here.
    }
};

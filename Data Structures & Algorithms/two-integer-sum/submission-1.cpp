// Ok, so we have nums and target, we are summing various pairs in nums such
// that they sum to target. We are assured to have a pair, return the lower
// index first in the pair.
// We need to use O(n) time and space.
// Brute force, we iterate through nums in a 2D for loop looking for a match.
// This is O(n^2) time, O(1) space.
// My intuition wants to subtract each member in nums from target, what does 
// that do.
// 10 - [4 5 6] = [6 5 4]
// This effectively reverses the array, that's interesting.
// Maybe we sum outside to in on the array
// [4 5 6] + [6 5 4] = [10 10 10].
// If we do this approach, we will only ever sum halfway through the array.
// Need to handle odd and even length cases differently (maybe? maybe could
// get cute with a unified solution).
// Nope, this isn't it, doesn't work with example 1.
// Hint 2 says rearrange the equation with, this makes me think more
// about the compliment array.
// 10 - [4 5 6] = [6 5 4]
// we know that target-nums[i] = reverse(nums[i])
// nums[i] = nums[length-i]
// Oh, we use a hashmap to store the values we've seen already.
// So, for example 1:
// Look for 7-3=4 in the hashmap, dont see it, add {3:0} in the hashmap.
// Look for 7-4=3 in the hashmap, do see it, return [map.at(diff), i]


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> previous_values;
        vector<int> result;
        for (auto i = 0; i < nums.size(); ++i) {
            auto difference = target - nums[i];
            if (previous_values.find(difference) != previous_values.end()) {
                // Found the key, return it
                auto augend_index = previous_values.at(difference);
                result.push_back(augend_index);
                result.push_back(i);
                return result;
            }
            else {
                // Have not found the key, add the key to map with index as value.
                std::cout << "adding pair {" << nums[i] << ", " << i << "} to map." << std::endl;
                previous_values[nums[i]] = i;
            } 
        }
        return result;
    }
};

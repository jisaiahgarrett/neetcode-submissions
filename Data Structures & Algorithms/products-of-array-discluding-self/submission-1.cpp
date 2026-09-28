// Naive solution: 
// For each value in nums, multiple by the other values in nums
// This is o(n^2) time.
// Trick 1:
// Multiply all values together, then divide by each nums[i].
// But, if we can't divide, this is out of the question.
// Using prefix/suffix, we can solve this.
// nums =   [1,  2,  4,  6 ]
// prefix = [1,  1,  2,  8 ]
// suffix = [48, 24, 6,  1 ]
// Now, output[i] = prefix[i] * suffix[i]
// output = [48, 24, 12, 8 ]
// Test case 2
//.           0  1 2 3 4
// nums =   [-1  0 1 2 3 ]
// prefix = [ 1 -1 0 0 0 ]
// suffix = [ 0  6 6 3 1 ]
// output = [ 0 -6 0 0 0 ]

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t length = nums.size();

        // Build the prefix array
        vector<int> prefix(length);
        prefix.at(0) = 1; // Initialize the first position to 1.
        std::cout << "printing prefix" << std::endl;
        for (int i = 1; i < length; ++i) {
            prefix.at(i) = nums.at(i-1) * prefix.at(i-1);
            std::cout << prefix.at(i) << std::endl;
        }

        // Build the suffix array
        vector<int> suffix(length);
        suffix.at(length-1) = 1; // Initialize the final position to 1.
        std::cout << "printing suffix" << std::endl;
        for (int i = length-2; i >= 0; --i) {
            suffix.at(i) = nums.at(i+1) * suffix.at(i+1);
            std::cout << suffix.at(i) << std::endl;
        }

        vector<int> result(length);
        for (int i = 0; i < result.size(); ++i) {
            result.at(i) = prefix.at(i) * suffix.at(i);
        }
        return result; 
    }
};

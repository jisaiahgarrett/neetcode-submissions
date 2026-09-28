// Brute force solution: 2d for loop through it. O(n^2) time though.
// Smarter:
// 2 pointers, start l at 0, start r at 1.
// Sum l+r
// if sum is less than target, increment r.
// if sum is greater than target, decrement r, increment l



class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size()-1;

        while (left < right) {
            auto sum = numbers.at(left) + numbers.at(right);
            if (sum < target) {
                left++;
            } else if (sum > target) {
                right--;
            }
            else {
                break; // We found our answer
            }
        }
        
        return vector<int>{left + 1, right + 1};



    }
};

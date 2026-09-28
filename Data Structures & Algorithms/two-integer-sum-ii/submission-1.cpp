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
        int right = 1;
        
        int sum = numbers.at(left) + numbers.at(right); 
        cout << "left: " << left << ", right: " << right << ", sum: " << sum << endl;
        while (sum != target) {
            if (sum < target) {
                right++;
                // Right is at the border, need to increment left.
                if (right == numbers.size()) {
                    left++;
                    right--;
                }
            }
            else if (sum > target) {
                left++;
                right--;
            }
            if (left >= right) {
                left--;
            }

            sum = numbers.at(left) + numbers.at(right);
            cout << "left: " << left << ", right: " << right << ", sum: " << sum << endl;
        }
        return vector<int>{left + 1, right + 1};



    }
};

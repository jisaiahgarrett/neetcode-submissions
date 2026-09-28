class Solution {
public:
    int search(vector<int>& nums, int target) {
        const int nums_len = nums.size();
        int left_idx = 0, right_idx = nums_len-1;

        while(left_idx <= right_idx) {
            int pivot_idx = left_idx + (right_idx - left_idx) / 2;
            int pivot = nums[pivot_idx];
            if (pivot == target) {
                return pivot_idx;
            }
            if (pivot < target) {
                left_idx = pivot_idx + 1;
            } else {
                right_idx = pivot_idx - 1;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int left_max = height.at(l), right_max = height.at(r);
        int area = 0;
        while (l < r) {
            if (left_max < right_max) {
                l++;
                left_max = max(left_max, height.at(l));
                area += left_max - height.at(l);
            } else {
                r--;
                right_max = max(right_max, height.at(r));
                area += right_max - height.at(r);
            }
        }
        return area;
    }
};

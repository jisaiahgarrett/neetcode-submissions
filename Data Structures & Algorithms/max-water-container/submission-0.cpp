// While L<R,
// Calculate the area, compare it to the best area we've seen.
// Iterate the smaller of the two pointers.

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1, best = 0;
        while(l < r) {
            auto l_height = heights.at(l);
            auto r_height = heights.at(r);
            auto lower_height = min(l_height, r_height);
            auto width = r - l;
            auto area = lower_height * width;
            best = max(area, best);
            if (l_height <= r_height) {
                l++;
            }
            else {
                r--;
            }
        } 
        return best; 
    }
};

class Solution {
public:
    int trap(vector<int>& height) {
        // calculate max left array
        vector<int> maxLeft(height.size());
        maxLeft.at(0) = height.at(0);
        cout << "maxLeft.at(" << 0 << ") = " << maxLeft.at(0) << endl;
        for (int i = 1; i < maxLeft.size(); i++) {
            maxLeft.at(i) = max(maxLeft.at(i-1), height.at(i));
            cout << "maxLeft.at(" << i << ") = " << maxLeft.at(i) << endl;
        }
        // calculate max right array
        vector<int> maxRight(height.size());
        maxRight.at(maxRight.size()-1) = height.at(height.size()-1);
        for (int i = maxRight.size()-2; i >= 0; i--) {
            maxRight.at(i) = max(maxRight.at(i+1), height.at(i));
        }
        // calculate min of two arrays
        vector<int> mins(height.size());
        for (int i = 0; i < mins.size(); i++) {
            mins.at(i) = min(maxLeft.at(i), maxRight.at(i));
        }
        // subtract min - height[i], accumulate into area
        int area = 0;
        for (int i = 0; i < mins.size(); i++) {
            area += max(0, mins.at(i) - height.at(i));
        }
        return area;
    }
};

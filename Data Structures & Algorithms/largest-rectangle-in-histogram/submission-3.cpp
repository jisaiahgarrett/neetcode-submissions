// Brute force:
// check for height 1 rectangles, find largest area, then check for height 2, etc..
// O(n^2) time, O(n) space.
// Subtract 1 from all entries, look for longest run of 0's, then use that to find your area.
// Repeat for 2, etc...
// We need O(n) time.
// 

struct RectangleOrigin {
    int starting_index;
    int height;
};

std::ostream& operator<<(std::ostream &os, const RectangleOrigin &rect) {
    os << "{idx:" << rect.starting_index << ", height: " << rect.height << "}";
    return os;
}

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int result = 0;
        stack<RectangleOrigin> rectangles;
        // Left to right traversal
        cout << "Starting left to right traversal..." << endl;
        for (auto i = 0; i < heights.size(); i++) {
            int idx = 0; // How far left we can grow the current rectangle. 
            while (!rectangles.empty() && heights.at(i) < rectangles.top().height) {
                // We have lowered, pop and calculate area.
                auto rect = rectangles.top();
                rectangles.pop();
                int area = rect.height * (i - rect.starting_index);
                std::cout << "Popped rectangle: " << rect << " with area: " << area << " at index: " << i << endl;
                result = max(result, area);
                idx++;
            }
            std::cout << "Pushed rectangle at " << i << ", extends back to: " << i-idx << ", with height: " << heights.at(i) << endl;
            rectangles.push({i-idx, heights.at(i)});
        }
        // Left to right traversal has ended, empty stack.
        while(!rectangles.empty()) {
            auto rect = rectangles.top();
            rectangles.pop();
            int area = rect.height * (heights.size()-rect.starting_index);
            std::cout << "Popped rectangle: " << rect << " with area: " << area << " at index: " << heights.size() << endl;
            result = max(result, area);
        }

        // Reverse the vector, then do a right to left traversal.
        cout << "Starting right to left traversal..." << endl;
        std::reverse(heights.begin(), heights.end());
        // right to left traversal
        for (auto i = 0; i < heights.size(); i++) {
            int idx = 0; // How far left we can grow the current rectangle. 
            while (!rectangles.empty() && heights.at(i) < rectangles.top().height) {
                // We have lowered, pop and calculate area.
                auto rect = rectangles.top();
                rectangles.pop();
                int area = rect.height * (i - rect.starting_index);
                std::cout << "Popped rectangle: " << rect << " with area: " << area << " at index: " << i << endl;
                result = max(result, area);
                idx++;
            }
            std::cout << "Pushed rectangle at " << i << ", extends back to: " << i-idx << ", with height: " << heights.at(i) << endl;
            rectangles.push({i-idx, heights.at(i)});
        }
        // right to left traversal has ended, empty stack.
        while(!rectangles.empty()) {
            auto rect = rectangles.top();
            rectangles.pop();
            int area = rect.height * (heights.size()-rect.starting_index);
            std::cout << "Popped rectangle: " << rect << " with area: " << area << " at index: " << heights.size() << endl;
            result = max(result, area);
        }        




        return result;  
    }
};

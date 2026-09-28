class Solution {
public:
    bool isValid(string s) {
        stack<char> foo;
        for (auto c : s) {
            if (foo.empty()) {
                foo.push(c);
                continue;
            }
            auto top = foo.top();
            bool round_found = (c == ')') && (top == '(');
            bool curly_found = (c == '}') && (top == '{');
            bool square_found = (c == ']') && (top == '[');
            if (round_found || curly_found || square_found) {
                foo.pop();
            } else {
                foo.push(c);
            }
        }
        return foo.empty();
     }
};

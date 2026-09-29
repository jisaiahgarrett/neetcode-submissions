class Solution {
public:

    // Use length prefix encoding
    // "hello", "world" -> "5hello5world"

    string encode(vector<string>& strs) {
        string result;
        for (auto str : strs) {
            result.append(to_string(str.size()));
            result.append(" ");
            result.append(str);
        }
        cout << result << endl;
        return result;
    }

    vector<string> decode(string s) {
        // 2 state FSM here, but we can simplify with a while loop since the 
        // transitions are so predictable.
        vector<string> results;
        char * c_ptr;
        int i = 0;
        while (i < s.size()) {
            size_t separator = s.find(' ', i);
            size_t length = stoull(s.substr(i, separator - i));
            size_t start = separator + 1;

            results.push_back(s.substr(start, length));
            i = start + length;
        }
        return results;
    }
};

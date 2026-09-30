class Solution {
public:

    // use length prefix encoding with a space delimiter
    string encode(vector<string>& strs) {
        string result;
        for (auto str : strs) {
            result += to_string(str.length()) + " " + str;
        }
        cout << result << endl;
        return result;
    }

    vector<string> decode(string s) {
        vector<string> results;
        // read the length off of the string (digits until " ")
        int i = 0;
        while (i < s.size()) {
            size_t delimeter = s.find(" ", i); 
            size_t length = stoull(s.substr(i, delimeter - i));
            size_t start = delimeter + 1;
            cout << length << endl;
            results.push_back(s.substr(start, length));
            i = start + length;
        }
        return results;
    }
};

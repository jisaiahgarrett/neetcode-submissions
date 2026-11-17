class Solution {
private:
    char delimeter_ = ' ';
public:
    // We can use prefix length encoding.
    // ["hello", "world"] should become
    // [5hello5world]
    // Edge cases:
    // 1. a number in the string -> means that we need a delimiter (space)
    // 2. a 2 or more digit length -> means that we read digits until we reach the delimeter
    // 3. an empty string -> will have length 0
    // ["1longstring", "world", ""] -> "11 1longstring5 world0 "

    string encode(vector<string>& strs) {
        string result;
        for (auto str : strs) {
            result += to_string(str.size());
            result += " ";
            result += str;
        }

        //return "11 1longstring5 world0 0 "; // for testing
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result; 
        size_t left = 0;
        while (left < s.size()) {
            size_t right = s.find(this->delimeter_, left);
            int length = stoi(s.substr(left, right-left));
            string const entry = s.substr(right+1, length);
            result.push_back(entry);
            left = right + 1 + length;
        }        
        return result;
    }
};

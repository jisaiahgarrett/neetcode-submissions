class Solution {
public:

    string encode(vector<string>& strs) {
        string result;
        for (auto string : strs) {
            result.append(string);
            // append the null char after every string
            result.push_back('\0');
        }
        // remove the null char off the end of the string.
        //result.pop_back();
        std::cout << result << std::endl;
        return result;
    }

    vector<string> decode(string s) {
        vector<string> result;
        // iterate through string using string::find to find \0.
        // while substr is not string::npos, append to result.
        size_t p1 = 0;
        size_t p2 = s.find('\0');
        // return early if we didn't find it, that means we had the null input.
        if (p2 == string::npos) {
            return result;
        }
        
        while (p2 != string::npos){
            string my_substr = s.substr(p1, p2 - p1);
            std::cout << my_substr << std::endl;
            result.push_back(my_substr);
            // Update the pointer to find the next substr.
            p1 = p2 + 1; 
            p2 = s.find('\0', p1);
        }

        return result;
    }
};

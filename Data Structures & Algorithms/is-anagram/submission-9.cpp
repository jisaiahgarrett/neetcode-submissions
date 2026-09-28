class Solution {
public:
    bool isAnagram(string s, string t) {
        // build a signature of each string (histogram of chars)
        // see if the signatures are the same.
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> s_sig, t_sig;
        for (int i = 0; i < s.length(); i++) {
            s_sig[s[i]]++;
            t_sig[t[i]]++;
        }

        return s_sig == t_sig; 
    }
};

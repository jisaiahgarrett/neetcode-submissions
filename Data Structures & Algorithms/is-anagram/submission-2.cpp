#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> s_freq;
        std::unordered_map<char, int> t_freq;
        for (char c : s) {
            s_freq[c] = s_freq[c] + 1;
        }
        for (char c : t) {
            t_freq[c] = t_freq[c] + 1;
        }
        return (s_freq == t_freq);
    }
};

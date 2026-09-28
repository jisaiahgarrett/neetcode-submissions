class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }

        unordered_map<char, int> s_map;
        unordered_map<char, int> t_map;

        for (int i = 0; i < s.length(); i++) {
            auto incrementCount = [](unordered_map<char, int> &a_map, char a_char) {
                if (!a_map.contains(a_char)) {
                    a_map[a_char] = 0;
                } else {
                    a_map[a_char]++;
                }
            };

            incrementCount(s_map, s[i]);
            incrementCount(t_map, t[i]);
        }
        return s_map == t_map;
    }
};

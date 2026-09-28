#include <iostream>
#include <unordered_map>

class Solution {
public:
    void print_unordered_map(std::unordered_map<char, int> map){
        std::cout << "{" << std::endl;
        for (auto x : map){
            std::cout << "\t" << x.first << ": " << x.second << std::endl;
        }
        std::cout << "}" << std::endl;
    }

    std::unordered_map<char, int> string_to_hashtable(string str) {
        std::unordered_map<char, int> ht;
        for (auto c : str) {
            ht[c]++;
        }
        return ht;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<unordered_map<char, int>> hashtables;
        // foreach str in strs
        for (auto str : strs) {
            std::cout << str.size() << std::endl;
            // convert str to current_hashtable with characters as keys and counts as values
            auto hashtable = string_to_hashtable(str);
            // print_unordered_map(hashtable);
            if (hashtables.size() == 0) {
                hashtables.push_back(hashtable);
                std::vector<string> new_group = {str};
                std::cout << "new group is " << new_group[0] << std::endl;
                result.push_back(new_group);
                continue;
            }
            // foreach i, hashtable in anagram_tables
            auto index = 0;
            bool result_found = false;
            for (auto anagram : hashtables) {
                if (hashtable == anagram) {
                    // found an anagram group that matches us.
                    result.at(index).push_back(str);
                    result_found = true;
                    break;
                }
                index++;
            }
            if (!result_found) {
                hashtables.push_back(hashtable);
                std::vector<string> new_group = {str};
                std::cout << "new group is " << new_group[0] << std::endl;
                result.push_back(new_group);
            }
        }
        return result;
    }
};

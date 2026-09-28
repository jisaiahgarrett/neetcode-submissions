class Solution {
public:
    bool isPalindrome(string s) {
        char *left = &s[0];
        char *right = &s[s.size()] - 1; 
        int max_iter = s.size();
        int iter = 0;
        while (left < right && iter < max_iter) {
            // Skip non-alphanumeric characters
            while(!isalnum(*left)) {
                left++;
                iter++;
            }
            while(!isalnum(*right)) {
                right--;
                iter++;
            }
            cout << "left: " << *left << ", right: " << *right << endl;
            if (left >= right) {
                break;
            }

            if (tolower(*right) != tolower(*left)) {
                return false;
            }

            left++;
            right--;
            iter += 2;
        }
        return true;
    }
};

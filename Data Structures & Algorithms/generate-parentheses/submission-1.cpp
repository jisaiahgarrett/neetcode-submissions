// This one is weird to me, so let's do some examples.
// Looks like you always need to start with an open paren and end with
// a close paren. So just consider the inside.
// Same number of 1's and 0's.

class Solution {
private:
    vector<string> result;
    string stack;
public:
    vector<string> generateParenthesis(int n) {
        backtrace(n, 0, 0);
        return result;
    }

    void backtrace(int n, int open_n, int close_n) {
        cout << "top of bt, open_n=" << open_n << ", close_n=" << close_n << endl;
        cout << "stack is " << stack << endl;

        // Base case, we have n opening and n closing parenthesis.
        if (open_n == n && close_n == n) {
            cout << "Valid solution found: " << stack << ", returning..." << endl;
            result.push_back(stack);
            return;
        }

        if (open_n < n) {
            stack += "(";
            backtrace(n, open_n + 1, close_n);
            stack.pop_back();
        }

        if (close_n < open_n) {
            stack += ")";
            backtrace(n, open_n, close_n + 1);
            stack.pop_back();
        }
    }

    
};

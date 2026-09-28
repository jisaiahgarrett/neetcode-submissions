// Ok, so we're dealing with integers here, so no worries on decimals.
// Integer division, nice, ok.
// You must evalute it as you go, right?
// Algo:
// Push values onto the stack until you see a operator.
// Pop two elements, apply the operator to them.
// Push the result on the stack.
// Continue doing this until you have processed all tokens. You 
// ought to be left with one value on the stack.
// There is an edge case here with tokens length one. Just return that
// singular value.

// Seems weird to me that we need O(n) space at all. 
// Dont we just need two variables???
// This is why you need a stack. For test cases like this:
//["4","13","5","/","+"] = (13 / 5) + 4 = 6


class Solution {
public:
    bool isNumber(string s) {
        // Need to handle strings like "-11".
        if (s.size() > 1) {
            // Handles -11, 123
            return true;
        }
        if (isdigit(s.at(0))) {
            // Handles 7
            return true;
        }
        // Handles +, -
        return false; 
    }

    int evalRPN(vector<string>& tokens) {
        // Edge case if we only have one input token.
        // Assumption here that it is an integer.
        if (tokens.size() == 1) {
            return stoi(tokens.at(0));
        }


        stack<int> operands;
        auto token_iter = tokens.begin();
        while (token_iter != tokens.end()) {
            cout << "token (pre update) is " << *token_iter << endl << flush;
            //char const * token = (*token_iter).c_str();
            //cout << "token is " << *token << endl << flush;
            if (isNumber(*token_iter)) {
                // We have a digit, push it onto the stack.
                cout << *token_iter << " is digit" << endl << flush;
                operands.push(stoi(*token_iter));
                token_iter++;
            } else {
                // We have an operand. Evalute the values on the stack.
                auto top_operator = operands.top();
                operands.pop();
                auto bottom_operator = operands.top();
                operands.pop();
                int result;
                string op = *token_iter;
                token_iter++;
                cout << "Operator is " << op.c_str()[0] << endl << flush;
                switch(op.c_str()[0]) {
                    case '+':
                        result = top_operator + bottom_operator;
                        operands.push(result);
                        break;

                    case '-':
                        result = bottom_operator - top_operator;
                        cout << "subtraction result is " << result << endl;
                        operands.push(result);
                        break;

                    case '*':
                        result = top_operator * bottom_operator;
                        operands.push(result);
                        break;
                        

                    case '/':
                        result = bottom_operator / top_operator;
                        operands.push(result); 
                        break;

                    default:
                        cout << "No match found for operator: " << op << endl << flush;
                }
                cout << "result is " << result << endl << flush;
            }    
        }
        return operands.top(); 
    }
};

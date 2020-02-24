#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


//// trim from start (in place)
//static inline void ltrim(std::string &s) {
//    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
//        return !std::isspace(ch);
//    }));
//}
//
//// trim from end (in place)
//static inline void rtrim(std::string &s) {
//    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
//        return !std::isspace(ch);
//    }).base(), s.end());
//}
//
//// trim from both ends (in place)
//static inline void trim(std::string &s) {
//    ltrim(s);
//    rtrim(s);
//}
//
//// trim from start (copying)
//static inline string ltrim_copy(string s) {
//    ltrim(s);
//    return s;
//}
//
//// trim from end (copying)
//static inline string rtrim_copy(string s) {
//    rtrim(s);
//    return s;
//}
//
//// trim from both ends (copying)
//static inline string trim_copy(string s) {
//    trim(s);
//    return s;
//}

////////////////////////////

bool to_bool(const char &ch) {
    return ch != '0';
}

char to_char(const bool& i) {
    return i ? '1': '0';
}

int circuitOutput(const string &circuitExpression) {
    int result = 0;
    stack<char> op_stack;

    for(auto const &ch : circuitExpression) {
        queue<char> temp;

        switch (ch)
        {
            case '[':
            case '0':
            case '1':
            case '|':
            case '&':
            case '!':
                op_stack.push(ch);
                break;

            case ']':
                // pop stack till matching '['

                while (!op_stack.empty() && op_stack.top() != '[') {
                    temp.push(op_stack.top());
                    op_stack.pop();
                }

                if (!op_stack.empty() && op_stack.top() == '[') {
                    op_stack.pop();
                }

                // eval not
                if (temp.size() == 2) {
                    bool lhs = to_bool(temp.front());
                    temp.pop();

                    op_stack.push(to_char(!lhs));

                }
                // eval binary op
                else if (temp.size() == 3) {

                    bool rhs = to_bool(temp.front());
                    temp.pop();
                    bool lhs = to_bool(temp.front());
                    temp.pop();

                    int op = temp.front();
                    temp.pop();

                    switch (op) {
                        case '&':
                            op_stack.push(to_char(lhs && rhs));
                            break;
                        case '|':
                            op_stack.push(to_char(lhs || rhs));
                            break;
                        default:
                            // error
                            break;
                    }
                }
                break;
            default:
                // no op
                break;
        }

    }

    if (op_stack.size() == 1) {
        result = to_bool(op_stack.top()) ? 1:0;
    }

    return result;
}

vector<int> circuitsOutput(const vector<string> &circuitsExpression) {
    vector<int> result;

    for(auto const &exp : circuitsExpression) {
        result.push_back(circuitOutput(exp));
    }

    return result;
}

int main() {
    string test =
            "  [|,   [&, 1, [!, 0]], [!, [|, [|, 1, 0], [!, 1]]]]   "
    ;

    vector<string> input;
    input.push_back(test);
    auto result = circuitsOutput(input);

    cout << result.front() << endl;
    return 0;
}
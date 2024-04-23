#include "bracket.h"

//int main()
//{
//    // output 1
//    std::string str = "<[*][*](){7}8<9>>{(0_0)(7)}";
//    std::cout << checkBrackets(str);
//}

// (), [], {}, <>

bool checkBrackets(const std::string& s) {
    std::stack<char> stack_bracket;

    for (char bracket : s) {
        if (bracket == '('||  bracket == '[' || bracket == '{' || bracket == '<') {
            stack_bracket.push(bracket);
        }
        else if (bracket == ')' || bracket == ']' || bracket == '}' || bracket == '>') {
            if (stack_bracket.empty()) {
                return false;
            }
            char get_top = stack_bracket.top();
            stack_bracket.pop();
            if ((bracket == ')' && get_top != '(') ||
                (bracket == ']' && get_top != '[') ||
                (bracket == '}' && get_top != '{') ||
                (bracket == '>' && get_top != '<')) {
                return false;
            }
        }
        else {
            continue;
        }
    }

    return stack_bracket.empty();
}
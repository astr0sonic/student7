#include "rpn.h"

//int main()
//{
//    std::string str = "7 8 9 / 1 - * 2 3 4 5 * + * 6 / + 1 2 + 3 4 - * -";
//    try {
//        double result = calculateRPN(str);
//        std::cout << "Result: " << result << std::endl;
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Error: " << e.what() << std::endl;
//    }
//}

bool isOperator(char symbol)
{
    return (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/');
}

double getValue(double first, double second, char symbol)
{
    double result = 0.0;
    switch (symbol)
    {
    case '+':
        result = first + second;
        break;
    case '-':
        result = first - second;
        break;
    case '*':
        result = first * second;
        break;
    case '/':
        if (second == 0.0) {
            throw std::logic_error("Divison by zero");
        }
        else {
            result = first / second;
        }
        break;
    default:
        break;
    }

    return result;
}

double calculateRPN(const std::string& expression) {
    std::stack<double> stack_rpn;

    for (char symbol : expression) {
        if (isspace(symbol)) {
            continue;
        }
        else if (isdigit(symbol)) {
            stack_rpn.push(static_cast<double>(symbol - '0'));
        }
        else if (isOperator(symbol) ) {
            if (stack_rpn.size() < 2) {
                throw std::invalid_argument("Invalid expression : more than one value left in stack");
            }
            double first = stack_rpn.top();
            stack_rpn.pop();
            double second = stack_rpn.top();
            stack_rpn.pop();

            double result_operation = getValue(second, first, symbol);
            stack_rpn.push(result_operation);
        }
    }

    if (stack_rpn.size() != 1) {
        throw std::invalid_argument("Invalid expression: more than one value left in stack");
    }

    double result = stack_rpn.top();
    return std::round(result * 1000) / 1000;
}

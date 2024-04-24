#include <iostream>
#include <cmath>
#include <cctype>
#include <stack>
#include <string>
#include <iomanip>

enum {OPEN_BRACKET, CLOSED_BRACKET, PLUS_OR_MINUS, MULT_OR_DIV, DEGREE, UNARY_MINUS };

double calculate(const std::string& expression);
void getPostfixNotation(const std::string& expression, std::stack<std::string>* postfixNotation);
bool isOperator(char symbol);
int getPriorityOperators(char symbol);
void reverseStack(std::stack<std::string> postfixNotation, std::stack<std::string>* reversePostfixNotation);
double calculatePostfixNotation(std::stack<std::string> postfixNotation);
double getExpressionValue(double firstNumber, double secondNumber, std::string operators);
#include <string>
#include <stack>
#include <iostream>
#include <cctype>
#include <cmath>

double calculateRPN(const std::string& expression);
bool isOperator(char symbol);
double getValue(double first, double second, char symbol);

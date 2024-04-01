#include <iostream>
#include <algorithm>

#define INF 1e-9 

using namespace std;

double calculateMaxValue(double* nums, int n);
double updateMaxValue(double& maxValue, double newValue);
double updateMinValue(double& minValue, double newValue);
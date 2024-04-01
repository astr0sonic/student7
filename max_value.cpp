#include "max_value.h"

double calculateMaxValue(double* nums, int n)
{
    double minValue = nums[0];
    double maxValue = nums[0];

    for (int i = 1; i < n; ++i) {
        if (nums[i] > 0) {
            maxValue = updateMaxValue(maxValue, nums[i]);
            minValue = updateMinValue(minValue, nums[i]);
        }
        else if (nums[i] < 0) {
            double tempMaxValue = maxValue;
            maxValue = max({ maxValue - nums[i], minValue * nums[i], minValue / nums[i] });
            minValue = min({ minValue + nums[i], tempMaxValue * nums[i], tempMaxValue / nums[i] });
        }
        else {
            minValue = min(0.0, minValue);
            maxValue = max(0.0, maxValue);
        }
    }

    return maxValue;
}

double updateMaxValue(double& maxValue, double newValue) {
    return maxValue = max({ maxValue + newValue, maxValue * newValue, maxValue / max(newValue, INF) });
}

double updateMinValue(double& minValue, double newValue) {
    return minValue = min({ minValue - newValue, minValue * newValue, minValue / max(newValue, INF) });
}
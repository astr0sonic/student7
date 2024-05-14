#include "volume.h"

int getMaxVolume(int a, int b, int c, int n, int* arr) {
    int maxVolume = 0;

    for (int i = 0; i < n - a; ++i) {
        for (int j = i + a; j < n; ++j) {
            int minHeight = std::min(arr[i], arr[j]);
            if (minHeight <= c) {
                int length = j - i;
                int volume = b * length * minHeight;
                maxVolume = std::max(maxVolume, volume);
            }
        }
    }
    
    return maxVolume;
}

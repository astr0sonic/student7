#include "volume.h"

int getMaxVolume(int a, int b, int c, int n, int* arr) {
    int maxVolume = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (j - i <= a && std::min(arr[i], arr[j]) <= c) {
                
                int volume = b * (j - i) * std::min(arr[i], arr[j]);
                
                maxVolume = (volume > maxVolume) ? volume : maxVolume;
            }
        }
    }

    return maxVolume;
}

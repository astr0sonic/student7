#include "sundaram.h"

vector<int> sieve(int n) {
    vector<int> primes;
    primes.push_back(2);
    vector<bool> visited(n);

    int sizeOdd = (n - 1) / 2;
	for (int i = 1; i <= sizeOdd; i++) {
		visited[i] = true;
	}

	for (int i = 1; i <= sizeOdd; i++) {
		for (int j = i; (i + j + 2 * i * j) <= sizeOdd; j++) {
			visited[i + j + 2 * i * j] = false;
		}
	}

	for (int i = 1; i <= sizeOdd; i++) {
		if (visited[i]) {
			primes.push_back(2 * i + 1);
		}
	}

    return primes;
}

#include "eratosthenes.h"

vector<int> sieve(int n) {

	vector<int> primes;
	vector<bool> visited(n);

	for (int i = 2; i <= n; i++) {
		visited[i] = true;
	}

	for (int i = 2; i <= n; i++) {
		if (visited[i]) {
			primes.push_back(i);
			for (int j = i * i; j <= n; j += i) {
				visited[j] = false;
			}
		}
	}
	
	return primes;

}

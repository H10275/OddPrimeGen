#include "PrimeUtils.h"
#include <cmath>
#include <vector>
using namespace std;

static vector<bool> isPrimeArray;

void PrimeUtils::generatePrimes(int upperLimit) {
    isPrimeArray.assign(upperLimit + 1, true);
    isPrimeArray[0] = isPrimeArray[1] = false;
    for (int i = 2; i * i <= upperLimit; ++i) {
        if (isPrimeArray[i]) {
            for (int j = i * i; j <= upperLimit; j += i)
                isPrimeArray[j] = false;
        }
    }
}

bool PrimeUtils::isPrime(int n) {
    if (n < 2 || n >= isPrimeArray.size()) return false;
    return isPrimeArray[n];
}
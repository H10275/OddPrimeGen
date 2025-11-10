// GoldbachEvenFixedRange.cpp
// OddGoldGen++ Module: Verify Goldbach's Conjecture using fixed prime range
// Author: Hassan Mohammad Othman Haridi
// Description: Tests E = p1 + p2 for even E using primes in user-defined range

#include <iostream>
#include <vector>
using namespace std;

class GoldbachEvenFixedRange {
public:
    void run() {
        int primeStart, primeEnd, evenLimit;
        cout << "\n----------------------------------------\n";
        cout << "[Goldbach Even Model] Verify E = p1 + p2\n";
        cout << "----------------------------------------\n";
        cout << "Enter start of prime range: ";
        cin >> primeStart;
        cout << "Enter end of prime range: ";
        cin >> primeEnd;
        cout << "Enter upper limit for even numbers to test: ";
        cin >> evenLimit;

        vector<int> primes = generatePrimes(primeEnd, primeStart);
        int total = 0, success = 0, failed = 0;

        for (int even = 4; even <= evenLimit; even += 2) {
            total++;
            bool found = false;
            for (int i = 0; i < primes.size(); ++i) {
                int p1 = primes[i];
                int p2 = even - p1;
                if (p2 >= primeStart && p2 <= primeEnd && isPrime(p2)) {
                    cout << even << " = " << p1 << " + " << p2 << endl;
                    found = true;
                    break;
                }
            }
            if (found) success++;
            else {
                cout << even << " ❌ No valid representation using selected primes\n";
                failed++;
            }
        }

        // Summary report
        cout << "\n--- Goldbach Summary ---\n";
        cout << "Total even numbers tested: " << total << endl;
        cout << "Successful representations: " << success << endl;
        cout << "Failed cases: " << failed << endl;
        cout << "Success rate: " << (success * 100.0 / total) << "%\n";
        cout << "Failure rate: " << (failed * 100.0 / total) << "%\n";
        cout << "----------------------------------------\n";
        cout << "Press any key to return to main menu...\n";
        cin.ignore(); cin.get();
    }

private:
    // Checks if a number is prime
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; ++i)
            if (n % i == 0) return false;
        return true;
    }

    // Generates primes between start and end
    vector<int> generatePrimes(int end, int start) {
        vector<int> primes;
        for (int i = start; i <= end; ++i)
            if (isPrime(i)) primes.push_back(i);
        return primes;
    }
};

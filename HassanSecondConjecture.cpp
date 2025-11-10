// HassanSecondConjecture.cpp
// OddGoldGen++ Module: Hassan's Second Conjecture
// Author: Hassan Mohammad Othman Haridi
// Description: Tests odd numbers > 7 as n = 5 + p1 + p2

#include <iostream>
#include <vector>
using namespace std;

class HassanSecondConjecture {
public:
    // Test a range of odd numbers
    void runRange() {
        int start, end;
        cout << "\n[Hassan's Second Conjecture] Range Test\n";
        cout << "Enter start of odd number range (>7): ";
        cin >> start;
        cout << "Enter end of odd number range: ";
        cin >> end;

        vector<int> primes = generatePrimes(end);
        int total = 0, success = 0, failed = 0;

        for (int n = start; n <= end; n += 2) {
            if (n <= 7 || n % 2 == 0) continue;
            total++;
            if (verifyTriple(n, primes)) {
                success++;
            }
            else {
                cout << n << " ❌ No valid representation as 5 + p1 + p2\n";
                failed++;
            }
        }

        // Summary
        cout << "\n--- Hassan Second Summary ---\n";
        cout << "Total odd numbers tested: " << total << endl;
        cout << "Successful representations: " << success << endl;
        cout << "Failed cases: " << failed << endl;
        cout << "Success rate: " << (success * 100.0 / total) << "%\n";
        cout << "Failure rate: " << (failed * 100.0 / total) << "%\n";
        cout << "----------------------------------------\n";
        cout << "Press any key to return...\n";
        cin.ignore(); cin.get();
    }

    // Test a single odd number
    void runSingle() {
        int n;
        cout << "\n[Hassan's Second Conjecture] Single Test\n";
        cout << "Enter an odd number greater than 7: ";
        cin >> n;

        if (n <= 7 || n % 2 == 0) {
            cout << "Invalid input. Must be an odd number > 7.\n";
            return;
        }

        vector<int> primes = generatePrimes(n);
        if (!verifyTriple(n, primes)) {
            cout << n << " ❌ No valid representation as 5 + p1 + p2\n";
        }

        cout << "----------------------------------------\n";
        cout << "Press any key to return...\n";
        cin.ignore(); cin.get();
    }

private:
    // Check if a number is prime
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; ++i)
            if (n % i == 0) return false;
        return true;
    }

    // Generate primes up to a limit
    vector<int> generatePrimes(int limit) {
        vector<int> primes;
        for (int i = 2; i <= limit; ++i)
            if (isPrime(i)) primes.push_back(i);
        return primes;
    }

    // Verify if n = 5 + p1 + p2 for some primes p1, p2
    bool verifyTriple(int target, const vector<int>& primes) {
        for (int i = 0; i < primes.size(); ++i) {
            for (int j = i; j < primes.size(); ++j) {
                int sum = 5 + primes[i] + primes[j];
                if (sum == target) {
                    cout << target << " = 5 + " << primes[i] << " + " << primes[j] << endl;
                    return true;
                }
            }
        }
        return false;
    }
};
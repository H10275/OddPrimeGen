// GoldbachEvenRange.cpp
// OddGoldGen++ Module: Verify Goldbach's Conjecture for Even Numbers in Range
// Author: Hassan Mohammad Othman Haridi
// Description: Tests E = p1 + p2 for all even E in user-defined range

#include <iostream>
#include <vector>
using namespace std;

class GoldbachEvenRange {
public:
    void run() {
        int start, end;
        cout << "\n----------------------------------------\n";
        cout << "[Goldbach Even Model] Verify E = p1 + p2\n";
        cout << "----------------------------------------\n";
        cout << "Enter start of even range: ";
        cin >> start;
        cout << "Enter end of even range: ";
        cin >> end;

        if (start % 2 != 0) start++; // Ensure starting number is even
        if (end % 2 != 0) end--;     // Ensure ending number is even

        cout << "\nGenerating primes and verifying representations...\n\n";
        vector<int> primes = generatePrimes(end);
        int total = 0, success = 0, failed = 0;

        for (int even = start; even <= end; even += 2) {
            total++;
            bool found = false;
            for (int i = 0; i < primes.size(); ++i) {
                int p1 = primes[i];
                int p2 = even - p1;
                if (p2 >= 2 && isPrime(p2)) {
                    cout << even << " = " << p1 << " + " << p2 << endl;
                    found = true;
                    break;
                }
            }
            if (found) success++;
            else {
                cout << even << " ❌ No valid prime representation found\n";
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

    // Generates all prime numbers up to a given limit
    vector<int> generatePrimes(int limit) {
        vector<int> primes;
        for (int i = 2; i <= limit; ++i)
            if (isPrime(i)) primes.push_back(i);
        return primes;
    }
};
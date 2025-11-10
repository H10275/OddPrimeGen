// GoldbachEvenSingleTest.cpp
// OddGoldGen++ Module: Verify Goldbach's Conjecture for a single even number
// Author: Hassan Mohammad Othman Haridi
// Description: Tests E = p1 + p2 for a specific even number entered by the user

#include <iostream>
#include <vector>
using namespace std;

class GoldbachEvenSingleTest {
public:
    void run() {
        int even;
        cout << "\n----------------------------------------\n";
        cout << "[Goldbach Even Model] Single Number Test\n";
        cout << "----------------------------------------\n";
        cout << "Enter an even number greater than 2: ";
        cin >> even;

        if (even <= 2 || even % 2 != 0) {
            cout << "Invalid input. Please enter an even number greater than 2.\n";
            return;
        }

        vector<int> primes = generatePrimes(even);
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

        if (!found) {
            cout << even << " ❌ No valid prime representation found\n";
        }

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

    // Generates all primes up to a given limit
    vector<int> generatePrimes(int limit) {
        vector<int> primes;
        for (int i = 2; i <= limit; ++i)
            if (isPrime(i)) primes.push_back(i);
        return primes;
    }
};
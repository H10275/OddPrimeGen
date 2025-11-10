// HassanFirstConjecture.cpp
// Tests odd primes > 5 as p = 3 + p1 + p2

#include <iostream>
#include <vector>
using namespace std;

class HassanFirstConjecture {
public:
    void runRange() {
        int start, end;
        cout << "\n[Hassan's First Conjecture] Range Test\n";
        cout << "Enter start of prime range (>5): "; cin >> start;
        cout << "Enter end of prime range: "; cin >> end;

        vector<int> primes = generatePrimes(end);
        int total = 0, success = 0, failed = 0;

        for (int p : primes) {
            if (p <= 5 || p % 2 == 0) continue;
            total++;
            if (verifyTriple(p, primes)) success++;
            else { cout << p << " ❌ No valid representation as 3 + p1 + p2\n"; failed++; }
        }

        cout << "\n--- Hassan First Summary ---\n";
        cout << "Total: " << total << ", Success: " << success << ", Failed: " << failed << endl;
        cout << "Success rate: " << (success * 100.0 / total) << "%\n";
        cin.ignore(); cin.get();
    }

    void runSingle() {
        int p;
        cout << "\n[Hassan's First Conjecture] Single Test\n";
        cout << "Enter an odd prime > 5: "; cin >> p;
        if (p <= 5 || p % 2 == 0 || !isPrime(p)) {
            cout << "Invalid input.\n"; return;
        }

        vector<int> primes = generatePrimes(p);
        if (!verifyTriple(p, primes)) {
            cout << p << " ❌ No valid representation as 3 + p1 + p2\n";
        }
        cin.ignore(); cin.get();
    }

private:
    bool isPrime(int n) {
        if (n < 2) return false;
        for (int i = 2; i * i <= n; ++i)
            if (n % i == 0) return false;
        return true;
    }

    vector<int> generatePrimes(int limit) {
        vector<int> primes;
        for (int i = 2; i <= limit; ++i)
            if (isPrime(i)) primes.push_back(i);
        return primes;
    }

    bool verifyTriple(int target, const vector<int>& primes) {
        for (int i = 0; i < primes.size(); ++i)
            for (int j = i; j < primes.size(); ++j)
                if (3 + primes[i] + primes[j] == target) {
                    cout << target << " = 3 + " << primes[i] << " + " << primes[j] << endl;
                    return true;
                }
        return false;
    }
};
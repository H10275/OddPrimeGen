#include "GoldbachOddModel.h"
#include "PrimeUtils.h"
#include <iostream>
#include <vector>
using namespace std;

void GoldbachOddModel::run() {
    int subChoice;
    int start = 2, end = 100;

    while (true) {
        cout << "\n----------------------------------------\n";
        cout << "[Goldbach Odd Model] Verify n = p1 + p2 + p3\n";
        cout << "1. Generate primes and show representations for odd numbers\n";
        cout << "2. Test a specific odd number\n";
        cout << "3. Return to main menu\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> subChoice;

        if (subChoice == 1) {
            cout << "\nEnter start of prime range: ";
            cin >> start;
            cout << "Enter end of prime range: ";
            cin >> end;
            PrimeUtils::generatePrimes(end);

            int maxOdd;
            cout << "\nEnter upper limit for odd numbers to test: ";
            cin >> maxOdd;

            int success = 0, fail = 0;
            vector<int> failedList;

            cout << "\n--- Representations ---\n";
            for (int n = 9; n <= maxOdd; n += 2) {
                bool found = false;
                for (int i = start; i <= n - 4; ++i) {
                    for (int j = start; j <= n - i - 2; ++j) {
                        int k = n - i - j;
                        if (PrimeUtils::isPrime(i) && PrimeUtils::isPrime(j) && PrimeUtils::isPrime(k)) {
                            cout << n << " = " << i << " + " << j << " + " << k << "\n";
                            found = true;
                            break;
                        }
                    }
                    if (found) break;
                }
                if (found) success++;
                else {
                    fail++;
                    failedList.push_back(n);
                }
            }

            // عرض النتائج التحليلية
            cout << "\n--- Summary ---\n";
            cout << "Total tested: " << (success + fail) << "\n";
            cout << "Successful: " << success << "\n";
            cout << "Failed: " << fail << "\n";
            cout << "Success rate: " << (100.0 * success / (success + fail)) << "%\n";

            if (!failedList.empty()) {
                cout << "Failed numbers: ";
                for (int num : failedList)
                    cout << num << " ";
                cout << "\n";
            }
        }

        else if (subChoice == 2) {
            int test;
            cout << "\nEnter an odd number to test: ";
            cin >> test;
            if (test % 2 == 0 || test < 9) {
                cout << "Invalid input. Must be odd and >= 9.\n";
                continue;
            }
            cout << "Enter start of prime range: ";
            cin >> start;
            cout << "Enter end of prime range: ";
            cin >> end;
            PrimeUtils::generatePrimes(end);

            bool found = false;
            for (int i = start; i <= test - 4; ++i) {
                for (int j = start; j <= test - i - 2; ++j) {
                    int k = test - i - j;
                    if (PrimeUtils::isPrime(i) && PrimeUtils::isPrime(j) && PrimeUtils::isPrime(k)) {
                        cout << "Representation: " << test << " = " << i << " + " << j << " + " << k << "\n";
                        found = true;
                        break;
                    }
                }
                if (found) break;
            }
            if (!found)
                cout << "No representation found for " << test << "\n";
        }

        else if (subChoice == 3) {
            cout << "Returning to main menu...\n";
            break;
        }

        else if (subChoice == 4) {
            cout << "Exiting program. Goodbye!\n";
            exit(0);
        }

        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

#include "HassanCompositeModel.h"
#include "PrimeUtils.h"
#include <iostream>
#include <vector>
using namespace std;

void HassanCompositeModel::run() {
    int subChoice;
    int start = 2, end = 100;

    while (true) {
        cout << "\n----------------------------------------\n";
        cout << "[Hassan Composite Model] Verify n = 5 + p1 + p2\n";
        cout << "1. Generate primes and show representations for odd composites\n";
        cout << "2. Test a specific odd composite\n";
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

            int maxComposite;
            cout << "\nEnter upper limit for odd composites to test: ";
            cin >> maxComposite;

            int success = 0, fail = 0;
            vector<int> failedList;

            cout << "\n--- Representations ---\n";
            for (int n = 9; n <= maxComposite; n += 2) {
                if (PrimeUtils::isPrime(n)) continue;
                int target = n - 5;
                bool found = false;
                for (int i = start; i <= target / 2; ++i) {
                    int j = target - i;
                    if (PrimeUtils::isPrime(i) && PrimeUtils::isPrime(j)) {
                        cout << n << " = 5 + " << i << " + " << j << "\n";
                        found = true;
                        break;
                    }
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
                cout << "Failed composites: ";
                for (int num : failedList)
                    cout << num << " ";
                cout << "\n";
            }
        }

        else if (subChoice == 2) {
            int test;
            cout << "\nEnter an odd composite number to test: ";
            cin >> test;
            if (PrimeUtils::isPrime(test) || test % 2 == 0 || test < 9) {
                cout << "Invalid input. Must be an odd composite >= 9.\n";
                continue;
            }
            cout << "Enter start of prime range: ";
            cin >> start;
            cout << "Enter end of prime range: ";
            cin >> end;
            PrimeUtils::generatePrimes(end);

            int target = test - 5;
            bool found = false;
            for (int i = start; i <= target / 2; ++i) {
                int j = target - i;
                if (PrimeUtils::isPrime(i) && PrimeUtils::isPrime(j)) {
                    cout << "Representation: " << test << " = 5 + " << i << " + " << j << "\n";
                    found = true;
                    break;
                }
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

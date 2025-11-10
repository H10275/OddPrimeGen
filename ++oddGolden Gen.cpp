// main.cpp
// OddGoldGen++ Unified Interface
// Author: Hassan Mohammad Othman Haridi

#include <iostream>
#include "GoldbachEvenRange.cpp"
#include "GoldbachEvenSingleTest.cpp"
#include "HassanFirstConjecture.cpp"
#include "HassanSecondConjecture.cpp"

using namespace std;

void showMainMenu() {
    cout << "\n========================================\n";
    cout << "         OddGoldGen++ | Main Menu        \n";
    cout << "========================================\n";
    cout << "[1] Goldbach Basic Conjecture\n";
    cout << "[2] Hassan's First Conjecture\n";
    cout << "[3] Hassan's Second Conjecture\n";
    cout << "[4] Exit Program\n";
    cout << "========================================\n";
    cout << "Enter your selection: ";
}

void showGoldbachMenu() {
    int choice;
    while (true) {
        cout << "\n----------------------------------------\n";
        cout << " Goldbach Basic Conjecture\n";
        cout << "----------------------------------------\n";
        cout << "[1] Generate and test even numbers in range\n";
        cout << "[2] Test a specific even number\n";
        cout << "[3] Return to main menu\n";
        cout << "[4] Exit\n";
        cout << "----------------------------------------\n";
        cout << "Enter your selection: ";
        cin >> choice;

        switch (choice) {
        case 1: GoldbachEvenRange().run(); break;
        case 2: GoldbachEvenSingleTest().run(); break;
        case 3: return;
        case 4: exit(0);
        default: cout << "Invalid choice. Try again.\n";
        }
    }
}

void showHassanFirstMenu() {
    int choice;
    cout << "\nHassan's First Conjecture:\n";
    cout << "Every odd prime greater than 5 can be expressed as the sum of three primes, one of which is 3.\n";

    while (true) {
        cout << "\n----------------------------------------\n";
        cout << " Hassan's First Conjecture\n";
        cout << "----------------------------------------\n";
        cout << "[1] Generate and test odd primes in range\n";
        cout << "[2] Test a specific odd prime\n";
        cout << "[3] Return to main menu\n";
        cout << "[4] Exit\n";
        cout << "----------------------------------------\n";
        cout << "Enter your selection: ";
        cin >> choice;

        switch (choice) {
        case 1: HassanFirstConjecture().runRange(); break;
        case 2: HassanFirstConjecture().runSingle(); break;
        case 3: return;
        case 4: exit(0);
        default: cout << "Invalid choice. Try again.\n";
        }
    }
}

void showHassanSecondMenu() {
    int choice;
    cout << "\nHassan's Second Conjecture:\n";
    cout << "Every odd number greater than 7 can be expressed as the sum of three primes, one of which is 5.\n";

    while (true) {
        cout << "\n----------------------------------------\n";
        cout << " Hassan's Second Conjecture\n";
        cout << "----------------------------------------\n";
        cout << "[1] Generate and test odd numbers in range\n";
        cout << "[2] Test a specific odd number\n";
        cout << "[3] Return to main menu\n";
        cout << "[4] Exit\n";
        cout << "----------------------------------------\n";
        cout << "Enter your selection: ";
        cin >> choice;

        switch (choice) {
        case 1: HassanSecondConjecture().runRange(); break;
        case 2: HassanSecondConjecture().runSingle(); break;
        case 3: return;
        case 4: exit(0);
        default: cout << "Invalid choice. Try again.\n";
        }
    }
}

int main() {
    int mainChoice;
    while (true) {
        showMainMenu();
        cin >> mainChoice;

        switch (mainChoice) {
        case 1: showGoldbachMenu(); break;
        case 2: showHassanFirstMenu(); break;
        case 3: showHassanSecondMenu(); break;
        case 4: cout << "\nExiting program. Goodbye!\n"; return 0;
        default: cout << "Invalid selection. Please choose 1–4.\n";
        }
    }
}
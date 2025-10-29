#include <iostream>
using namespace std;

double tax(double income, double rate = 10 /*default 10%*/) {
    return income * rate / 100;
}

int main() {
    double income;
    cout << "Enter income: ";
    cin >> income;
    cout << "Tax amount (default 10%): " << tax(income);
    double tax_percent;
    cout << "\nEnter tax percentage: ";
    cin >> tax_percent;
    cout << "Tax amount (for " << tax_percent << "%): " << tax(income, tax_percent) << "\n";
    return 0;
}
